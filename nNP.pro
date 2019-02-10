TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    opt/Instance.cpp \
    opt/Result.cpp \
    opt/imp/ResultTrash.cpp \
    opt/Searcher.cpp \
    opt/fun2d/InstanceF2D.cpp

HEADERS += \
    opt/Instance.hpp \
    opt/Opt.hpp \
    opt/Result.hpp \
    opt/Searcher.hpp \
    opt/imp/ResultTrash.hpp \
    opt/res.hpp \
    opt/fun2d/InstanceF2D.hpp

