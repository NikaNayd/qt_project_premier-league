#include "draw.h"

#include <QPainter>

draw::draw(QWidget* parent)
    : QWidget(parent)
{
}
void draw::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);
    QPen pen;
    pen.setColor(Qt::green);
    pen.setWidth(7);
    QBrush brush;
    brush.setColor(Qt::yellow);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(50, 12, 250, 250);
    painter.drawRect(10, 10, 350, 250);
    pen.setColor(Qt::black);
    pen.setWidth(12);
    painter.setPen(pen);

    painter.drawText(rect(), Qt::AlignCenter,"Premier League");
    painter.end();
}


