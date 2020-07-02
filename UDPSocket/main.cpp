#include <QCoreApplication>
#include "udpserver.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    UdpServer client;
    QByteArray buffer;



    return a.exec();


}

