/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef PUNKTEZAEHLER_H
#define PUNKTEZAEHLER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "Zug.h"

class QTimer;
class Scene;

class Punktezaehler : public QObject
{
    Q_OBJECT

public:
    Punktezaehler(Scene *parent);
    virtual ~Punktezaehler();

    int punktstand() const;
    const QStringList speichere() const;
    bool lade(const QStringList&);
    bool begonnenes_spiel() const;

public slots:
    void neuer_zug(const Zug&);
    void stapel_durch();
    void neues_spiel();
    void spiel_zuende();
    void undo_meldung(const Zug&);

signals:
    void neue_punktzahl(int);
    void erster_zug();

private slots:
    void reaktion_auf_timeout();

private:
    int punkte;
    QTimer *straftimer;
    Scene *scene;
    QStringList nach_oben_liste;

    int kalkuliere_punkte(const Zug&) const;
    bool bringt_zeitaufschub(const Zug&) const;
};

#endif
