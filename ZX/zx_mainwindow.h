#ifndef ZX_MAINWINDOW_H
#define ZX_MAINWINDOW_H
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
namespace Ui {
class ZX_MainWindow;
}

class ZX_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZX_MainWindow(QWidget *parent = 0);
    QWidget *bg_Widget;
    QPushButton *CXXZ_BUtton, *BQKZ_BUtton, *CXXZ_BUtton_R,
                *CWMN_BUtton, *CXXZ_BUtton_B, *JGFX_BUtton,
                *Block_A, *Block_B, *Block_C, *Block_D, *CWFGL_Val,
                *monitor_ItemA_val, *monitor_ItemB_val,
                *monitor_ItemC_val, *monitor_ItemD_val,
                *monitor_ItemA, *monitor_ItemB,
                *monitor_ItemC, *monitor_ItemD,
                *JGFX_MNCS_Label, *JGFX_CWCS_Label,
                *JGFX_QTCW_Label, *JGFX_JCL_Label,*o_BUtton,*m_BUtton,*j_BUtton,*r_BUtton,
                *CWFGL_Lable1, *CWFGL_Lable2;
    QTextEdit *Code_Text1, *Code_Text2, *Code_Text3, *Code_Text4, *Code_Text5;
    QLineEdit *DMSC_Label, *CWMN_Label, *MNCS_Edit, *JGFX_Label;
    QStandardItemModel* model;
    QTableView* tableView;

    QString jg_filename, jg_filepath, jg_efilename, jg_efilepath;
    bool jg_jgfg;

    QString gzzr_filename, gzzr_filepath, gzzr_efilename, gzzr_efilepath, gzzr_count="100";
    bool gzzr_filefg=true, gzzr_countfg;
    int gzzr_cun, gzzr_Algor=0, gzzr_Prog=0, gzzr_timeout=0;
    float gzzr_SDC=0, gzzr_tos, gzzr_res;

    QString jgfx_direct;

    QPushButton *A,*B,*C,*D;


    void readCode(QString directory);
    void global_setStyleSheet();
    void global_setSizePolicy(QSizePolicy policy_00_Fixed_Fixed);
    ~ZX_MainWindow();



private:
    Ui::ZX_MainWindow *ui;

};

#endif // ZX_MAINWINDOW_H
