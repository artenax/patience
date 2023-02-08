/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef ZUG_H
#define ZUG_H

#include <QString>
#include <QList>

class Karte;
class Basisstapel;

class Zug
{
public:
    Zug();
    Zug(Karte* karte, Basisstapel *herkunft, Basisstapel *ziel);
    Zug(Karte* karte, Basisstapel *ort);
    virtual ~Zug();

    bool ist_gueltig() const;
    bool ist_bewegung() const;
    bool ist_aufdeckgung() const;

    void setze_bewegung(Karte* karte, Basisstapel *herkunft_, Basisstapel *ziel_);
    void setze_aufdeckung(Karte* karte, Basisstapel *ort);

    Karte* karte() const;
    Basisstapel* herkunft() const;
    Basisstapel* ziel() const;

    QString karte_name() const;
    QString herkunft_name() const;
    QString ziel_name() const;

    bool operator==(const Zug& anderer) const;
    const QList<Zug>& abhaengige_zuege() const;
    void fuege_abhaengigen_zug_an(const Zug&);
    bool hat_abhaengige_zuege() const;

private:
    Karte *Karte_;
    Basisstapel *Herkunft, *Ziel;

    QList<Zug> Abhaengige_zuege;
};

#endif
