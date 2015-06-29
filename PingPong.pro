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
    files.cpp \
    game.cpp \
    power_block.cpp \
    power_effects/power_effect.cpp \
    power_effects/minimize.cpp \
    power_effects/maximize.cpp \
    power_effects/double.cpp \
    power_effects/triple.cpp \
    power_effects/cloack.cpp

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
    files.hpp \
    game.hpp \
    power_block.hpp \
    power_effects/power_effect.hpp \
    power_effects/power_effects.hpp \
    power_effects/minimize.hpp \
    power_effects/maximize.hpp \
    power_effects/double.hpp \
    power_effects/triple.hpp \
    power_effects/cloack.hpp
