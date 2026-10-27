# this makefile was made ENTIRELY by Nightwind, I only modified it. (with clanker assistance because makefiles are 🤮)

PREFIX := /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
CC := $(PREFIX)/clang
LD := $(HOME)/ld/linker/ld64-objc1
SDK := $(THEOS)/sdks/iPhoneOS1.1.5.sdk

SRC := Tweak.m $(wildcard Firmware/*.m)
OUT := TuvaluBoard.dylib
WALLPAPER_SRC := wallpaper.m
WALLPAPER_OUT := TuvaluWallpaper.dylib

PXL_WORKINGDIR := _temp
PXL_INSTROOT := $(PXL_WORKINGDIR)/instroot
PXL_DYLIB_DIR := $(PXL_INSTROOT)/Library/MicroInjector/DynamicLibraries

STRICT_FLAGS := -Wall -Werror -Wpedantic -Wextra -Wshadow -Wformat=2 -Wnull-dereference -Wno-cast-function-type-mismatch -Wno-nullability-extension -Wno-dollar-in-identifier-extension -Wno-variadic-macros

CFLAGS := -arch armv6 -isysroot $(SDK) $(STRICT_FLAGS) -mthumb -miphoneos-version-min=1.0 -D_FORTIFY_SOURCE=0 -mfpu=none -I$(THEOS)/vendor/lib/CydiaSubstrate.framework/Headers --ld-path=$(LD)
LDFLAGS := -Wl,-install_name,/Library/MicroInjector/DynamicLibraries/$(OUT) -dynamiclib ../MicroInjector/libmicroinjector.dylib -fobjc-runtime=macosx-fragile -lobjc -framework Foundation -framework CoreFoundation -framework UIKit
WALLPAPER_LDFLAGS := $(LDFLAGS)

.PHONY: all clean pxl

all: $(OUT) $(WALLPAPER_OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $@
	strip -x $@

$(WALLPAPER_OUT): $(WALLPAPER_SRC)
	$(CC) $(WALLPAPER_SRC) $(CFLAGS) $(WALLPAPER_LDFLAGS) -o $@
	strip -x $@

$(PXL_DYLIB_DIR):
	mkdir -p $(PXL_DYLIB_DIR)

pxl: all $(PXL_DYLIB_DIR)
	cp $(OUT) $(PXL_DYLIB_DIR)/$(OUT)
	cp TuvaluBoard.plist $(PXL_DYLIB_DIR)/TuvaluBoard.plist
	cp $(WALLPAPER_OUT) $(PXL_DYLIB_DIR)/$(WALLPAPER_OUT)
	cp TuvaluWallpaper.plist $(PXL_DYLIB_DIR)/TuvaluWallpaper.plist
	cp PxlPkg.plist $(PXL_WORKINGDIR)/PxlPkg.plist
	cd $(PXL_WORKINGDIR) && zip -r ../TuvaluBoard.pxl .
	rm -rf $(PXL_WORKINGDIR)

clean:
	rm -f $(OUT) $(WALLPAPER_OUT) TuvaluBoard.pxl
	rm -rf $(PXL_WORKINGDIR)