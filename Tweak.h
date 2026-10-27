@class NSMutableArray, NSString, SBStatusBar, SBStatusBarContentsView, UIWindow;

@interface SBStatusBarController : NSObject
{
    UIWindow *_slidingStatusBarWindow;
    int _slidingStatusBarAnimation;
    UIWindow *_animatingCallStatusBarWindow;
    UIWindow *_leftBottomCorner;
    UIWindow *_rightBottomCorner;
    SBStatusBar *_statusBarView;
    SBStatusBarContentsView *_statusBarContentsView;
    SBStatusBar *_transitioningStatusBarView;
    SBStatusBar *_animatingCallStatusBar;
    SBStatusBarContentsView *_transitioningStatusBarContentsView;
    unsigned int _isLocked:1;
    unsigned int _lockIsChanging:1;
    unsigned int _dimmed:1;
    unsigned int _showDimmerOverlay:1;
    unsigned int _animating:1;
    unsigned int _isInCall:1;
    unsigned int _airplaneMode:1;
    unsigned int _showsProgress:1;
    unsigned int _cloakStatusBar:1;
    unsigned int _showAirport:1;
    unsigned int _animateDefaultStatusBarDown:1;
    unsigned int _animateDefaultStatusBarUp:1;
    NSMutableArray *_statusBarIndicatorNames;
    int _mode;
    int _orientation;
    int _animatingCallStatusBarOrientation;
    NSString *_customText;
    int _airPortSignalStrength;
    int _queuedStatusBarMode;
    int _queuedStatusBarOrientation;
    float _duration;
    BOOL _telephonyControllerCheckedIn;
    BOOL _bluetoothControllerCheckedIn;
}

+ (id)sharedStatusBarController;
+ (BOOL)isLikeAFullScreenStatusBar:(int)arg1;
+ (id)statusBarImageNamed:(id)arg1 forMode:(int)arg2;
- (id)init;
- (void)dealloc;
- (void)preheatStatusBarForMode:(int)arg1 orientation:(int)arg2;
- (id)statusBarWindow;
- (id)statusBarView;
- (id)transitioningStatusBarView;
- (void)addStatusBarItem:(id)arg1;
- (void)setIsLocked:(BOOL)arg1;
- (BOOL)isLocked;
- (BOOL)isLockChanging;
- (void)setDimmed:(BOOL)arg1;
- (BOOL)dimmed;
- (BOOL)showDimmerOverlay;
- (void)setShowDimmerOverlay:(BOOL)arg1;
- (void)tearDownWindowForSlidingStatusBar:(id)arg1 overStatusBar:(id)arg2;
- (void)setupWindowForSlidingStatusBar:(id)arg1 overStatusBar:(id)arg2;
- (void)endCallStatusBarAnimationFinished;
- (void)resizeStatusBar:(float)arg1 grow:(BOOL)arg2;
- (void)setIsInCall:(BOOL)arg1;
- (BOOL)isInCall;
- (void)animateDefaultStatusBarDown;
- (BOOL)isAnimatingStatusBarDown;
- (void)animateDefaultStatusBarUp:(int)arg1;
- (BOOL)isAnimatingStatusBarUp;
- (BOOL)_isServiceAvailable;
- (id)_SIMStatus;
- (void)_SIMOrServiceStatusChanged;
- (void)_SIMStatusChanged:(id)arg1;
- (void)_serviceStatusChanged:(id)arg1;
- (void)setAirplaneModeIsEnabled:(BOOL)arg1;
- (BOOL)airplaneModeIsEnabled;
- (void)removeStatusBarItem:(id)arg1;
- (id)statusBarIndicatorNames;
- (id)customText;
- (void)setCustomText:(id)arg1;
- (void)setAirPortStrength:(int)arg1;
- (void)setShowsAirPort:(BOOL)arg1;
- (BOOL)showsAirPort;
- (int)airPortStrength;
- (void)setCloakStatusBar:(BOOL)arg1;
- (BOOL)cloakStatusBar;
- (void)updateProgressVisibility;
- (BOOL)showsProgress;
- (void)setStatusBarMode:(int)arg1 orientation:(int)arg2 duration:(float)arg3 fenceID:(int)arg4 animation:(int)arg5;
- (void)_setStatusBarSize:(BOOL)arg1;
- (void)_setTransitionalStatusBarSize:(BOOL)arg1;
- (void)finishSwitching;
- (void)statusBarDidFinishAnimatingDown;
- (void)restoreLevels;
- (void)statusBarDidFinishAnimatingUp;
- (void)switchBackstopFrom:(int)arg1 to:(int)arg2 fromOrientation:(int)arg3 toOrientation:(int)arg4 duration:(float)arg5 fenceID:(int)arg6 animation:(int)arg7;
- (void)orderStatusBarFront;
- (void)_finishStatusBarAnimation;
- (void)lockCurrentStatusBarForAnimation;
- (void)releaseLockedStatusBarForAnimationForDisplay:(id)arg1;
- (int)statusBarMode;
- (int)statusBarOrientation;
- (float)animationDuration;
- (void)significantTimeChange;
- (void)updateClockFormat;
- (void)signalFormatChanged;
- (void)checkInController:(int)arg1;
- (BOOL)telephonyControllerCheckedIn;
- (BOOL)bluetoothControllerCheckedIn;
- (void)loopCarrierNameIfNecessary;

