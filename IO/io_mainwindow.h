#ifndef IO_MAINWINDOW_H
#define IO_MAINWINDOW_H

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
#include <QProcess>
namespace Ui {
class IO_MainWindow;
}

class IO_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IO_MainWindow(QWidget *parent = 0);
    QWidget *bg_Widget;
    QPushButton *CXXZ_BUtton, *BQKZ_BUtton, *LLVM_BUtton, *CXXZ_BUtton_R,
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
    QLineEdit *DMSC_Label, *LLVM_Label, *CWMN_Label, *JGFX_Label,*MNCS_Edit;

    QString jg_directory,jg_filepath,jg_filename,jg_efilepath,jg_efilename,directory;
    //QTextEdit *MNCS_Edit;
    QStandardItemModel* model;
    QTableView* tableView;

    QString jg_waitForJG_path, jg_clang_path, jg_exec_source_path, jg_arm_path, jg_source_path;
    QStringList jg_waitForJG_path_list, jg_arg_to_exec, jg_arg_to_exec_PUT,
                jg_argu, jg_arg_to_o, jg_arg_to_over, jg_exec_source_path_list;
    QProcess *jg_process;

    QProcess *gzzr_process, *gzzr_process2;

    int gzzr_FINum;
    QStringList gzzr_arg_to_exec, gzzr_over;
    QString gzzr_filename, gzzr_filepath, gzzr_efilename, gzzr_efilepath, gzzr_command1, gzzr_command2;
    QString BK(QString result),gzzr_num="100";

    QProcess *jgfx_process;
    QString jgfx_command1;

    QPushButton *A,*B,*C,*D;




    void readCode(QString directory, QString EditLine_name);
    void global_setStyleSheet();
    void global_setSizePolicy(QSizePolicy policy_00_Fixed_Fixed);
    ~IO_MainWindow();

private:
    Ui::IO_MainWindow *ui;

private slots:
    void on_readoutput();
    void on_readerror();
};

#endif // IO_MAINWINDOW_H
