#include "calculator.h"
#include <QKeyEvent>
#include <QApplication>
#include <QObject>
#include<QString>
QString evaluate;

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    createWidgets();
    placeWidget();
    makeConnexions();

    left=nullptr;
    right=nullptr;
    operation=nullptr;
}
void Calculator::createWidgets()
{
    //Creating the layouts
    layout = new QVBoxLayout();
    layout->setSpacing(2);

    //grid layout
    buttonsLayout = new QGridLayout;
setStyleSheet("QPushButton{  display: inline-block;background-color: #7b38d8;border-radius: 10px;border: 4px double #cccccc;color: #eeeeee;text-align: center;padding: 10px;width: 10px;transition: all 0.5s;cursor: pointer;margin: 5px;}");

    //creating the buttons
    for(int i=0; i < 10; i++)
    {
        digits.push_back(new QPushButton(QString::number(i)));
        digits.back()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        digits.back()->resize(sizeHint().width(), sizeHint().height());
    }
    //enter button
    enter = new QPushButton("Enter",this);
    enter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    enter->resize(sizeHint().width(), sizeHint().height());

    //operatiosn buttons
    operations.push_back(new QPushButton("+"));
    operations.push_back(new QPushButton("-"));
   operations.push_back(new QPushButton("*"));
   operations.push_back(new QPushButton("/"));
   //clear button
   clear = new QPushButton("Clear",this);
   clear->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
   clear->resize(sizeHint().width(), sizeHint().height());


   //quit button
   quit = new QPushButton("Exit",this);
   quit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
   quit->resize(sizeHint().width(), sizeHint().height());
    //creating the lcd
    disp = new QLCDNumber();
    disp->setDigitCount(6);
}
void Calculator::placeWidget()
{
    layout->addWidget(disp);
    layout->addLayout(buttonsLayout);
    // Adding the digits
     for(int i=0; i < 10; i++)
      buttonsLayout->addWidget(digits[ i], (i-1)/3,(i-1)%3 );
   // Adding the operations
   for(int i=0; i < 4; i++)
     buttonsLayout->addWidget(operations[ i], i, 4);
    //Adding the 0 button
    buttonsLayout->addWidget(digits[0], 3, 0);
 //Adding the enter button
    buttonsLayout->addWidget(enter, 4, 4);
    //Adding the clear button
       buttonsLayout->addWidget(clear);
 //Adding the quit button
     buttonsLayout->addWidget(quit,5,2);
    setLayout(layout);
//connect the digit
for(int i=0;i<10;i++){
    connect(digits[i],&QPushButton::clicked,this,&Calculator::newDigit);
}
//connect the operations
for(int i=0;i<4;i++){
    connect(operations[i],&QPushButton::clicked,this,&Calculator::changeOperation);
}
//connect the Enter button

    connect(enter,&QPushButton::clicked,this,&Calculator::Enter);

    //connect the clear button

        connect(clear,&QPushButton::clicked,this,&Calculator::clearAll);
    //connect the quit button

        connect(quit,&QPushButton::clicked,this,&Calculator::Quit);
}
void Calculator::makeConnexions()
{

}
void Calculator::newDigit( )
{
    //getting the sender
    auto button = dynamic_cast<QPushButton*>(sender());

    //getting the value
    double value = button->text().toInt();

    //Check if we have an operation defined
    if(operation)
    {
        //check if we have a value or not
        if(!right)
            right = new double{value};
        else
            *right = 10 * (*right) + value;

        disp->display(*right);
    }
    else
    {
        if(!left)
            left = new double{value};
        else
            *left = 10 * (*left) + value;

        disp->display(*left);
    }
}
void Calculator::changeOperation()

{
    //Getting the sender button
       auto button = dynamic_cast<QPushButton*>(sender());

       //Storing the operation
       operation = new QString{button->text()};

       //Initiating the right button
       right = new double{0};

       //reseting the display
       disp->display(0);
}

void Calculator::Enter(){
    if(*operation=="+"){

        disp->display(*left+(*right));*left=*left+(*right);
    }else if(*operation=="-"){
        disp->display(*left-(*right));*left=*left-(*right);
   } else if (*operation=="*"){
            disp->display(*left*(*right));*left=*left*(*right);
   } else{
                disp->display(*left/(*right));*left=*left/(*right);}
 //  waitingForOperand = true;
}

void Calculator::clearAll()
{
disp->display("");
evaluate ="";

}
void Calculator::Quit(){
    QMessageBox messageBox;
        messageBox.setWindowTitle(tr("Calculator"));
        messageBox.setText(tr("Do you really want to quit?"));
        messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        messageBox.setDefaultButton(QMessageBox::No);
        if (messageBox.exec() == QMessageBox::Yes)
            qApp->quit();
}
void Calculator::keyPressEvent(QKeyEvent *e)
{
    //Exiting the application by a click on space
    if( e->key() == Qt::Key_Escape)
        qApp->exit(0);
    //You could add more keyboard interation here (like digit to button)
}
