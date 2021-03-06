#-------------------------------------------------
#
# Project created by QtCreator 2013-02-05T12:28:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Capturer
TEMPLATE = app


SOURCES += main.cpp\
        imageviewerwindow.cpp \
    image_thread.cpp

HEADERS  += imageviewerwindow.h \
    image_thread.h

FORMS    += imageviewerwindow.ui

LIBS	+= -lprotobuf

include(QtOpenCV.pri)

add_opencv_modules(core video imgproc)

PROTOS = protocol.proto
include(protobuf.pri)

OTHER_FILES += \
    protocol.proto \
