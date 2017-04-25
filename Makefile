#############################################################################
# Makefile for building: text_detection
# Generated by qmake (2.01a) (Qt 4.8.7) on: �t dub 25 20:09:27 2017
# Project:  text_detection.pro
# Template: app
# Command: /home/darthvader/Enthought/Canopy_64bit/User/bin/qmake -o Makefile text_detection.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/linux-g++-64 -I. -I../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/include/QtCore -I../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/include/QtGui -I../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/include -I/usr/local/include/opencv -I/usr/local/include/tesseract -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -Wl,-rpath,/home/vagrant/pisi/tmp/Qt-4.8.7-4/usr/lib
LIBS          = $(SUBLIBS)  -L/home/darthvader/Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/lib -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -ltesseract -llept -lQtGui -L/home/vagrant/src/buildsystem-git/build/master-env -L/home/vagrant/src/buildsystem-git/build/master-env/lib -L/home/vagrant/pisi/tmp/Qt-4.8.7-4/usr/lib -L/usr/X11R6/lib64 -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/darthvader/Enthought/Canopy_64bit/User/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		fusion.cpp \
		gradient.cpp \
		interactiveimage.cpp \
		ocr.cpp \
		closeerdgeelements.cpp moc_mainwindow.cpp \
		moc_interactiveimage.cpp
OBJECTS       = main.o \
		mainwindow.o \
		fusion.o \
		gradient.o \
		interactiveimage.o \
		ocr.o \
		closeerdgeelements.o \
		moc_mainwindow.o \
		moc_interactiveimage.o
DIST          = ../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/unix.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/linux.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/gcc-base.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/gcc-base-unix.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/g++-base.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/g++-unix.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/qconfig.pri \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/modules/qt_webkit_version.pri \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/qt_functions.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/qt_config.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/exclusive_builds.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/default_pre.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/release.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/default_post.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/shared.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/warn_on.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/qt.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/unix/thread.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/moc.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/resources.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/uic.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/yacc.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/lex.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/include_source_dir.prf \
		text_detection.pro
QMAKE_TARGET  = text_detection
DESTDIR       = 
TARGET        = text_detection

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: text_detection.pro  ../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/linux-g++-64/qmake.conf ../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/unix.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/linux.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/gcc-base.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/gcc-base-unix.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/g++-base.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/g++-unix.conf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/qconfig.pri \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/modules/qt_webkit_version.pri \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/qt_functions.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/qt_config.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/exclusive_builds.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/default_pre.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/release.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/default_post.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/shared.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/warn_on.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/qt.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/unix/thread.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/moc.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/resources.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/uic.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/yacc.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/lex.prf \
		../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/include_source_dir.prf \
		/home/darthvader/Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/lib/libQtGui.prl \
		/home/darthvader/Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/lib/libQtCore.prl
	$(QMAKE) -o Makefile text_detection.pro
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/unix.conf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/linux.conf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/gcc-base.conf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/gcc-base-unix.conf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/g++-base.conf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/common/g++-unix.conf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/qconfig.pri:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/modules/qt_webkit_version.pri:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/qt_functions.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/qt_config.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/exclusive_builds.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/default_pre.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/release.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/default_post.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/shared.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/unix/gdb_dwarf_index.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/warn_on.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/qt.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/unix/thread.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/moc.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/resources.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/uic.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/yacc.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/lex.prf:
../../../Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/mkspecs/features/include_source_dir.prf:
/home/darthvader/Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/lib/libQtGui.prl:
/home/darthvader/Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile text_detection.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/text_detection1.0.0 || $(MKDIR) .tmp/text_detection1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/text_detection1.0.0/ && $(COPY_FILE) --parents mainwindow.h closeerdgeelements.h fusion.h gradient.h interactiveimage.h ocr.h .tmp/text_detection1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp fusion.cpp gradient.cpp interactiveimage.cpp ocr.cpp closeerdgeelements.cpp .tmp/text_detection1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/text_detection1.0.0/ && (cd `dirname .tmp/text_detection1.0.0` && $(TAR) text_detection1.0.0.tar text_detection1.0.0 && $(COMPRESS) text_detection1.0.0.tar) && $(MOVE) `dirname .tmp/text_detection1.0.0`/text_detection1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/text_detection1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_interactiveimage.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_interactiveimage.cpp
moc_mainwindow.cpp: gradient.h \
		closeerdgeelements.h \
		fusion.h \
		ocr.h \
		mainwindow.h
	/home/darthvader/Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_interactiveimage.cpp: interactiveimage.h
	/home/darthvader/Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/bin/moc $(DEFINES) $(INCPATH) interactiveimage.h -o moc_interactiveimage.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui \
		interactiveimage.h
	/home/darthvader/Canopy/appdata/canopy-1.7.4.3348.rh5-x86_64/bin/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		gradient.h \
		closeerdgeelements.h \
		fusion.h \
		ocr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		gradient.h \
		closeerdgeelements.h \
		fusion.h \
		ocr.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

fusion.o: fusion.cpp fusion.h \
		gradient.h \
		closeerdgeelements.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fusion.o fusion.cpp

gradient.o: gradient.cpp gradient.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gradient.o gradient.cpp

interactiveimage.o: interactiveimage.cpp interactiveimage.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o interactiveimage.o interactiveimage.cpp

ocr.o: ocr.cpp ocr.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ocr.o ocr.cpp

closeerdgeelements.o: closeerdgeelements.cpp closeerdgeelements.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o closeerdgeelements.o closeerdgeelements.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_interactiveimage.o: moc_interactiveimage.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_interactiveimage.o moc_interactiveimage.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

