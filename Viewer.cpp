#include "Viewer.h"
#include "Scene.h"
#include "Karte.h"
#include <QResizeEvent>
#include <QMouseEvent>

using namespace std;

Viewer::Viewer(QWidget *parent) : QGraphicsView(parent)
{
    setMouseTracking(true);
}


Viewer::~Viewer()
{
}


void Viewer::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);

    if (scene() != 0) ((Scene*) scene())->groessenanpassung(event);
}


void Viewer::mouseMoveEvent(QMouseEvent* event)
{
    QGraphicsView::mouseMoveEvent(event);

    // wenn noch eine aktive karte besteht, obwohl die linke maustaste nicht mehr gehalten wird ...
    if (((Scene*) scene())->aktiveKarte() != 0 && event->buttons() != Qt::LeftButton)
    {
        // die aktive karte zu ihrer ausgangsposition schicken,
        ((Scene*) scene())->aktiveKarte()->nach_hause();

        // ... dadurch gilt die karte nicht mehr als aktive.
        ((Scene*) scene())->setze_aktive_karte(0);
    }
}
