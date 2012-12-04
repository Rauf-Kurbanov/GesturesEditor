#include <xmlLoader.h>
//#include <scene.h>

//#include "../../qrutils/xmlUtils.h"

XmlLoader::XmlLoader(Scene *scene)
{
	mScene = scene;
	initListScalePoint();
	mStrX = 0;
	mStrY = 0;
	mFloorY = 0;
	mReadFile = true;
}

//void XmlLoader::initListScalePoint()
//{
//	mListScalePoint.clear();
//	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::topLeftX, QColor(Qt::black)));
//	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::topRightX, QColor(Qt::black)));
//	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::bottomLeftX, QColor(Qt::black)));
//	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::bottomRightX, QColor(Qt::black)));
//	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::topLeftY, QColor(Qt::black)));
//	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::topRightY, QColor(Qt::black)));
//	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::bottomLeftY, QColor(Qt::black)));
//	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::bottomRightY, QColor(Qt::black)));
//}

void XmlLoader::readFile(const QString &fileName)
{
	mReadFile = true;
//	mDocument = utils::xmlUtils::loadDocument(fileName);
//	readDocument();
}

void XmlLoader::readDocument()
{
	QDomNodeList const graphics = mDocument.elementsByTagName("graphics");
	for (unsigned i = 0; i < graphics.length(); ++i) {
		QDomElement graphic = graphics.at(i).toElement();
//		readGraphics(graphic);
	}
}

//void XmlLoader::readGraphics(QDomElement const &graphic)
//{
//	QDomNodeList graphicAttributes = graphic.childNodes();

//	int sizePictureX = 0;
//	int sizePictureY = 0;

//	for (unsigned i = 0; i < graphicAttributes.length(); ++i) {
//		QDomElement type = graphicAttributes.at(i).toElement();
//		if (type.tagName() == "picture") {
//			sizePictureX = (type.attribute("sizex", "")).toInt();
//			sizePictureY = (type.attribute("sizey", "")).toInt();
//			if (mReadFile) {
//				if (mStrX + distanceFigure + sizePictureX >= sizeEmptyRectX) {
//					mStrY = mFloorY;
//					mStrX = 0;
//				}
//				mDrift = QPoint(mStrX + distanceFigure, mStrY + distanceFigure);
//			} else
//				mDrift = QPoint(mScene->centerEmpty().x() - sizePictureX / 2, mScene->centerEmpty().y() - sizePictureY / 2);
//			readPicture(type);
//		}
//		else if (type.tagName() == "labels")
//			readLabels(type);
//		else if (type.tagName() == "ports")
//			readPorts(type);
//		else
//			qDebug() << "Incorrect graphics tag";
//	}

//	if (mReadFile) {
//		mFloorY = qMax(mFloorY, mDrift.y() + sizePictureY);
//		mStrX = mDrift.x() + sizePictureX;
//	}
//}
