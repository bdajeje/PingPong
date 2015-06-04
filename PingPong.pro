TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    header.cpp \
    fonts.cpp \
    utils.cpp \
    ball.cpp \
    sounds.cpp \
    textures.cpp \
    jukebox.cpp \
    files.cpp

LIBS += -pthread
LIBS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS += -lboost_filesystem -lboost_regex -lboost_system

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    player.hpp \
    constants.hpp \
    header.hpp \
    fonts.hpp \
    utils.hpp \
    ball.hpp \
    sounds.hpp \
    textures.hpp \
    jukebox.hpp \
    files.hpp
