/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef SPEICHERN_FRAGE_H
#define SPEICHERN_FRAGE_H

#include <QDialog>
#include "ui_Speichern_frage.h"

class Speichern_frage : public QDialog, private Ui::Speichern_frage
{
    Q_OBJECT

public:
    Speichern_frage(QWidget *parent = 0);
    virtual ~Speichern_frage();

    bool soll_merken() const;
    bool soll_speichern() const;

public slots:
    void setze_merken(bool);
    void setze_speichern(bool);
    void verbindung_merken(bool);

private slots:
    void speichern();
    void nicht_speichern();
    void abbruch();
    void releay_verbindung_merk_status(bool);

signals:
    void verbindung_merk_status(bool);
    void wird_gespeichert(bool);
    void wird_nicht_gespeichert(bool);

private:
    bool speichern_wert;
};

#endif
