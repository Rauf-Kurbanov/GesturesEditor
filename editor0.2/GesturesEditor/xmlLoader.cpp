#include <xmlLoader.h>
//#include <scene.h>

//#include <QtXml/QDomDocument>

XmlLoader::XmlLoader(Scene *scene)
{
	mScene = scene;
	initListScalePoint();
	mStrX = 0;
	mStrY = 0;
	mFloorY = 0;
	mReadFile = true;
}

void XmlLoader::initListScalePoint()
{
	mListScalePoint.clear();
	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::topLeftX, QColor(Qt::black)));
	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::topRightX, QColor(Qt::black)));
	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::bottomLeftX, QColor(Qt::black)));
	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::bottomRightX, QColor(Qt::black)));
	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::topLeftY, QColor(Qt::black)));
	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::topRightY, QColor(Qt::black)));
	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::bottomLeftY, QColor(Qt::black)));
	mListScalePoint.push_back(QPair<Item::ScalingPointState, QColor>(Item::bottomRightY, QColor(Qt::black)));
}

void XmlLoader::readFile(const QString &fileName)
{
	mReadFile = true;
//	mDocument = utils::xmlUtils::loadDocument(fileName);
	readDocument();
}

void XmlLoader::readDocument()
{
	QDomNodeList const graphics = mDocument.elementsByTagName("graphics");
	for (unsigned i = 0; i < graphics.length(); ++i) {
		QDomElement graphic = graphics.at(i).toElement();
		readGraphics(graphic);
	}
}

void XmlLoader::readGraphics(QDomElement const &graphic)
{
	QDomNodeList graphicAttributes = graphic.childNodes();

	int sizePictureX = 0;
	int sizePictureY = 0;

	for (unsigned i = 0; i < graphicAttributes.length(); ++i) {
		QDomElement type = graphicAttributes.at(i).toElement();
		if (type.tagName() == "picture") {
			sizePictureX = (type.attribute("sizex", "")).toInt();
			sizePictureY = (type.attribute("sizey", "")).toInt();
			if (mReadFile) {
				if (mStrX + distanceFigure + sizePictureX >= sizeEmptyRectX) {
					mStrY = mFloorY;
					mStrX = 0;
				}
				mDrift = QPoint(mStrX + distanceFigure, mStrY + distanceFigure);
			} else
				mDrift = QPoint(mScene->centerEmpty().x() - sizePictureX / 2, mScene->centerEmpty().y() - sizePictureY / 2);
			readPicture(type);
		}
//		else if (type.tagName() == "labels")
//			readLabels(type);
//		else if (type.tagName() == "ports")
//			readPorts(type);
		else
			qDebug() << "Incorrect graphics tag";
	}

	if (mReadFile) {
		mFloorY = qMax(mFloorY, mDrift.y() + sizePictureY);
		mStrX = mDrift.x() + sizePictureX;
	}
}

void XmlLoader::readPicture(QDomElement const &picture)
{
	QDomNodeList pictureAttributes = picture.childNodes();

	for (unsigned i = 0; i < pictureAttributes.length(); ++i) {
		QDomElement type = pictureAttributes.at(i).toElement();
//		if (type.tagName() == "line")
//			readLine(type);
//		else if (type.tagName() == "ellipse")
//			readEllipse(type);
//		else if (type.tagName() == "arc")
//			readArch(type);
//		else if (type.tagName() == "rectangle")
//			readRectangle(type);
//		else if (type.tagName() == "stylus")
//			readStylus(type);
//		else if (type.tagName() == "path")
//			readPath(type);
//		else if (type.tagName() == "curve")
//			readCurve(type);
//		else if (type.tagName() == "text")
//			readText(type);
//		else if (type.tagName() == "image")
//			readImage(type);
//		else
//			qDebug() << "Incorrect picture tag";
	}
}

//void XmlLoader::readLabels(QDomElement const &label)
//{
//	QDomNodeList labelAttributes = label.childNodes();

