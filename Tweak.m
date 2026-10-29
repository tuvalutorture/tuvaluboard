#include <Foundation/Foundation.h>
#include <CydiaSubstrate.h>
#include <objc/runtime.h>
#include <UIKit/UIKit.h>
#include "Firmware/Firmware.h"
#include "Tweak.h"

static void SBIconList_layoutIconsIfNeeded(__unused id self, __unused SEL _cmd) {
    // do fuck all, apparently, to fix the stupid
    /*
      if ( -[SBIconList iconsInRow:](self, "iconsInRow:", v13) == 1 )
        v2 = (float)(v5 - 59.0) - 17.0 + 1.0;
    */
    // sadkghklasjdghkjasdhfgkjwehfklwrhglkjwehfklwhfklwerhfkjwerhfkwehrfklwehf
    // i'mma go chamber a round through my head brb
}

static id bgView = nil;

static void updateBGImage(__unused CFNotificationCenterRef center, __unused void *observer, __unused CFStringRef name, __unused void *object, __unused CFDictionaryRef userInfo) {
    if (bgView) {
        id image = [UIImage alloc];
        [bgView setImage:[image initWithContentsOfFile:@"/var/root/Library/LockBackground.jpg" cache:YES]];
        [bgView setNeedsDisplay];
        [image release];
    }
}

@interface Scapegoat : UIImageView 
@end

@implementation Scapegoat
- (void)setAlpha:(CGFloat)alpha {
    return;
}
@end

static void (*SBSlidingAlertDisplay_dismiss_orig)(id, SEL) = NULL;
static void SBSlidingAlertDisplay_dismiss(SBAwayView *self, SEL _cmd) {
    object_setClass(self->_backgroundView, [Scapegoat class]);
    SBSlidingAlertDisplay_dismiss_orig(self, _cmd);
    object_setClass(self->_backgroundView, [UIImageView class]);
}

// TESTING WEIRD SHIT HERE

// void __cdecl -[SBDisplay setActivationSetting:flag:](SBDisplay *self, SEL a2, int a3, char a4)
static void (*SBDisplay_setActivationSetting_flag_orig)(id, SEL, int, char) = NULL;
static void SBDisplay_setActivationSetting_flag(SBDisplay *self, SEL _cmd, int a3, char a4) {
    SBDisplay_setActivationSetting_flag_orig(self, _cmd, a3, a4);           
}

// void __cdecl -[SBDisplay setDeactivationSetting:flag:](SBDisplay *self, SEL a2, int a3, char a4)
static void (*SBDisplay_setDeactivationSetting_flag_orig)(id, SEL, int, char) = NULL;
static void SBDisplay_setDeactivationSetting_flag(SBDisplay *self, SEL _cmd, int a3, char a4) {
    SBDisplay_setDeactivationSetting_flag_orig(self, _cmd, a3, a4);
    if (a3 == 2 && !a4) {
        //[[[NSClassFromString(@"SBStatusBarController") sharedStatusBarController] statusBarView] setAlpha:0.6f];        
    }
}

// void __cdecl -[SBUIController restoreIconList:force:](SBUIController *self, SEL a2, char a3, char a4)
static void (*SBUIController_restoreIconList_force_orig)(id, SEL, char, char) = NULL;
static void SBUIController_restoreIconList_force(SBUIController *self, SEL _cmd, char a3, char a4) {
    SBUIController_restoreIconList_force_orig(self, _cmd, a3, a4);
    //[[NSClassFromString(@"SBStatusBarController") sharedStatusBarController] setStatusBarMode:1 orientation:0 duration:0 fenceID:0 animation:0];
    //[[NSClassFromString(@"SBApplication") springBoard] updateStatusBar:2.0f];
}

// void __cdecl -[SBUIController setState:](SBUIController *self, SEL a2, int a3)
static void (*SBUIController_setState_orig)(id, SEL, int) = NULL;
static void SBUIController_setState(SBUIController *self, SEL _cmd, int a3) {
    SBUIController_setState_orig(self, _cmd, a3);
    if (a3 == 0) {
        //[[NSClassFromString(@"SBStatusBarController") sharedStatusBarController] setStatusBarMode:1 orientation:0 duration:0 fenceID:0 animation:0];
        //[[NSClassFromString(@"SBApplication") springBoard] updateStatusBar:2.0f];
    }
}

