# TuvaluBoard
TuvaluBoard is a QOL (Quality-of-Life) tweak for iPhone OS 1, and aims to bring a richer experience when using iPhone OS 1, closer to that of iOS 4+.

This tweak, additionally, is meant to be a sort of stand-in for other tweaks, such as SummerBoard, as it is meant to be far lighter (though less capable) and more polished, providing a more "stock" experience akin to that of say, iOS 4, while still being iPhone OS 1.

Features of TuvaluBoard include:
- Home Screen wallpaper support (currently is the same as the lock screen, will separate)
- Showing ALL icons on the home screen (integrates the [FullIconList tweak](https://github.com/theiphoneos1project/fulliconlist-iphoneos1) by [Nightwind](https://github.com/nightwind) of the [iPhone OS 1 Project](https://github.com/theiphoneos1project/), though is unlikely to cause issues if both tweaks are installed)
- Makes certain system animations closer to iOS 6. (to do)
- Adds paging to the home screen (to do)
- Adds folders to the home screen (to do)
- Fix icon alignment when only one icon is present
- Allow the reordering of home screen icons (to do)

This tweak was tested principally on an iPod Touch (first generation) running iPhone OS 1.1, further testing is required.

### How to compile 
Make sure you have [Theos](https://github.com/theos/theos) installed and configured.

Make sure you are in an environment with `clang` and have the unofficial iPhone OS 1 SDK (directions for getting the SDK can be found [here](https://github.com/theiphoneos1project/iPhoneOS1-SDK)). Also, make sure you have the patched `ld` with the Objective-C fragile runtime support, which can be found [here](https://github.com/theiphoneos1project/ld64-build). Feel free to modify the [`Makefile`](./Makefile) as needed for your paths. Additionally, make sure you have Python 3 installed to package the `.PXL` file.

Make sure you compile MicroInjector and have the `libmicroinjector.dylib` library. The `Makefile` is configured in such a way that if MicroInjector was cloned in the parent directory of this repo and compiled correctly, it would automatically detect it. If you clone and compile MicroInjector in a different place, you may need to modify the `Makefile` accordingly.

An example directory structure could be:
```
~/
---> MicroInjector/
------> libmicroinjector.dylib
------> ...
---> ld/
------> lib/
---------> ...
------> linker/
---------> ld64-objc1
---> tuvaluboard/
------> (tweak code here)
```

Clone the repo and the run this to compile the binary:
```bash
make clean && make
```
To package the `.PXL` file, run:
```bash
make pxl
```

### How to install
Once compiled, use [PXLInstaller](https://github.com/theiphoneos1project/PXLInstaller) (tested) or iBrickr using Windows XP (untested). Make sure `MicroInjector` is already installed ([link](https://github.com/theiphoneos1project/MicroInjector/releases)).


#### Credits
This tweak was written almost entirely by myself, tuvalutorture, with minimal assistance from LLMs beyond conceptual things (and for the makefile :P). <br>
A HUGE shoutout goes to [Nightwind](https://github.com/Nightwind), a fellow tweak creator and someone who has been INSTRUMENTAL to this project, both in helping me get started, building the tooling around this, and additionally, being the foundation of this project (this repo is based on the [FullIconList](https://github.com/theiphoneos1project/fulliconlist-iphoneos1) tweak by him, includes code from it, as well as is under the same license). Additionally, it cannot be overstated how instrumental his work on [The iPhone OS 1 project](https://github.com/theiphoneos1project) has been as well, with almost all tooling used here taking advantage of the repos found within.

#### License
This project is licensed under [MIT](LICENSE).

###### Copyright (c) 2026 tuvalutorture, wit massive thanks to Nightwind.

###### P.S.
FUCK YOU, COPILOT; THOU HATH NO RIGHT TO CLAIM AUTHORSHIP OVER THINE COMMITS; FOR THOU ART NOT A CONTRIBUTOR TO MY WORK YOU LAZY FUCKING SWINE