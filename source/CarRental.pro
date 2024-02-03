QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    create_ride.cpp \
    data.cpp \
    edit_account.cpp \
    findride.cpp \
    main.cpp \
    log_in.cpp \
    mainpage.cpp \
    sign_up.cpp

HEADERS += \
    create_ride.h \
    data.h \
    edit_account.h \
    findride.h \
    log_in.h \
    mainpage.h \
    sign_up.h

FORMS += \
    create_ride.ui \
    edit_account.ui \
    findride.ui \
    log_in.ui \
    mainpage.ui \
    sign_up.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
