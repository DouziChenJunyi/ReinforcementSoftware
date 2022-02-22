#ifndef JCQ_MAINWINDOW_H
#define JCQ_MAINWINDOW_H
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
class JCQ_MainWindow;
}

class JCQ_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit JCQ_MainWindow(QWidget *parent = 0);
    ~JCQ_MainWindow();
    QWidget *bg_Widget;
    QPushButton *CXXZ_BUtton, *BQKZ_BUtton, *LLVM_BUtton, *JCBY_BUtton,*CXXZ_BUtton_R,
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
    QLineEdit *DMSC_Label, *DMSC_Label_B, *CWMN_Label, *MNCS_Edit, *JGFX_Label;
    QStandardItemModel* model;
    QTableView* tableView;

    bool crossCompile_Flag=false;

    QString filename, filepath, efilename, efilepath, index_path, llfilename, idllfilename,
            dfllfile, directory, command1, command2, command3, command4;


    QProcess *process, *process_CWMN, *process2_CWMN, *f_process_CWMN;

    QString filename_CWMN, filepath_CWMN, efilename_CWMN, efilepath_CWMN, directory_CWMN,
            command1_CWMN, command2_CWMN;


    QProcess *jg_process;
    QString jg_filename, jg_filepath, jg_efilename, jg_efilepath, jg_index_path, jg_llfilename,
            jg_idllfilename, jg_dfllfile, jg_directory, jg_arg_to_IR, jg_command1, jg_command2,
            jg_command3, jg_command4;

    bool jg_flag=false;

    QProcess *gzzr_process, *gzzr_process2, *gzzr_f_process;
    QString gzzr_filename, gzzr_filepath, gzzr_efilename, gzzr_efilepath, gzzr_directory,
            gzzr_command1, gzzr_command2;



    QProcess *jgfx_process;
    QString jgfx_fx_path, jgfx_command1, jgfx_filepath;
    QStringList jgfx_arg_c;
    QString gzzr_count="100";

    QPushButton *A,*B,*C,*D;


    void readCode(QString directory, QString EditLine_name);
    void crossCompile();
    void tagExpand();
    void errorMimic();
    void global_setStyleSheet();
    void global_setSizePolicy(QSizePolicy policy_00_Fixed_Fixed);

private:
    Ui::JCQ_MainWindow *ui;
};

#endif // JCQ_MAINWINDOW_H
