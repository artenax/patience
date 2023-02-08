######################################################################
# Automatically generated by qmake (3.0) Mo. Dez. 24 17:41:15 2012
######################################################################

TEMPLATE = app
TARGET = Patience
DEPENDPATH += .
INCLUDEPATH += .
QT += gui widgets

VERSION = 1.02.0

macx:ICON = icon.icns

win32:RC_FILE = Patience.rc

# Input
HEADERS += Ablagestapel.h \
           Austeilcostapel.h \
           Austeilstapel.h \
           Basisstapel.h \
           Highscore.h \
           Hilfszeiger.h \
           Karte.h \
           MainWindow.h \
           Proportionen.h \
           Punktezaehler.h \
           Rahmen.h \
           Random.h \
           Scene.h \
           Siegkontrolle.h \
           Speichern_frage.h \
           Undo.h \
           Viewer.h \
           Zielstapel.h \
           Zug.h
FORMS += Highscore.ui MainWindow.ui Speichern_frage.ui
SOURCES += Ablagestapel.cpp \
           Austeilcostapel.cpp \
           Austeilstapel.cpp \
           Basisstapel.cpp \
           Highscore.cpp \
           Hilfszeiger.cpp \
           Karte.cpp \
           main.cpp \
           MainWindow.cpp \
           Punktezaehler.cpp \
           Rahmen.cpp \
           Random.cpp \
           Scene.cpp \
           Siegkontrolle.cpp \
           Speichern_frage.cpp \
           Undo.cpp \
           Viewer.cpp \
           Zielstapel.cpp \
           Zug.cpp
RESOURCES += resourcen.qrc
TRANSLATIONS += Uebersetzung_de.ts