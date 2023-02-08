#include "Austeilcostapel.h"
#include "Karte.h"
#include "Proportionen.h"
#include "Scene.h"

using namespace std;

Austeilcostapel::Austeilcostapel(const QPixmap& pixmap, Scene* oparent, QGraphicsItem* gparent) : Basisstapel(pixmap, oparent, gparent), austeilstapel(0)
{
}


Austeilcostapel::~Austeilcostapel()
{
}


void Austeilcostapel::registriere_austeilstapel(Basisstapel* stapel)
{
    austeilstapel = stapel;
}


bool Austeilcostapel::ablage_moeglich(Karte * karte) const
{
    bool erg = false;

    if (karte->eigentuemer_stapel()->objectName() == BASISSTAPEL_AUSTEILSTAPEL) erg = true;

    return erg;
}


bool Austeilcostapel::lege_karte_ab(Karte* karte)
{
    if (oberste_karte() != 0 && ablage_moeglich(karte) == true && meineScene()->nur_eine_wird_gezogen() == false) oberste_karte()->setFlag(QGraphicsItem::ItemIsMovable, false);

    bool erg = Basisstapel::lege_karte_ab(karte);

    // wenn drei karten gezogen werden die karten auffaechern
    if (meineScene()->nur_eine_wird_gezogen() == false) karten_auffaechern();

    return erg;
}


void Austeilcostapel::alle_karten_einreihen()
{
    // von allen karten im stapel die drift entfernen
    for (register int idx = 0; idx < kartenliste.size(); idx++)
    {
        kartenliste.at(idx)->setPos(0, 0);
        kartenliste.at(idx)->speichere_zuhause();
    }
}


void Austeilcostapel::entferne_karte(Karte* karte)
{
    Basisstapel::entferne_karte(karte);

    if (oberste_karte() != 0 && meineScene()->nur_eine_wird_gezogen() == false)
    {
        oberste_karte()->setFlag(QGraphicsItem::ItemIsMovable, true);
    }

    if (meineScene()->nur_eine_wird_gezogen() == false) karten_auffaechern();
}


void Austeilcostapel::hilfsanfrage_start(Karte*)
{
}


const QStringList Austeilcostapel::speichere() const
{
    QStringList erg(Basisstapel::speichere());

    return erg;
}


bool Austeilcostapel::lade(const QStringList& daten)
{
    bool erg = Basisstapel::lade(daten);

    karten_auffaechern();

    return erg;
}


void Austeilcostapel::passe_groesse_an(double wert)
{
    // wenn eine oberste karte vorhanden ist sicherstellen, das diese an ihre ausgangsposition zurueckkehrt
    if (oberste_karte() != 0) oberste_karte()->nach_hause();

    Basisstapel::passe_groesse_an(wert);

    for (register int idx1 = kartenliste.size() - 1, idx2 = 0; meineScene()->nur_eine_wird_gezogen() == false && idx1 > 0 && idx2 < 2; idx1--, idx2++)
    {
        kartenliste.at(idx1)->setPos(QPointF((double) boundingRect().width() / AUSTEILCOSTAPEL_XDRIFT_VERHAELTNIS, kartenliste.at(idx1)->pos().y()));

        // die neue ausgangsposition der karte speichern
        kartenliste.at(idx1)->speichere_zuhause();
    }
}


void Austeilcostapel::karten_auffaechern()
{
    // zunaechst alle karten einreihen
    alle_karten_einreihen();

    for (register int idx1 = kartenliste.size() - 1, idx2 = 0; meineScene()->nur_eine_wird_gezogen() == false && idx1 > 0 && idx2 < 2; idx1--, idx2++)
    {
        kartenliste.at(idx1)->setPos(QPointF((double) kartenliste.at(idx1)->boundingRect().width() / AUSTEILCOSTAPEL_XDRIFT_VERHAELTNIS, kartenliste.at(idx1)->pos().y()));

        kartenliste.at(idx1)->speichere_zuhause();
    }
}

void Austeilcostapel::initialisiere_karte(Karte* karte)
{
    if (oberste_karte() != 0 && meineScene()->nur_eine_wird_gezogen() == false) oberste_karte()->setFlag(QGraphicsItem::ItemIsMovable, false);

    Basisstapel::initialisiere_karte(karte);

    karten_auffaechern();
}


void Austeilcostapel::undo_karten_ablage(Karte* karte)
{
    if (meineScene()->nur_eine_wird_gezogen() == false && oberste_karte() != 0) oberste_karte()->setFlag(QGraphicsItem::ItemIsMovable, false);

    Basisstapel::undo_karten_ablage(karte);

    karte->zeige_vorderseite();

    if (meineScene()->nur_eine_wird_gezogen() == false) karten_auffaechern();

    if (oberste_karte() != 0) oberste_karte()->setFlag(QGraphicsItem::ItemIsMovable, true);
}


void Austeilcostapel::karte_wurde_aufgedeckt(Karte*)
{
    // hier nicht die basisimplementierung aufrufen !!!
}
