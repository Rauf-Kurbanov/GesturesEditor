#pragma once

#include <QtXml/QDomDocument>

#include <scene.h>
#include <item.h>
#include <parser.h>
#include "../../qrutils/xmlUtils.h"
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
};
