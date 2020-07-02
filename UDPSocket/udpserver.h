#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include <ctime>
#include "mouseEvent.h"
#include "recognizer.h"


class UdpServer : public QObject
{
    Q_OBJECT
public:
    explicit UdpServer(QObject *parent = 0);

    void getData(QByteArray *Buffer);
   inline void act(QByteArray *buffer);
    Display *disp;
    Display *dpy;
    Window root_window;



signals:

public slots:
 void readyRead();

private:
    QUdpSocket *socket;

    Recognizer *r;
    int record, gesture;
    float v[2];

    float prev_x, prev_y, vy, vx, dt, prev_prev_x, prev_prev_y;
    float gravity[3], linear_acel[3];

    float alpha;

    clock_t _currentTime;
    clock_t _lastTIme;

};
/*
float UdpServer::a1 =0;
float UdpServer::a2 = 0;
float  UdpServer::vx = 0;
float UdpServer::vy = 0;
float UdpServer::ux = 0;
float UdpServer::uy = 0;
float UdpServer::velocityMagnitude = 0;
int UdpServer::state = 0;
*/

#endif // UDPSERVER_H
