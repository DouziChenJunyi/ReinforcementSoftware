#ifndef CPU_MAINWINDOW_H
#define CPU_MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMainWindow>
#include <QTimer>
#include <QTextEdit>
#include <QTextEdit>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>
#include <QModelIndex>
#include <QSizePolicy>
#include <QDialog>

//#include <loading.h>

namespace Ui {
class CPU_MainWindow;
}

class CPU_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CPU_MainWindow(QWidget *parent = 0);
    QWidget *bg_Widget;
    QPushButton *CXXZ_BUtton, *BQKZ_BUtton, *CXXZ_BUtton_R,
                *CWMN_BUtton, *CXXZ_BUtton_B, *JGFX_BUtton,
                *Block_A, *Block_B, *Block_C, *Block_D, *CWFGL_Val,
                *monitor_ItemA_val, *monitor_ItemB_val,
                *monitor_ItemC_val, *monitor_ItemD_val,
                *monitor_ItemA, *monitor_ItemB,
                *monitor_ItemC, *monitor_ItemD,
                *JGFX_MNCS_Label, *JGFX_CWCS_Label,
                *JGFX_QTCW_Label, *JGFX_JCL_Label, *o_BUtton,*m_BUtton,*j_BUtton,*r_BUtton,
                *CWFGL_Lable1, *CWFGL_Lable2;
    QTextEdit *Code_Text1, *Code_Text2, *Code_Text3, *Code_Text4, *Code_Text5;
    QLineEdit *DMSC_Label, *CWMN_Label, *JGFX_Label;
    QTextEdit *MNCS_Edit;
    QStandardItemModel* model;
    QTableView* tableView;

    QPushButton *A,*B,*C,*D;
    int sumnumber=100;

    QString gzzr_benchpath, jg_benchpath, jg_file;
    QString gzzr_count;

//    Loading *loading;

    void readCode(QString directory);
    void global_setStyleSheet();
    void global_setSizePolicy(QSizePolicy policy_00_Fixed_Fixed);
    void BQKZ_BUtton_func();
    ~CPU_MainWindow();

private:
    Ui::CPU_MainWindow *ui;
};

#endif // CPU_MAINWINDOW_H
