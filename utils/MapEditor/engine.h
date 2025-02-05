#ifndef ENGINE_H
#define ENGINE_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <map>
#include <QPixmap>
#include <vector>
#include <QPoint>

class Engine : public QWidget
{
    Q_OBJECT
    QString name;
    int w, h;

    QPoint vOrigin;
    QPoint vTileSize;
    QPoint Selected;

    // for camera move
    QTimer *mouseTrackTimer;
    int dx, dy;

    std::map<int, QPixmap*> spriteMap;
    std::vector<std::vector<int>> GameMap;

public:
    QPoint originOffset;

private:
    void loadSprites();

public:
    Engine(QString name, int w, int h);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

};

#endif // ENGINE_H
