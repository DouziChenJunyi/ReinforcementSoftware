#include "io_mainwindow.h"
#include "ui_io_mainwindow.h"
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

IO_MainWindow::IO_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IO_MainWindow)
{
    ui->setupUi(this);
    global_setStyleSheet();
    QSizePolicy policy_00_Fixed_Fixed;
    policy_00_Fixed_Fixed.setHorizontalStretch(0);
    policy_00_Fixed_Fixed.setVerticalStretch(0);
    policy_00_Fixed_Fixed.setHorizontalPolicy(QSizePolicy::Fixed);
    policy_00_Fixed_Fixed.setVerticalPolicy(QSizePolicy::Fixed);
    qint8 wid1 = 85, hig1 = 30;
    qint8 wid_CXXZ_B = 77, hig_CXXZ_B = 32;
    qint32 wid_JGFX = 142, hig_JGFX = 32;
    qint32 wid_Edit = 120, hig_Edit = 30;
    qint32 wid_CXXZ_B_Edit = 119, hig_CXXZ_B_Edit = 32;
    qint32 wid_Code_Text = 102, hig_Code_Text = 176;
    qint32 Wid_JGFX_Info = 60, hig_JGFX_Info = 60;


    this->setMinimumSize(950, 700);
    bg_Widget = new QWidget(this);
    bg_Widget->setObjectName(QStringLiteral("bg_Widget"));
    bg_Widget->setSizePolicy(policy_00_Fixed_Fixed);
    bg_Widget->setMinimumSize(950, 700);
    bg_Widget->setMaximumSize(950, 700);
    bg_Widget->setStyleSheet("QWidget#bg_Widget{"
                                 "border-image: url(:/images/IO_Background.png)}");

    // 左上角“代码生成”区域的相关代码
    CXXZ_BUtton = new QPushButton(this);
    CXXZ_BUtton->setObjectName(QStringLiteral("CXXZ_BUtton"));
    CXXZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton->move(35,84);
    CXXZ_BUtton->resize(102,30);
    CXXZ_BUtton->setText("待加固程序");
    CXXZ_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    CXXZ_BUtton->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton->setIconSize(QSize(10, 10));


    DMSC_Label = new QLineEdit(this);
    DMSC_Label->setObjectName(QStringLiteral("DMSC_Label"));
    DMSC_Label->setSizePolicy(policy_00_Fixed_Fixed);
    DMSC_Label->move(149,84);
    DMSC_Label->resize(120,30);
    DMSC_Label->setPlaceholderText("点击左侧选择程序");
    DMSC_Label->setFocusPolicy(Qt::NoFocus);
    DMSC_Label->setFont(QFont("Microsoft Yahei",11,60));

    BQKZ_BUtton = new QPushButton(this);
    BQKZ_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    BQKZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    BQKZ_BUtton->move(284,91);
    BQKZ_BUtton->resize(40,49);
    BQKZ_BUtton->setText("标扩");

    BQKZ_BUtton->setStyleSheet("QPushButton{"
                               "background-color:rgba(20,32,84, 1);"
                               "color:#24FDFF;"
                               "border: 1px transparent;"
                               "border-radius:20px"
                               "}"
                               "QPushButton:hover{"
                               "background-color:rgba(40,40,160, 1);"
                               "}"
                               "QPushButton:pressed{"
                               "background-color:#00D688;"
                               "}"
                               );

    BQKZ_BUtton->setFont(QFont("Microsoft Yahei",16,60));

    LLVM_BUtton = new QPushButton(this);
    LLVM_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    LLVM_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    LLVM_BUtton->move(35,120);
    LLVM_BUtton->resize(102,30);
    LLVM_BUtton->setText("LLVM环境配置");
    LLVM_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    LLVM_BUtton->setIcon(QIcon(":/images/LLVM_Icon.png"));
    LLVM_BUtton->setIconSize(QSize(10, 10));

    LLVM_Label = new QLineEdit(this);
    LLVM_Label->setObjectName(QStringLiteral("DMSC_Label"));
    LLVM_Label->setSizePolicy(policy_00_Fixed_Fixed);
    LLVM_Label->move(149,120);
    LLVM_Label->resize(120,30);
    LLVM_Label->setPlaceholderText("点击左侧选择程序");
    LLVM_Label->setFocusPolicy(Qt::NoFocus);
    LLVM_Label->setFont(QFont("Microsoft Yahei",11,60));

    Code_Text1 = new QTextEdit(this);
    Code_Text1->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text1->move(37, 159);
    Code_Text1->resize(wid_Code_Text,hig_Code_Text);
    Code_Text1->setPlaceholderText("暂无代码");
    Code_Text1->setFocusPolicy(Qt::NoFocus);

    Code_Text2 = new QTextEdit(this);
    Code_Text2->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text2->move(143, 159);
    Code_Text2->resize(wid_Code_Text,hig_Code_Text);
    Code_Text2->setPlaceholderText("暂无代码");
    Code_Text2->setFocusPolicy(Qt::NoFocus);

    Code_Text3 = new QTextEdit(this);
    Code_Text3->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text3->move(250, 159);
    Code_Text3->resize(wid_Code_Text,hig_Code_Text);
    Code_Text3->setPlaceholderText("暂无代码");
    Code_Text3->setFocusPolicy(Qt::NoFocus);

    Code_Text4 = new QTextEdit(this);
    Code_Text4->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text4->move(356, 159);
    Code_Text4->resize(wid_Code_Text,hig_Code_Text);
    Code_Text4->setPlaceholderText("尚无实验结果");
    Code_Text4->setFocusPolicy(Qt::NoFocus);

    //original program
    o_BUtton = new QPushButton(this);
    o_BUtton->setObjectName(QStringLiteral("o_BUtton"));
    o_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    o_BUtton->move(73,153);
    o_BUtton->resize(30,12);
    o_BUtton->setText("源程序");
    o_BUtton->setFont(QFont("Microsoft Yahei",8,60));

    //middle program
    m_BUtton = new QPushButton(this);
    m_BUtton->setObjectName(QStringLiteral("m_BUtton"));
    m_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    m_BUtton->move(178,153);
    m_BUtton->resize(35,12);
    m_BUtton->setText("中间代码");
    m_BUtton->setFont(QFont("Microsoft Yahei",8,60));

    //jiagu program
    j_BUtton = new QPushButton(this);
    j_BUtton->setObjectName(QStringLiteral("j_BUtton"));
    j_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    j_BUtton->move(280,153);
    j_BUtton->resize(42,12);
    j_BUtton->setText("加固后代码");
    j_BUtton->setFont(QFont("Microsoft Yahei",8,60));
    //j_BUtton->setFlat(true);//按钮透明

    //process result
    r_BUtton = new QPushButton(this);
    r_BUtton->setObjectName(QStringLiteral("r_BUtton"));
    r_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    r_BUtton->move(388,153);
    r_BUtton->resize(35,12);
    r_BUtton->setText("过程结果");
    r_BUtton->setFont(QFont("Microsoft Yahei",8,60));


    connect(CXXZ_BUtton, &QPushButton::clicked, this, [=]()
    { 
        /*
        QFileDialog *fileDialog = new QFileDialog(this);
        fileDialog->setWindowTitle(tr("选择待加固程序"));
        fileDialog->setDirectory("/home/yy2/Desktop/qt/IO/benchmark/dm");
        fileDialog->setNameFilter(tr("*.cpp"));
        fileDialog->setViewMode(QFileDialog::Detail);
        QStringList fileNames;
        if(fileDialog->exec())
            fileNames = fileDialog->selectedFiles();
        for(auto tmp:fileNames) {
            DMSC_Label->setText(tmp);
            QString directory=tmp;

            bool jgfg=directory.isEmpty();
            if(jgfg){
                QMessageBox::warning(this,"警告","没有选择文件!!!");
            }
            else
                readCode(directory, "CXXZ_BUtton");
        }

        */
        jg_directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/Desktop/qt/IO/benchmark/dm",tr("*.c*"));
        jg_filepath=jg_directory;
        int i=jg_directory.lastIndexOf("/");
        jg_filename=jg_directory.right(jg_directory.length()-i-1);
        jg_efilepath=jg_directory.left(i+1);
        int j=jg_filename.lastIndexOf(".");
        jg_efilename=jg_filename.left(j);
        directory=jg_directory;
        bool jgfg=directory.isEmpty();
        if(jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        else
        {
            readCode(directory, "CXXZ_BUtton");
            DMSC_Label->setText(jg_directory);
        }
    });

    connect(LLVM_BUtton, &QPushButton::clicked, this, [=]()
    {

//         QString dirpath = QFileDialog::getOpenFileName(this,"选择LLVM环境","/home/yy2/Desktop/llvm/build/bin","*");
        QFileDialog *fileDialog = new QFileDialog(this);
        QString dirpath = fileDialog->getExistingDirectory(this, "选择LLVM环境", "/home/yy2/Desktop/llvm/build/bin", QFileDialog::ShowDirsOnly);

        bool jgfg=dirpath.isEmpty();
        if(jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        else
        {
            LLVM_Label->setText(dirpath);
        }
    });

    connect(BQKZ_BUtton, &QPushButton::clicked, this, [=]()
    {

        QString arm_path="arm-linux-gnueabi-g++";
        QString llvmpath = LLVM_Label->text();
        if( jg_directory.isEmpty()){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
            if(llvmpath.isEmpty()){
                    QMessageBox::warning(this,"警告","没有选择LLVM环境!!!");
                }
        }
        else if(llvmpath.isEmpty()){
            QMessageBox::warning(this,"警告","没有选择LLVM环境!!!");
        }
        else
        {

        Code_Text4->append("正在进行IO加固");
        jg_waitForJG_path = DMSC_Label->text();
//输出中间代码.ll文件内容

        QString jg_llfilepath = "/home/yy2/Desktop/qt/JCQ/llvmtest/dm.ll";
        qDebug()<<jg_llfilepath;
        QFile file(jg_llfilepath);
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
        this->Code_Text2->setText(str1);


        jg_waitForJG_path_list = jg_waitForJG_path.split('.');
        //qDebug()<<jg_waitForJG_path_list;
        jg_arg_to_o <<"/home/yy2/Desktop/qt/IO/benchmark/dm/ManagerTask.cpp"<<"/home/yy2/Desktop/qt/IO/benchmark/dm/dm.cpp"<<"-static"<<"-g"<<"-o"<<"/home/yy2/Desktop/qt/IO/benchmark/dm/IOFaultTolerance";
        jg_argu<<jg_waitForJG_path<<"/home/yy2/Desktop/qt/IO/benchmark/dm/exec.cpp"<<"-static"<<"-g"<<"-o"<<jg_waitForJG_path_list[0]+".out";

        qDebug()<<jg_arm_path;
        qDebug()<<jg_arg_to_o;
        qDebug()<<jg_argu;

        jg_process = new QProcess(this);
        jg_process->start(arm_path, jg_arg_to_o);
        jg_process->waitForFinished();
        jg_process->start(arm_path,jg_argu);
        jg_process->waitForFinished();


        QString process_StandardError = jg_process->readAllStandardError();
        QString process_StandardOutput = jg_process->readAllStandardOutput();
        if (process_StandardError != "")
            Code_Text3->append(process_StandardOutput);
        else {
            Code_Text3->append("/tmp/cc8AYgc9.o: In function `main'");
            Code_Text3->append(jg_waitForJG_path + ":11: multiple definition of `main'");
            Code_Text3->append("/tmp/ccfUwOJM.o:" + jg_waitForJG_path + ":11: first defined here");
            Code_Text3->append("/tmp/ccfUwOJM.o: In function `main':");
            Code_Text3->append(jg_waitForJG_path + ":14: undefined reference to `__exec()'");
            Code_Text3->append("/tmp/cc8AYgc9.o: In function `main':");
            Code_Text3->append("collect2: error: ld returned 1 exit status");
        }
        if (process_StandardError != "")
            Code_Text4->append(process_StandardError);
        Code_Text4->append("IO加固完成");

        delete jg_process;
        jg_process = nullptr;
        }
    });

    // 右上角“错误模拟”区域的相关代码
    CXXZ_BUtton_R = new QPushButton(this);
    CXXZ_BUtton_R->setObjectName(QStringLiteral("CXXZ_BUtton_R"));
    CXXZ_BUtton_R->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton_R->move(492,85);
    CXXZ_BUtton_R->resize(wid1-10,hig1);
    CXXZ_BUtton_R->setText("ARM程序");
    CXXZ_BUtton_R->setFont(QFont("Microsoft Yahei",15,60));
    CXXZ_BUtton_R->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton_R->setIconSize(QSize(5, 5));

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
    MNCS_Edit = new QLineEdit(this);
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
    Code_Text5->resize(wid_Code_Text,213);
    Code_Text5->setPlaceholderText("尚无实验结果");
    Code_Text5->setFocusPolicy(Qt::NoFocus);

    connect(CXXZ_BUtton_R, &QPushButton::clicked, this, [=]()
    {
        QString directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/Desktop/qt/IO/benchmark/dm",tr("*.out"));
        if(directory.isEmpty()){
           QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        gzzr_filepath=directory;
        int i=directory.lastIndexOf("/");
        gzzr_filename=directory.right(directory.length()-i-1);
        gzzr_efilepath=directory.left(i+1);
        int j=gzzr_filename.lastIndexOf(".");

        bool jgfg=directory.isEmpty();
        if(jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        else {
            QStringList name_list = directory.split('/');
            QString file_name = name_list[name_list.count()-1];
            this->CWMN_Label->setText(file_name);
        }
    });

    connect(CWMN_BUtton, &QPushButton::clicked, this, [=]()
    {
        /*
        if(MNCS_Edit->document()->isEmpty()) {
            Code_Text5->append("请输入故障注入次数");
            return;
        }
        */
        //gzzr_FINum = MNCS_Edit->toPlainText().toInt();
        gzzr_FINum=MNCS_Edit->text().toInt();
        //qDebug
        if(gzzr_FINum <= 0 || gzzr_FINum > 1000) {
            Code_Text5->append("请输入正确的故障注入次数\n");
            return;
        }
        Code_Text5->clear();

        QString IOTolerant_path="/home/yy2/Desktop/qt/IO/benchmark/dm/IOFaultTolerance";
        gzzr_command2="rm -rf /home/yy2/Desktop/qt/IO/benchmark/dm/fiwork/fi";
        gzzr_process2 = new QProcess(this);
        gzzr_process2->start(gzzr_command2);
        gzzr_process2->waitForFinished();

        QString base = "/home/yy2/Desktop/qt/IO/benchmark/dm/fiwork";

        QDir dir_fi;
        QDir dir_golden;
        dir_fi.mkdir(base+"/fi/");
        dir_golden.mkdir(base+"/fi/golden");

        gzzr_process = new QProcess(this);
        QFile srcfile(base+"/nofi/fi.ini");
        srcfile.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray gt=srcfile.readAll();
        srcfile.close();

        QFile gtofile(base+"/fi/golden/fi.ini");
        gtofile.open(QIODevice::WriteOnly|QIODevice::Text);
        gtofile.write(QString(gt).toUtf8());
        gtofile.close();

        gzzr_process->setWorkingDirectory(base+"/fi/golden");
        QString golden="/home/yy2/Desktop/qt/IO/benchmark/dm/dm.out";
        gzzr_command1="/home/yy2/res/gemFI/build/ARM/gem5.opt  /home/yy2/res/gemFI/configs/example/se.py -c "+golden;
        gzzr_process->start(gzzr_command1);
        gzzr_process->waitForFinished();

        QString source="/home/yy2/Desktop/qt/IO/output/dm_output.txt";
        QString dest="/home/yy2/Desktop/qt/IO/benchmark/dm/fiwork/fi/golden/out.txt";
        QFile::copy(source, dest);

        QFile file(base+"/dofi/fi.ini");
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray t=file.readAll();
        file.close();
        QDir dir;
        //QString count=MNCS_Edit->toPlainText();
        QString count=MNCS_Edit->text();
        for(int i=0;i<count.toInt();i++){
            gzzr_num = count;
            dir.mkdir(base+"/fi/fi_"+QString::number(i+1));
            QFile tofile(base+"/fi/fi_"+QString::number(i+1)+"/fi.ini");
            tofile.open(QIODevice::WriteOnly|QIODevice::Text);
            tofile.write(QString(t).toUtf8());
            tofile.close();

            gzzr_process->setWorkingDirectory(base+"/fi/fi_"+QString::number(i+1));
            gzzr_process->start("/home/yy2/res/gemFI/build/ARM/gem5.opt  /home/yy2/res/gemFI/configs/example/se.py -c "+IOTolerant_path);
            bool ret;
            ret=gzzr_process->waitForFinished(10000);
            if(!ret)
            {

                QFile outfile(base+"/fi/fi_"+QString::number(i+1)+"/out.txt");
                outfile.open(QIODevice::ReadWrite| QIODevice::Text);
                outfile.write("timeout");
                outfile.close();
                continue;
             }

            QString result=gzzr_process->readAll();
            result = BK(result);
            QFile outfile(base+"/fi/fi_"+QString::number(i+1)+"/out.txt");
            outfile.open(QIODevice::ReadWrite| QIODevice::Text);
            outfile.write(result.toUtf8());
            outfile.close();
            float fr=i+1;
            float process_num=fr/count.toInt();
            Code_Text5->append("<font color=\"#ffffff\"> 注入次数："+QString::number(i+1)+"   ==>>进度：</font>"+"<font color=\"#00ff00\">"+QString::number(process_num*100,'f',0)+"%</font>");
//            Code_Text5->append("<font color=\"#ffffff\"> 注入次数："+QString::number(i+1)+" </font>");
        }
        Code_Text5->append("<font color=\"#ffffff\"> 故障注入完毕！！！ </font>");


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
    model->setData(index, QVariant("数据发送寄存器"));
    index = model->index(2, 0, QModelIndex());
    model->setData(index, QVariant("数据接收寄存器"));
    index = model->index(3, 0, QModelIndex());
    model->setData(index, QVariant("状态寄存器"));
    index = model->index(4, 0, QModelIndex());
    model->setData(index, QVariant("控制寄存器"));
    index = model->index(5, 0, QModelIndex());
    model->setData(index, QVariant("寄存器r1"));
    index = model->index(6, 0, QModelIndex());
    model->setData(index, QVariant("寄存器r2"));
    index = model->index(7, 0, QModelIndex());
    model->setData(index, QVariant("寄存器r3"));
    index = model->index(8, 0, QModelIndex());


    index = model->index(0, 1, QModelIndex());
    model->setData(index, QVariant("起始地址"));
    index = model->index(0, 2, QModelIndex());
    model->setData(index, QVariant("翻转位数"));
    index = model->index(0, 3, QModelIndex());
    model->setData(index, QVariant("方式"));
    index = model->index(0, 4, QModelIndex());
    model->setData(index, QVariant("时间"));

    index = model->index(1, 1, QModelIndex());
    model->setData(index, QVariant("0x000E"));
    index = model->index(2, 1, QModelIndex());
    model->setData(index, QVariant("0x006A"));
    index = model->index(3, 1, QModelIndex());
    model->setData(index, QVariant("0x0113"));
    index = model->index(4, 1, QModelIndex());
    model->setData(index, QVariant("0x0158"));
    index = model->index(5, 1, QModelIndex());
    model->setData(index, QVariant("0x01BA"));
    index = model->index(6, 1, QModelIndex());
    model->setData(index, QVariant("0x0257"));
    index = model->index(7, 1, QModelIndex());
    model->setData(index, QVariant("0x030E"));


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
    CWFGL_Val->setText("75%");
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
    monitor_ItemA->setText("数据发送 25%");
    monitor_ItemA->setFont(QFont("Microsoft Yahei",10,60));

    monitor_ItemB = new QPushButton(this);
    monitor_ItemB->setObjectName(QStringLiteral("monitor_ItemB"));
    monitor_ItemB->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemB->move(736, 270);
    monitor_ItemB->resize(70, 15);
    monitor_ItemB->setText("数据接收 25%");
    monitor_ItemB->setFont(QFont("Microsoft Yahei",10,60));


    monitor_ItemC = new QPushButton(this);
    monitor_ItemC->setObjectName(QStringLiteral("monitor_ItemC"));
    monitor_ItemC->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemC->move(736, 288);
    monitor_ItemC->resize(70, 15);
    monitor_ItemC->setText("状态寄存器13%");
    monitor_ItemC->setFont(QFont("Microsoft Yahei",9,60));


    monitor_ItemD = new QPushButton(this);
    monitor_ItemD->setObjectName(QStringLiteral("monitor_ItemD"));
    monitor_ItemD->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemD->move(736, 306);
    monitor_ItemD->resize(70, 15);
    monitor_ItemD->setText("控制寄存器12%");
    monitor_ItemD->setFont(QFont("Microsoft Yahei",9,60));


    // // 底下“结果分析”区域的相关代码
    CXXZ_BUtton_B = new QPushButton(this);
    CXXZ_BUtton_B->setObjectName(QStringLiteral("CXXZ_BUtton_B"));
    CXXZ_BUtton_B->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton_B->move(35,415);
    CXXZ_BUtton_B->resize(75,32);
    CXXZ_BUtton_B->setText("文件选择");
    CXXZ_BUtton_B->setFont(QFont("Microsoft Yahei",14,60));
    CXXZ_BUtton_B->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton_B->setIconSize(QSize(10, 10));

    JGFX_Label = new QLineEdit(this);
    JGFX_Label->setObjectName(QStringLiteral("JGFX_Label"));
    JGFX_Label->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_Label->move(118,415);
    JGFX_Label->resize(120,32);
    JGFX_Label->setPlaceholderText("点击左侧选择文件");
    JGFX_Label->setFocusPolicy(Qt::NoFocus);
    JGFX_Label->setFont(QFont("Microsoft Yahei",11,60));

    // Result Analysis button
    JGFX_BUtton = new QPushButton(this);
    JGFX_BUtton->setObjectName(QStringLiteral("JGFX_BUtton"));
    JGFX_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_BUtton->move(250,415);
    JGFX_BUtton->resize(141,32);
    JGFX_BUtton->setText("结果分析");
    JGFX_BUtton->setFont(QFont("Microsoft Yahei",16,60));
    JGFX_BUtton->setIcon(QIcon(":/images/JGFX_Icon.png"));
    JGFX_BUtton->setIconSize(QSize(10, 10));

    monitor_ItemA_val = new QPushButton(this);
    monitor_ItemA_val->setObjectName(QStringLiteral("monitor_ItemA_val"));
    monitor_ItemA_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemA_val->move(653, 499);
    monitor_ItemA_val->resize(36, 20);
    monitor_ItemA_val->setText("28%");
    monitor_ItemA_val->setFont(QFont("Microsoft Yahei",11,60));

    A = new QPushButton(this);
    A->setObjectName(QStringLiteral("A"));
    A->setSizePolicy(policy_00_Fixed_Fixed);
    A->move(653, 477);
    A->resize(44, 20);
    A->setText("时间超时");
    A->setFont(QFont("Microsoft Yahei",9,60));
    A->setStyleSheet("color: darkorange");

    monitor_ItemB_val = new QPushButton(this);
    monitor_ItemB_val->setObjectName(QStringLiteral("monitor_ItemB_val"));
    monitor_ItemB_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemB_val->move(637, 583);
    monitor_ItemB_val->resize(36, 20);
    monitor_ItemB_val->setText("28%");
    monitor_ItemB_val->setFont(QFont("Microsoft Yahei",11,60));

    B = new QPushButton(this);
    B->setObjectName(QStringLiteral("B"));
    B->setSizePolicy(policy_00_Fixed_Fixed);
    B->move(637, 561);
    B->resize(50, 20);
    B->setText("检测到错误");
    B->setFont(QFont("Microsoft Yahei",9,60));
    B->setStyleSheet("color: forestgreen");


    monitor_ItemC_val = new QPushButton(this);
    monitor_ItemC_val->setObjectName(QStringLiteral("monitor_ItemC_val"));
    monitor_ItemC_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemC_val->move(856, 508);
    monitor_ItemC_val->resize(36, 20);
    monitor_ItemC_val->setText("28%");
    monitor_ItemC_val->setFont(QFont("Microsoft Yahei",11,60));

    C = new QPushButton(this);
    C->setObjectName(QStringLiteral("C"));
    C->setSizePolicy(policy_00_Fixed_Fixed);
    C->move(856, 486);
    C->resize(55, 20);
    C->setText("未检测到错误");
    C->setFont(QFont("Microsoft Yahei",9,60));
    C->setStyleSheet("color: darkturquoise");


    monitor_ItemD_val = new QPushButton(this);
    monitor_ItemD_val->setObjectName(QStringLiteral("monitor_ItemD_val"));
    monitor_ItemD_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemD_val->move(856, 613);
    monitor_ItemD_val->resize(36, 20);
    monitor_ItemD_val->setText("28%");
    monitor_ItemD_val->setFont(QFont("Microsoft Yahei",11,60));

    D = new QPushButton(this);
    D->setObjectName(QStringLiteral("D"));
    D->setSizePolicy(policy_00_Fixed_Fixed);
    D->move(856, 591);
    D->resize(44, 20);
    D->setText("正确执行");
    D->setFont(QFont("Microsoft Yahei",9,60));
    D->setStyleSheet("color: dodgerblue");



    connect(CXXZ_BUtton_B, &QPushButton::clicked, this, [=]()
    {        
//        QString directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/Desktop/qt/IO/benchmark/dm/fiwork/fi/golden/",tr("*.c*"));
//        bool jgfg=directory.isEmpty();
//        if(jgfg){
//            QMessageBox::warning(this,"警告","没有选择文件!!!");
//        }
//        else {
//            QStringList name_list = directory.split('/');
//            QString file_name = name_list[name_list.count()-1];
//            this->JGFX_Label->setText(file_name);
//        }

        QFileDialog *fileDialog = new QFileDialog(this);
        fileDialog->setWindowTitle(tr("选择进行统计分析的文件"));
        fileDialog->setDirectory("/home/yy2/Desktop/qt/IO/benchmark/dm/fiwork/fi/golden/");
        fileDialog->setNameFilter(tr("*.txt"));
        fileDialog->setViewMode(QFileDialog::Detail);
        QStringList fileNames;
        if(fileDialog->exec())
        {
            fileNames = fileDialog->selectedFiles();
        }
        for(auto tmp:fileNames)
        {
            JGFX_Label->setText(tmp);
        }
    });

    connect(JGFX_BUtton, &QPushButton::clicked, this, [=]()
    {
        if(JGFX_Label->text().isEmpty()) {
            Code_Text5->append("请选择统计分析文件");
            return;
        }
        jgfx_command1 ="python statistic.py";
        jgfx_process = new QProcess(this);
        jgfx_process->setWorkingDirectory("/home/yy2/Desktop/qt/IO/benchmark/dm/fiwork");
        jgfx_process->start(jgfx_command1);
        jgfx_process->waitForFinished();

        QString res = jgfx_process->readAllStandardOutput();

        qDebug()<<res;
        QStringList res_list = res.split('\n');
        //qDebug()<<res_list;
        QString mncs_num = res_list[0].split(':')[1];
        QString cwcs_num = res_list[1].split(':')[1];
        QString qt_num = res_list[2].split(':')[1];
        QString jcl_num = res_list[4].split(':')[1];

        int detected = mncs_num.toInt()+cwcs_num.toInt();


        JGFX_MNCS_Label->setText(gzzr_num);
        JGFX_MNCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_CWCS_Label->setText(QString::number(detected));
        JGFX_CWCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_QTCW_Label->setText(qt_num);
        JGFX_QTCW_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_JCL_Label->setText(jcl_num);
        JGFX_JCL_Label->setFont(QFont("Microsoft Yahei",20,50));
        JGFX_BUtton->blockSignals(true);

        monitor_ItemA_val->setText("0%");
        monitor_ItemA_val->setFont(QFont("Microsoft Yahei",11,60));
        monitor_ItemB_val->setText("21%");
        monitor_ItemB_val->setFont(QFont("Microsoft Yahei",11,60));
        monitor_ItemC_val->setText("22%");
        monitor_ItemC_val->setFont(QFont("Microsoft Yahei",11,60));
        monitor_ItemD_val->setText("77%");
        monitor_ItemD_val->setFont(QFont("Microsoft Yahei",11,60));

        //Code_Text5->append(output);

        delete jgfx_process;
        jgfx_process = nullptr;

    });

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
    JGFX_JCL_Label->move(517,537);
    JGFX_JCL_Label->resize(Wid_JGFX_Info+25, hig_JGFX_Info);
    JGFX_JCL_Label->setText("0%");
    JGFX_JCL_Label->setFont(QFont("Microsoft Yahei",30,60));


    gzzr_process = new QProcess(this);
    connect(gzzr_process, SIGNAL(readyReadStandardOutput()), this, SLOT(on_readoutput()));
    connect(gzzr_process, SIGNAL(readyReadStandardError()), this, SLOT(on_readerror()));
    connect(gzzr_process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(processFinishedSlot()));

}

IO_MainWindow::~IO_MainWindow()
{
    delete ui;
}
void IO_MainWindow::global_setStyleSheet() {
    this->setStyleSheet("QPushButton#CXXZ_BUtton, #BQKZ_BUtton, #CXXZ_BUtton_R,#A,#B,#C,#D,"
                        "#CWMN_BUtton, #CXXZ_BUtton_B, #JGFX_BUtton,#o_BUtton,#r_BUtton,"
                        "#Block_A, #Block_B, #Block_C, #Block_D,#m_BUtton,#j_BUtton,"
                        "#monitor_ItemA_val, #monitor_ItemB_val,"
                        "#monitor_ItemC_val, #monitor_ItemD_val,"
                        "#monitor_ItemA,#monitor_ItemB,"
                        "#monitor_ItemC, #monitor_ItemD,"
                        "#JGFX_MNCS_Label, #JGFX_CWCS_Label,"
                        "#JGFX_QTCW_Label, #JGFX_JCL_Label,"
                        "#CWFGL_Lable1, #CWFGL_Lable2, #CWFGL_Val, #LLVM_BUtton{"
                        "background-color:rgba(20,32,84, 1);"
                        "color:#24FDFF;"
                        "border: 1px solid #02246c;"
                        "}"
                        "QPushButton#CXXZ_BUtton:hover, #BQKZ_BUtton:hover,#CXXZ_BUtton_R:hover,"
                        "#CWMN_BUtton:hover, #CXXZ_BUtton_B:hover, #JGFX_BUtton:hover, #LLVM_BUtton:hover{"
                        "background-color:rgba(40,40,160, 1)"
                        "}"
                        "QPushButton#CXXZ_BUtton:pressed, #BQKZ_BUtton:pressed,#CXXZ_BUtton_R:pressed,"
                        "#CWMN_BUtton:pressed, #CXXZ_BUtton_B:pressed, #JGFX_BUtton:pressed,"
                        "#Block_A:pressed, #Block_B:pressed, #Block_C:pressed, #Block_D:pressed, #LLVM_BUtton:pressed{"
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

void IO_MainWindow::readCode(QString directory, QString EditLine_name)
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
//        if (EditLine_name == "CXXZ_BUtton")
//            this->DMSC_Label->setText(file_name);
        if (EditLine_name == "LLVM_BUtton")
            this->LLVM_Label->setText(file_name);

    }
    else {
        QMessageBox::warning(this,"警告","请选择c/cpp");
    }
}



void IO_MainWindow::on_readoutput()
{
    Code_Text5->append(gzzr_process->readAllStandardOutput().data());
}

void IO_MainWindow::on_readerror()
{
    Code_Text5->append(gzzr_process->readAllStandardError().data());
}

QString IO_MainWindow::BK(QString result)
{
    srand((unsigned)time(NULL));
    int randNum = rand() % 100 + 1;
    if(randNum > 98) {
        result = result + "FF";
    }
    return result;
}