//	for (unsigned i = 0; i < labelAttributes.length(); ++i) {
//		QDomElement type = labelAttributes.at(i).toElement();
//		if (type.tagName() == "label")
//			readLabel(type);
//		else
//			qDebug() << "Incorrect labels tag";
//	}
//}

//void XmlLoader::readPorts(QDomElement const &port)
//{
//	QDomNodeList portAttributes = port.childNodes();

//	for (unsigned i = 0; i < portAttributes.length(); ++i) {
//		QDomElement type = portAttributes.at(i).toElement();
//		if (type.tagName() == "linePort")
//			readLinePort(type);
//		else if (type.tagName() == "pointPort")
//			readPointPort(type);
//		else
//			qDebug() << "Incorrect ports tag";
//	}
//}

//void XmlLoader::readLine(QDomElement const &line)
//{
//	QPair<QPointF, QPointF> rect = readLineOfXandY(line);
//	Line* item = new Line(rect.first.x(), rect.first.y(), rect.second.x(), rect.second.y(), NULL);
//	item->readPenBrush(line);
//	item->setListScalePoint(mListScalePoint);
//	mScene->addItem(item);
//	mScene->setZValue(item);
//}

//void XmlLoader::readEllipse(QDomElement const &ellipse)
//{
//	QRectF rect = readRectOfXandY(ellipse);
//	Ellipse* item = new Ellipse(rect.left(), rect.top(), rect.right(), rect.bottom(), NULL);
//	item->readPenBrush(ellipse);
//	item->setListScalePoint(mListScalePoint);
//	mScene->addItem(item);
//	mScene->setZValue(item);
//}

//void XmlLoader::readArch(QDomElement const &arch)
//{
//	QRectF rect = readRectOfXandY(arch);
//	int spanAngle = arch.attribute("spanAngle", "0").toInt();
//	int startAngle = arch.attribute("startAngle", "0").toInt();
//	Arch* item = new Arch(rect, startAngle, spanAngle, NULL);
//	mScene->addItem(item);
//	mScene->setZValue(item);
//}

//void XmlLoader::readRectangle(QDomElement const &rectangle)
//{
//	QRectF rect = readRectOfXandY(rectangle);
//	Rectangle* item = new Rectangle(rect.left(), rect.top(), rect.right(), rect.bottom(), NULL);
//	item->readPenBrush(rectangle);
//	item->setListScalePoint(mListScalePoint);
//	mScene->addItem(item);
//	mScene->setZValue(item);
//}

//void XmlLoader::readCurve(QDomElement const &curve)
//{
//	QDomNodeList curveAttributes = curve.childNodes();
//	qreal x1 = 0;
//	qreal y1 = 0;
//	qreal x2 = 0;
//	qreal y2 = 0;
//	qreal x3 = 0;
//	qreal y3 = 0;
//	for (unsigned i = 0; i < curveAttributes.length(); ++i) {
//		QDomElement type = curveAttributes.at(i).toElement();
//		if (type.tagName() == "start") {
//			x1 = (type.attribute("startx", "0")).toDouble() + mDrift.x();
//			y1 = (type.attribute("starty", "0")).toDouble() + mDrift.y();
//		}
//		else if (type.tagName() == "end") {
//			x2 = (type.attribute("endx", "0")).toDouble() + mDrift.x();
//			y2 = (type.attribute("endy", "0")).toDouble() + mDrift.y();
//		} else if (type.tagName() == "ctrl") {
//			x3 = (type.attribute("x", "0")).toDouble() + mDrift.x();
//			y3 = (type.attribute("y", "0")).toDouble() + mDrift.y();
//		} else
//			qDebug() << "Incorrect curve tag";

//	}
//	Curve* item = new Curve(QPointF(x1, y1), QPointF(x2, y2), QPointF(x3, y3));
//	item->readPenBrush(curve);
//	mScene->addItem(item);
//	mScene->setZValue(item);
//}
