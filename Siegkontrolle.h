/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef SIEGKONTROLLE_H
#define SIEGKONTROLLE_H

#include <QObject>

class Basisstapel;
class Karte;

class Siegkontrolle : public QObject
{
    Q_OBJECT

public:
    Siegkontrolle(QObject *parent = 0);
    virtual ~Siegkontrolle();

    void teste_auf_sieg();
    void registriere_zielstapel(Basisstapel* kreutzstapel, Basisstapel* pikstapel, Basisstapel* herzstapel, Basisstapel *karostapel);

signals:
    void gewonnen();

private:
    QList<Basisstapel*> zielstapel;
};

#endif
