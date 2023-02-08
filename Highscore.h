/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QDialog>
#include <QString>
#include "ui_Highscore.h"

class QSettings;

class Highscore : public QDialog, private Ui::Highscore
{
    Q_OBJECT

public:
    Highscore(QWidget *parent);
    virtual ~Highscore();

    bool neues_ergebnis(int, long);
    void registriere_einstellungen(QSettings*);
    void einstellungen_laden();
    void einstellungen_speichern();

private:
    QSettings *einstellungen;
};

#endif
