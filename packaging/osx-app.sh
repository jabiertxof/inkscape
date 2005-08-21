#! /bin/bash
# Copyright 2005, Kees Cook <kees@outflux.net>
# Licensed under GNU General Public License
#
# Usage: osx-app [-s] /path/to/bin/inkscape Info.plist /path/to/packaging/macosx
#
# This attempts to build an Inkscape.app package for OSX, resolving
# Dynamic libraries, etc.  Strips the executable and libraries if
# '-s' is given.
#
# Thanks to GNUnet's "build_app" script for help with library dep resolution.
# https://gnunet.org/svn/GNUnet/contrib/OSX/build_app
# 
# Fixes and modifications to use Gimp.app style launcher:
# Michael Wybrow <mjwybrow@users.sourceforge.net>
#
#
# Notes:
# The Info.plist file can be found in the base inkscape directory once
# configure has been run.
# The macosx directory is in the inkscape/packaging directory.
#
# Thus, the usual use of this file would be to run it from the within the
# inkscape/packaging directory, substituting in the inkscape binary path:
# 	./osx-app.sh /path/to/bin/inkscape ../Info.plist macosx

SW=/sw

# Package always has the same name.  Version information is stored in
# the Info.plist file which is filled in by the configure script.
pkg=Inkscape
package="$pkg.app"

# TODO: Rewrite handling of command line args and make more robust.

strip=false
if [ "$1" = "-s" ]; then
	strip=true
	shift
fi

binary="$1"
if [ ! -x "$binary" ]; then
        echo "Not executable: $binary" >&2
        exit 1
fi
shift

plist="$1"
if [ ! -f "$plist" ]; then
	echo "Need plist file" >&2
	exit 1
fi
shift

resdir=$1
if [ ! -d $resdir ]; then
	echo "Need the macosx packaging directory" >&2
	exit 1
fi
shift

# Fix a given executable or library to be relocatable
fixlib () {
if [ ! -d "$1" ]; then
  echo $1
  libs="`otool -L $1 | fgrep compatibility | cut -d\( -f1`"
  for lib in $libs; do
    echo "  $lib"
    base=`echo $lib | awk -F/ '{print $NF}'`
    first=`echo $lib | cut -d/ -f1-3`
    to=@executable_path/../lib/$base
    if [ $first != /usr/lib -a $first != /usr/X11R6 ]; then
      /usr/bin/install_name_tool -change $lib $to $1
      if [ "`echo $lib | fgrep libcrypto`" = "" ]; then
        /usr/bin/install_name_tool -id $to ../lib/$base
        for ll in $libs; do
          base=`echo $ll | awk -F/ '{print $NF}'`
          first=`echo $ll | cut -d/ -f1-3`
          to=@executable_path/../lib/$base
          if [ $first != /usr/lib -a $first != /usr/X11R6 -a "`echo $ll | fgrep libcrypto`" = "" ]; then
            /usr/bin/install_name_tool -change $ll $to ../lib/$base
          fi
        done
      fi
    fi
  done
fi
}



mkdir -p "$package"/Contents/MacOS
mkdir -p "$package"/Contents/Resources/bin
mkdir -p "$package"/Contents/Resources/lib

binname=`basename "$binary"`
binpath="$package/Contents/Resources/bin/inkscape-bin"

cp "$binary" "$binpath"


# Build and add the launcher.
(
  # Build fails if CC happens to be set (to anything other than CompileC)
  unset CC
  
  cd "$resdir/ScriptExec"
  xcodebuild -buildstyle Deployment clean build
)
cp "$resdir/ScriptExec/build/ScriptExec.app/Contents/MacOS/ScriptExec" "$package/Contents/MacOS/Inkscape"

# Pull down all the share files
binary_dir=`dirname "$binary"`
rsync -av "$binary_dir/../share/$binname"/* "$package/Contents/Resources/"
cp "$plist" "$package/Contents/Info.plist"

# PkgInfo must match bundle type and creator code from Info.plist
echo "APPLInks" > $package/Contents/PkgInfo

# Pull in extra requirements.
pkgetc="$package/Contents/Resources/etc"
mkdir -p $pkgetc/pango
cp $SW/etc/pango/pangox.aliases $pkgetc/pango/
# Need to adjust path and quote incase of spaces in path.
sed -e "s,$SW,\"\${CWD},g" -e 's,\.so ,.so" ,g' $SW/etc/pango/pango.modules > $pkgetc/pango/pango.modules
cat > $pkgetc/pango/pangorc <<END_PANGO
[Pango]
ModuleFiles = "\${HOME}/.inkscape-etc/pango.modules"
[PangoX]
AliasFiles = "\${HOME}/.inkscape-etc/pangox.aliases"
END_PANGO

mkdir -p $pkgetc/fonts/
cp /etc/fonts/* $pkgetc/fonts/

mkdir -p $pkgetc/gtk-2.0
sed -e "s,$SW,\${CWD},g" $SW/etc/gtk-2.0/gdk-pixbuf.loaders > $pkgetc/gtk-2.0/gdk-pixbuf.loaders
sed -e "s,$SW,\${CWD},g" $SW/etc/gtk-2.0/gtk.immodules > $pkgetc/gtk-2.0/gtk.immodules

pkglib="$package/Contents/Resources/lib"
mkdir -p $pkglib/pango/1.4.0/modules
cp $SW/lib/pango/1.4.0/modules/*.so $pkglib/pango/1.4.0/modules/

mkdir -p $pkglib/gtk-2.0/2.4.0/{engines,immodules,loaders}
cp -r $SW/lib/gtk-2.0/2.4.0/engines/* $pkglib/gtk-2.0/2.4.0/engines/
cp $SW/lib/gtk-2.0/2.4.0/immodules/*.so $pkglib/gtk-2.0/2.4.0/immodules/
cp $SW/lib/gtk-2.0/2.4.0/loaders/*.so $pkglib/gtk-2.0/2.4.0/loaders/

# Find out libs we need from fink (e.g. $SW) - loop until no changes
a=1
nfiles=0
endl=true
while $endl; do
  echo "Looking for dependencies. Round " $a
  libs="`otool -L $pkglib/gtk-2.0/2.4.0/loaders/* $pkglib/gtk-2.0/2.4.0/immodules/* $pkglib/gtk-2.0/2.4.0/engines/*.so $pkglib/pango/1.4.0/modules/* $package/Contents/Resources/lib/* $binary 2>/dev/null | fgrep compatibility | cut -d\( -f1 | grep $SW | sort | uniq`"
  cp -f $libs $package/Contents/Resources/lib
  let "a+=1"  
  nnfiles=`ls $package/Contents/Resources/lib | wc -l`
  if [ $nnfiles = $nfiles ]; then
    endl=false
  else
    nfiles=$nnfiles
  fi
done

if [ "$strip" = "true" ]; then
  strip -x "$package"/Contents/Resources/lib/*.dylib
  strip -ur "$binpath"
fi

# NOTE: This works for all the dylibs but causes GTK to crash at startup.
#       Instead we leave them with their original install_names and set
#       DYLD_LIBRARY_PATH within the app bundle before running Inkscape.
#
# Fix package deps
#(cd "$package/Contents/MacOS/bin"
# for file in *; do
#    fixlib "$file"
# done
# cd ../lib
# for file in *; do
#    fixlib "$file"
# done)

# Get all the icons and the rest of the script framework
rsync -av $resdir/Resources/* $package/Contents/Resources/


# Make an image
/usr/bin/hdiutil create -srcfolder "$pkg.app" "$pkg.dmg"
