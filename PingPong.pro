TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    header.cpp \
    fonts.cpp \
    utils.cpp \
    ball.cpp

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lboost_filesystem -lboost_regex -lboost_system

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    player.hpp \
    constants.hpp \
    header.hpp \
    fonts.hpp \
    utils.hpp \
    ball.hpp \
    drawable.hpp
