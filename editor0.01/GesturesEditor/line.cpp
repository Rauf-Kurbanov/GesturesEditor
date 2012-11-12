#include "line.h"

Line::Line()
{

}

Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->drawLine(10,10,20,20);
}
