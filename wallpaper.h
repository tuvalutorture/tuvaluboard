@class WPPhotoPicker, WallpaperWindow;

@interface WallpaperAlbumController : NSObject // lie but works
{
    @public
    WallpaperWindow *_window;
    UIView *_photoPicker; // another lie but is acceptable
}

- (void)photoSelected:(id)arg1;
- (void)dismissDidSetWallpaper:(BOOL)arg1;
- (void)dismiss;
- (void)photoPicker:(id)arg1 didCropPhotoToRect:(struct CGRect)arg2 fullSizeImageData:(id)arg3 fullScreenImageData:(id)arg4 croppedImageData:(id)arg5;
- (void)_backgroundSavePhoto:(id)arg1;
- (void)_saveCompleted:(struct CGImage *)arg1;
- (void)photoPickerDidCancel:(id)arg1;
- (void)didFinishUpTransition;
- (void)didFinishDownTransition;
- (void)imageViewWillSwitchToFullSizeImage:(id)arg1;
- (void)imageViewDidSwitchToFullSizeImage:(id)arg1;
- (void)dealloc;

@end