@end



@class SBAlert;

@interface SBAlertDisplay : UIView
{
    SBAlert *_alert;
    unsigned int _displaysAboveStatusBar:1;
    unsigned int _shouldAnimateIn:1;
}

- (void)setAlert:(id)arg1;
- (id)alert;
- (void)launchURL:(id)arg1;
- (void)willDismiss;
- (void)dismiss;
- (void)setHandlerAlreadyActive:(BOOL)arg1;
- (void)alertDisplayWillBecomeVisible;
- (void)alertDisplayBecameVisible;
- (BOOL)displaysAboveStatusBar;
- (void)setDisplaysAboveStatusBar:(BOOL)arg1;
- (BOOL)isReadyToBeRemovedFromView;
- (void)setShouldAnimateIn:(BOOL)arg1;
- (BOOL)shouldAnimateIn;

@end



@class SBDeviceLockKeypad, SBEmergencyCallView, TPLCDView, UIImageView, UIPasscodeField, UIView;

@interface SBSlidingAlertDisplay : SBAlertDisplay
{
    @public
    UIImageView *_backgroundView;
    UIView *_topBar;
    UIView *_bottomBar;
    TPLCDView *_deviceLockStatusView;
    SBDeviceLockKeypad *_deviceLockKeypad;
    UIImageView *_deviceLockEntryBackground;
    UIPasscodeField *_deviceLockEntryField;
    SBEmergencyCallView *_emergencyCallView;
    BOOL _playKeyboardClicks;
    unsigned int _animatingEmergencyCall:1;
    unsigned int _animatingIn:1;
    unsigned int _animatingOut:1;
    unsigned int _shouldFenceAnimations:1;
    unsigned int _showingDeviceLock:1;
    unsigned int _attemptingUnlock:1;
    unsigned int _showingDeviceUnlockFailure:1;
}

