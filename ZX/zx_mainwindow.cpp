#include "zx_mainwindow.h"
#include "ui_zx_mainwindow.h"
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
#include <QFileInfo>
#include <QByteArray>
#include <QCryptographicHash>
#include <QDir>
void  genIniFile(QString efilepath,QString filepath);

ZX_MainWindow::ZX_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ZX_MainWindow)
{
    this->setWindowTitle("总线");
    ui->setupUi(this);
    global_setStyleSheet();
    QSizePolicy policy_00_Fixed_Fixed;
    policy_00_Fixed_Fixed.setHorizontalStretch(0);
    policy_00_Fixed_Fixed.setVerticalStretch(0);
    policy_00_Fixed_Fixed.setHorizontalPolicy(QSizePolicy::Fixed);
    policy_00_Fixed_Fixed.setVerticalPolicy(QSizePolicy::Fixed);
    qint8 wid1 = 85, hig1 = 30;
    qint8 wid_CXXZ_B = 73, hig_CXXZ_B = 33;
    qint32 wid_JGFX = 142, hig_JGFX = 33;
    qint32 wid_Edit = 120, hig_Edit = 30;
    qint32 wid_CXXZ_B_Edit = 119, hig_CXXZ_B_Edit = 33;
    qint32 wid_Code_Text = 102, hig_Code_Text = 213;
    qint32 Wid_JGFX_Info = 60, hig_JGFX_Info = 60;


    this->setMinimumSize(950, 700);
    bg_Widget = new QWidget(this);
    bg_Widget->setObjectName(QStringLiteral("bg_Widget"));
    bg_Widget->setSizePolicy(policy_00_Fixed_Fixed);
    bg_Widget->setMinimumSize(950, 700);
    bg_Widget->setMaximumSize(950, 700);
    bg_Widget->setStyleSheet("QWidget#bg_Widget{"
                                 "border-image: url(:/images/ZX_Background.png)}");

    // 左上角“代码生成”区域的相关代码
    CXXZ_BUtton = new QPushButton(this);
    CXXZ_BUtton->setObjectName(QStringLiteral("CXXZ_BUtton"));
    CXXZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton->move(35,82);
    CXXZ_BUtton->resize(wid1-5,hig1);
    CXXZ_BUtton->setText("待加固程序");
    CXXZ_BUtton->setFont(QFont("Microsoft Yahei",14,60));
    CXXZ_BUtton->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton->setIconSize(QSize(5, 5));


    DMSC_Label = new QLineEdit(this);
    DMSC_Label->setObjectName(QStringLiteral("DMSC_Label"));
    DMSC_Label->setSizePolicy(policy_00_Fixed_Fixed);
    DMSC_Label->move(117,82);
    DMSC_Label->resize(wid_Edit,hig_Edit);
    DMSC_Label->setPlaceholderText("点击左侧选择程序");
    DMSC_Label->setFocusPolicy(Qt::NoFocus);
    DMSC_Label->setFont(QFont("Microsoft Yahei",11,60));

    BQKZ_BUtton = new QPushButton(this);
    BQKZ_BUtton->setObjectName(QStringLiteral("BQKZ_BUtton"));
    BQKZ_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    BQKZ_BUtton->move(247,82);
    BQKZ_BUtton->resize(wid1,hig1);
    BQKZ_BUtton->setText("标签扩展");
    BQKZ_BUtton->setFont(QFont("Microsoft Yahei",15,60));
    BQKZ_BUtton->setIcon(QIcon(":/images/BQKZ_Icon.png"));
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
        QString directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/res/tt/arm_test_hot",tr("*.c*"));
        jg_jgfg=directory.isEmpty();
        if(jg_jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        jg_filepath=directory;
        int i=directory.lastIndexOf("/");
        jg_filename=directory.right(directory.length()-i-1);
        jg_efilepath=directory.left(i+1);
        int j=jg_filename.lastIndexOf(".");
        jg_efilename=jg_filename.left(j);

        bool jgfg=directory.isEmpty();
        if(jgfg){
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        }
        else
            readCode(directory);
    });

    connect(BQKZ_BUtton, &QPushButton::clicked, this, [=]()
    {
        BQKZ_BUtton->blockSignals(true);
        if(!jg_jgfg){
            QFile dis(jg_efilepath+jg_efilename+"_dmr");
            if(dis.exists())dis.remove();
            QProcess p(0);
            QString working=jg_efilepath;
            p.setWorkingDirectory(working);
            QString llfilename=jg_efilename+".ll";
            QString command1="clang "+jg_filename+" --target=arm-v7-linux-gnueabi -emit-llvm -S -g -o "+llfilename;
            p.start(command1);
            p.waitForFinished();
            if(p.readAll().isEmpty())
                Code_Text4->append("<font color=\"#ffffff\">"+llfilename+" 中间代码文件生成！"+"</font>");
            QCoreApplication::processEvents();

            QString jg_llfilepath = jg_efilepath+llfilename;
            qDebug()<<jg_llfilepath;
            QFile file1(jg_llfilepath);
            if(!file1.open(QIODevice::ReadOnly | QIODevice::Text)){
               QMessageBox::warning(this,"警告","无法打开该文件！");
            }
            qint32 linecnt = 0;
            QString str1;
            QStringList str_list;
            QByteArray line;
            while (!file1.atEnd()) {
                line = file1.readLine();
                str_list.append((QString)line);
                linecnt++;
            }
            file1.close();
            for (int i = 0; i < linecnt; i++) {
                    str1 += str_list[i];
            }
            this->Code_Text2->setText(str1);

            QString idllfilename=jg_efilename+"_id.ll";
            QString command2="opt -load /home/yy2/res/eddi/libgenLLFIIndex.so -genllfiindexpass "+llfilename+" -S -o "+idllfilename;
            p.start(command2);
            p.waitForFinished();
            if(p.readAll().isEmpty())
                Code_Text4->append("<font color=\"#ffffff\">"+idllfilename+" 代码编号文件生成！"+"</font>");
            QCoreApplication::processEvents();
            QString command3="./gen_index 90";
            p.start(command3);
            p.waitForFinished();
            QFile file("index.txt");
            if(file.exists())
                Code_Text4->append("<font color=\"#ffffff\"> index文件生成！</font>");
            QCoreApplication::processEvents();

            QString dmrllfile=jg_efilename+"_dmr.ll";
            QString command4="opt -load /home/yy2/res/eddi/libdmr.so -eddi "+idllfilename+" -select_set_file=index.txt  -S -o "+dmrllfile;
            p.start(command4);
            p.waitForFinished();
            if(!p.readAll().isEmpty())
                Code_Text4->append("<font color=\"#ffffff\"> 冗余成功！</font>");
            QCoreApplication::processEvents();

            QString jg_llfilepath1 = jg_efilepath+dmrllfile;
            qDebug()<<jg_llfilepath1;
            QFile file2(jg_llfilepath1);
            if(!file2.open(QIODevice::ReadOnly | QIODevice::Text)){
               QMessageBox::warning(this,"警告","无法打开该文件！");
            }
            qint32 linecnt1 = 0;
            QString str11;
            QStringList str_list1;
            QByteArray line1;
            while (!file2.atEnd()) {
                line1 = file2.readLine();
                str_list1.append((QString)line1);
                linecnt1++;
            }
            file2.close();
            for (int i = 0; i < linecnt1; i++) {
                    str11 += str_list1[i];
            }
            this->Code_Text3->setText(str11);

            QString command5="arm-linux-gnueabi-gcc exec.c -c -o exec.o";
            QString command6="clang "+dmrllfile+" --target=arm-v7-linux-gnueabi -c -fPIC -o "+jg_efilename+"_dmr.o";
            p.start(command5);
            p.waitForFinished();
            p.start(command6);
            p.waitForFinished();
            Code_Text4->append("<font color=\"#ffffff\"> 生成链接文件…… </font>");
            QCoreApplication::processEvents();
            QString command7="arm-linux-gnueabi-gcc exec.o "+jg_efilename+"_dmr.o  -static -o "+jg_efilename+"_dmr";
            p.start(command7);
            p.waitForFinished();

            QDir di(working);
            foreach(QFileInfo msi,di.entryInfoList()){
                if(msi.isFile()&&(msi.suffix()=="ll"||msi.suffix()=="o"))
                    di.remove(msi.fileName());
            }

            Code_Text4->append("<font color=\"#ffffff\"> 生成可执行文件！</font>");
        }else{
            QMessageBox::warning(this,"警告","请选择文件");
        }
        Code_Text4->blockSignals(false);
    });

    // 右上角“错误模拟”区域的相关代码
    CXXZ_BUtton_R = new QPushButton(this);
    CXXZ_BUtton_R->setObjectName(QStringLiteral("CXXZ_BUtton_R"));
    CXXZ_BUtton_R->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton_R->move(493,85);
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
    Code_Text5->setPlaceholderText("尚无实验结果！");
    Code_Text5->setFocusPolicy(Qt::NoFocus);

    connect(CXXZ_BUtton_R, &QPushButton::clicked, this, [=]()
    {
        QString directory=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/res/tt/arm_test_hot",tr("*"));
        gzzr_filefg=directory.isEmpty();
        if(gzzr_filefg)
            QMessageBox::warning(this,"警告","没有选择文件!!!");
        gzzr_filepath=directory;
        int i=directory.lastIndexOf("/");
        gzzr_filename=directory.right(directory.length()-i-1);
        gzzr_efilepath=directory.left(i+1);
        int j=gzzr_filename.lastIndexOf(".");
        gzzr_efilename=gzzr_filename.left(j);

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

        CWMN_BUtton->blockSignals(true);
        genIniFile(gzzr_efilepath,gzzr_filepath);
        QString base=gzzr_efilepath+"gem";
        QProcess p(0);

        QRegExp rxa("data flow find error!");
        QRegExp rxp("BEGIN LIBC BACKTRACE");
        QRegExp rxc("^[0-9]+$");

        gzzr_Algor=0, gzzr_Prog=0, gzzr_timeout=0;
        gzzr_SDC=0;
        gzzr_count=MNCS_Edit->text();
        gzzr_cun=gzzr_count.toInt();
        if(!gzzr_filefg&&!gzzr_count.isEmpty()&&gzzr_count.toInt()>=1&&gzzr_count.toInt()<=1000){
            QDir outs(base+"/fi");
            outs.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
            if(!outs.entryInfoList().isEmpty()){
                QFileInfoList filelist=outs.entryInfoList();
                foreach(QFileInfo f,filelist){
                    if(f.isFile()){
                        f.dir().remove(f.fileName());
                    }else{
                        outs.setPath(base+"/fi/"+f.fileName());
                        outs.removeRecursively();
                    }
                }
            }
            Code_Text5->append("<font color=\"#ffffff\"> 初始化……</font>");
            QCoreApplication::processEvents();
            QDir gold;
            gold.mkdir(base+"/fi/golden");
            QFile srcfile(base+"/nofi/fi.ini");
            srcfile.open(QIODevice::ReadOnly|QIODevice::Text);
            QByteArray gt=srcfile.readAll();
            srcfile.close();
            QFile gtofile(base+"/fi/golden/fi.ini");
            gtofile.open(QIODevice::WriteOnly|QIODevice::Text);
            gtofile.write(QString(gt).toUtf8());
            gtofile.close();
            //加固
            p.setWorkingDirectory(base+"/fi/golden");
            QString golden=gzzr_efilepath + gzzr_efilename;
            QString command8="/home/yy2/res/gemFI/build/ARM/gem5.opt  /home/yy2/res/gemFI/configs/example/se.py -c " + golden;
            p.start(command8);
            p.waitForFinished();
            QString gresult=p.readAll();


            QCryptographicHash h1(QCryptographicHash::Md5);
            h1.addData(gresult.toUtf8());
            QString md5g=h1.result().toHex();
            QFile goutfile(base+"/fi/golden/out.txt");
            goutfile.open(QIODevice::ReadWrite| QIODevice::Text);
            goutfile.write(gresult.toUtf8());
            goutfile.close();
            QFile file(base+"/fiini/fi.ini");
            file.open(QIODevice::ReadOnly|QIODevice::Text);
            QByteArray t=file.readAll();
            file.close();
            QDir dir;
            gzzr_tos=gzzr_count.toInt();
            for(int i=0;i<gzzr_count.toInt();i++){
                dir.mkdir(base+"/fi/fi_"+QString::number(i+1));
                QFile tofile(base+"/fi/fi_"+QString::number(i+1)+"/fi.ini");
                tofile.open(QIODevice::WriteOnly|QIODevice::Text);
                tofile.write(QString(t).toUtf8());
                tofile.close();
                p.setWorkingDirectory(base+"/fi/fi_"+QString::number(i+1));
                QString execs=gzzr_efilepath+gzzr_efilename;
                p.start("/home/yy2/res/gemFI/build/ARM/gem5.opt  /home/yy2/res/gemFI/configs/example/se.py -c "+execs);
                bool b=p.waitForFinished(10000);
                if(!b) gzzr_timeout++;
                QString result=p.readAll();
                if(rxa.indexIn(result)!=-1)gzzr_Algor++;
                else if(rxp.indexIn(result)!=-1)gzzr_Prog++;
                else{
                    QCryptographicHash h2(QCryptographicHash::Md5);
                    h2.addData(result.toUtf8());
                    QString r=h2.result().toHex();
                    if(QString::compare(r,md5g)!=0) gzzr_SDC++;        }
                QFile outfile(base+"/fi/fi_"+QString::number(i+1)+"/out.txt");
                outfile.open(QIODevice::ReadWrite| QIODevice::Text);
                if(!b) outfile.write("timeout");

                outfile.write(result.toUtf8());
                outfile.close();
                float fr=i+1;
                float process=fr/gzzr_tos;
                Code_Text5->append("<font color=\"#ffffff\"> 注入次数："+QString::number(i+1)+"   ==>>进度：</font>"+"<font color=\"#00ff00\">"+QString::number(process*100,'f',0)+"%</font>");
                QCoreApplication::processEvents();
            }
            Code_Text5->append("<font color=\"#ffffff\"> 故障注入完毕！！！ </font>");
            gzzr_res=1-(gzzr_SDC/gzzr_tos);
            /*
            Code_Text5->append("系统检测到错误："+QString::number(gzzr_Prog));
            Code_Text5->append("超时执行："+QString::number(gzzr_timeout));
            Code_Text5->append("正确执行："+QString::number(gzzr_count.toInt()-gzzr_Algor-gzzr_Prog-gzzr_timeout-gzzr_SDC));
            Code_Text5->append("系统检测到错误："+QString::number(gzzr_Prog));
            Code_Text5->append("SDC错误："+QString::number(gzzr_SDC));
            Code_Text5->append("检测率："+QString::number(gzzr_res*100,'f',2)+"%");
            */


            QFile ans(base+"/result.txt");
            if(ans.exists()){
                ans.remove();
            }
            ans.open(QIODevice::ReadWrite|QIODevice::Text);
            ans.write("算法检测到错误："+QString::number(gzzr_Algor).toUtf8());
            ans.write("\n系统检测到错误："+QString::number(gzzr_Prog).toUtf8());
            ans.write("\n超时执行："+QString::number(gzzr_timeout).toUtf8());
            ans.write("\n正确执行："+QString::number(gzzr_count.toInt()-gzzr_Algor-gzzr_Prog-gzzr_timeout-gzzr_SDC).toUtf8());
            ans.write("\n未检测到错误："+QString::number(gzzr_SDC).toUtf8());
            ans.write("\n检测率："+QString::number(gzzr_res*100,'f',2).toUtf8()+"%");
            ans.close();

        }else{
            QMessageBox::warning(this,"警告","请选择文件或输入1-1000范围的数!");
        }
        CWMN_BUtton->blockSignals(false);
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
    model->setData(index, QVariant("地址总线"));
    index = model->index(2, 0, QModelIndex());
    model->setData(index, QVariant("数据总线"));
    index = model->index(3, 0, QModelIndex());
    model->setData(index, QVariant("控制总线"));
    index = model->index(4, 0, QModelIndex());
    model->setData(index, QVariant("ISA"));
    index = model->index(5, 0, QModelIndex());
    model->setData(index, QVariant("EISA"));
    index = model->index(6, 0, QModelIndex());
    model->setData(index, QVariant("SPI"));
    index = model->index(7, 0, QModelIndex());
    model->setData(index, QVariant("I2C"));

    index = model->index(0, 1, QModelIndex());
    model->setData(index, QVariant("起始地址"));
    index = model->index(0, 2, QModelIndex());
    model->setData(index, QVariant("翻转位数"));
    index = model->index(0, 3, QModelIndex());
    model->setData(index, QVariant("方式"));
    index = model->index(0, 4, QModelIndex());
    model->setData(index, QVariant("时间"));

    index = model->index(1, 1, QModelIndex());
    model->setData(index, QVariant("0x0003"));
    index = model->index(2, 1, QModelIndex());
    model->setData(index, QVariant("0x00B4"));
    index = model->index(3, 1, QModelIndex());
    model->setData(index, QVariant("0x0152"));
    index = model->index(4, 1, QModelIndex());
    model->setData(index, QVariant("0x01A8"));
    index = model->index(5, 1, QModelIndex());
    model->setData(index, QVariant("0x023B"));
    index = model->index(6, 1, QModelIndex());
    model->setData(index, QVariant("0x02E1"));
    index = model->index(7, 1, QModelIndex());
    model->setData(index, QVariant("0x0329"));



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
                model->setData(index, t);;
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
    Block_A->move(714, 257);
    Block_A->resize(14, 7);


    Block_B = new QPushButton(this);
    Block_B->setObjectName(QStringLiteral("Block_B"));
    Block_B->setSizePolicy(policy_00_Fixed_Fixed);
    Block_B->move(714, 275);
    Block_B->resize(14, 7);

    Block_C = new QPushButton(this);
    Block_C->setObjectName(QStringLiteral("Block_C"));
    Block_C->setSizePolicy(policy_00_Fixed_Fixed);
    Block_C->move(714, 293);
    Block_C->resize(14, 7);

    Block_D = new QPushButton(this);
    Block_D->setObjectName(QStringLiteral("Block_D"));
    Block_D->setSizePolicy(policy_00_Fixed_Fixed);
    Block_D->move(714, 311);
    Block_D->resize(14, 7);

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
    monitor_ItemA->move(731, 252);
    monitor_ItemA->resize(70, 16);
    monitor_ItemA->setText("地址总线 25%");
    monitor_ItemA->setFont(QFont("Microsoft Yahei",11,60));

    monitor_ItemB = new QPushButton(this);
    monitor_ItemB->setObjectName(QStringLiteral("monitor_ItemB"));
    monitor_ItemB->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemB->move(731, 270);
    monitor_ItemB->resize(70, 16);
    monitor_ItemB->setText("数据总线 35%");
    monitor_ItemB->setFont(QFont("Microsoft Yahei",11,60));


    monitor_ItemC = new QPushButton(this);
    monitor_ItemC->setObjectName(QStringLiteral("monitor_ItemC"));
    monitor_ItemC->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemC->move(731, 288);
    monitor_ItemC->resize(70, 16);
    monitor_ItemC->setText("控制总线 30%");
    monitor_ItemC->setFont(QFont("Microsoft Yahei",11,60));


    monitor_ItemD = new QPushButton(this);
    monitor_ItemD->setObjectName(QStringLiteral("monitor_ItemD"));
    monitor_ItemD->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemD->move(731, 306);
    monitor_ItemD->resize(70, 16);
    monitor_ItemD->setText("内部总线 10%");
    monitor_ItemD->setFont(QFont("Microsoft Yahei",11,60));

    // // 底下“结果分析”区域的相关代码
    CXXZ_BUtton_B = new QPushButton(this);
    CXXZ_BUtton_B->setObjectName(QStringLiteral("CXXZ_BUtton_B"));
    CXXZ_BUtton_B->setSizePolicy(policy_00_Fixed_Fixed);
    CXXZ_BUtton_B->move(35,411);
    CXXZ_BUtton_B->resize(wid_CXXZ_B+7,hig_CXXZ_B);
    CXXZ_BUtton_B->setText("文件选择");
    CXXZ_BUtton_B->setFont(QFont("Microsoft Yahei",15,60));
    CXXZ_BUtton_B->setIcon(QIcon(":/images/CXXZ_Icon.png"));
    CXXZ_BUtton_B->setIconSize(QSize(10, 10));

    JGFX_Label = new QLineEdit(this);
    JGFX_Label->setObjectName(QStringLiteral("JGFX_Label"));
    JGFX_Label->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_Label->move(118,411);
    JGFX_Label->resize(wid_CXXZ_B_Edit,hig_CXXZ_B_Edit);
    JGFX_Label->setPlaceholderText("点击左侧选择程序");
    JGFX_Label->setFocusPolicy(Qt::NoFocus);
    JGFX_Label->setFont(QFont("Microsoft Yahei",11,60));

    // Result Analysis button
    JGFX_BUtton = new QPushButton(this);
    JGFX_BUtton->setObjectName(QStringLiteral("JGFX_BUtton"));
    JGFX_BUtton->setSizePolicy(policy_00_Fixed_Fixed);
    JGFX_BUtton->move(248,411);
    JGFX_BUtton->resize(wid_JGFX,hig_JGFX);
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
    JGFX_JCL_Label->move(509,537);
    JGFX_JCL_Label->resize(Wid_JGFX_Info+45, hig_JGFX_Info);
    JGFX_JCL_Label->setText("0%");
    JGFX_JCL_Label->setFont(QFont("Microsoft Yahei",30,60));


    monitor_ItemA_val = new QPushButton(this);
    monitor_ItemA_val->setObjectName(QStringLiteral("monitor_ItemA_val"));
    monitor_ItemA_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemA_val->move(645, 496);
    monitor_ItemA_val->resize(36, 20);
    monitor_ItemA_val->setText("28%");
    monitor_ItemA_val->setFont(QFont("Microsoft Yahei",11,60));

    A = new QPushButton(this);
    A->setObjectName(QStringLiteral("A"));
    A->setSizePolicy(policy_00_Fixed_Fixed);
    A->move(645, 474);
    A->resize(44, 20);
    A->setText("时间超时");
    A->setFont(QFont("Microsoft Yahei",9,60));
    A->setStyleSheet("color: darkorange");


    monitor_ItemB_val = new QPushButton(this);
    monitor_ItemB_val->setObjectName(QStringLiteral("monitor_ItemB_val"));
    monitor_ItemB_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemB_val->move(624, 583);
    monitor_ItemB_val->resize(36, 20);
    monitor_ItemB_val->setText("28%");
    monitor_ItemB_val->setFont(QFont("Microsoft Yahei",11,60));

    B = new QPushButton(this);
    B->setObjectName(QStringLiteral("B"));
    B->setSizePolicy(policy_00_Fixed_Fixed);
    B->move(624, 561);
    B->resize(50, 20);
    B->setText("检测到错误");
    B->setFont(QFont("Microsoft Yahei",9,60));
    B->setStyleSheet("color: forestgreen");


    monitor_ItemC_val = new QPushButton(this);
    monitor_ItemC_val->setObjectName(QStringLiteral("monitor_ItemC_val"));
    monitor_ItemC_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemC_val->move(856, 506);
    monitor_ItemC_val->resize(36, 20);
    monitor_ItemC_val->setText("28%");
    monitor_ItemC_val->setFont(QFont("Microsoft Yahei",11,60));

    C = new QPushButton(this);
    C->setObjectName(QStringLiteral("C"));
    C->setSizePolicy(policy_00_Fixed_Fixed);
    C->move(856, 484);
    C->resize(55, 20);
    C->setText("未检测到错误");
    C->setFont(QFont("Microsoft Yahei",9,60));
    C->setStyleSheet("color: darkturquoise");


    monitor_ItemD_val = new QPushButton(this);
    monitor_ItemD_val->setObjectName(QStringLiteral("monitor_ItemD_val"));
    monitor_ItemD_val->setSizePolicy(policy_00_Fixed_Fixed);
    monitor_ItemD_val->move(856, 614);
    monitor_ItemD_val->resize(36, 20);
    monitor_ItemD_val->setText("28%");
    monitor_ItemD_val->setFont(QFont("Microsoft Yahei",11,60));

    D = new QPushButton(this);
    D->setObjectName(QStringLiteral("D"));
    D->setSizePolicy(policy_00_Fixed_Fixed);
    D->move(856, 592);
    D->resize(44, 20);
    D->setText("正确执行");
    D->setFont(QFont("Microsoft Yahei",9,60));
    D->setStyleSheet("color: dodgerblue");



    connect(CXXZ_BUtton_B, &QPushButton::clicked, this, [=]()
    {
        jgfx_direct=QFileDialog::getOpenFileName(this,tr("选择文件"),"/home/yy2/res/tt/arm_test_hot/gem",tr("*.txt"));

        QString directory=jgfx_direct;
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
        QFile ansy(jgfx_direct);
        ansy.open(QIODevice::ReadOnly|QIODevice::Text);
        while(!ansy.atEnd())
        //Code_Text5->append("<font color=\"#00ff00\">"+QString(ansy.readLine()).toUtf8()+"</font>");
        ansy.close();
        JGFX_MNCS_Label->setText(gzzr_count);
        JGFX_MNCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_CWCS_Label->setText(QString::number(gzzr_count.toInt()-gzzr_timeout-gzzr_SDC).toUtf8());
        JGFX_CWCS_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_QTCW_Label->setText(QString::number(gzzr_SDC));
        JGFX_QTCW_Label->setFont(QFont("Microsoft Yahei",26,60));
        JGFX_JCL_Label->setText(QString::number(gzzr_res*100,'f',2)+"%");
        JGFX_JCL_Label->setFont(QFont("Microsoft Yahei",26,60));

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

ZX_MainWindow::~ZX_MainWindow()
{
    delete ui;
}

void ZX_MainWindow::global_setStyleSheet() {
    this->setStyleSheet("QPushButton#CXXZ_BUtton, #BQKZ_BUtton, #CXXZ_BUtton_R,#A,#B,#C,#D,"
                        "#CWMN_BUtton, #CXXZ_BUtton_B, #JGFX_BUtton,#o_BUtton,#r_BUtton,"
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

void ZX_MainWindow::readCode(QString directory)
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

void  genIniFile(QString efilepath,QString filepath){
    QFile nofi(efilepath+"gem/nofi/fi.ini");
    QFile fiini(efilepath+"/gem/fiini/fi.ini");
    if(nofi.exists())nofi.remove();
    if(fiini.exists())fiini.remove();
    if(!nofi.open(QIODevice::WriteOnly)){
        qDebug()<<"ini 文件创建失败";
        return;
    }
    if(!fiini.open(QIODevice::WriteOnly)){
        qDebug()<<"ini 文件创建失败";
        return;
    }
    QTextStream nout(&nofi),fout(&fiini);
    nout<<"[GLOBAL]\n";
    nout<<"section=PROFILE\n";
    nout<<"program="<<filepath<<"\n";

    fout<<"[GLOBAL]\n";
    fout<<"fcount=1\n";
    fout<<"section=BUS\n";
    fout<<"program="<<filepath<<"\n";
    fout<<"profile="<<efilepath<<"gem/fi/golden/profile\n";


}