// ok weird tests over

static id (*SBIconController_contentView_orig)(id, SEL) = NULL;
static id SBIconController_contentView(SBIconController *self, SEL _cmd) {
    id orig = SBIconController_contentView_orig(self, _cmd);
    if (!bgView) {
        id backgroundView = [NSClassFromString(@"UIImageView") new];
        [self->_contentView insertSubview:backgroundView atIndex:0];
        CGSize size = [NSClassFromString(@"UIHardware") mainScreenSize];
        CGRect frame = CGRectMake(0, -20.0, size.width, size.height);
        [backgroundView setFrame:frame];
        [backgroundView release];
        bgView = backgroundView;
        [bgView setImage:[NSClassFromString(@"UIImage") defaultDesktopImage]];
        CFNotificationCenterAddObserver(CFNotificationCenterGetDarwinNotifyCenter(), bgView, (CFNotificationCallback)updateBGImage, CFSTR("__UIKitDesktopImageChangedNotification"), NULL, CFNotificationSuspensionBehaviorDeliverImmediately);
    }
    return orig;
}

/*  
    this code down here was all written by my goat Nightwind, 
    i'm lwk just incorporating it here because it's easy enough to incorporate, 
    plus it'll be fine if the original tweak is installed alongside anyways so :P 
*/
@interface FIL_NSArray : NSArray
@end

@implementation FIL_NSArray
- (BOOL)containsObject:(id)object {
    return YES;
}
@end

static NSArray *SBPlatformController_disallowedDisplayIdentifiers_hook(__unused id self, __unused SEL _cmd) {
    return @[];
}

static NSArray *(*SBPlatformController_allowedDisplayIdentifiers_orig)(id, SEL) = NULL;
static NSArray *SBPlatformController_allowedDisplayIdentifiers_hook(id self, SEL _cmd) {
    NSArray *orig = SBPlatformController_allowedDisplayIdentifiers_orig(self, _cmd);
    object_setClass(orig, [FIL_NSArray class]);
    return orig;
}

__attribute__((constructor)) static void init(void) {
    /* more nightwind code */
    if (FIRMWARE_AT_LEAST(@"1.1.3")) {
        MSHookMessageEx(NSClassFromString(@"SBPlatformController"), sel_getUid("disallowedDisplayIdentifiers"), (IMP)SBPlatformController_disallowedDisplayIdentifiers_hook, NULL);
    } else {
        MSHookMessageEx(NSClassFromString(@"SBPlatformController"), sel_getUid("allowedDisplayIdentifiers"), (IMP)SBPlatformController_allowedDisplayIdentifiers_hook, (IMP *)&SBPlatformController_allowedDisplayIdentifiers_orig);
    }
    /* end of nightwind code, begin my code :3 */
    MSHookMessageEx(NSClassFromString(@"SBIconList"), sel_getUid("layoutIconsIfNeeded"), (IMP)SBIconList_layoutIconsIfNeeded, NULL);
    MSHookMessageEx(NSClassFromString(@"SBIconController"), sel_getUid("contentView"), (IMP)SBIconController_contentView, (IMP *)&SBIconController_contentView_orig);
    MSHookMessageEx(NSClassFromString(@"SBSlidingAlertDisplay"), sel_getUid("dismiss"), (IMP)SBSlidingAlertDisplay_dismiss, (IMP *)&SBSlidingAlertDisplay_dismiss_orig);
    MSHookMessageEx(NSClassFromString(@"SBDisplay"), sel_getUid("setDeactivationSetting:flag:"), (IMP)SBDisplay_setDeactivationSetting_flag, (IMP *)&SBDisplay_setDeactivationSetting_flag_orig);
    MSHookMessageEx(NSClassFromString(@"SBUIController"), sel_getUid("restoreIconList:force:"), (IMP)SBUIController_restoreIconList_force, (IMP *)&SBUIController_restoreIconList_force_orig);
    MSHookMessageEx(NSClassFromString(@"SBUIController"), sel_getUid("setState:"), (IMP)SBUIController_setState, (IMP *)&SBUIController_setState_orig);
    MSHookMessageEx(NSClassFromString(@"SBDisplay"), sel_getUid("setActivationSetting:flag:"), (IMP)SBDisplay_setActivationSetting_flag, (IMP *)&SBDisplay_setActivationSetting_flag_orig);
}