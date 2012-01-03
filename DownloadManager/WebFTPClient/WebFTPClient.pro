#-------------------------------------------------
#
# Project created by QtCreator 2012-01-02T11:25:30
#
#-------------------------------------------------

QT       += core gui network webkit

TARGET = WebFTPClient
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    networkaccessmanager.cpp \
    FtpView.cpp \
    ftpreply.cpp \
    downloader.cpp

HEADERS += \
    NetworkAccessManager.h \
    ftpview.h \
    ftpreply.h \
    downloader.h
