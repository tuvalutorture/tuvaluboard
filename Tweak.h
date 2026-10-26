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
