/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef UNDO_H
#define UNDO_H

#include <QObject>
#include <QMap>
#include <QList>
#include "Zug.h"

class Karte;
class Basisstapel;
class Scene;

class Undo : public QObject
{
    Q_OBJECT

public:
    Undo(Scene *parent);
    virtual ~Undo();

    const QStringList speichere() const;
    bool lade(const QStringList&);

public slots:
    void speichere_zug(const Zug&);
    void undo();
    void clear();

signals:
    void undo_meldung(const Zug&);
    void undo_verfuegbar(bool);

private:
    QList<Zug> verlauf;
    Scene *scene;

    void loesche_ueberschuessige_undoelemente();
};

#endif
