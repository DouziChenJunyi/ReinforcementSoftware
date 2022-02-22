#include "jcq_mainwindow.h"
#include "ui_jcq_mainwindow.h"
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
JCQ_MainWindow::JCQ_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    #include <QString>
    ui(new Ui::JCQ_MainWindow)
{
    this->setWindowTitle("寄存器");
    ui->setupUi(this);
    global_setStyleSheet();
    QSizePolicy policy_00_Fixed_Fixed;
    policy_00_Fixed_Fixed.setHorizontalStretch(0);
    policy_00_Fixed_Fixed.setVerticalStretch(0);
    policy_00_Fixed_Fixed.setHorizontalPolicy(QSizePolicy::Fixed);
    policy_00_Fixed_Fixed.setVerticalPolicy(QSizePolicy::Fixed);
    qint8 wid1 = 85, hig1 = 30;
    qint8 wid_CXXZ_B = 75, hig_CXXZ_B = 32;
    qint32 wid_JGFX = 142, hig_JGFX = 32;
    qint32 wid_Edit = 120, hig_Edit = 30;
    qint32 wid_CXXZ_B_Edit = 120, hig_CXXZ_B_Edit = 32;
    qint32 wid_Code_Text = 102, hig_Code_Text = 176;
    qint32 Wid_JGFX_Info = 60, hig_JGFX_Info = 60;

    this->setSizePolicy(policy_00_Fixed_Fixed);
    this->setMinimumSize(950, 700);
    bg_Widget = new QWidget(this);
    bg_Widget->setObjectName(QStringLiteral("bg_Widget"));
    bg_Widget->setSizePolicy(policy_00_Fixed_Fixed);
    bg_Widget->setMinimumSize(950, 700);
    bg_Widget->setMaximumSize(950, 700);
    bg_Widget->setStyleSheet("QWidget#bg_Widget{"
                             "border-image:url(:images/JCQ_background.png)}");

    // chengxu xuanze in Code Produce
    CXXZ_BUtton = new QPushButton(this);
    CXXZ_BUtton->setObjectName(QStringLiteral("CXXZ_BUtton"));
    CXXZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton->move(35,84);
    CXXZ_BUtton->resize(102,30);
    CXXZ_BUtton->setText("待加固程序");
    CXXZ_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    CXXZ_BUtton->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton->setIconSize(QSize(10, 10));

    // daima shengcheng label in Code Produce
    DMSC_Label = new QLineEdit(this);
    DMSC_Label->setObjectName(QStringLiteral("DMSC_Label"));
    DMSC_Label->setSizePolicy(policy_00_Fixed_Fixed);
    DMSC_Label->move(149,84);
    DMSC_Label->resize(120,30);
    DMSC_Label->setPlaceholderText("点击左侧选择程序");
    DMSC_Label->setFocusPolicy(Qt::NoFocus);
    DMSC_Label->setFont(QFont("Microsoft Yahei",11,60));

    // biaoqian kuozhan
    BQKZ_BUtton = new QPushButton(this);
    BQKZ_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    BQKZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    BQKZ_BUtton->move(280,84);
    BQKZ_BUtton->resize(80,30);
    BQKZ_BUtton->setText("标签扩展");
    BQKZ_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    BQKZ_BUtton->setIcon(QIcon(":/images/BQKZ_Icon.png"));
    BQKZ_BUtton->setIconSize(QSize(10, 10));

    LLVM_BUtton = new QPushButton(this);
    LLVM_BUtton->setObjectName(QStringLiteral("LLVM_BUtton"));
    LLVM_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    LLVM_BUtton->move(35,120);
    LLVM_BUtton->resize(102,30);
    LLVM_BUtton->setText("LLVM环境配置");
    LLVM_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    LLVM_BUtton->setIcon(QIcon(":/images/LLVM_Icon.png"));
    LLVM_BUtton->setIconSize(QSize(10, 10));

    DMSC_Label_B = new QLineEdit(this);
    DMSC_Label_B->setObjectName(QStringLiteral("DMSC_Label_B"));
    DMSC_Label_B->setSizePolicy(policy_00_Fixed_Fixed);
    DMSC_Label_B->move(149,120);
    DMSC_Label_B->resize(120,30);
    DMSC_Label_B->setPlaceholderText("点击左侧选择程序");
    DMSC_Label_B->setFocusPolicy(Qt::NoFocus);
    DMSC_Label_B->setFont(QFont("Microsoft Yahei",11,60));

    JCBY_BUtton = new QPushButton(this);
    JCBY_BUtton->setObjectName(QStringLiteral("JCBY_BUtton"));
    JCBY_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    JCBY_BUtton->move(280,120);
    JCBY_BUtton->resize(80,30);
    JCBY_BUtton->setText("交叉编译");
    JCBY_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    JCBY_BUtton->setIcon(QIcon(":/images/JCBY_Icon.png"));
    JCBY_BUtton->setIconSize(QSize(10, 10));

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
    Code_Text4->setPlaceholderText("尚未运行shell脚本，无处理结果");
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
        jg_directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/Desktop/qt/JCQ/llvmtest",tr("*.c*"));
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
            readCode(directory, "CXXZ_BUtton");
    });

    connect(LLVM_BUtton, &QPushButton::clicked, this, [=]()
    {              
        QFileDialog *fileDialog = new QFileDialog(this);
        QString dirpath = fileDialog->getExistingDirectory(this, "选择LLVM环境", "/home/yy2/Desktop/llvm", QFileDialog::ShowDirsOnly);

//        QString dirpath = QFileDialog::getOpenFileName(this,tr("选择LLVM环境"),"/home/yy2/Desktop/llvm",tr("*.c*"));
        bool jgfg=dirpath.isEmpty();
        if(jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        else {
           DMSC_Label_B->setText(dirpath);
        }
    });


    connect(JCBY_BUtton, &QPushButton::clicked, this, [=]()
    {

        crossCompile();
    });

    connect(BQKZ_BUtton, &QPushButton::clicked, this, [=]()
    {
        jg_process = new QProcess(this);
        QString working=jg_efilepath;
        jg_process->setWorkingDirectory(working);
        jg_llfilename=jg_efilename+".ll";
        jg_index_path=jg_efilepath+"/index.txt";
        QString llvmpath = DMSC_Label_B->text();
        if( jg_directory.isEmpty()){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
            if(llvmpath.isEmpty()){
                    QMessageBox::warning(this,"警告","没有选择LLVM环境!!!");
                }
        }
        else if(llvmpath.isEmpty()){
            QMessageBox::warning(this,"警告","没有选择LLVM环境!!!");
        }
        else{
            Code_Text4->append("正在将源程序转化为中间代码!\n");
            jg_arg_to_IR = "clang "+jg_filename+" --target=arm-v7-linux-gnueabi -emit-llvm -g -S -o " +jg_llfilename;
            jg_process->start(jg_arg_to_IR);
            jg_process->waitForFinished();
            Code_Text4->append("转化为中间代码成功!\n");
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
            //qDebug()<<jg_efilepath;

            jg_idllfilename=jg_efilename+"_id.ll";
            Code_Text4->append("正在加固程序，请稍后:");
            jg_command1 = "opt -load /home/yy2/Desktop/qt/JCQ/llvmtest/pass/build/libgenLLFIIndex/libgenLLFIIndex.so -genllfiindexpass -S "+jg_llfilename+" -o "+jg_idllfilename;
            jg_process->start(jg_command1);
            jg_process->waitForFinished();
            Code_Text4->append("代码编号文件生成!");

            jg_dfllfile=jg_efilename+"_df.ll";
            jg_command2 = "opt -load /home/yy2/Desktop/qt/JCQ/llvmtest/pass/build/libdmr/libdmr.so -eddi -select_set_file="+jg_index_path+" -S "+jg_idllfilename+" -o "+jg_dfllfile;
            jg_process->start(jg_command2);
            jg_process->waitForFinished();
            Code_Text4->append("冗余成功!\n");
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

            crossCompile_Flag=true;

        }
    });

    // chengxu xuanze in Error Mimic
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
    MNCS_Edit->setValidator(new QIntValidator(100,1000,this));
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

    connect(CXXZ_BUtton_R, &QPushButton::clicked, this, [=]()
    {

        gzzr_directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/Desktop/qt/JCQ/llvmtest",tr("*"));
        int i=gzzr_directory.lastIndexOf("/");
        gzzr_filename=gzzr_directory.right(directory.length()-i-1);
        gzzr_efilepath=gzzr_directory.left(i+1);
        int j=gzzr_filename.lastIndexOf(".");
        gzzr_efilename=gzzr_filename.left(j);

        qDebug()<<gzzr_efilepath;


        QString directory=gzzr_directory;
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
//        errorMimic();
        QString rmfile = gzzr_efilepath+"/reg/fi";
        gzzr_command2="rm -rf "+rmfile;
        gzzr_process2 = new QProcess(this);
        gzzr_process2->start(gzzr_command2);
        gzzr_process2->waitForFinished();

        QString base = gzzr_efilepath+"/reg";

        if(gzzr_directory.isEmpty()){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
         }
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
        QString golden=gzzr_efilepath +gzzr_efilename;
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
           QMessageBox::warning(this,"警告","请输入100-1000范围的数!!!");
        else{
            //gzzr_count = count;
            Code_Text5->append("<font color=\"#ffffff\"> 初始化……</font>");
            for(int i=0;i<count.toInt();i++){
                dir.mkdir(base+"/fi/fi_"+QString::number(i+1));
                QFile tofile(base+"/fi/fi_"+QString::number(i+1)+"/fi.ini");
                tofile.open(QIODevice::WriteOnly|QIODevice::Text);
                tofile.write(QString(t).toUtf8());
                tofile.close();

                gzzr_f_process= new QProcess(this);
                gzzr_f_process->setWorkingDirectory(base+"/fi/fi_"+QString::number(i+1));
                QString execs=gzzr_efilepath + gzzr_efilename;
                gzzr_f_process->start("/home/yy2/res/gemFI/build/ARM/gem5.opt  /home/yy2/res/gemFI/configs/example/se.py -c "+execs);
                bool ret;
                ret=gzzr_f_process->waitForFinished(10000);

                QString result=gzzr_f_process->readAll();
                QFile outfile(base+"/fi/fi_"+QString::number(i+1)+"/out.txt");
                outfile.open(QIODevice::ReadWrite| QIODevice::Text);
                if(!ret)
                    outfile.write("timeout");
                outfile.write(result.toUtf8());
                outfile.close();
                gzzr_f_process->kill();
            }
            gzzr_count=count;
            for(int i=0;i<gzzr_count.toInt();i++){
                float fr=i+1;
                float process_num=fr/gzzr_count.toInt();
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
    model->setData(index, QVariant("EAX"));
    index = model->index(2, 0, QModelIndex());
    model->setData(index, QVariant("EBX"));
    index = model->index(3, 0, QModelIndex());
    model->setData(index, QVariant("ECX"));
    index = model->index(4, 0, QModelIndex());
    model->setData(index, QVariant("EDX"));
    index = model->index(5, 0, QModelIndex());
    model->setData(index, QVariant("ESI"));
    index = model->index(6, 0, QModelIndex());
    model->setData(index, QVariant("EDI"));
    index = model->index(7, 0, QModelIndex());
    model->setData(index, QVariant("ESP"));
    index = model->index(8, 0, QModelIndex());
    model->setData(index, QVariant("EBP"));
    index = model->index(9, 0, QModelIndex());
    model->setData(index, QVariant("EIP"));


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
    model->setData(index, QVariant("0x003A"));
    index = model->index(3, 1, QModelIndex());
    model->setData(index, QVariant("0x0112"));
    index = model->index(4, 1, QModelIndex());
    model->setData(index, QVariant("0x0185"));
    index = model->index(5, 1, QModelIndex());
    model->setData(index, QVariant("0x0251"));
    index = model->index(6, 1, QModelIndex());
    model->setData(index, QVariant("0x02E1"));
    index = model->index(7, 1, QModelIndex());
    model->setData(index, QVariant("0x0352"));
    index = model->index(7, 1, QModelIndex());
    model->setData(index, QVariant("0x03A5"));
    index = model->index(8, 1, QModelIndex());
    model->setData(index, QVariant("0x0412"));
    index = model->index(9, 1, QModelIndex());
    model->setData(index, QVariant("0x0456"));


    for (int row=1; row < 10; row++)
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
    monitor_ItemA->setText("数据寄存器25%");
    monitor_ItemA->setFont(QFont("Microsoft Yahei",9,60));

    monitor_ItemB = new QPushButton(this);
    monitor_ItemB->setObjectName(QStringLiteral("monitor_ItemB"));
    monitor_ItemB->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemB->move(736, 270);
    monitor_ItemB->resize(70, 15);
    monitor_ItemB->setText("地址寄存器25%");
    monitor_ItemB->setFont(QFont("Microsoft Yahei",9,60));


    monitor_ItemC = new QPushButton(this);
    monitor_ItemC->setObjectName(QStringLiteral("monitor_ItemC"));
    monitor_ItemC->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemC->move(736, 288);
    monitor_ItemC->resize(70, 15);
    monitor_ItemC->setText("标志寄存器15%");
    monitor_ItemC->setFont(QFont("Microsoft Yahei",9,60));


    monitor_ItemD = new QPushButton(this);
    monitor_ItemD->setObjectName(QStringLiteral("monitor_ItemD"));
    monitor_ItemD->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemD->move(736, 306);
    monitor_ItemD->resize(70, 15);
    monitor_ItemD->setText("段寄存器 35%");
    monitor_ItemD->setFont(QFont("Microsoft Yahei",10,60));

    Code_Text5 = new QTextEdit(this);
    Code_Text5->setSizePolicy(policy_00_Fixed_Fixed);
    Code_Text5->move(813, 122);
    Code_Text5->resize(104,212);
    Code_Text5->setPlaceholderText("尚未运行shell脚本，无处理结果");
    Code_Text5->setFocusPolicy(Qt::NoFocus);

    CXXZ_BUtton_B = new QPushButton(this);
    CXXZ_BUtton_B->setObjectName(QStringLiteral("CXXZ_BUtton_B"));
    CXXZ_BUtton_B->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton_B->move(35,415);
    CXXZ_BUtton_B->resize(wid_CXXZ_B,hig_CXXZ_B);
    CXXZ_BUtton_B->setText("文件选择");
    CXXZ_BUtton_B->setFont(QFont("Microsoft Yahei",14,60));
    CXXZ_BUtton_B->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton_B->setIconSize(QSize(10, 10));

    JGFX_Label = new QLineEdit(this);
    JGFX_Label->setObjectName(QStringLiteral("JGFX_Label"));
    JGFX_Label->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_Label->move(118,415);
    JGFX_Label->resize(wid_CXXZ_B_Edit,hig_CXXZ_B_Edit);
    JGFX_Label->setPlaceholderText("点击左侧选择文件夹");
    JGFX_Label->setFocusPolicy(Qt::NoFocus);
    JGFX_Label->setFont(QFont("Microsoft Yahei",11,60));

    // Result Analysis button
    JGFX_BUtton = new QPushButton(this);
    JGFX_BUtton->setObjectName(QStringLiteral("JGFX_BUtton"));
    JGFX_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_BUtton->move(248,415);
    JGFX_BUtton->resize(wid_JGFX,hig_JGFX);
    JGFX_BUtton->setText("结果分析");
    JGFX_BUtton->setFont(QFont("Microsoft Yahei",16,60));
    JGFX_BUtton->setIcon(QIcon(":/images/JGFX_Icon.png"));
    JGFX_BUtton->setIconSize(QSize(10, 10));

    connect(CXXZ_BUtton_B, &QPushButton::clicked, this, [=]()
    {
        QFileDialog *fileDialog = new QFileDialog(this);
        jgfx_filepath = fileDialog->getExistingDirectory(this,tr("选择统计分析的文件夹"),"/home/yy2/Desktop/qt/JCQ/llvmtest");
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


    monitor_ItemA_val = new QPushButton(this);
    monitor_ItemA_val->setObjectName(QStringLiteral("monitor_ItemA_val"));
    monitor_ItemA_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemA_val->move(646, 498);
    monitor_ItemA_val->resize(36, 20);
    monitor_ItemA_val->setText("28%");
    monitor_ItemA_val->setFont(QFont("Microsoft Yahei",11,60));

    A = new QPushButton(this);
    A->setObjectName(QStringLiteral("A"));
    A->setSizePolicy(policy_00_Fixed_Fixed);
    A->move(646, 476);
    A->resize(44, 20);
    A->setText("时间超时");
    A->setFont(QFont("Microsoft Yahei",9,60));
    A->setStyleSheet("color: darkorange");

    monitor_ItemB_val = new QPushButton(this);
    monitor_ItemB_val->setObjectName(QStringLiteral("monitor_ItemB_val"));
    monitor_ItemB_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemB_val->move(624, 586);
    monitor_ItemB_val->resize(36, 20);
    monitor_ItemB_val->setText("28%");
    monitor_ItemB_val->setFont(QFont("Microsoft Yahei",11,60));

    B = new QPushButton(this);
    B->setObjectName(QStringLiteral("B"));
    B->setSizePolicy(policy_00_Fixed_Fixed);
    B->move(624, 564);
    B->resize(50, 20);
    B->setText("检测到错误");
    B->setFont(QFont("Microsoft Yahei",9,60));
    B->setStyleSheet("color: forestgreen");

    monitor_ItemC_val = new QPushButton(this);
    monitor_ItemC_val->setObjectName(QStringLiteral("monitor_ItemC_val"));
    monitor_ItemC_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemC_val->move(857, 508);
    monitor_ItemC_val->resize(36, 20);
    monitor_ItemC_val->setText("28%");
    monitor_ItemC_val->setFont(QFont("Microsoft Yahei",11,60));

    C = new QPushButton(this);
    C->setObjectName(QStringLiteral("C"));
    C->setSizePolicy(policy_00_Fixed_Fixed);
    C->move(857, 486);
    C->resize(55, 20);
    C->setText("未检测到错误");
    C->setFont(QFont("Microsoft Yahei",9,60));
    C->setStyleSheet("color: darkturquoise");

    monitor_ItemD_val = new QPushButton(this);
    monitor_ItemD_val->setObjectName(QStringLiteral("monitor_ItemD_val"));
    monitor_ItemD_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemD_val->move(857, 617);
    monitor_ItemD_val->resize(36, 20);
    monitor_ItemD_val->setText("28%");
    monitor_ItemD_val->setFont(QFont("Microsoft Yahei",11,60));

    D = new QPushButton(this);
    D->setObjectName(QStringLiteral("D"));
    D->setSizePolicy(policy_00_Fixed_Fixed);
    D->move(857, 595);
    D->resize(44, 20);
    D->setText("正确执行");
    D->setFont(QFont("Microsoft Yahei",9,60));
    D->setStyleSheet("color: dodgerblue");

    connect(JGFX_BUtton, &QPushButton::clicked, this, [=]()
    {
        QString workpath = jgfx_filepath;
        if(jgfx_filepath.isEmpty()){
            QMessageBox::warning(this,"警告","没有选择文件夹!!!");
        }
        jgfx_process = new QProcess(this);
        jgfx_process->setWorkingDirectory(workpath);
        //jgfx_command1 ="python /home/yy2/Desktop/qt/JCQ/llvmtest/reg/.statistic1.py";
        jgfx_command1 ="python ./.statistic1.py";
        jgfx_process->start(jgfx_command1);
        jgfx_process->waitForFinished();
        QString res = jgfx_process->readAllStandardOutput();
        qDebug()<<res;
        //Code_Text5->append(output);
        QStringList res_list = res.split('\n');
        QString mncs_num = res_list[0].split(':')[1];
        QString cwcs_num = res_list[1].split(':')[1];
        QString qt_num = res_list[2].split(':')[1];
        QString nt_num = res_list[3].split(':')[1];
        QString jcl_num = res_list[5].split(':')[1];

        int detected = mncs_num.toInt()+cwcs_num.toInt()+qt_num.toInt();



        JGFX_MNCS_Label->setText(gzzr_count);
        JGFX_MNCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_CWCS_Label->setText(QString::number(detected));
        JGFX_CWCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_QTCW_Label->setText(nt_num+"  ");
        JGFX_QTCW_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_JCL_Label->setText(jcl_num);
        JGFX_JCL_Label->setFont(QFont("Microsoft Yahei",20,50));
        JGFX_BUtton->blockSignals(true);

        monitor_ItemA_val->setText("0%");
        monitor_ItemA_val->setFont(QFont("Microsoft Yahei",11,60));
        monitor_ItemB_val->setText("45%");
        monitor_ItemB_val->setFont(QFont("Microsoft Yahei",11,60));
        monitor_ItemC_val->setText("3%");
        monitor_ItemC_val->setFont(QFont("Microsoft Yahei",11,60));
        monitor_ItemD_val->setText("52%");
        monitor_ItemD_val->setFont(QFont("Microsoft Yahei",11,60));


        delete jgfx_process;
        jgfx_process = nullptr;
    });



}

JCQ_MainWindow::~JCQ_MainWindow()
{
    delete ui;
}

void JCQ_MainWindow::global_setStyleSheet() {
    this->setStyleSheet("QPushButton#CXXZ_BUtton, #BQKZ_BUtton, #CXXZ_BUtton_R,#A,#B,#C,#D,"
                        "#CWMN_BUtton, #CXXZ_BUtton_B, #JGFX_BUtton,#o_BUtton,#r_BUtton,"
                        "#Block_A, #Block_B, #Block_C, #Block_D,#m_BUtton,#j_BUtton,"
                        "#monitor_ItemA_val, #monitor_ItemB_val,"
                        "#monitor_ItemC_val, #monitor_ItemD_val,"
                        "#monitor_ItemA,#monitor_ItemB,"
                        "#monitor_ItemC, #monitor_ItemD,"
                        "#JGFX_MNCS_Label, #JGFX_CWCS_Label,"
                        "#JGFX_QTCW_Label, #JGFX_JCL_Label,"
                        "#CWFGL_Lable1, #CWFGL_Lable2, #CWFGL_Val,"
                        "#LLVM_BUtton, #JCBY_BUtton{"
                        "background-color:rgba(20,32,84, 1);"
                        "color:#24FDFF;"
                        "border: 1px solid #02246c;"
                        "}"
                        "QPushButton#CXXZ_BUtton:hover, #BQKZ_BUtton:hover,#CXXZ_BUtton_R:hover,"
                        "#CWMN_BUtton:hover, #CXXZ_BUtton_B:hover, #JGFX_BUtton:hover,"
                        "#LLVM_BUtton:hover, #JCBY_BUtton:hover{"
                        "background-color:rgba(40,40,160, 1)"
                        "}"
                        "QPushButton#CXXZ_BUtton:pressed, #BQKZ_BUtton:pressed,#CXXZ_BUtton_R:pressed,"
                        "#CWMN_BUtton:pressed, #CXXZ_BUtton_B:pressed, #JGFX_BUtton:pressed,"
                        "#Block_A:pressed, #Block_B:pressed, #Block_C:pressed, #Block_D:pressed"
                        "#LLVM_BUtton:pressed, #JCBY_BUtton:pressed{"
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


void JCQ_MainWindow::readCode(QString directory, QString EditLine_name)
{

    QStringList name_list = directory.split('/');
    QString file_name = name_list[name_list.count()-1];
    //qDebug()<<directory;
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
        filepath=directory;
        int i=directory.lastIndexOf("/");
        filename=directory.right(directory.length()-i-1);
        efilepath=directory.left(i+1);
        int j=filename.lastIndexOf(".");
        efilename=filename.left(j);
        if (EditLine_name == "CXXZ_BUtton") {
            this->DMSC_Label->setText(file_name);
        }
        if (EditLine_name == "LLVM_BUtton")
            this->DMSC_Label_B->setText(file_name);

    }
    else {
        QMessageBox::warning(this,"警告","请选择c/cpp");
    }
}


void JCQ_MainWindow::crossCompile()
{
    if(crossCompile_Flag)
    {
       process = new QProcess(this);
       QString working=efilepath;
       qDebug()<<working;
       qDebug()<<efilename;
       process->setWorkingDirectory(working);
       Code_Text4->append("正在编译程序:");
       dfllfile=efilename+"_df.ll";
       command3 ="clang "+dfllfile+" --target=arm-v7-linux-gnueabi -c -o "+efilename+"_df.o" ;
       process->start(command3);
       process->waitForFinished();
       Code_Text4->append("生成链接文件!");

       command4 ="arm-linux-gnueabi-gcc "+efilename+"_df.o exec.o -static -o "+efilename+"_df";
       process->start(command4);
       process->waitForFinished();
       Code_Text4->append("生成可执行文件!");
    }
    else
    {
       QMessageBox::warning(this,"警告","请先完成寄存器加固!!!");
    }    
}


/*
void JCQ_MainWindow::tagExpand()
{
    process = new QProcess(this);
    QString working=efilepath;
    process->setWorkingDirectory(working);
    llfilename=efilename+".ll";
    index_path=efilepath+"/index.txt";
    QString llvmpath = DMSC_Label_B->text();
    if(directory.isEmpty()){
        QMessageBox::warning(this,"警告","没有选择文件!!!");
        if(llvmpath.isEmpty()){
                QMessageBox::warning(this,"警告","没有选择LLVM环境!!!");
            }
    }
    else if(llvmpath.isEmpty()){
        QMessageBox::warning(this,"警告","没有选择LLVM环境!!!");
    }
    else{
    // translate source to llvm ir
    Code_Text4->append("正在将源程序转化为中间代码!\n");
    //clang dm.cpp --target=arm-v7-linux-gnueabi  -emit-llvm -g -S -o dm.ll
    arg_to_IR = "clang "+filename+" --target=arm-v7-linux-gnueabi -emit-llvm -g -S -o " +llfilename;
    process->start(arg_to_IR);
    process->waitForFinished();
    Code_Text4->append("转化为中间代码成功!\n");

    idllfilename=efilename+"_id.ll";
    Code_Text4->append("正在加固程序，请稍后:");
    //opt -load ./pass/build/libgenLLFIIndex/libgenLLFIIndex.so -genllfiindexpass -S dm.ll -o dm_id.ll
    command1 = "opt -load /home/yy2/Desktop/qt/JCQ/llvmtest/pass/build/libgenLLFIIndex/libgenLLFIIndex.so -genllfiindexpass -S "+llfilename+" -o "+idllfilename;
    process->start(command1);
    process->waitForFinished();
    Code_Text4->append("代码编号文件生成!");
    dfllfile=efilename+"_df.ll";
    //opt -load ./pass/build/libdmr/libdmr.so -eddi -select_set_file=index.txt -S dm_id.ll -o dm_df.ll
    command2 = "opt -load /home/yy2/Desktop/qt/JCQ/llvmtest/pass/build/libdmr/libdmr.so -eddi -select_set_file="+index_path+" -S "+idllfilename+" -o "+dfllfile;
    process->start(command2);
    process->waitForFinished();
    Code_Text4->append("冗余成功!\n");
    crossCompile_Flag=true;
    }

}
*/


void JCQ_MainWindow::errorMimic()    //perform fault injection
{
    QString rmfile = efilepath_CWMN+"/reg/fi";
    //删除原有文件夹
    command2_CWMN="rm -rf "+rmfile;
    process2_CWMN = new QProcess(this);
    process2_CWMN->start(command2);
    process2_CWMN->waitForFinished();

    QString base = efilepath+"/reg";

    if(directory_CWMN.isEmpty()){
        QMessageBox::warning(this,"警告","没有选择文件!!!");
     }
    //创建 fi 以及golden目录
    QDir dir_fi;
    QDir dir_golden;
    dir_fi.mkdir(base+"/fi/");
    dir_golden.mkdir(base+"/fi/golden");

    // nofi
    process_CWMN = new QProcess(this);
    QFile srcfile(base+"/nofi/fi.ini");
    srcfile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray gt=srcfile.readAll();
    srcfile.close();
    QFile gtofile(base+"/fi/golden/fi.ini");
    gtofile.open(QIODevice::WriteOnly|QIODevice::Text);
    gtofile.write(QString(gt).toUtf8());
    gtofile.close();

    process_CWMN->setWorkingDirectory(base+"/fi/golden");
    QString golden=efilepath_CWMN+efilename_CWMN;
    // /gemFI/build/ARM/gem5.opt /gemFI/configs/example/se.py -c dm_df"
    command1_CWMN="/home/yy2/res/gemFI/build/ARM/gem5.opt  /home/yy2/res/gemFI/configs/example/se.py -c "+golden;
    process_CWMN->start(command1_CWMN);
    process_CWMN->waitForFinished();
    QString gresult=process_CWMN->readAll();
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
    for(int i=0;i<count.toInt();i++){
        dir.mkdir(base+"/fi/fi_"+QString::number(i+1));
        QFile tofile(base+"/fi/fi_"+QString::number(i+1)+"/fi.ini");
        tofile.open(QIODevice::WriteOnly|QIODevice::Text);
        tofile.write(QString(t).toUtf8());
        tofile.close();

        f_process_CWMN= new QProcess(this);
        //故障注入
        f_process_CWMN->setWorkingDirectory(base+"/fi/fi_"+QString::number(i+1));
        QString execs=efilepath_CWMN+efilename_CWMN;
        // /gemFI/build/ARM/gem5.opt /gemFI/configs/example/se.py -c dm_df"
        f_process_CWMN->start("/home/yy2/res/gemFI/build/ARM/gem5.opt  /home/yy2/res/gemFI/configs/example/se.py -c "+execs);
        //Timeout
        bool ret;
        ret=f_process_CWMN->waitForFinished(10000);

        QString result=f_process_CWMN->readAll();
        QFile outfile(base+"/fi/fi_"+QString::number(i+1)+"/out.txt");
        outfile.open(QIODevice::ReadWrite| QIODevice::Text);
        if(!ret)
        {
            outfile.write("timeout");
        }
        outfile.write(result.toUtf8());
        outfile.close();
        f_process_CWMN->kill();
        //ui->textBrowser_3->append("注入次数："+QString::number(i+1));
    }
    Code_Text5->append("故障注入"+count+"次");
    Code_Text5->append("故障注入结束");
    }
}
