#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "common.h"
#include <QGLWidget>
#include <functional>
#include <QSet>

class GameMap;
class Game;
class Player;

class GameWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);
    void appendToGame(Game* g);

signals:

public slots:
	void highlightWinner(Player *, QSet<QPoint> fields);

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent*);
    void resizeEvent(QResizeEvent*);
    void mousePressEvent(QMouseEvent*);

    QPoint getCursorCell();
    bool cursorOverAnyCell();
    QRect cellRect(int x, int y, float sizeMod = 1.0);

private:
    GameMap *map;
    Game *game;
    QPoint cursor;

    QImage canvas;
    QImage shadow;

    float wSquare;
    float hCenter;
    float vCenter;
    float lineWidth;

	const float iconSize = 0.6f;

    QSet<QPoint> highlightedFields;
};

#endif // GAMEWIDGET_H
