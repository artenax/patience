/*

 Name: Patience
 Autor: Andreas Konarski
 Lizenz: GPL v3 or later
 Plattformen: Alle Systeme, auf denen QT 4.6 verfuegbar ist. Kompatibel mit QT 5.0.0
 
 Kontakt: programmieren@konarski-wuppertal.de
 home: www.konarski-wuppertal.de
 
 Falls ich mit diesem Programm die Rechte von irgend jemand verletzen sollte, bitte ich um einen Hinweis. Wenn dies Tatsaechlich der Fall ist, entferne ich es schnellstmoeglich von meiner Homepage.
 
 */

#ifndef BASISSTAPEL_H
#define BASISSTAPEL_H

#include "Zug.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPixmap>
#include <QList>
#include <QPointF>
#include <QRectF>

class Karte;
class Siegkontrolle;
class Rahmen;
class Hilfszeiger;
class Scene;

class Basisstapel : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Basisstapel(const QPixmap& pixmap, Scene* oparent, QGraphicsItem* gparent = 0);
    virtual ~Basisstapel();

    void registriere_rahmen(Rahmen*);
    void zeige_rahmen();
    Scene* meineScene() const;

    virtual bool beruehrungstest(Karte*);
    virtual Karte* oberste_karte() const;
    virtual bool ist_oberste_karte(Karte*);
    virtual void lege_child_karten_ab(Karte*);
    virtual void erhoehe_zwert();
    virtual void normalisiere_zwert();
    virtual int karten() const;
    virtual void setze_kartenliste_zurueck();
    virtual QRectF gesamt_rect() const;
    virtual int ueberlappungs_flaeche(Karte*);
    virtual bool ablage_moeglich(Karte *) const;
    virtual bool lege_karte_ab(Karte*);
    virtual void undo_karten_ablage(Karte*);
    virtual void initialisiere_karte(Karte*);
    virtual void karte_wurde_aufgedeckt(Karte*);
    virtual void ablage_erfolgt();
    virtual void entferne_karte(Karte*);
    virtual void registriere_costapel(Basisstapel*);
    virtual void registriere_austeilstapel(Basisstapel*);
    virtual void registriere_siegkontrolle(Siegkontrolle*);
    virtual void registriere_nachbar_zielstapel(Basisstapel*, Basisstapel*, Basisstapel*);
    virtual const QStringList speichere() const;
    virtual bool lade(const QStringList&);
    virtual void karten_auffaechern();

public slots:
    virtual void hilfsanfrage_start(Karte*);
    virtual void hilfsanfrage_ende();
    virtual void alle_karten_einreihen();

    // in jeder abgeleiteten klasse, in der diese methode ueberschrieben wird und die position von karten geaendert wird bei den betroffenen karten zunaechst nach_hause() aufrufen! nach der positionsaenderung speichere_zuhause() aufrufen!
    virtual void passe_groesse_an(double);

signals:
    void zug(const Zug&);
    void stapel_durch();

protected:
    QList<Karte*> kartenliste;

    virtual QPointF ablageposition() const;
    virtual int zwert() const;

private:
    Scene *meine_scene;
    Rahmen *meinrahmen;
    Hilfszeiger *meinhilfszeiger;
    QPixmap bild, bild_skaliert;
    double stapelgroesse;
};

#endif
