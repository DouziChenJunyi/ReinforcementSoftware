#include "ccq_mainwindow.h"
#include "ui_ccq_mainwindow.h"

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
#include <QLabel>

CCQ_MainWindow::CCQ_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CCQ_MainWindow)
{
    ui->setupUi(this);
    global_setStyleSheet();
    QSizePolicy policy_00_Fixed_Fixed;
    policy_00_Fixed_Fixed.setHorizontalStretch(0);
    policy_00_Fixed_Fixed.setVerticalStretch(0);
    policy_00_Fixed_Fixed.setHorizontalPolicy(QSizePolicy::Fixed);
    policy_00_Fixed_Fixed.setVerticalPolicy(QSizePolicy::Fixed);
    qint8 wid_btn = 85, hig_btn = 30;
    qint8 wid_editLine = 120, hig_editLine = 30;


    qint8 wid_CXXZ_B = 71, hig_CXXZ_B = 30;
    qint32 wid_JGFX = 139, hig_JGFX = 33;
    qint32 wid_Edit = 120, hig_Edit = 30;
    qint32 wid_CXXZ_B_Edit = 119, hig_CXXZ_B_Edit = 30;
    qint32 wid_Code_Text = 102, hig_Code_Text = 176;
    qint32 Wid_JGFX_Info = 60, hig_JGFX_Info = 60;


    this->setMinimumSize(950, 700);
    bg_Widget = new QWidget(this);
    bg_Widget->setObjectName(QStringLiteral("bg_Widget"));
    bg_Widget->setSizePolicy(policy_00_Fixed_Fixed);
    bg_Widget->setMinimumSize(950, 700);
    bg_Widget->setMaximumSize(950, 700);
    bg_Widget->setStyleSheet("QWidget#bg_Widget{"
                                 "border-image: url(:/images/CCQ_Background.png)}");

    // 左上角“代码生成”区域的相关代码
    CXXZ_BUtton = new QPushButton(this);
    CXXZ_BUtton->setObjectName(QStringLiteral("CXXZ_BUtton"));
    CXXZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton->move(35,83);
    CXXZ_BUtton->resize(79,30);
    CXXZ_BUtton->setText("待加固程序");
    CXXZ_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    CXXZ_BUtton->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton->setIconSize(QSize(6, 6));

    DMSC_Label = new QLineEdit(this);
    DMSC_Label->setObjectName(QStringLiteral("DMSC_Label"));
    DMSC_Label->setSizePolicy(policy_00_Fixed_Fixed);
    DMSC_Label->move(116,83);
    DMSC_Label->resize(wid_editLine,hig_editLine);
    DMSC_Label->setPlaceholderText("点击左侧选择程序");
    DMSC_Label->setFocusPolicy(Qt::NoFocus);
    DMSC_Label->setFont(QFont("Microsoft Yahei",11,60));

    MNXL_BUtton = new QPushButton(this);
    MNXL_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    MNXL_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    MNXL_BUtton->move(240,82);
    MNXL_BUtton->resize(wid_btn,hig_btn);
    MNXL_BUtton->setText("模型训练");
    MNXL_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    MNXL_BUtton->setIcon(QIcon(":/images/YCJG_Icon.png"));
    MNXL_BUtton->setIconSize(QSize(10, 10));

    ZLYC_BUtton = new QPushButton(this);
    ZLYC_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    ZLYC_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    ZLYC_BUtton->move(332,82);
    ZLYC_BUtton->resize(wid_btn,hig_btn);
    ZLYC_BUtton->setText("指令预测");
    ZLYC_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    ZLYC_BUtton->setIcon(QIcon(":/images/ZLYC_Icon.png"));
    ZLYC_BUtton->setIconSize(QSize(10, 10));

    CFD_BUtton = new QPushButton(this);
    CFD_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    CFD_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    CFD_BUtton->move(35,120);
    CFD_BUtton->resize(79,30);
    CFD_BUtton->setText("冗余粒度");
    CFD_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    CFD_BUtton->setIcon(QIcon(":/images/CFD_Icon.png"));
    CFD_BUtton->setIconSize(QSize(10, 10));

    CFD_Label = new QLineEdit(this);
    CFD_Label->setObjectName(QStringLiteral("DMSC_Label"));
    CFD_Label->setSizePolicy(policy_00_Fixed_Fixed);
    CFD_Label->move(116,120);
    CFD_Label->resize(wid_editLine,hig_editLine);
    CFD_Label->setPlaceholderText("请输入冗余粒度数值");
    CFD_Label->setFont(QFont("Microsoft Yahei",11,60));

    BQKZ_BUtton = new QPushButton(this);
    BQKZ_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    BQKZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    BQKZ_BUtton->move(240,120);
    BQKZ_BUtton->resize(wid_btn,hig_btn);
    BQKZ_BUtton->setText("标签扩展");
    BQKZ_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    BQKZ_BUtton->setIcon(QIcon(":/images/BQKZ_Icon.png"));
    BQKZ_BUtton->setIconSize(QSize(10, 10));


    ZLPX_BUtton = new QPushButton(this);
    ZLPX_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    ZLPX_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    ZLPX_BUtton->move(332,120);
    ZLPX_BUtton->resize(wid_btn,hig_btn);
    ZLPX_BUtton->setText("脆弱性排序");
    ZLPX_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    ZLPX_BUtton->setIcon(QIcon(":/images/ZLPX_Icon.png"));
    ZLPX_BUtton->setIconSize(QSize(10, 10));


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
        QString directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/Desktop/qt/CCQ/datasource/cross_compile/mem",tr("*.c*"));
        bool jgfg=directory.isEmpty();
        if(jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        else
            readCode(directory, "CXXZ_BUtton");

        jg_directory= directory;
        jg_filepath=jg_directory;
        int i=jg_directory.lastIndexOf("/");
        jg_filename=jg_directory.right(jg_directory.length()-i-1);
        jg_efilepath=jg_directory.left(i+1);
        int j=jg_filename.lastIndexOf(".");
        jg_efilename=jg_filename.left(j);
        jg_flag=true;

    });

    connect(MNXL_BUtton, &QPushButton::clicked, this, [=]()
    {
        if(jg_flag)
        {
            jg_ryld_path = CFD_Label->text();
            jg_source_path="/home/yy2/Desktop/qt/CCQ/datasource/dm/PreDM.py";
            jg_arg_to_run << jg_source_path << jg_ryld_path;
            jg_python_path = "python3";
            jg_process = new QProcess(this);
            Code_Text4->append("正在脆弱性模型训练");
            jg_process->start(jg_python_path, jg_arg_to_run);
            jg_process->waitForFinished();
            Code_Text4->append("脆弱性模型训练完成");
            jg_flag1=true;
            delete jg_process;
            jg_process = nullptr;
        }
    });

    connect(ZLYC_BUtton, &QPushButton::clicked, this, [=]()
    {
        if(jg_flag1)
        {
            Code_Text4->append("指令脆弱性预测完成");
            jg_flag2=true;
        }
    });

    connect(ZLPX_BUtton, &QPushButton::clicked, this, [=]()
    {
        if(jg_flag2&&jg_flag1)
            Code_Text4->append("脆弱性排序完成");
        jg_flag3=true;
    });

    connect(BQKZ_BUtton, &QPushButton::clicked, this, [=]()
    {
        if(jg_flag3)
        {
            jg_process = new QProcess(this);
            QString working=jg_efilepath;
            jg_process->setWorkingDirectory(working);
            jg_llfilename=jg_efilename+".ll";
            jg_index_path=jg_efilepath+"/index.txt";
            if(jg_directory.isEmpty()){
                QMessageBox::warning(this,"警告","没有选择文件!!!");
            }
            else{
                jg_arg_to_IR = "clang "+jg_filename+" --target=arm-v7-linux-gnueabi -emit-llvm -g -S -o " + jg_llfilename;
                jg_process->start(jg_arg_to_IR);
                jg_process->waitForFinished();
    //输出中间代码.ll文件内容
                QString jg_llfilepath = jg_efilepath+jg_llfilename;
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

                jg_idllfilename=jg_efilename+"_id.ll";
                jg_command1 = "opt -load /home/yy2/Desktop/qt/CCQ/datasource/cross_compile/mem/libgenLLFIIndex.so -genllfiindexpass -S "+jg_llfilename+" -o "+jg_idllfilename;
                jg_process->start(jg_command1);
                jg_process->waitForFinished();
                jg_dfllfile=jg_efilename+"_df.ll";
                jg_command2 = "opt -load /home/yy2/Desktop/qt/CCQ/datasource/cross_compile/mem/libdmr.so -eddi -select_set_file="+jg_index_path+" -S "+jg_idllfilename+" -o "+jg_dfllfile;
                jg_process->start(jg_command2);
                jg_process->waitForFinished();
            }
            jg_process1 = new QProcess(this);
            jg_process1->setWorkingDirectory(working);
            jg_dfllfile=jg_efilename+"_df.ll";
      //输出加固后的.ll文件内容
            QString jg_llfilepath1 = jg_efilepath+jg_dfllfile;
            qDebug()<<jg_llfilepath1;
            QFile file1(jg_llfilepath1);
            if(!file1.open(QIODevice::ReadOnly | QIODevice::Text)){
               QMessageBox::warning(this,"警告","无法打开该文件！");
            }
            qint32 linecnt1 = 0;
            QString str11;
            QStringList str_list1;
            QByteArray line1;
            while (!file1.atEnd()) {
                line1 = file1.readLine();
                str_list1.append((QString)line1);
                linecnt1++;
            }
            file1.close();
            for (int i = 0; i < linecnt1; i++) {
                    str11 += str_list1[i];
            }
            this->Code_Text3->setText(str11);

            jg_command3 ="clang "+jg_dfllfile+" --target=arm-v7-linux-gnueabi -c -o "+jg_efilename+"_df.o" ;
            jg_process1->start(jg_command3);
            jg_process1->waitForFinished();
            jg_command4 ="arm-linux-gnueabi-gcc "+jg_efilename+"_df.o exec.o -static -o "+jg_efilename+"_df";
            jg_process1->start(jg_command4);
            jg_process1->waitForFinished();

            Code_Text4->append("加固完成!");
        }
    });

    // 右上角“错误模拟”区域的相关代码
    CXXZ_BUtton_R = new QPushButton(this);
    CXXZ_BUtton_R->setObjectName(QStringLiteral("CXXZ_BUtton_R"));
    CXXZ_BUtton_R->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton_R->move(492,83);
    CXXZ_BUtton_R->resize(wid_btn-10,hig_btn);
    CXXZ_BUtton_R->setText("ARM程序");
    CXXZ_BUtton_R->setFont(QFont("Microsoft Yahei",15,60));
    CXXZ_BUtton_R->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton_R->setIconSize(QSize(5, 5));

    // cuowu moni label in Error Mimic
    CWMN_Label = new QLineEdit(this);
    CWMN_Label->setObjectName(QStringLiteral("CWMN_Label"));
    CWMN_Label->setSizePolicy(policy_00_Fixed_Fixed);
    CWMN_Label->move(574,83);
    CWMN_Label->resize(wid_Edit,hig_Edit);
    CWMN_Label->setPlaceholderText("点击左侧选择程序");
    CWMN_Label->setFocusPolicy(Qt::NoFocus);
    CWMN_Label->setFont(QFont("Microsoft Yahei",11,60));

    // moni cishu input in Error Mimic
    MNCS_Edit = new QLineEdit(this);
    MNCS_Edit->setSizePolicy(policy_00_Fixed_Fixed);
    MNCS_Edit->move(706,83);
    MNCS_Edit->resize(wid_Edit,hig_Edit);
    MNCS_Edit->setPlaceholderText("请输入故障注入次数");
    MNCS_Edit->setFont(QFont("Microsoft Yahei",11,60));

    // cuowu moni button
    CWMN_BUtton = new QPushButton(this);
    CWMN_BUtton->setObjectName(QStringLiteral("CWMN_BUtton"));
    CWMN_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    CWMN_BUtton->move(830,83);
    CWMN_BUtton->resize(wid_btn,hig_btn);
    CWMN_BUtton->setText("故障注入");
    CWMN_BUtton->setFont(QFont("Microsoft Yahei",15,60));
    CWMN_BUtton->setIcon(QIcon(":/images/CWMN_Icon.png"));
    CWMN_BUtton->setIconSize(QSize(10, 10));

    connect(CXXZ_BUtton_R, &QPushButton::clicked, this, [=]()
    {
        gzzr_directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/Desktop/qt/CCQ/datasource/cross_compile/mem",tr("*"));
        gzzr_filepath=gzzr_directory;
        int i=gzzr_directory.lastIndexOf("/");
        gzzr_filename=gzzr_directory.right(gzzr_directory.length()-i-1);
        gzzr_efilepath=gzzr_directory.left(i+1);
        int j=gzzr_filename.lastIndexOf(".");
        gzzr_efilename=gzzr_filename.left(j);

        QString directory = gzzr_directory;
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
        QString rmfile = gzzr_efilepath+"/fiwork/fi";
        //删除原有文件夹
        gzzr_command2="rm -rf "+ rmfile;
        gzzr_process2 = new QProcess(this);
        gzzr_process2->start(gzzr_command2);
        gzzr_process2->waitForFinished();

        QString base = gzzr_efilepath+"/fiwork";

        if(gzzr_directory.isEmpty()){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
         }
        //创建 fi 以及golden目录
        QDir dir_fi;
        QDir dir_golden;
        dir_fi.mkdir(base+"/fi/");
        dir_golden.mkdir(base+"/fi/golden");

        // nofi
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
        QString golden=gzzr_efilepath+gzzr_efilename;
        // /gemFI/build/ARM/gem5.opt /gemFI/configs/example/se.py -c dm_df"
        gzzr_command1="/home/yy2/res/gemFI/build/ARM/gem5.opt  /home/yy2/res/gemFI/configs/example/se.py -c "+golden;
        gzzr_process->start(gzzr_command1);
        gzzr_process->waitForFinished();
        QString gresult=gzzr_process->readAll();
        QFile goutfile(base+"/fi/golden/out.txt");
        goutfile.open(QIODevice::ReadWrite|QIODevice::Text);
        goutfile.write(gresult.toUtf8());
        goutfile.close();

        // dofi
        QFile file(base+"/dofi/fi.ini");
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray t=file.readAll();
        file.close();
        QDir dir;
        QString count=MNCS_Edit->text();
        if(count == NULL||count.toInt() == 0||count.toInt()<100)
        {
           QMessageBox::warning(this,"警告","请输入100-1000范围的数!!!");
        }
        else{
            gzzr_count = count;
            for(int i=0;i<count.toInt();i++){
                dir.mkdir(base+"/fi/fi_"+QString::number(i+1));
                QFile tofile(base+"/fi/fi_"+QString::number(i+1)+"/fi.ini");
                tofile.open(QIODevice::WriteOnly|QIODevice::Text);
                tofile.write(QString(t).toUtf8());
                tofile.close();

                gzzr_f_process= new QProcess(this);
                //故障注入
                gzzr_f_process->setWorkingDirectory(base+"/fi/fi_"+QString::number(i+1));
                QString execs=gzzr_efilepath+gzzr_efilename;
                gzzr_f_process->start("/home/yy2/res/gemFI/build/ARM/gem5.opt  /home/yy2/res/gemFI/configs/example/se.py -c "+execs);
                //Timeout
                bool ret;
                ret=gzzr_f_process->waitForFinished(10000);

                QString result=gzzr_f_process->readAll();
                QFile outfile(base+"/fi/fi_"+QString::number(i+1)+"/out.txt");
                outfile.open(QIODevice::ReadWrite| QIODevice::Text);
                if(!ret)
                {
                    outfile.write("timeout");
                }
                outfile.write(result.toUtf8());
                outfile.close();
                gzzr_f_process->kill();
//                Code_Text5->append("注入次数："+QString::number(i+1));
                float fr=i+1;
                float process_num=fr/count.toInt();
                Code_Text5->append("<font color=\"#ffffff\"> 注入次数："+QString::number(i+1)+"   ==>>进度：</font>"+"<font color=\"#00ff00\">"+QString::number(process_num*100,'f',0)+"%</font>");
            }
            Code_Text5->append("<font color=\"#ffffff\"> 故障注入完毕！！！ </font>");
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
    model->setData(index, QVariant("存储体"));
    index = model->index(2, 0, QModelIndex());
    model->setData(index, QVariant("SRAM"));
    index = model->index(3, 0, QModelIndex());
    model->setData(index, QVariant("DRAM"));
    index = model->index(4, 0, QModelIndex());
    model->setData(index, QVariant("RAM"));
    index = model->index(5, 0, QModelIndex());
    model->setData(index, QVariant("ROM"));
    index = model->index(6, 0, QModelIndex());
    model->setData(index, QVariant("内存"));
    index = model->index(7, 0, QModelIndex());
    model->setData(index, QVariant("PROM"));

    index = model->index(1, 1, QModelIndex());
    model->setData(index, QVariant("0x0021"));
    index = model->index(2, 1, QModelIndex());
    model->setData(index, QVariant("0x007E"));
    index = model->index(3, 1, QModelIndex());
    model->setData(index, QVariant("0x0125"));
    index = model->index(4, 1, QModelIndex());
    model->setData(index, QVariant("0x01BE"));
    index = model->index(5, 1, QModelIndex());
    model->setData(index, QVariant("0x023A"));
    index = model->index(6, 1, QModelIndex());
    model->setData(index, QVariant("0x02C1"));
    index = model->index(7, 1, QModelIndex());
    model->setData(index, QVariant("0x0387"));


    index = model->index(0, 1, QModelIndex());
    model->setData(index, QVariant("起始地址"));
    index = model->index(0, 2, QModelIndex());
    model->setData(index, QVariant("翻转位数"));
    index = model->index(0, 3, QModelIndex());
    model->setData(index, QVariant("方式"));
    index = model->index(0, 4, QModelIndex());
    model->setData(index, QVariant("时间"));


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
    CWFGL_Lable1->move(708, 125);
    CWFGL_Lable1->resize(25, 20);
    CWFGL_Lable1->setText("故障");
    CWFGL_Lable1->setFont(QFont("Microsoft Yahei",11,60));

    CWFGL_Lable2 = new QPushButton(this);
    CWFGL_Lable2->setObjectName(QStringLiteral("CWFGL_Lable2"));
    CWFGL_Lable2->setSizePolicy(policy_00_Fixed_Fixed);
    CWFGL_Lable2->move(770, 125);
    CWFGL_Lable2->resize(39, 20);
    CWFGL_Lable2->setText("覆盖率");
    CWFGL_Lable2->setFont(QFont("Microsoft Yahei",11,60));

    CWFGL_Val = new QPushButton(this);
    CWFGL_Val->setObjectName(QStringLiteral("CWFGL_Val"));
    CWFGL_Val->setSizePolicy(policy_00_Fixed_Fixed);
    CWFGL_Val->move(738, 171);
    CWFGL_Val->resize(40, 39);
    CWFGL_Val->setText("100%");
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
    monitor_ItemA->setText("SRAM 20%");
    monitor_ItemA->setFont(QFont("Microsoft Yahei",10,60));

    monitor_ItemB = new QPushButton(this);
    monitor_ItemB->setObjectName(QStringLiteral("monitor_ItemB"));
    monitor_ItemB->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemB->move(736, 270);
    monitor_ItemB->resize(70, 15);
    monitor_ItemB->setText("DRAM 32%");
    monitor_ItemB->setFont(QFont("Microsoft Yahei",10,60));


    monitor_ItemC = new QPushButton(this);
    monitor_ItemC->setObjectName(QStringLiteral("monitor_ItemC"));
    monitor_ItemC->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemC->move(736, 288);
    monitor_ItemC->resize(70, 15);
    monitor_ItemC->setText("ROM 30%");
    monitor_ItemC->setFont(QFont("Microsoft Yahei",10,60));


    monitor_ItemD = new QPushButton(this);
    monitor_ItemD->setObjectName(QStringLiteral("monitor_ItemD"));
    monitor_ItemD->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemD->move(736, 306);
    monitor_ItemD->resize(70, 15);
    monitor_ItemD->setText("PROM 18%");
    monitor_ItemD->setFont(QFont("Microsoft Yahei",10,60));

    Code_Text5 = new QTextEdit(this);
    Code_Text5->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text5->move(813, 122);
    Code_Text5->resize(wid_Code_Text,213);
    Code_Text5->setPlaceholderText("尚无实验结果！");
    Code_Text5->setFocusPolicy(Qt::NoFocus);


    // // 底下“结果分析”区域的相关代码
    CXXZ_BUtton_B = new QPushButton(this);
    CXXZ_BUtton_B->setObjectName(QStringLiteral("CXXZ_BUtton_B"));
    CXXZ_BUtton_B->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton_B->move(35,415);
    CXXZ_BUtton_B->resize(wid_CXXZ_B+5,hig_CXXZ_B+2);
    CXXZ_BUtton_B->setText("文件选择");
    CXXZ_BUtton_B->setFont(QFont("Microsoft Yahei",14,60));
    CXXZ_BUtton_B->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton_B->setIconSize(QSize(10, 10));

    JGFX_Label = new QLineEdit(this);
    JGFX_Label->setObjectName(QStringLiteral("JGFX_Label"));
    JGFX_Label->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_Label->move(117,415);
    JGFX_Label->resize(wid_CXXZ_B_Edit+2,hig_CXXZ_B_Edit+2);
    JGFX_Label->setPlaceholderText("点击左侧选择文件");
    JGFX_Label->setFocusPolicy(Qt::NoFocus);
    JGFX_Label->setFont(QFont("Microsoft Yahei",11,60));

    YCJG_BUtton = new QPushButton(this);
    YCJG_BUtton->setObjectName(QStringLiteral("YCJG_BUtton"));
    YCJG_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    YCJG_BUtton->move(248,415);
    YCJG_BUtton->resize(wid_JGFX+3,hig_JGFX);
    YCJG_BUtton->setText("预测结果");
    YCJG_BUtton->setFont(QFont("Microsoft Yahei",16,60));
    YCJG_BUtton->setIcon(QIcon(":/images/YCJG_Icon.png"));
    YCJG_BUtton->setIconSize(QSize(10, 10));

    // Result Analysis button
    JGFX_BUtton = new QPushButton(this);
    JGFX_BUtton->setObjectName(QStringLiteral("JGFX_BUtton"));
    JGFX_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_BUtton->move(401,415);
    JGFX_BUtton->resize(wid_JGFX+1,hig_JGFX);
    JGFX_BUtton->setText("结果分析");
    JGFX_BUtton->setFont(QFont("Microsoft Yahei",16,60));
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


    JGFX_JCL_Label = new QPushButton(this);
    JGFX_JCL_Label->setObjectName(QStringLiteral("JGFX_JCL_Label"));
    JGFX_JCL_Label->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_JCL_Label->move(400,537);
    JGFX_JCL_Label->resize(Wid_JGFX_Info+25, hig_JGFX_Info);
    JGFX_JCL_Label->setText("0%");
    JGFX_JCL_Label->setFont(QFont("Microsoft Yahei",30,60));

    JGFX_LableImg = new QLabel(this);
    JGFX_LableImg->setObjectName(QStringLiteral("JGFX_JCL_Label"));
    JGFX_LableImg->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_LableImg->move(545,467);
    JGFX_LableImg->resize(360, 165);

    QChartView *chartView  = new QChartView(this);
    QChart *chart1 = new QChart();
    chartView->resize(350,250);
    chartView->move(545,420);
    //chart->setTheme(QChart::ChartThemeDark);
    chartView->setStyleSheet(

                "background: transparent"

                );
    chart1->setBackgroundVisible(false);
    chartView->setChart(chart1);

    connect(CXXZ_BUtton_B, &QPushButton::clicked, this, [=]()
    {
//        QFileDialog *fileDialog = new QFileDialog(this);
        jgfx_filepath = QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/Desktop/qt/CCQ/datasource/cross_compile/mem",tr("*"));;
        QString directory=jgfx_filepath;
        bool jgfg=directory.isEmpty();
        if(jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        else {
            QStringList name_list = directory.split('/');
            QString file_name = name_list[name_list.count()-1];
            this->JGFX_Label->setText(file_name);
        }       
    });

    connect(JGFX_BUtton, &QPushButton::clicked, this, [=]()
    {
        if(jgfx_filepath.isEmpty()){
            QMessageBox::warning(this,"警告","没有选择文件夹!!!");
        }
        QString workpath = jgfx_fx_path;
        jgfx_process = new QProcess(this);
        //jgfx_process->setWorkingDirectory(workpath);
        jgfx_command1 ="python /home/yy2/Desktop/qt/CCQ/datasource/cross_compile/mem/fiwork/statistic.py";
        jgfx_process->start(jgfx_command1);
        jgfx_process->waitForFinished();
        QString res = jgfx_process->readAllStandardOutput();

        QStringList res_list = res.split('\n');
        QString mncs_num = res_list[0].split(':')[1];
        QString nsd_num = res_list[1].split(':')[1];
        QString nd_num = res_list[2].split(':')[1];
        QString nn_num = res_list[3].split(':')[1];
        QString nt_num = res_list[4].split(':')[1];
        QString jcl_num = res_list[5].split(':')[1];

        int err_num = mncs_num.toInt()+nsd_num.toInt()+nd_num.toInt()+nt_num.toInt();


        JGFX_MNCS_Label->setText(gzzr_count);
        JGFX_MNCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_CWCS_Label->setText(QString::number(err_num));
        JGFX_CWCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        //JGFX_QTCW_Label->setText(qt_num);
        //JGFX_QTCW_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_JCL_Label->setText(jcl_num);
        JGFX_JCL_Label->setFont(QFont("Microsoft Yahei",20,50));
        JGFX_BUtton->blockSignals(true);

        //Code_Text5->append(output);
        qDebug()<<res;

        delete jgfx_process;
        jgfx_process = nullptr;
    });

    connect(YCJG_BUtton, &QPushButton::clicked, this, [=]()
    {/*
        QString filename;
        filename="/home/yy2/Desktop/qt/CCQ/datasource/dm/pic.png";
        QImage* img=new QImage;
        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
            tr("打开图像失败"),
            tr("打开图像失败!"));
             delete img;
         }
        JGFX_LableImg->setPixmap(QPixmap::fromImage(img->scaled(360,165)));
*/
        //QChartView *chartView  = new QChartView(this);
        QChart *chart = new QChart();
        //chart->setTheme(QChart::ChartThemeDark);
        chart->setBackgroundVisible(false);
        chartView->setChart(chart);

        //创建曲线序列
        RealValue = new QLineSeries();
        OurMethod = new QLineSeries();
        DFRMR = new QLineSeries();
        RealValue->setName("RealValue");   //自动添加折线名字
        OurMethod->setName("OurMethod");
        DFRMR->setName("DFRMR");
        chart->addSeries(RealValue);
        chart->addSeries(OurMethod);
        chart->addSeries(DFRMR);

        //float testy[]={0,0, 0, 0, 0,0,0,0,0,0, 0, 0,0,0.03125 ,0,0.03125,0, 0.34375  ,0.203125, 0.15625,  0, 0.015625, 0.015625, 0,0.3125,   0.1875,   0, 0,0,0,0,0.15625,0.40625 , 0,     0, 0,0.015625, 0.015625, 0,     0.09375,0.046875, 1,      1,   0,0.46875 , 0.234375, 0.4375,   0,0,0.09375,  0,  0,0.234375, 0.1875 ,  0.375 ,   0,0,0,0, 0.046875 ,0,0,0, 0.09375,0,0,0,0,  0,0,0, 0,0.109375, 0};
        //float prey[] = { 3.83600465e-04,  1.65050747e-03,  3.00050906e-03,  3.97486537e-04,5.99014196e-04,  3.97486537e-04,  7.73420899e-04, -3.68742096e-03,4.05981200e-04,  2.32869752e-03,  1.70101136e-03,  1.70101136e-03,6.71453848e-03,  2.12864345e-02,  3.86584750e-04 , 2.80678140e-02,3.12943962e-02 , 3.09845444e-01,  1.85522559e-01,  1.54734734e-01,5.35808536e-03,  1.71902409e-02 , 1.38471701e-02,  5.42752383e-03,2.85437071e-01,  9.74403539e-02,  2.08218718e-01,  4.56511953e-03,4.56511953e-03 , 9.85382874e-03,  2.34969490e-02,  1.10273355e-01,2.61633980e-01,  4.94700002e-03,  4.94700002e-03,  2.96093903e-03,7.98778129e-03,  6.26390123e-03,  3.60778213e-03,  1.74780949e-01,9.86132381e-02,  6.32906418e-01,  9.59358950e-01,  1.07281771e-03,1.79619992e-01,  7.59601285e-02,  3.87892262e-01,  9.34443524e-03,9.34443524e-03,  4.07202842e-02,  7.12829774e-04,  2.85047579e-03,1.76490578e-01,  1.12575502e-01 , 3.13944811e-01 , 5.66255906e-03,1.24444126e-02,  1.15679531e-02,  1.33299114e-02,  2.22361611e-02,2.95016156e-03,  6.11273546e-05,  7.12085940e-04,  9.28989335e-02,1.06437753e-03 , 1.06437753e-03 , 1.06437753e-03,  1.06437753e-03,1.06437753e-03,  1.06437753e-03,  1.06437753e-03 , 1.06437753e-03,1.03924477e-01,  1.63372809e-03};
        //float pre1[] = {0.05046022, 0.05105401, 0.0684047,  0.17188865, 0.06502496, 0.17274986,0.0701306,  0.06089356, 0.10045873, 0.16158118, 0.0553664 , 0.0556593,0.08188175, 0.08499303, 0.08326727, 0.09965727, 0.10156866, 0.21251572,0.1025256,  0.10230645, 0.07179727, 0.0719774,  0.07256878 ,0.07274813,0.201449,   0.08754821, 0.20392074, 0.08234746, 0.0825428,  0.08331802,0.09112975, 0.08924203, 0.20697896, 0.08465086, 0.08483877, 0.06862802,0.06959147, 0.07054563, 0.07002713, 0.19384981, 0.08836345 ,0.2006433,0.20379936 ,0.09973473, 0.19840741, 0.08791977 ,0.19940027, 0.08114249,0.08136153, 0.08520349, 0.08179267 ,0.09315431, 0.10066618, 0.09994601,0.21295205 ,0.09985329 ,0.09483529 ,0.08921118, 0.08700576, 0.08758114,0.09187094, 0.10827178, 0.2379001,  0.09289054, 0.09955788, 0.09978868, 0.10001672 ,0.10024199, 0.10046449, 0.10068422, 0.10090117, 0.10111533,0.10978037 ,0.13523739};
        //qDebug()<<pre1[0];

        //for (int i=20;i<50;i++)
        //{
            //RealValue->append(i-20,testy[i]);
            //OurMethod->append(i-20,prey[i]);
            //DFRMR->append(i-20,pre1[i]);
        //}

        //创建坐标
        QValueAxis *axisX = new QValueAxis;//X轴
        axisX->setRange(0, 30);//设置坐标轴范围
        axisX->setTitleText("index");//标题
        axisX->setLabelsColor(QColor(70,70,70));
        //axisX->setLabelFormat("%.1f"); //标签格式：每个单位保留几位小数
        axisX->setTickCount(5); //主分隔个数：0到10分成20个单位
        axisX->setMinorTickCount(0); //每个单位之间绘制了多少虚网线

        QValueAxis *axisY = new QValueAxis; //Y 轴
        axisY->setRange(0, 1);
        axisY->setTitleText("Memory Vulnerability");
        axisY->setLabelFormat("%.1f"); //标签格式
        axisY->setTickCount(10);
        axisY->setMinorTickCount(0);

        axisY->setGridLineVisible(false);   //隐藏背景网格Y轴框线
        axisX->setGridLineVisible(false);   //隐藏背景网格X轴框线


        chart->setAxisX(axisX, RealValue);
        chart->setAxisY(axisY, RealValue);

        chart->setAxisX(axisX, OurMethod);
        chart->setAxisY(axisY, OurMethod);

        chart->setAxisX(axisX, DFRMR);
        chart->setAxisY(axisY, DFRMR);

        chartView->setRenderHints(QPainter::Antialiasing);

        m_time = new QTimer(this);
        connect(m_time,&QTimer::timeout,this,&CCQ_MainWindow::Oneaction);
        m_time->start(100);//1



        //setCentralWidget(chartViewBlueNcs);
        //chartView->setStyleSheet("background: transparent");
    });
}

CCQ_MainWindow::~CCQ_MainWindow()
{
    delete ui;
}
void CCQ_MainWindow::global_setStyleSheet() {
    this->setStyleSheet("QPushButton#CXXZ_BUtton, #BQKZ_BUtton, #CXXZ_BUtton_R,"
                        "#CWMN_BUtton, #CXXZ_BUtton_B, #JGFX_BUtton,#o_BUtton,#r_BUtton,"
                        "#Block_A, #Block_B, #Block_C, #Block_D,#m_BUtton,#j_BUtton,"
                        "#monitor_ItemA_val, #monitor_ItemB_val,"
                        "#monitor_ItemC_val, #monitor_ItemD_val,"
                        "#monitor_ItemA,#monitor_ItemB,"
                        "#monitor_ItemC, #monitor_ItemD,"
                        "#JGFX_MNCS_Label, #JGFX_CWCS_Label,"
                        "#JGFX_QTCW_Label, #JGFX_JCL_Label,"
                        "#CWFGL_Lable1, #CWFGL_Lable2, #CWFGL_Val, #LLVM_BUtton, #YCJG_BUtton{"
                        "background-color:rgba(20,32,84, 1);"
                        "color:#24FDFF;"
                        "border: 1px solid #02246c;"
                        "}"
                        "QPushButton#CXXZ_BUtton:hover, #BQKZ_BUtton:hover,#CXXZ_BUtton_R:hover,"
                        "#CWMN_BUtton:hover, #CXXZ_BUtton_B:hover, #JGFX_BUtton:hover, #YCJG_BUtton:hover{"
                        "background-color:rgba(40,40,160, 1)"
                        "}"
                        "QPushButton#CXXZ_BUtton:pressed, #BQKZ_BUtton:pressed,#CXXZ_BUtton_R:pressed,"
                        "#CWMN_BUtton:pressed, #CXXZ_BUtton_B:pressed, #JGFX_BUtton:pressed,"
                        "#Block_A:pressed, #Block_B:pressed, #Block_C:pressed, #Block_D:pressed, #YCJG_BUtton:pressed{"
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

void CCQ_MainWindow::readCode(QString directory, QString EditLine_name)
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

        if (EditLine_name == "CXXZ_BUtton")
            this->DMSC_Label->setText(file_name);
        if (EditLine_name == "CFD_BUtton")
            this->CFD_Label->setText(file_name);

    }
    else {
        QMessageBox::warning(this,"警告","请选择c/cpp");
    }
}

void CCQ_MainWindow::outlog()
{
    Code_Text5->append(jgfx_process->readAllStandardOutput().data());
}

void CCQ_MainWindow::addone(QLineSeries *target,QLineSeries *target1,QLineSeries *target2, int count, float value,float value1,float value2)
{
    target->append(count-20,value);
    target1->append(count-20,value1);
    target2->append(count-20,value2);
}

void CCQ_MainWindow::Oneaction()
{
    if (TimeCount>50)
    {
        RealValue->clear();
        OurMethod->clear();
        DFRMR->clear();
        TimeCount = 20;
    }
    TimeCount++;

    addone(RealValue,OurMethod,DFRMR,TimeCount,testy[TimeCount],prey[TimeCount],pre1[TimeCount]);
}