+ (id)createTopBarForInstance:(id)arg1;
+ (id)createBottomBarForInstance:(id)arg1;
+ (void)setDisplayPropertiesForActivationOfAlert:(id)arg1;
- (void)_setTopBarImage:(id)arg1 shadowColor:(struct CGColor *)arg2;
- (void)_resetStatusTextView;
- (void)_clearUnlockFailedIndicator;
- (void)_showUnlockFailedIndicator;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dealloc;
- (id)lockBar;
- (struct CGRect)middleFrame;
- (void)getFrameForTopButton:(struct CGRect *)arg1 bottomButton:(struct CGRect *)arg2;
- (BOOL)showsDesktopImage;
- (void)updateDesktopImage:(id)arg1;
- (void)finishedAnimatingIn;
- (BOOL)shouldAnimateIconsIn;
- (BOOL)shouldAnimateIconsOut;
- (BOOL)isAnimatingOut;
- (void)_fadeOutCompleted:(id)arg1;
- (void)setMiddleContentAlpha:(float)arg1;
- (BOOL)isReadyToBeRemovedFromView;
- (float)durationForOthersActivation;
- (void)dismiss;
- (void)beginAnimatingDisplayIn:(BOOL)arg1;
- (void)performAnimateDisplayIn;
- (void)animateDisplayIn:(float)arg1 middleDelay:(float)arg2 animateStatusBar:(BOOL)arg3;
- (void)alertDisplayWillBecomeVisible;
- (void)setShouldFenceAnimations:(BOOL)arg1;
- (BOOL)isShowingDeviceLock;
- (struct CGRect)_entryFrame;
- (float)_startingKeypadXOrigin;
- (void)setShowingDeviceLock:(BOOL)arg1 duration:(float)arg2;
- (void)setShowingDeviceLock:(BOOL)arg1;
- (void)animateToShowingDeviceLock:(BOOL)arg1;
- (void)_animateToHidingOrShowingDeviceLockFinished;
- (void)_animateToShowingDeviceLockFinished;
- (void)_animateToHidingDeviceLockFinished;
- (void)deviceUnlockSucceeded;
- (void)deviceUnlockFailed;
- (void)deviceUnlockCanceled;
- (void)_enableEntry;
- (BOOL)shouldShowBlockedRedStatus;
- (void)showBlockedStatus;
- (void)removeBlockedStatus;
- (BOOL)isDisplayingErrorStatus;
- (void)_entryFinishedWithPassword:(id)arg1;
- (void)phonePad:(id)arg1 keyDown:(BOOL)arg2;
- (void)phonePad:(id)arg1 keyUp:(BOOL)arg2;
- (void)passcodeFieldDidAcceptEntry:(id)arg1;
- (void)_animateView:(id)arg1 direction:(int)arg2;
- (void)animateToEmergencyCall;
- (void)emergencyCallWasDisplayed;
- (void)animateFromEmergencyCallWithDuration:(float)arg1;
- (void)emergencyCallWasRemoved;
- (id)bottomBar;
- (id)topBar;

@end



@class NSDictionary, NSString, NSTimer, SBActivationView, SBAwayChargingView, SBAwayDateView, SBAwayInCallController, SBAwayItemsView, SBNowPlayingArtView, TPBottomButtonBar, TPBottomLockBar, UIAlertSheet, UIImage, UIPushButton;

@interface SBAwayView : SBSlidingAlertDisplay
{
    @public
    BOOL _isDimmed;
    BOOL _deferAwayItemFetching;
    BOOL _showingBlockedIndicator;
    SBAwayChargingView *_chargingView;
    SBAwayDateView *_dateView;
    SBNowPlayingArtView *_albumArtView;
    SBAwayItemsView *_awayItemsView;
    SBActivationView *_activationView;
    NSTimer *_mediaControlsTimer;
    UIImage *_controlsLCDBG;
    UIImage *_priorLCDBG;
    NSDictionary *_nowPlayingInfo;
    UIImage *_nowPlayingArt;
    NSString *_lastTrackArtPath;
    NSTimer *_blockedStatusUpdateTimer;
    UIAlertSheet *_alertSheet;
    SBAwayInCallController *_inCallController;
    TPBottomLockBar *_lockBar;
    TPBottomButtonBar *_cancelSyncBar;
    UIPushButton *_infoButton;
}

