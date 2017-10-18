#-------------------------------------------------
#
# Project created by QtCreator 2017-10-15T18:18:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CG
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dda.cpp \
    dda_paint.cpp \
    bresenham.cpp \
    bre_paint.cpp \
    circle.cpp \
    cir_paint.cpp \
    ellipse.cpp \
    ell_paint.cpp

HEADERS  += mainwindow.h \
    dda.h \
    dda_paint.h \
    bresenham.h \
    bre_paint.h \
    circle.h \
    cir_paint.h \
    ellipse.h \
    ell_paint.h

FORMS    += mainwindow.ui \
    dda.ui \
    dda_paint.ui \
    bresenham.ui \
    bre_paint.ui \
    circle.ui \
    cir_paint.ui \
    ellipse.ui \
    ell_paint.ui
