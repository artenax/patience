#include "Austeilstapel.h"
#include "Karte.h"
#include "Proportionen.h"
#include "Zug.h"
#include "Scene.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

using namespace std;

Austeilstapel::Austeilstapel(const QPixmap& pixmap, Scene* oparent , QGraphicsItem* gparent) : Basisstapel(pixmap, oparent , gparent), costapel(0)
{
}


Austeilstapel::~Austeilstapel()
{
}


void Austeilstapel::registriere_costapel(Basisstapel* costapel_)
{
    costapel = costapel_;
}


void Austeilstapel::karte_wurde_aufgedeckt(Karte* karte)
{
    // hier nicht die basisimplementierung aufrufen !!!

    costapel->lege_karte_ab(karte);

    // wenn drei karten gezogen werden hier das zugsignal erzeugen
    Zug zug_;

    zug_.setze_bewegung(karte, this, costapel);

    // nur, wenn drei karten gezogen werden
    if (meineScene()->nur_eine_wird_gezogen() == false)
    {
        // zwei weitere karten ...
        for (register int idx = 0; idx < 2 && oberste_karte() != 0; idx++)
        {
            Karte *tmp_karte = oberste_karte();

            // ... auf costapel legen, ...
            costapel->lege_karte_ab(tmp_karte);

            // ... und dort aufdecken
            tmp_karte->zeige_vorderseite();

            zug_.fuege_abhaengigen_zug_an(Zug(tmp_karte, this, costapel));
        }

        // die neue oberste karte auf costapel beweglich machen
        if (costapel->oberste_karte() != 0) costapel->oberste_karte()->setFlag(QGraphicsItem::ItemIsMovable, true);
    }

    emit zug(zug_);

    normalisiere_zwert();
}


bool Austeilstapel::ablage_moeglich(Karte *karte) const
{
    bool erg = false;

    if (karte->eigentuemer_stapel()->objectName() == BASISSTAPEL_AUSTEILCOSTAPEL && karte->ist_rueckseite() == true) erg = true;

    return erg;
}


void Austeilstapel::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    QGraphicsPixmapItem::mousePressEvent(event);

    if (event->button() == Qt::LeftButton)
    {
        if (kartenliste.isEmpty() == true && costapel->karten() > 0)
        {
            Zug zug_;

            while (costapel->karten() > 0)
            {
                if (zug_.ist_gueltig() == false) zug_.setze_bewegung(costapel->oberste_karte(), costapel, this);
                else zug_.fuege_abhaengigen_zug_an(Zug(costapel->oberste_karte(), costapel, this));

                costapel->oberste_karte()->zeige_rueckseite();

                lege_karte_ab(costapel->oberste_karte());
            }

            emit zug(zug_);

            if (kartenliste.isEmpty() == false) emit stapel_durch();

            if (meineScene()->nur_eine_wird_gezogen() == false) costapel->alle_karten_einreihen();
        }

        // sicherstellen, das die scene aktualisiert wird. ist dies ein fehler in QT ???
        scene()->update();
    }
}


void Austeilstapel::hilfsanfrage_start(Karte*)
{
}


void Austeilstapel::undo_karten_ablage(Karte* karte)
{
    karte->zeige_rueckseite();

    Basisstapel::undo_karten_ablage(karte);
}
