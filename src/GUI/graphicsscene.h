#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include "data/imageinfo.h"

class GraphicsItem : public QGraphicsItem
{
public:
	GraphicsItem(QGraphicsItem *parent = 0) : QGraphicsItem(parent) {}

	virtual QString info() const = 0;
	virtual const QVector<ImageInfo> images() const { return QVector<ImageInfo>(); }
	int type() const {return QGraphicsItem::UserType + 1;}
};

class GraphicsScene : public QGraphicsScene
{
public:
	GraphicsScene(QObject *parent = 0) : QGraphicsScene(parent) {}

public slots:
	void clear();

protected:
	void helpEvent(QGraphicsSceneHelpEvent *event);

private:
	QList<QGraphicsItem *> itemsAtPosition(const QPoint &screenPos,
	  const QPointF &scenePos, QWidget *widget) const;
};

#endif // GRAPHICSSCENE_H
