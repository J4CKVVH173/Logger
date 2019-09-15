TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    libs/sqlite3.c \
    logger.cpp

HEADERS += \
    libs/sqlite3.h \
    logger.h
