#pragma once

#include <QtXml/QDomDocument>

#include <scene.h>
#include <item.h>
//#include <parser.h>
//#include "../../qrutils/xmlUtils.h"
//#include "C:/Users/Maestro/GesturesEditor/editor0.2/qrutils/xmlUtils.h"

const int distanceFigure = 50;

class XmlLoader
{
public:
	XmlLoader(Scene *scene);
//	void readString(const QString &text);
	void readFile(const QString &fileName);

private:
	QDomDocument mDocument;
	Scene *mScene;
	QPoint mDrift;
	QList<QPair<Item::ScalingPointState, QColor> > mListScalePoint;
	int mStrY;
	int mStrX;
	int mFloorY;
	bool mReadFile;

	void initListScalePoint();
	void readDocument();
	void readGraphics(QDomElement const &graphic);
	void readPicture(QDomElement const &picture);
	void readLabels(QDomElement const &label);
	void readPorts(QDomElement const &port);
	void readLine(QDomElement const &line);
	void readEllipse(QDomElement const &ellipse);
	void readArch(QDomElement const &arch);
	void readRectangle(QDomElement const &rectangle);
	void readCurve(QDomElement const &element);
	QPair<QPointF, QPointF> readLineOfXandY(QDomElement const &docItem);
	QPair<QString, bool> readScaleCoord(QString point, QDomElement const &docItem);
	QPair<QPointF, QPointF> calcLineOfXandY(QPair<QString, bool> pointX1, QPair<QString, bool> pointX2
			, QPair<QString, bool> pointY1, QPair<QString, bool> pointY2);
	QRectF readRectOfXandY(QDomElement const &docItem);
};
