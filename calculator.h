#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QGridLayout>
#include <QVector>
#include<QPushButton>
#include <QLCDNumber>
#include<QMessageBox>

class Calculator : public QWidget
{
    Q_OBJECT
public:
    Calculator(QWidget *parent = nullptr);
    //~Calculator();

 // Add you custom slots here

protected:
    void createWidgets();        //Function to create the widgets
    void placeWidget();         // Function to place the widgets
    void makeConnexions();      // Create all the connectivity

//events
protected:
    void keyPressEvent(QKeyEvent *e)override;     //Override the keypress events
public slots:
       void newDigit();
        void changeOperation();
        void Enter();
         void Quit();
         void clearAll();
        //Slot to handle the click on operations
signals:
       void digitClicked(int digit);
private:
       QPushButton *createButton(const QString &text, const char *member);

    QGridLayout *buttonsLayout; // layout for the buttons
    QVBoxLayout *layout;        //main layout for the button
    QVector<QPushButton*> digits;  //Vector for the digits
    QPushButton *enter;            // enter button
    QPushButton *quit;
    QPushButton *clear;
    QVector<QPushButton*> operations; //operation buttons
    QLCDNumber *disp; // Where to display the numbers
    double * left;          //left operand
        double * right;         // right operand
        QString *operation;  // Pointer on the current operation
};
#endif // CALCULATOR_H
