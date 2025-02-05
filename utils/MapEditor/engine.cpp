#include "engine.h"

#include <QMouseEvent>
#include <QDir>

Engine::Engine(QString name, int w, int h){
    this->name = name;
    this->w = w;
    this->h = h;

    dx = 0;
    dy = 0;

    vOrigin = QPoint(0, 0);

    vTileSize = QPoint(40, 20);

    originOffset = QPoint(0, 0);

    mouseTrackTimer = new QTimer(this);

    connect(mouseTrackTimer, &QTimer::timeout, this, [&](){
        originOffset.rx() += dx * 0.1;
        originOffset.ry() += dy * 0.1;

        this->repaint();
    });

    mouseTrackTimer->start(10);
    setMouseTracking(true);

    loadSprites();


    GameMap.resize(w);
    for (int i = 0; i < GameMap.size(); i++) {
        GameMap[i].resize(h);
    }
}

void Engine::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::yellow);

    auto ToScreen = [&](int x, int y)
    {

        int w_x = (vOrigin.x() * vTileSize.x()) + (x - y) * (vTileSize.x() / 2);
        int w_y = (vOrigin.y() * vTileSize.y()) + (x + y) * (vTileSize.y() / 2);
        return QPoint(w_x, w_y);
    };

    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            QPoint vWorld = ToScreen(x, y);
            QPoint source_size;


            source_size.setX(vTileSize.x());
            source_size.setY(vTileSize.y());

            vWorld -= originOffset;

            painter.drawPixmap(vWorld, *spriteMap[0]);
        }
    }



    // draw selected cell
    QPoint vSelectedWorld = ToScreen(Selected.x(), Selected.y());
    painter.drawRect(vSelectedWorld.x(), vSelectedWorld.y(), vTileSize.x(), vTileSize.y());
}

void Engine::mouseMoveEvent(QMouseEvent *event) {
    int x = event->pos().x();
    int y = event->pos().y();
    dx = 0;
    dy = 0;

    if ( x < 10) {
        dx = -70;
    }

    if ( x > width() - 10) {
        dx = 70;
    }

    if ( y < 10) {
        dy = -70;
    }

    if ( y > height() - 10) {
        dy = 70;
    }


    QPoint cell = QPoint( x / vTileSize.x(), y / vTileSize.y());
    QPoint offset = QPoint( x % vTileSize.x(), y % vTileSize.y());

    Selected = QPoint ((cell.y() - vOrigin.y()) + (cell.x() - vOrigin.x()), (cell.y() - vOrigin.y()) - (cell.x() - vOrigin.x()));
    qDebug() << "cell: " << Selected;
}

void Engine::loadSprites() {
    QDir dir("content/sprites");
    QStringList filters;
    filters << "*.png";
    dir.setNameFilters(filters);

    QFileInfoList files = dir.entryInfoList();


    for (const QFileInfo &fileInfo : files) {
        QString spriteName = fileInfo.baseName();
        QPixmap *pixmap = new QPixmap(fileInfo.absoluteFilePath());

        bool ok = false;
        int idx = spriteName.toInt(&ok);

        if (!pixmap->isNull() && ok) {
            spriteMap[idx] = pixmap;
            qDebug() << "Loaded sprite: " << spriteName;
        } else {
            qWarning() << "Failed to load sprite:" << spriteName;
        }
    }
}


























