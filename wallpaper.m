#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import <CydiaSubstrate.h>
#import "wallpaper.h"

typedef struct {
    id albumController;
    id a3;
    CGRect a4;
    id a5;
    id a6;
    id a7;
} photoPickerStruct;

static photoPickerStruct photoPickerData;

@implementation WallpaperAlbumController (TuvaluBoard)
- (void)setWallpaperData:(NSString*)destPath withImage:(id)image withNotification:(NSString*)notificationName {
    NSString* path = [NSHomeDirectory() stringByAppendingPathComponent:destPath];
    [image writeToFile:path atomically:YES];
    CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(), (CFStringRef)notificationName, NULL, NULL, YES);
}

- (void)_backgroundSaveHomeScreenPhoto:(id)photo { 
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    [self setWallpaperData:@"Library/HomeBackground.jpg" withImage:photo withNotification:@"__UIKitHomeScreenImageChangedNotification"];
    [pool release];
}

- (void)_backgroundSaveLockScreenPhoto:(id)photo { 
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    [self setWallpaperData:@"Library/LockBackground.jpg" withImage:photo withNotification:@"__UIKitDesktopImageChangedNotification"];
    [pool release];
}

- (void)alertSheet:(id)sheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    switch (buttonIndex) {
        case 0:
            [NSThread detachNewThreadSelector:@selector(_backgroundSaveHomeScreenPhoto:) toTarget:self withObject:photoPickerData.a6];
            break;
        case 1:
            [NSThread detachNewThreadSelector:@selector(_backgroundSaveLockScreenPhoto:) toTarget:self withObject:photoPickerData.a6];
            break;
        case 2:
            [self dismissDidSetWallpaper:NO];
            break;
        default:
            break;
    }

    [sheet dismiss];
    memset(&photoPickerData, 0, sizeof(photoPickerData));
    
}
@end

static void WallpaperAlbumController_photoPicker(WallpaperAlbumController *self, __unused SEL _cmd, id a3, CGRect a4, id a5, id a6, id a7) {

    photoPickerData.albumController = self;
    photoPickerData.a3 = a3;
    photoPickerData.a4 = a4;
    photoPickerData.a5 = a5;
    photoPickerData.a6 = a6;
    photoPickerData.a7 = a7;
    UIAlertSheet *sheet = [[NSClassFromString(@"UIAlertSheet") alloc] initWithFrame:[self->_photoPicker frame]];
    [sheet setTitle:@"Set Wallpaper"];
    [sheet setBodyText:@"Set for Lock Screen or Home Screen?"];
    [sheet addButtonWithTitle:@"Lock Screen"];
    [sheet addButtonWithTitle:@"Home Screen"];
    [sheet addButtonWithTitle:@"Cancel"];
    [sheet popupAlertAnimated:YES];
    [sheet setDelegate:self];
}

__attribute__((constructor)) static void init(void) {
    int *deref = NULL;
    deref[0] = 0;
    memset(&photoPickerData, 0, sizeof(photoPickerData));
    MSHookMessageEx(NSClassFromString(@"WallpaperAlbumController"), sel_getUid("photoPicker:didCropPhotoToRect:fullSizeImageData:fullScreenImageData:croppedImageData:"), (IMP)WallpaperAlbumController_photoPicker, NULL);
}
