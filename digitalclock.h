#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H
#include<QLCDNumber>
#include<QWidget>


class digitalclock : public QWidget
{
public:
    explicit  digitalclock(QWidget *parent = nullptr);
protected:
void createwidgets();
void placewidgets();

 void timerEvent(QTimerEvent *e)override;
private slots:
 void updateTime();

  private:
    QLCDNumber * hour;
    QLCDNumber * minute;
    QLCDNumber * second;
};
#endif // DIGITALCLOCK_H