+ (id)createBottomBarForInstance:(id)arg1;
+ (id)lockLabel:(BOOL)arg1 fontSize:(float *)arg2;
- (void)_clearBlockedStatusUpdateTimer;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)postLockCompletedNotification:(BOOL)arg1;
- (void)dealloc;
- (void)_postLockCompletedNotification;
- (void)finishedAnimatingIn;
- (void)dismiss;
- (void)setBottomLockBar:(id)arg1;
- (BOOL)shouldAnimateIn;
- (void)startAnimations;
- (void)stopAnimations;
- (void)showInfoButton;
- (void)hideInfoButton;
- (void)updateInterface;
- (void)setMiddleContentAlpha:(float)arg1;
- (void)setDimmed:(BOOL)arg1;
- (void)setDrawsBlackBackground:(BOOL)arg1;
- (void)lockBarUnlocked:(id)arg1;
- (void)lockBarStartedTracking:(id)arg1;
- (void)lockBarStoppedTracking:(id)arg1;
- (void)updateLockBarLabel;
- (BOOL)shouldShowBlockedRedStatus;
- (void)_updateBlockedStatusLabel;
- (void)showBlockedStatus;
- (void)removeBlockedStatus;
- (void)_updateBlockedStatus;
- (id)dateView;
- (void)removeDateView;
- (void)addDateView;
- (id)inCallController;
- (BOOL)shouldShowInCallInfo;
- (void)updateInCallInfo;
- (void)_positionAwayItemsView;
- (void)hideAwayItems;
- (void)showAwayItems;
- (BOOL)hasAwayItems;
- (void)setShowingDeviceLock:(BOOL)arg1 duration:(float)arg2;
- (void)showAlertSheet:(id)arg1;
- (void)removeAlertSheet;
- (void)slideAlertSheetOut:(BOOL)arg1 direction:(BOOL)arg2 duration:(float)arg3;
- (void)_batteryStatusChanged:(id)arg1;
- (id)chargingView;
- (void)addChargingView;
- (void)hideChargingView;
- (void)clearMediaControlsTimer;
- (void)restartMediaControlsTimer;
- (void)hideMediaControls;
- (void)showMediaControls;
- (void)toggleMediaControls;
- (BOOL)isShowingMediaControls;
- (void)showSyncingBottomBar:(BOOL)arg1;
- (void)hideSyncingBottomBar:(BOOL)arg1;
- (void)hideNowPlaying;
- (id)nowPlayingArtView;
- (void)musicPlayerDied:(id)arg1;
- (void)updateNowPlayingInfo:(id)arg1;
- (BOOL)updateNowPlayingArt;
- (void)handleRequestedAlbumArtBytes:(char *)arg1 length:(unsigned int)arg2;
- (void)animateToShowingDeviceLock:(BOOL)arg1;

@end



@class SBApplication, SBApplicationIconBadge, SBApplicationIconLabel, UIImage, UIImageView;

@interface SBApplicationIcon : UIControl
{
    UIImage *_icon;
    SBApplication *_app;
    UIImageView *_image;
    UIImageView *_reflection;
    SBApplicationIconBadge *_badge;
    SBApplicationIconLabel *_label;
    BOOL _drawsLabel;
    BOOL _isHidden;
    BOOL _isRevealable;
    BOOL _inDock;
}

+ (struct CGSize)defaultIconSize;
- (id)initWithApplication:(id)arg1;
- (void)dealloc;
- (id)application;
- (BOOL)ignoresMouseEvents;
- (void)showIconAnimationDidStop:(id)arg1 didFinish:(id)arg2 icon:(id)arg3;
- (void)setIsHidden:(BOOL)arg1 animate:(BOOL)arg2;
- (BOOL)isHidden;
- (void)setIsRevealable:(BOOL)arg1;
- (BOOL)isRevealable;
- (id)subviews;
- (void)setDisplayedIcon:(id)arg1;
- (id)icon;
- (id)hilightedIcon;
- (id)reflectedIcon:(BOOL)arg1;
- (void)layout;
- (void)updateLabelOrigin;
- (void)setDrawsLabel:(BOOL)arg1;
- (void)setBadge:(id)arg1;
- (id)displayName;
- (id)_automationID;
- (BOOL)shouldTrack;
- (BOOL)pointMostlyInside:(struct CGPoint)arg1 forEvent:(struct __GSEvent *)arg2;
- (void)setHighlighted:(BOOL)arg1;
- (void)setInDock:(BOOL)arg1;
- (void)setOrigin:(struct CGPoint)arg1;

