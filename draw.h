#ifndef DRAW_H
#define DRAW_H
#include <QWidget>
#include <QPushButton>
#include <QPalette>
#include <QColor>
#include <QPainter>

class draw : public QWidget
{
    Q_OBJECT
public:
    explicit draw(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

signals:

};


#endif // DRAW_H
