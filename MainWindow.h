/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define VERSION "1.03"

#include <QMainWindow>
#include "ui_MainWindow.h"

class Scene;
class QSettings;
class QMessageBox;
class QLabel;
class Highscore;
class Speichern_frage;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

private slots:
    void neues_spiel();
    void about();
    void restliche_einstellungen_laden();
    void einstellungen_speichern();
    void gewonnen(int, long);
    void aktualisiere_punktelabel(int);
    void aktualisiere_spielzeit(long);
    void eine_ziehen();
    void drei_ziehen();

private:
    Scene *scene;
    QSettings *einstellungen;
    QMessageBox *siegmeldung, *sicherheitsfrage;
    QLabel *punktelabel, *zeitlabel;
    Highscore *highscore;
    Speichern_frage *speichern_frage;

    virtual void closeEvent(QCloseEvent*);
};

#endif
