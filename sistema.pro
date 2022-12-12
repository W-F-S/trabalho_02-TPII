QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adicionar_agenda.cpp \
    agenda.cpp \
    atendente.cpp \
    atendente_cadastrar_medico.cpp \
    atendente_cadastrar_usuario.cpp \
    atendente_tela.cpp \
    get_agenda.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    medico.cpp \
    pasciente.cpp \
    sistema.cpp

HEADERS += \
    adicionar_agenda.h \
    agenda.h \
    atendente.h \
    atendente_cadastrar_medico.h \
    atendente_cadastrar_usuario.h \
    atendente_tela.h \
    get_agenda.h \
    login.h \
    mainwindow.h \
    medico.h \
    pasciente.h \
    sistema.h

FORMS += \
    adicionar_agenda.ui \
    atendente_cadastrar_medico.ui \
    atendente_cadastrar_usuario.ui \
    atendente_tela.ui \
    get_agenda.ui \
    login.ui \
    login1.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
