TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG +=c++11
SOURCES += main.cpp
QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread
HEADERS += \
    heap.h \
    merge.h \
    quick.h \
    pancake.h

