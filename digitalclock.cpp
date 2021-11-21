#include "digitalclock.h"
#include<QHBoxLayout>
#include<QTime>
#include<QTimer>
#include<QTimerEvent>
digitalclock::digitalclock(QWidget * parent): QWidget(parent)
{
    createwidgets();
    placewidgets();

    startTimer(1000);
    setWindowTitle(tr("DiditalClock"));
}
void digitalclock::createwidgets(){
    hour=new QLCDNumber;
    hour->setDigitCount(2);
    minute=new QLCDNumber;
   minute->setDigitCount(2);
   second=new QLCDNumber;
   second->setDigitCount(2);
   //aficher le temps courant
    updateTime();
}
void digitalclock::placewidgets(){
  QLayout *layout=new QHBoxLayout;
  setLayout(layout);
  layout->addWidget(hour);
  layout->addWidget(minute);
  layout->addWidget(second);
}
void digitalclock::updateTime(){

    //obtenir le temps actuel
    auto T=QTime::currentTime();
    hour->display(T.hour());
    minute->display(T.minute());
    second->display(T.second());
}
void digitalclock::timerEvent(QTimerEvent *e){
    updateTime();
}


