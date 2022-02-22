#include "cpu_mainwindow.h"
#include "ui_cpu_mainwindow.h"
#include <QPushButton>
#include <QSizePolicy>
#include <QWidget>
#include <QProcess>
#include <QFile>
#include <QDebug>
#include <QIcon>
#include <QSize>
#include <QLineEdit>
#include <QPalette>
#include <QTextEdit>
#include <QStandardItemModel>
#include <QTableView>
#include <QLabel>
#include <QTimer>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QByteArray>

CPU_MainWindow::CPU_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CPU_MainWindow)
{
    ui->setupUi(this);
    global_setStyleSheet();
    QSizePolicy policy_00_Fixed_Fixed;
    policy_00_Fixed_Fixed.setHorizontalStretch(0);
    policy_00_Fixed_Fixed.setVerticalStretch(0);
    policy_00_Fixed_Fixed.setHorizontalPolicy(QSizePolicy::Fixed);
    policy_00_Fixed_Fixed.setVerticalPolicy(QSizePolicy::Fixed);
    //73 27
    qint8 wid1 = 85, hig1 = 30;
    //qint8 wid_CXXZ_B = 73, hig_CXXZ_B = 30;
    qint32 wid_JGFX = 140, hig_JGFX = 32;
    qint32 wid_Edit = 120, hig_Edit = 30;//120 27
    //qint32 wid_CXXZ_B_Edit = 119, hig_CXXZ_B_Edit = 30;
    qint32 wid_Code_Text = 102, hig_Code_Text = 213;
    qint32 Wid_JGFX_Info = 60, hig_JGFX_Info = 60;


    this->setMinimumSize(950, 700);
    bg_Widget = new QWidget(this);
    bg_Widget->setObjectName(QStringLiteral("bg_Widget"));
    bg_Widget->setSizePolicy(policy_00_Fixed_Fixed);
    bg_Widget->setMinimumSize(950, 700);
    bg_Widget->setMaximumSize(950, 700);
    bg_Widget->setStyleSheet("QWidget#bg_Widget{"
                                 "border-image: url(:/images/CPU_Background.png)}");

    // chengxu xuanze in Code Produce
    CXXZ_BUtton = new QPushButton(this);
    CXXZ_BUtton->setObjectName(QStringLiteral("CXXZ_BUtton"));
    CXXZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton->move(35,82);//35 85
    CXXZ_BUtton->resize(wid1-5,hig1);
    CXXZ_BUtton->setText("待加固程序");
    CXXZ_BUtton->setFont(QFont("Microsoft Yahei",14,60));//12 60
    CXXZ_BUtton->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton->setIconSize(QSize(5, 5));//10 10



    // daima shengcheng label in Code Produce
    DMSC_Label = new QLineEdit(this);
    DMSC_Label->setObjectName(QStringLiteral("DMSC_Label"));
    DMSC_Label->setSizePolicy(policy_00_Fixed_Fixed);
    DMSC_Label->move(117,82);
    DMSC_Label->resize(wid_Edit,hig_Edit);
    DMSC_Label->setPlaceholderText("点击左侧选择程序");
    DMSC_Label->setFocusPolicy(Qt::NoFocus);
    DMSC_Label->setFont(QFont("Microsoft Yahei",11,60));

    // biaoqian kuozhan
    BQKZ_BUtton = new QPushButton(this);
    BQKZ_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    BQKZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    BQKZ_BUtton->move(247,82);
    BQKZ_BUtton->resize(wid1,hig1);
    BQKZ_BUtton->setText("标签插桩");
    BQKZ_BUtton->setFont(QFont("Microsoft Yahei",15,60));
    BQKZ_BUtton->setIcon(QIcon(":/images/CWMN_Icon.png"));
    BQKZ_BUtton->setIconSize(QSize(10, 10));

    Code_Text1 = new QTextEdit(this);
    Code_Text1->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text1->move(36, 121);
    Code_Text1->resize(wid_Code_Text,hig_Code_Text);
    Code_Text1->setPlaceholderText("暂无代码");
    Code_Text1->setFocusPolicy(Qt::NoFocus);

    Code_Text2 = new QTextEdit(this);
    Code_Text2->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text2->move(143, 121);
    Code_Text2->resize(wid_Code_Text,hig_Code_Text);
    Code_Text2->setPlaceholderText("暂无代码");
    Code_Text2->setFocusPolicy(Qt::NoFocus);

    Code_Text3 = new QTextEdit(this);
    Code_Text3->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text3->move(250, 121);
    Code_Text3->resize(wid_Code_Text,hig_Code_Text);
    Code_Text3->setPlaceholderText("暂无代码");
    Code_Text3->setFocusPolicy(Qt::NoFocus);

    Code_Text4 = new QTextEdit(this);
    Code_Text4->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text4->move(356, 121);
    Code_Text4->resize(wid_Code_Text,hig_Code_Text);
    Code_Text4->setPlaceholderText("暂无代码");
    Code_Text4->setFocusPolicy(Qt::NoFocus);

    //original program
    o_BUtton = new QPushButton(this);
    o_BUtton->setObjectName(QStringLiteral("o_BUtton"));
    o_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    o_BUtton->move(73,115);//35 85
    o_BUtton->resize(30,12);
    o_BUtton->setText("源程序");
    o_BUtton->setFont(QFont("Microsoft Yahei",8,60));

    //middle program
    m_BUtton = new QPushButton(this);
    m_BUtton->setObjectName(QStringLiteral("m_BUtton"));
    m_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    m_BUtton->move(178,115);//35 85
    m_BUtton->resize(35,12);
    m_BUtton->setText("中间代码");
    m_BUtton->setFont(QFont("Microsoft Yahei",8,60));

    //jiagu program
    j_BUtton = new QPushButton(this);
    j_BUtton->setObjectName(QStringLiteral("j_BUtton"));
    j_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    j_BUtton->move(280,115);//35 85
    j_BUtton->resize(42,12);
    j_BUtton->setText("加固后代码");
    j_BUtton->setFont(QFont("Microsoft Yahei",8,60));
    //j_BUtton->setFlat(true);//按钮透明

    //process result
    r_BUtton = new QPushButton(this);
    r_BUtton->setObjectName(QStringLiteral("r_BUtton"));
    r_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    r_BUtton->move(388,115);//35 85
    r_BUtton->resize(35,12);
    r_BUtton->setText("过程结果");
    r_BUtton->setFont(QFont("Microsoft Yahei",8,60));


    connect(CXXZ_BUtton, &QPushButton::clicked, this, [=]()
    {
        jg_benchpath=QFileDialog::getOpenFileName(this,"待加固程序","/home/yy2/Desktop/qt/TestPrograms","*");
        QString directory = jg_benchpath;
//        QString directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/res/tt/arm_test_hot",tr("*.c*"));
        bool jgfg=directory.isEmpty();
        if(jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        else
            readCode(directory);
    });

    connect(BQKZ_BUtton, &QPushButton::clicked, this, [=]()
    {
        BQKZ_BUtton_func();
    });

    // chengxu xuanze in Error Mimic
    CXXZ_BUtton_R = new QPushButton(this);
    CXXZ_BUtton_R->setObjectName(QStringLiteral("CXXZ_BUtton_R"));
    CXXZ_BUtton_R->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton_R->move(493,85);
    CXXZ_BUtton_R->resize(wid1-10,hig1);
    CXXZ_BUtton_R->setText("ARM程序");
    CXXZ_BUtton_R->setFont(QFont("Microsoft Yahei",15,60));
    CXXZ_BUtton_R->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton_R->setIconSize(QSize(5,5));

    // cuowu moni label in Error Mimic
    CWMN_Label = new QLineEdit(this);
    CWMN_Label->setObjectName(QStringLiteral("CWMN_Label"));
    CWMN_Label->setSizePolicy(policy_00_Fixed_Fixed);
    CWMN_Label->move(574,85);
    CWMN_Label->resize(wid_Edit,hig_Edit);
    CWMN_Label->setPlaceholderText("点击左侧选择程序");
    CWMN_Label->setFocusPolicy(Qt::NoFocus);
    CWMN_Label->setFont(QFont("Microsoft Yahei",11,60));

    // moni cishu input in Error Mimic
    MNCS_Edit = new QTextEdit(this);
    MNCS_Edit->setSizePolicy(policy_00_Fixed_Fixed);
    MNCS_Edit->move(706,85);
    MNCS_Edit->resize(wid_Edit,hig_Edit);
    MNCS_Edit->setPlaceholderText("请输入故障注入次数");
    MNCS_Edit->setFont(QFont("Microsoft Yahei",11,60));

    // cuowu moni button
    CWMN_BUtton = new QPushButton(this);
    CWMN_BUtton->setObjectName(QStringLiteral("CWMN_BUtton"));
    CWMN_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    CWMN_BUtton->move(830,85);
    CWMN_BUtton->resize(wid1,hig1);
    CWMN_BUtton->setText("故障注入");
    CWMN_BUtton->setFont(QFont("Microsoft Yahei",15,60));
    CWMN_BUtton->setIcon(QIcon(":/images/CWMN_Icon.png"));
    CWMN_BUtton->setIconSize(QSize(10, 10));

    Code_Text5 = new QTextEdit(this);
    Code_Text5->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text5->move(813, 122);
    Code_Text5->resize(wid_Code_Text,hig_Code_Text);
    Code_Text5->setPlaceholderText("暂无代码");
    Code_Text5->setFocusPolicy(Qt::NoFocus);


    connect(CXXZ_BUtton_R, &QPushButton::clicked, this, [=]()
    {
        gzzr_benchpath=QFileDialog::getOpenFileName(this,"ARM程序","/home/yy2/Desktop/qt/TestPrograms/datamanage","*");
        QString directory= gzzr_benchpath;
        bool jgfg=directory.isEmpty();
        if(jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        else {
            QStringList name_list = directory.split('/');
            QString file_name = name_list[name_list.count()-1];
            this->CWMN_Label->setText(file_name);
        }

        QString str = gzzr_benchpath;
        QStringList list =str.split("/");
        QString filename =list[list.length()-1];//cut down the path, just leave the filename
        CWMN_Label->setText(filename);
    });

    connect(CWMN_BUtton, &QPushButton::clicked, this, [=]()
    {
        Code_Text5->clear();
        if(CWMN_Label->text()==""){
            Code_Text5->setText("请选择ARM程序！");
        }else if(MNCS_Edit->toPlainText()==""){
            Code_Text5->setText("故障注入次数不可为空！");
        }else{
            Code_Text5->append("<font color=\"#ffffff\"> 初始化……</font>");
            QByteArray ba = MNCS_Edit->toPlainText().toLatin1();
            const char *s = ba.data();
            while(*s && *s>='0' && *s<='9') s++;
            if(*s)
            {
                Code_Text5->setText("请输入正整数");
            }
            else{
                int tmp = MNCS_Edit->toPlainText().toInt();
                if(tmp<100)
                    Code_Text5->setText("请输入大于100的正整数");
                else if(tmp>1000)
                    Code_Text5->setText("请输入小于1000的正整数");
                else{
                    sumnumber = tmp;
                    Code_Text5->append("<font color=\"#ffffff\"> 初始化……</font>");
                    QString runtimes = MNCS_Edit->toPlainText();
                    QString FItype = "r";//故障注入方式r表示随机故障注入 p表示程序内故障注入
                    QString str = gzzr_benchpath;
                    QString input = "input_small.dat";
                    QProcess *run1=new QProcess;
                    run1->setWorkingDirectory("/home/yy2/Desktop/qt/CPUControl/fault_inject");
                    QStringList arg;
                    arg << str << input << runtimes << FItype <<"3";
                    run1->start("./auto.sh",arg);

                    run1->waitForFinished(-1);
                    QString s1 = run1->readAllStandardOutput();
                    gzzr_count=runtimes;
                    for(int i=0;i<gzzr_count.toInt();i++){
                        float fr=i+1;
                        float process_num=fr/gzzr_count.toInt();
                        Code_Text5->append("<font color=\"#ffffff\"> 注入次数："+QString::number(i+1)+"   ==>>进度：</font>"+"<font color=\"#00ff00\">"+QString::number(process_num*100,'f',0)+"%</font>");
                    }
                    Code_Text5->append("<font color=\"#ffffff\"> 故障注入完毕！！！ </font>");
                }
            }
        }


    });


    // TABLE in Error Mimic

    model = new QStandardItemModel(10, 5);
    tableView = new QTableView(this);
    tableView->setSizePolicy(policy_00_Fixed_Fixed);
    tableView->setModel(model);
    tableView->move(493, 120);
    tableView->resize(210,218);

    model->setHeaderData(0, Qt::Horizontal, tr("部件名"));
    model->setHeaderData(1, Qt::Horizontal, tr("起始地址"));
    model->setHeaderData(2, Qt::Horizontal, tr("翻转位数"));
    model->setHeaderData(3, Qt::Horizontal, tr("方式"));
    model->setHeaderData(4, Qt::Horizontal, tr("时间"));

    QModelIndex index = model->index(0, 0, QModelIndex());
    model->setData(index, QVariant("部件名"));
    index = model->index(1, 0, QModelIndex());
    model->setData(index, QVariant("条件标志"));
    index = model->index(2, 0, QModelIndex());
    model->setData(index, QVariant("内部通用寄存器"));
    index = model->index(3, 0, QModelIndex());
    model->setData(index, QVariant("内部专用寄存器"));
    index = model->index(4, 0, QModelIndex());
    model->setData(index, QVariant("指令指针寄存器"));
    index = model->index(5, 0, QModelIndex());
    model->setData(index, QVariant("指令缓冲寄存器"));
    index = model->index(6, 0, QModelIndex());
    model->setData(index, QVariant("指令译码器"));
    index = model->index(7, 0, QModelIndex());
    model->setData(index, QVariant("运算器"));


    index = model->index(0, 1, QModelIndex());
    model->setData(index, QVariant("起始地址"));
    index = model->index(0, 2, QModelIndex());
    model->setData(index, QVariant("翻转位数"));
    index = model->index(0, 3, QModelIndex());
    model->setData(index, QVariant("方式"));
    index = model->index(0, 4, QModelIndex());
    model->setData(index, QVariant("时间"));

    index = model->index(1, 1, QModelIndex());
    model->setData(index, QVariant("0x0012"));
    index = model->index(2, 1, QModelIndex());
    model->setData(index, QVariant("0x006A"));
    index = model->index(3, 1, QModelIndex());
    model->setData(index, QVariant("0x0101"));
    index = model->index(4, 1, QModelIndex());
    model->setData(index, QVariant("0x0149"));
    index = model->index(5, 1, QModelIndex());
    model->setData(index, QVariant("0x021C"));
    index = model->index(6, 1, QModelIndex());
    model->setData(index, QVariant("0x02A5"));
    index = model->index(7, 1, QModelIndex());
    model->setData(index, QVariant("0x031D"));


    for (int row=1; row < 8; row++)
        for (int col=1; col < 5; col++)
        {
            int n = qrand()%3+1;
            int f = qrand()%2;
            int t = qrand()%100+1;
            index = model->index(row, col, QModelIndex());
            if (col == 2)
                model->setData(index, n);
            if (col == 3)
                model->setData(index, f);
            if (col > 3)
                model->setData(index, t);
        }


    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->hide();
    tableView->verticalHeader()->hide();
    tableView->setFont(QFont("Microsoft Yahei",11,60));

    CWFGL_Lable1 = new QPushButton(this);
    CWFGL_Lable1->setObjectName(QStringLiteral("CWFGL_Lable1"));
    CWFGL_Lable1->setSizePolicy(policy_00_Fixed_Fixed);
    CWFGL_Lable1->move(708, 123);
    CWFGL_Lable1->resize(25, 20);
    CWFGL_Lable1->setText("故障");
    CWFGL_Lable1->setFont(QFont("Microsoft Yahei",11,60));

    CWFGL_Lable2 = new QPushButton(this);
    CWFGL_Lable2->setObjectName(QStringLiteral("CWFGL_Lable2"));
    CWFGL_Lable2->setSizePolicy(policy_00_Fixed_Fixed);
    CWFGL_Lable2->move(770, 123);
    CWFGL_Lable2->resize(39, 20);
    CWFGL_Lable2->setText("覆盖率");
    CWFGL_Lable2->setFont(QFont("Microsoft Yahei",11,60));

    CWFGL_Val = new QPushButton(this);
    CWFGL_Val->setObjectName(QStringLiteral("CWFGL_Val"));
    CWFGL_Val->setSizePolicy(policy_00_Fixed_Fixed);
    CWFGL_Val->move(738, 171);
    CWFGL_Val->resize(40, 39);
    CWFGL_Val->setText("71%");
    CWFGL_Val->setFont(QFont("Microsoft Yahei",16,60));


    Block_A = new QPushButton(this);
    Block_A->setObjectName(QStringLiteral("Block_A"));
    Block_A->setSizePolicy(policy_00_Fixed_Fixed);
    Block_A->move(720, 257);
    Block_A->resize(16, 7);


    Block_B = new QPushButton(this);
    Block_B->setObjectName(QStringLiteral("Block_B"));
    Block_B->setSizePolicy(policy_00_Fixed_Fixed);
    Block_B->move(720, 275);
    Block_B->resize(16, 7);

    Block_C = new QPushButton(this);
    Block_C->setObjectName(QStringLiteral("Block_C"));
    Block_C->setSizePolicy(policy_00_Fixed_Fixed);
    Block_C->move(720, 292);
    Block_C->resize(16, 7);

    Block_D = new QPushButton(this);
    Block_D->setObjectName(QStringLiteral("Block_D"));
    Block_D->setSizePolicy(policy_00_Fixed_Fixed);
    Block_D->move(720, 309);
    Block_D->resize(16, 7);


    QTimer *timerA = new QTimer(this);
    connect(timerA, &QTimer::timeout, this ,[=]()
    {
        Block_A->animateClick(100);
    });
    timerA->start(1000);

    QTimer *timerB = new QTimer(this);
    connect(timerB, &QTimer::timeout, this ,[=]()
    {
        Block_B->animateClick(100);
    });
    timerB->start(1100);

    QTimer *timerC = new QTimer(this);
    connect(timerC, &QTimer::timeout, this ,[=]()
    {
        Block_C->animateClick(100);
    });
    timerC->start(1200);

    QTimer *timerD = new QTimer(this);
    connect(timerD, &QTimer::timeout, this ,[=]()
    {
        Block_D->animateClick(100);
    });
    timerD->start(1300);

    monitor_ItemA = new QPushButton(this);
    monitor_ItemA->setObjectName(QStringLiteral("monitor_ItemA"));
    monitor_ItemA->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemA->move(736, 252);
    monitor_ItemA->resize(70, 15);
    monitor_ItemA->setText("条件标志 14%");
    monitor_ItemA->setFont(QFont("Microsoft Yahei",10,60));

    monitor_ItemB = new QPushButton(this);
    monitor_ItemB->setObjectName(QStringLiteral("monitor_ItemB"));
    monitor_ItemB->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemB->move(736, 270);
    monitor_ItemB->resize(70, 15);
    monitor_ItemB->setText("寄存器 57%");
    monitor_ItemB->setFont(QFont("Microsoft Yahei",10,60));


    monitor_ItemC = new QPushButton(this);
    monitor_ItemC->setObjectName(QStringLiteral("monitor_ItemC"));
    monitor_ItemC->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemC->move(736, 288);
    monitor_ItemC->resize(70, 15);
    monitor_ItemC->setText("译码器 14%");
    monitor_ItemC->setFont(QFont("Microsoft Yahei",10,60));


    monitor_ItemD = new QPushButton(this);
    monitor_ItemD->setObjectName(QStringLiteral("monitor_ItemD"));
    monitor_ItemD->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemD->move(736, 306);
    monitor_ItemD->resize(70, 15);
    monitor_ItemD->setText("运算器 15%");
    monitor_ItemD->setFont(QFont("Microsoft Yahei",10,60));



    // Result Analysis button
    JGFX_BUtton = new QPushButton(this);
    JGFX_BUtton->setObjectName(QStringLiteral("JGFX_BUtton"));
    JGFX_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_BUtton->move(35,415);
    JGFX_BUtton->resize(wid_JGFX,hig_JGFX);
    JGFX_BUtton->setText("结果分析");
    JGFX_BUtton->setFont(QFont("Microsoft Yahei",17,60));
    JGFX_BUtton->setIcon(QIcon(":/images/JGFX_Icon.png"));
    JGFX_BUtton->setIconSize(QSize(10, 10));


    // info label in Result Analysis
    JGFX_MNCS_Label = new QPushButton(this);
    JGFX_MNCS_Label->setObjectName(QStringLiteral("JGFX_MNCS_Label"));
    JGFX_MNCS_Label->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_MNCS_Label->move(75,537);
    JGFX_MNCS_Label->resize(Wid_JGFX_Info, hig_JGFX_Info);
    JGFX_MNCS_Label->setText("0");
    JGFX_MNCS_Label->setFont(QFont("Microsoft Yahei",30,60));

    JGFX_CWCS_Label = new QPushButton(this);
    JGFX_CWCS_Label->setObjectName(QStringLiteral("JGFX_CWCS_Label"));
    JGFX_CWCS_Label->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_CWCS_Label->move(225,537);
    JGFX_CWCS_Label->resize(Wid_JGFX_Info, hig_JGFX_Info);
    JGFX_CWCS_Label->setText("0");
    JGFX_CWCS_Label->setFont(QFont("Microsoft Yahei",30,60));

    JGFX_QTCW_Label = new QPushButton(this);
    JGFX_QTCW_Label->setObjectName(QStringLiteral("JGFX_QTCW_Label"));
    JGFX_QTCW_Label->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_QTCW_Label->move(377,537);
    JGFX_QTCW_Label->resize(Wid_JGFX_Info, hig_JGFX_Info);
    JGFX_QTCW_Label->setText("0");
    JGFX_QTCW_Label->setFont(QFont("Microsoft Yahei",30,60));

    JGFX_JCL_Label = new QPushButton(this);
    JGFX_JCL_Label->setObjectName(QStringLiteral("JGFX_JCL_Label"));
    JGFX_JCL_Label->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_JCL_Label->move(500,537);
    JGFX_JCL_Label->resize(Wid_JGFX_Info+45, hig_JGFX_Info);
    JGFX_JCL_Label->setText("0%");
    JGFX_JCL_Label->setFont(QFont("Microsoft Yahei",30,60));


    //圆饼百分比
    monitor_ItemA_val = new QPushButton(this);
    monitor_ItemA_val->setObjectName(QStringLiteral("monitor_ItemA_val"));
    monitor_ItemA_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemA_val->move(648, 493);
    monitor_ItemA_val->resize(36, 20);
    monitor_ItemA_val->setText("28%");
    monitor_ItemA_val->setFont(QFont("Microsoft Yahei",11,60));

    A = new QPushButton(this);
    A->setObjectName(QStringLiteral("A"));
    A->setSizePolicy(policy_00_Fixed_Fixed);
    A->move(648, 471);
    A->resize(44, 20);
    A->setText("时间超时");
    A->setFont(QFont("Microsoft Yahei",9,60));
    A->setStyleSheet("color: darkorange");

    monitor_ItemB_val = new QPushButton(this);
    monitor_ItemB_val->setObjectName(QStringLiteral("monitor_ItemB_val"));
    monitor_ItemB_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemB_val->move(626, 582);
    monitor_ItemB_val->resize(36, 20);
    monitor_ItemB_val->setText("28%");
    monitor_ItemB_val->setFont(QFont("Microsoft Yahei",11,60));


    B = new QPushButton(this);
    B->setObjectName(QStringLiteral("B"));
    B->setSizePolicy(policy_00_Fixed_Fixed);
    B->move(626, 560);
    B->resize(50, 20);
    B->setText("检测到错误");
    B->setFont(QFont("Microsoft Yahei",9,60));
    B->setStyleSheet("color: forestgreen");

    monitor_ItemC_val = new QPushButton(this);
    monitor_ItemC_val->setObjectName(QStringLiteral("monitor_ItemC_val"));
    monitor_ItemC_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemC_val->move(855, 503);
    monitor_ItemC_val->resize(36, 20);
    monitor_ItemC_val->setText("28%");
    monitor_ItemC_val->setFont(QFont("Microsoft Yahei",11,60));

    C = new QPushButton(this);
    C->setObjectName(QStringLiteral("C"));
    C->setSizePolicy(policy_00_Fixed_Fixed);
    C->move(855, 481);
    C->resize(55, 20);
    C->setText("未检测到错误");
    C->setFont(QFont("Microsoft Yahei",9,60));
    C->setStyleSheet("color: darkturquoise");


    monitor_ItemD_val = new QPushButton(this);
    monitor_ItemD_val->setObjectName(QStringLiteral("monitor_ItemD_val"));
    monitor_ItemD_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemD_val->move(859, 613);
    monitor_ItemD_val->resize(36, 20);
    monitor_ItemD_val->setText("28%");
    monitor_ItemD_val->setFont(QFont("Microsoft Yahei",11,60));

    D = new QPushButton(this);
    D->setObjectName(QStringLiteral("D"));
    D->setSizePolicy(policy_00_Fixed_Fixed);
    D->move(859, 591);
    D->resize(44, 20);
    D->setText("正确执行");
    D->setFont(QFont("Microsoft Yahei",9,60));
    D->setStyleSheet("color: dodgerblue");


    connect(JGFX_BUtton, &QPushButton::clicked, this, [=]()
    {
        QProcess *run=new QProcess;
        run->setWorkingDirectory("/home/yy2/Desktop/qt/CPUControl/fault_inject/");
        //run->start("python3 /home/yy2/Desktop/qt/CPUControl/fault_inject/statistics.py inject.output inject.correct");
        run->start("python3 /home/yy2/Desktop/qt/CPUControl/fault_inject/statistics.py inject.output inject.correct");
        run->waitForFinished();
        QString res = run->readAllStandardOutput();
        qDebug()<<res;
        QStringList res_list = res.split('\n');
        QString mncs_num = res_list[0].split(':')[1];
        QString cwcs_num = res_list[1].split(':')[1];
        QString qt_num = res_list[2].split(':')[1];
        QString jcl_num = res_list[3].split(':')[1];


        JGFX_MNCS_Label->setText(mncs_num);
        JGFX_MNCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_CWCS_Label->setText(cwcs_num);
        JGFX_CWCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_QTCW_Label->setText(qt_num);
        JGFX_QTCW_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_JCL_Label->setText(jcl_num);
        JGFX_JCL_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_BUtton->blockSignals(true);

        monitor_ItemA_val->setText("0%");
        monitor_ItemA_val->setFont(QFont("Microsoft Yahei",11,60));
        monitor_ItemB_val->setText("46%");
        monitor_ItemB_val->setFont(QFont("Microsoft Yahei",11,60));
        monitor_ItemC_val->setText("3%");
        monitor_ItemC_val->setFont(QFont("Microsoft Yahei",11,60));
        monitor_ItemD_val->setText("51%");
        monitor_ItemD_val->setFont(QFont("Microsoft Yahei",11,60));

    });



}

CPU_MainWindow::~CPU_MainWindow()
{
    delete ui;
}
void CPU_MainWindow::global_setStyleSheet() {
    this->setStyleSheet("QPushButton#CXXZ_BUtton, #BQKZ_BUtton, #CXXZ_BUtton_R,#A,#B,#C,#D,"
                        "#CWMN_BUtton, #CXXZ_BUtton_B, #JGFX_BUtton, #o_BUtton,#r_BUtton,"
                        "#Block_A, #Block_B, #Block_C, #Block_D,#m_BUtton,#j_BUtton,"
                        "#monitor_ItemA_val, #monitor_ItemB_val,"
                        "#monitor_ItemC_val, #monitor_ItemD_val,"
                        "#monitor_ItemA,#monitor_ItemB,"
                        "#monitor_ItemC, #monitor_ItemD,"
                        "#JGFX_MNCS_Label, #JGFX_CWCS_Label,"
                        "#JGFX_QTCW_Label, #JGFX_JCL_Label,"
                        "#CWFGL_Lable1, #CWFGL_Lable2, #CWFGL_Val{"
                        "background-color:rgba(20,32,84, 1);"
                        "color:#24FDFF;"
                        "border: 1px solid #02246c;"
                        "}"
                        "QPushButton#CXXZ_BUtton:hover, #BQKZ_BUtton:hover,#CXXZ_BUtton_R:hover,"
                        "#CWMN_BUtton:hover, #CXXZ_BUtton_B:hover, #JGFX_BUtton:hover{"
                        "background-color:rgba(40,40,160, 1)"
                        "}"
                        "QPushButton#CXXZ_BUtton:pressed, #BQKZ_BUtton:pressed,#CXXZ_BUtton_R:pressed,"
                        "#CWMN_BUtton:pressed, #CXXZ_BUtton_B:pressed, #JGFX_BUtton:pressed,"
                        "#Block_A:pressed, #Block_B:pressed, #Block_C:pressed, #Block_D:pressed{"
                        "background-color:#00D688;"
                        "}"
                        "QPushButton#monitor_ItemA,#monitor_ItemB,"
                        "#monitor_ItemC, #monitor_ItemD{"
                        "background-color:rgba(20,32,84, 1);"
                        "color:#24FDFF;"
                        "}"
                        "QLineEdit{"
                        "background-color:#142054;"
                        "border: 1px solid #0F7CDE;"
                        "color:#24FDFF;"
                        "}"
                        "QTextEdit{"
                        "background-color:#142054;"
                        "border: 1px solid #20ABFF;"
                        "color:#24FDFF;"
                        "}"
                        "QTableView{"
                        "background-color:#142054;"
                        "border: 1px solid #20ABFF;"
                        "color:#24FDFF;"
                        "}");
}



void CPU_MainWindow::readCode(QString directory)
{
    QStringList name_list = directory.split('/');
    QString file_name = name_list[name_list.count()-1];

    QStringList list = directory.split('.');
    if (list[list.count()-1] == "c" || list[list.count()-1] == "cpp") {
        QFile file(directory);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           QMessageBox::warning(this,"警告","无法打开该文件！");
        }
        qint32 linecnt = 0;
        QString str1;
        QStringList str_list;
        QByteArray line;
        while (!file.atEnd()) {
            line = file.readLine();
            str_list.append((QString)line);
            linecnt++;
        }
        file.close();
        for (int i = 0; i < linecnt; i++) {
             str1 += str_list[i];

        }
        this->Code_Text1->setText(str1);
        this->DMSC_Label->setText(file_name);
    }
    else {
        QMessageBox::warning(this,"警告","请选择c/cpp");
    }
}

void CPU_MainWindow::BQKZ_BUtton_func()
{
    Code_Text4->clear();
    Code_Text4->setStyleSheet("QTextBrowser{color:white;"
                                     "background-color:rgba(243,243,243,40);"
                                     "border-color:rgba(243,243,243,30);"
                                     "}");
    Code_Text4->setFont(QFont("Microsoft Yahei",11,60));
    QString str2 = jg_benchpath;
    QStringList list =str2.split("/");
    QString filename =list[list.length()-1];
    jg_file = filename.left(filename.length()-2);

    qDebug()<<"/home/yy2/Desktop/qt/TestPrograms/"+jg_file+".ll";


    if(str2.trimmed()==""){
        Code_Text4->setText("待加固程序不能为空");
        return;
    }

    QProcess *run=new QProcess;
    run->setWorkingDirectory("/home/yy2/Desktop/qt/TestPrograms/");
    //run->start("/home/yy2/Desktop/qt/TestPrograms/Preprocess.sh "+str2);
    run->start("/home/yy2/Desktop/qt/TestPrograms/Preprocess.sh "+str2);
    run->waitForFinished(-1);
    QString res = run->readAllStandardOutput();
    Code_Text4->setText(res);

    QProcess *run2=new QProcess;
    run2->setWorkingDirectory("/home/yy2/Desktop/qt/.Testprograms/");
    run2->start("/home/yy2/Desktop/qt/.Testprograms/Preprocess.sh "+str2);
    run2->waitForFinished(-1);
    run2->start("clang cfcss.ll --target=arm-v7-linux-gnueabi -c -o dm_df.o");
    //arm-linux-gnueabi-gcc dm_df.o exec.o -static -o dm_df
    //run2->start("arm-linux-gnueabi-gcc dm_df.o -static -g -o datamanage/datamanage_cf");
    run2->waitForFinished(-1);
    run2->start("arm-linux-gnueabi-gcc dm_df.o -static -g -o "+jg_file+"/"+jg_file+"_cf");

    QString jg_llfilepath = "/home/yy2/Desktop/qt/TestPrograms/"+jg_file+".ll";
    qDebug()<<jg_llfilepath;
    QFile file(jg_llfilepath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
       QMessageBox::warning(this,"警告","无法打开该文件！");
    }
    qint32 linecnt = 0, str_num=0;
    QString str1, str_h;
    QStringList str_list;
    QByteArray line;
    while (!file.atEnd()) {
        line = file.readLine();
        str_list.append((QString)line);
        linecnt++;
    }
    file.close();
    str_num = linecnt*0.5;
    for (int i = 0; i < linecnt; i++) {
        if (i <= str_num )
        {
            str1 += str_list[i];
        }
        else{
            str_h += str_list[i];
        }
    }
    this->Code_Text2->setText(str1);
    this->Code_Text3->setText(str_h);


    Code_Text4->setText("标签插桩完成,生成可执行程序！");
}
