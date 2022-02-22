#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QSizePolicy>
#include <QWidget>
#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QMovie>
#include <QApplication>
#include <QTime>
#include <QImage>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    global_setStyleSheet();
    QSizePolicy policy_00_Fixed_Fixed;
    QSizePolicy policy_this;
    policy_00_Fixed_Fixed.setHorizontalStretch(0);
    policy_00_Fixed_Fixed.setVerticalStretch(0);
    policy_00_Fixed_Fixed.setHorizontalPolicy(QSizePolicy::Fixed);
    policy_00_Fixed_Fixed.setVerticalPolicy(QSizePolicy::Fixed);
    qint8 wid = 56, hig = 40;

    this->setSizePolicy(policy_00_Fixed_Fixed);
    this->setMinimumSize(950, 700);
    this->setObjectName("mainWindow");


    bg_Widget = new QWidget(this);
    bg_Widget->setObjectName(QStringLiteral("bg_Widget"));
    bg_Widget->setSizePolicy(policy_00_Fixed_Fixed);
    bg_Widget->setMinimumSize(950, 700);
    bg_Widget->setMaximumSize(950, 700);
    bg_Widget->setStyleSheet("QWidget#bg_Widget{"
                                 "border-image: url(:/images/mainwindow.png)}");

    CPU_Button = new QPushButton(this);
    CPU_Button->setObjectName(QStringLiteral("CPU_Button"));
    CPU_Button->setSizePolicy(policy_00_Fixed_Fixed);
    CPU_Button->move(164,313);
    CPU_Button->resize(wid,hig);
    CPU_Button->setText("CPU");
    CPU_Button->setFont(QFont("Microsoft Yahei",16,60));

    connect(CPU_Button, &QPushButton::clicked, this, [=]()
    {
        QProcess *cpu=new QProcess;
        cpu->setWorkingDirectory("/home/yy2/Desktop/qt/chen_yy2/build-CPU-Desktop_Qt_5_9_0_GCC_64bit-Debug/");
        cpu->start("./CPU");
    });

    ZX_Button = new QPushButton(this);
    ZX_Button->setObjectName(QStringLiteral("ZX_Button"));
    ZX_Button->setSizePolicy(policy_00_Fixed_Fixed);
    ZX_Button->move(714, 305);
    ZX_Button->resize(wid,hig);
    ZX_Button->setText("总线");
    ZX_Button->setFont(QFont("Microsoft Yahei",16,60));
    connect(ZX_Button, &QPushButton::clicked, this, [=]()
    {
        QProcess *zx=new QProcess;
        zx->setWorkingDirectory("/home/yy2/Desktop/qt/chen_yy2/build-ZX-Desktop_Qt_5_9_0_GCC_64bit-Debug");
        zx->start("./ZX");
    });


    JCQ_Button = new QPushButton(this);
    JCQ_Button->setObjectName(QStringLiteral("JCQ_Button"));
    JCQ_Button->setSizePolicy(policy_00_Fixed_Fixed);
    JCQ_Button->move(242, 524);
    JCQ_Button->resize(wid,hig);
    JCQ_Button->setText("寄存器");
    JCQ_Button->setFont(QFont("Microsoft Yahei",16,60));
    connect(JCQ_Button, &QPushButton::clicked, this, [=]()
    {
        QProcess *jcq=new QProcess;
        jcq->setWorkingDirectory("/home/yy2/Desktop/qt/chen_yy2/build-JCQ-Desktop_Qt_5_9_0_GCC_64bit-Debug");
        jcq->start("./JCQ");
    });


    IO_Button = new QPushButton(this);
    IO_Button->setObjectName(QStringLiteral("IO_Button"));
    IO_Button->setSizePolicy(policy_00_Fixed_Fixed);
    IO_Button->move(666, 497);
    IO_Button->resize(wid,hig);
    IO_Button->setText("I/O");
    IO_Button->setFont(QFont("Microsoft Yahei",16,60));
    connect(IO_Button, &QPushButton::clicked, this, [=]()
    {
        QProcess *io=new QProcess;
        io->setWorkingDirectory("/home/yy2/Desktop/qt/chen_yy2/build-IO-Desktop_Qt_5_9_0_GCC_64bit-Debug");
        io->start("./IO");
    });

    CCQ_Button = new QPushButton(this);
    CCQ_Button->setObjectName(QStringLiteral("CCQ_Button"));
    CCQ_Button->setSizePolicy(policy_00_Fixed_Fixed);
    CCQ_Button->move(449, 589);
    CCQ_Button->resize(wid,hig);
    CCQ_Button->setText("存储器");
    CCQ_Button->setFont(QFont("Microsoft Yahei",16,60));
    connect(CCQ_Button, &QPushButton::clicked, this, [=]()
    {
        QProcess *ccq=new QProcess;
        ccq->setWorkingDirectory("/home/yy2/Desktop/qt/chen_yy2/build-CCQ-Desktop_Qt_5_9_0_GCC_64bit-Debug");
        ccq->start("./CCQ");
    });

    initInfo();


    test = new QLabel(this);
    test->setGeometry(270,110,400,320);// 230 70 480 420 //270 110
    /*
    test->setStyleSheet("QLabel{"
                        "min-width: 400px;"
                        "min-height: 400px;"
                        "max-width:400px;"
                        "max-height: 400px;"
                        "border-radius:100px;"
                        "}"
                        );
    */
    test->setObjectName(QStringLiteral("test"));

    QImage imag;
    imag.load("/home/yy2/Desktop/qt/chen_yy2/main/浅色星球.png");
    QPixmap pixmap = QPixmap::fromImage(imag);//400,320
    QPixmap fitpixmap = pixmap.scaled(test->size(),Qt::IgnoreAspectRatio);

    test->setPixmap(fitpixmap);

    //QMovie *movie = new QMovie("/home/yy2/Desktop/qt/chen_yy2/main/unscreen.gif");
    //test->setMovie(movie);//蓝色星球动图
    //movie->setScaledSize(QSize(480,420));
    //movie->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initInfo(){
    QString perfWorkDir = "/home/yy2/res/perf/";
    QString mipsInfo = "200";
    QFile file(perfWorkDir+"perf");
    file.open(QIODevice::ReadOnly);
    if(file.isOpen()){
        mipsInfo = QString::fromStdString(file.readAll().toStdString());
    }
    file.close();
    QProcess p;

    p.setWorkingDirectory(perfWorkDir);
    p.start("/home/yy2/res/gemFI/build/ARM/gem5.oe/yy2/res/gemFI/configs/example/se.py -c  exec");

}

void MainWindow::global_setStyleSheet() {
    this->setStyleSheet("QPushButton#CPU_Button, #CCQ_Button, #JCQ_Button,"
                        "#IO_Button, #ZX_Button{"
                        "background-color:rgba(20,32,84, 1);"
                        "color:#24FDFF;"
                        "border: 1px solid #02246c;"
                        "}"
                        "QPushButton#CPU_Button:hover, #CCQ_Button:hover,#JCQ_Button:hover,"
                        "#IO_Button:hover, #ZX_Button:hover{"
                        "background-color:rgba(40,40,160, 1)"
                        "}"
                        "QPushButton#CPU_Button:pressed, #CCQ_Button:pressed,#JCQ_Button:pressed,"
                        "#IO_Button:pressed, #ZX_Button:pressed"
                        "#Block_A:pressed, #Block_B:pressed, #Block_C:pressed, #Block_D:pressed, #YCJG_BUtton:pressed{"
                        "background-color:#00D688;"
                        "}"
                        );
}

void MainWindow::Sleep(unsigned int msec)
{
    QTime reachtime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachtime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}
