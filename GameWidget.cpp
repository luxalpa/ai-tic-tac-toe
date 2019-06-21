#include "GameWidget.h"

#include "GameMap.h"
#include "Game.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QMouseEvent>

GameWidget::GameWidget(QWidget *parent) : QGLWidget(parent)
{
    setMouseTracking(true);
    game = NULL;
    map = NULL;
}

void GameWidget::appendToGame(Game* g)
{
    highlightedFields.clear();
    this->game = g;
    this->map = game->map();
    connect(game, SIGNAL(winner(Player*,QSet<QPoint>)), this, SLOT(highlightWinner(Player*,QSet<QPoint>)));
}

void GameWidget::highlightWinner(Player*, QSet<QPoint> fields)
{
    highlightedFields = fields;
}

void GameWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    canvas.fill(Qt::transparent);
    QPainter canvasPainter(&canvas);


    auto drawFunction = [&](QPainter &target){
        if(map == NULL)
            return;

        QPen standardPen = QPen(QBrush(QColor(81, 164, 64)), lineWidth, Qt::SolidLine, Qt::RoundCap);
        QPen fadedPen = standardPen;
        fadedPen.setColor(QColor(81, 164, 64, 100));
        QPen highlightPen = standardPen;
        highlightPen.setColor(QColor(230, 60, 60));

        target.setPen(standardPen);

        float linePosX = hCenter - wSquare / 2;
        float linePosY = vCenter - wSquare / 2;

        // Vertical Lines

        target.drawLine(linePosX + wSquare * (1.0 / 3), linePosY, linePosX + wSquare * (1.0 / 3), linePosY + wSquare);
        target.drawLine(linePosX + wSquare * (2.0 / 3), linePosY, linePosX + wSquare * (2.0 / 3), linePosY + wSquare);

        // Horizontal Lines

        target.drawLine(linePosX, linePosY + wSquare * (1.0 / 3), linePosX + wSquare, linePosY + wSquare * (1.0 / 3));
        target.drawLine(linePosX, linePosY + wSquare * (2.0 / 3), linePosX + wSquare, linePosY + wSquare * (2.0 / 3));

        // Player Icons

        QPoint p = getCursorCell();

        for(int x = 0; x < map->width(); x++) {
            for(int y = 0; y < map->height(); y++) {

                PlayerIcon playerOnField = map->iconAt(x, y);
                PlayerIcon currentPlayerIcon = game->currentPlayerIcon();

                PlayerIcon toDraw = playerOnField;

                if(playerOnField == PlayerIcon::None && game->allowsInput() && p.x() == x && p.y() == y) {
                    toDraw = currentPlayerIcon;
                    target.setPen(fadedPen);
                } else {
                    if(highlightedFields.contains(QPoint(x, y))) {
                        target.setPen(highlightPen);
                    } else {
                        target.setPen(standardPen);
                    }
                }

                QRect rect = cellRect(x, y, iconSize);

                switch(toDraw) {
                case PlayerIcon::None:
                    break;
                case PlayerIcon::Circle:
                    target.drawEllipse(rect.x(), rect.y(), rect.width(), rect.height());
                    break;
                case PlayerIcon::Cross:
                    target.drawLine(rect.x(), rect.y(), rect.x() + rect.width(), rect.y() + rect.height());
                    target.drawLine(rect.x() + rect.width(), rect.y(), rect.x(), rect.y() + rect.height());
                    break;
                }
            }
        }
    };

    drawFunction(canvasPainter);

    // draw shadow

    shadow.fill(Qt::transparent);
    QPainter shadowPainter(&shadow);
    shadowPainter.translate(wSquare / 70, wSquare / 50);
    drawFunction(shadowPainter);

    // todo: Improve performance.
    for(int r = 0; r < shadow.height(); r++) {
        QRgb *pixel = (QRgb*)shadow.scanLine(r);
        for(int c = 0; c < shadow.width(); c++) {
            QRgb color = pixel[c];
            pixel[c] = QColor(0, 0, 0, qAlpha(color) * 0.2).rgba();
        }
    }

    painter.drawImage(0, 0, shadow);
    painter.drawImage(0, 0, canvas);
}



void GameWidget::mouseMoveEvent(QMouseEvent* event)
{
    update();
    cursor = event->pos();
    if(cursorOverAnyCell() && game->allowsInput()) {
        setCursor(Qt::PointingHandCursor);
    } else {
        setCursor(Qt::ArrowCursor);
    }
}


void GameWidget::resizeEvent(QResizeEvent*)
{
    wSquare = (height() > width() ? width() : height()) * 0.8f;
    hCenter = width() / 2;
    vCenter = height() / 2;
    lineWidth = wSquare / 30;

    shadow = QImage(width(), height(), QImage::Format_ARGB32_Premultiplied);
    canvas = QImage(width(), height(), QImage::Format_ARGB32_Premultiplied);
}

QPoint GameWidget::getCursorCell()
{
    if(map != NULL) {
        for(int x = 0; x < map->width(); x++) {
            for(int y = 0; y < map->height(); y++) {
                if(cellRect(x, y, qMin(iconSize + 0.1, 1.0)).contains(cursor)) {
                    return QPoint(x, y);
                }
            }
        }
    }
    return QPoint(-1, -1);
}

bool GameWidget::cursorOverAnyCell()
{
    return getCursorCell().x() != -1;
}

QRect GameWidget::cellRect(int x, int y, float sizeMod)
{
    float w = wSquare / 3.0 * sizeMod;
    float h = wSquare / 3.0 * sizeMod;
    int posX = hCenter - wSquare / 2.0 + wSquare * ((float)x / 3) + (1.0 - sizeMod) * wSquare / 3.0 / 2.0;
    int posY = vCenter - wSquare / 2.0 + wSquare * ((float)y / 3) + (1.0 - sizeMod) * wSquare / 3.0 / 2.0;

    return QRect(posX, posY, w, h);
}


void GameWidget::mousePressEvent(QMouseEvent*)
{
    QPoint cell = getCursorCell();
    if(cell.x() != -1 && game->allowsInput()) {
        game->activateField(cell.x(), cell.y());
        update();
    }
}
