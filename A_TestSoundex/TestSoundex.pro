GOOGLETEST_DIR = C:\Qt\googletest\googletest-master
include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
  tst_soundex.h

SOURCES += \
  testSoundexMain.cpp