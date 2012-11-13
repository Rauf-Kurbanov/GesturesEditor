#include "painter.h"

Painter::Painter(QGraphicsView *view)
{
	this->begin(view);
	this->setRenderHint(QPainter::Antialiasing, true);
	this->setPen(QPen(Qt::black, 14, Qt::SolidLine, Qt::RoundCap));
}
