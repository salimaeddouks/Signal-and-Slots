#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H
#include <QWidget>
#include<QVector>
#include<QKeyEvent>
#include<QTime>
class QRadioButton;
class TrafficLight: public QWidget{
  Q_OBJECT
public:
  TrafficLight(QWidget * parent = nullptr);
protected:
     void createWidgets();
     void placeWidgets();
     //surcharger l'ecoute de temps
     void timerEvent(QTimerEvent *e)override;
     void keyPressEvent(QKeyEvent *e)override;
private:
  QRadioButton * redlight;
  QRadioButton * yellowlight;
  QRadioButton * greenlight;
//QVector<QRadioButton*> lights;
//int index;     //indice du feu d'indice
  int lifeTime; //la vie du feu coutant
};




#endif