@end

@interface SBIconList : UIView
{
    @public
    NSMutableArray *_iconMatrix;
    unsigned int _scattered:1;
    unsigned int _needsLayout:1;
}

+ (id)sharedInstance;
- (id)initWithDefaultSize;
- (void)dealloc;
- (id)iconAtX:(int)arg1 Y:(int)arg2;
- (BOOL)firstFreeSlotX:(int *)arg1 Y:(int *)arg2;
- (BOOL)isEmpty;
- (void)showIconAnimationDidStop:(id)arg1 didFinish:(id)arg2 icon:(id)arg3;
- (void)insertIcon:(id)arg1 atX:(int)arg2 Y:(int)arg3 animate:(BOOL)arg4;
- (BOOL)getX:(int *)arg1 Y:(int *)arg2 forIcon:(id)arg3;
- (BOOL)containsIcon:(id)arg1;
- (void)removeIconAtX:(int)arg1 Y:(int)arg2 animate:(BOOL)arg3;
- (void)removeIcon:(id)arg1 animate:(BOOL)arg2;
- (void)removeAllIcons;
- (BOOL)isScattered;
- (void)scatter:(BOOL)arg1;
- (void)unscatter:(BOOL)arg1 startTime:(double)arg2;
- (void)stopAnimations;
- (void)clickedIcon:(id)arg1;
- (float)verticalIconPadding;
- (float)topIconPadding;
- (void)setIconsNeedLayout;
- (int)iconsInRow:(id)arg1;
- (void)layoutIconsIfNeeded;
- (struct CGPoint)originForIconAtX:(int)arg1 Y:(int)arg2;
- (struct CGPoint)originForIcon:(id)arg1;

@end

@class NSMutableArray, SBIconModel, TPLCDTextView, UIPageIndicator, UIScroller, UIView;

@interface SBIconController : NSObject
{
    @public
    NSMutableArray *_iconLists;
    SBIconModel *_iconModel;
    UIView *_contentView;
    UIScroller *_scroller;
    UIPageIndicator *_pageIndicator;
    int _currentIconListIndex;
    TPLCDTextView *_idleText;
}

+ (id)sharedInstance;
- (id)init;
- (void)dealloc;
- (id)contentView;
- (void)updateCurrentIconListIndex;
- (id)currentIconList;
- (id)iconListContainingIcon:(id)arg1;
- (void)scrollToIconListAtIndex:(int)arg1 animate:(BOOL)arg2;
- (void)updateContentSizeAndPageCount;
- (id)addEmptyIconList;
- (void)removeEmptyIconList:(id)arg1 animate:(BOOL)arg2;
- (void)relayoutIcons;
- (void)addIconToFirstAvailableList:(id)arg1 animate:(BOOL)arg2 scrollToList:(BOOL)arg3;
- (void)removeIcon:(id)arg1 animate:(BOOL)arg2;
- (id)iconLists;
- (void)lcdTextViewCompletedScroll:(id)arg1;
- (float)idleModeTextHeight;
- (void)idleTextDidAnimate:(id)arg1 finished:(id)arg2 toText:(id)arg3;
- (void)updateNumberOfRowsWithDuration:(float)arg1;
- (BOOL)hasIdleModeText;
- (void)setIdleModeText:(id)arg1;
- (void)scatter:(BOOL)arg1;
- (void)unscatter:(BOOL)arg1 startTime:(double)arg2;
- (void)scrollerDidEndDragging:(id)arg1 willSmoothScroll:(BOOL)arg2;
- (void)scrollerDidEndSmoothScrolling:(id)arg1;
- (void)scrollerDidEndAnimatedScrolling:(id)arg1;
- (void)showAccessory:(id)arg1;
- (void)removeAccessory:(id)arg1;
- (int)maxIconRows;
- (int)maxIconColumns;

@end
