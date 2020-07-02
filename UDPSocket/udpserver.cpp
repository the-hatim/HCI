#include "udpserver.h"
#include <iostream>

using namespace std;

UdpServer::UdpServer(QObject *parent) : QObject(parent)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::QHostAddress::Any,2050);

    prev_x = 0;
    prev_y = 0;
   // gravity[3] = {0};
     //   alpha =  0.9f;
    disp = XOpenDisplay(0);

   root_window = DefaultRootWindow(disp);

    XSelectInput(disp, root_window, KeyReleaseMask);

    //_lastTIme = 0;


    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
     r = new Recognizer();
}


void UdpServer::readyRead()
{
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 port;

    socket->readDatagram(Buffer.data(),Buffer.size(),&sender,
                         &port);

   // qDebug() << Buffer;

   if (Buffer.at(0) == '*')
        act(&Buffer);




}

inline void UdpServer::act(QByteArray *buf)
{

  //int x=0,y=0;


    QString buffer(*buf);
    QStringList buflist = buffer.split('|');
    //int X = ()buflist.at(1);
    QString Xtemp(buflist.at(1));
    QString YTemp(buflist.at(2));


   // qDebug() << buflist.at(1) << " " << buflist.at(2)<< " " << buflist.at(3) <<  "------------- " << buflist.at(4)<<"-------------"<<buflist.at(5);

   // int xmov = 0;
   // int ymov = 0;
    float x = buflist[1].toFloat();
    float y = buflist[2].toFloat();
    float z = buflist[3].toFloat();

            /*gravity[0] = alpha * gravity[0] + (1 - alpha) * x;
            gravity[1] = alpha * gravity[1] + (1 - alpha) * y;
            gravity[2] = alpha * gravity[2] + (1 - alpha) * z;*/

            linear_acel[0] = x;// - gravity[0];
            linear_acel[1] = y;//- gravity[1];
            linear_acel[2] = z; //- gravity[2];


           // qDebug()<< linear_acel[0]<<"\t"<<linear_acel[1]<<"\t"<<linear_acel[2];

    if(buflist.at(4) == "R")
     {
        qDebug() << "Right Clicked.";
         mousebutton(disp,Button3,True);
     }

    else if(buflist.at(4) == "L")
     {
         qDebug() << "Left Clicked.";
         mousebutton(disp,Qt::LeftButton,True);
    }
    else if (buflist.at(4) == "G")
    {
        gesture = 1;

        r->recognitionData(linear_acel[0], linear_acel[1], linear_acel[2]);
    }
    else if(gesture ==   1)
    {
        gesture = 0;
        r->Recognize();


    }


   else  if(buflist.at(4) == "RS")
    {
        //flag for starting record
        record = 1;

        if (buflist.at(5) == "1")
        {

            r->starting = 3;
             r->recordGesture(linear_acel[0],linear_acel[1],linear_acel[2]);
        }
        else if (buflist.at(5) == "2")
        {
              r->recordGesture(linear_acel[0],linear_acel[1],linear_acel[2]);
        }



          //  qDebug() << "Recording";
    }

    else if (buflist.at(4) == "S")
    {

        r->saveFile();
         qDebug() << "saved successfully.";
          r->loadTrainingData();
    }
    
    else if (record == 1)
    {

        r->saveTrainingData();
        record = 0;
    }

else{
    //qDebug() << "acr";
      //  cout<<"\n"<<ceil(x)<<"  " <<ceil(y);
        //cout<<"\n"<<y;


  //    _currentTime = clock();

//      dt = (_currentTime - _lastTIme) * -0.05;

         vx = (x + prev_x) / 2 * 0.9;
         vy = (y + prev_y)/ 2 * 0.9;


        prev_x = x;
        prev_y = y;




//cout<<"\nvx"<<vx<<"\nvy"<<vy;
      //if (abs(floor(x)) > 1 || abs(floor(y)) > 1)
        //     move_mouse(disp,floor(x)*20 ,floor(y)*20);

//if(abs(floor(vx)) > 1 || abs(floor(vy)) > 1)
       move_mouse(disp,-vx,-vy);
}

}
