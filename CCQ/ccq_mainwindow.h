#ifndef CCQ_MAINWINDOW_H
#define CCQ_MAINWINDOW_H

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
#include <QLabel>

# include <QChartView>
# include <QLineSeries>
# include <QValueAxis>

QT_CHARTS_USE_NAMESPACE


constexpr static float testy[74]={0,0, 0, 0, 0,0,0,0,0,0, 0, 0,0,0.03125 ,0,0.03125,0, 0.34375  ,0.203125, 0.15625,  0, 0.015625, 0.015625, 0,0.3125,   0.1875,   0, 0,0,0,0,0.15625,0.40625 , 0,     0, 0,0.015625, 0.015625, 0,     0.09375,0.046875, 1,      1,   0,0.46875 , 0.234375, 0.4375,   0,0,0.09375,  0,  0,0.234375, 0.1875 ,  0.375 ,   0,0,0,0, 0.046875 ,0,0,0, 0.09375,0,0,0,0,  0,0,0, 0,0.109375, 0};
constexpr static float prey[74] = { 3.83600465e-04,  1.65050747e-03,  3.00050906e-03,  3.97486537e-04,5.99014196e-04,  3.97486537e-04,  7.73420899e-04, -3.68742096e-03,4.05981200e-04,  2.32869752e-03,  1.70101136e-03,  1.70101136e-03,6.71453848e-03,  2.12864345e-02,  3.86584750e-04 , 2.80678140e-02,3.12943962e-02 , 3.09845444e-01,  1.85522559e-01,  1.54734734e-01,5.35808536e-03,  1.71902409e-02 , 1.38471701e-02,  5.42752383e-03,2.85437071e-01,  9.74403539e-02,  2.08218718e-01,  4.56511953e-03,4.56511953e-03 , 9.85382874e-03,  2.34969490e-02,  1.10273355e-01,2.61633980e-01,  4.94700002e-03,  4.94700002e-03,  2.96093903e-03,7.98778129e-03,  6.26390123e-03,  3.60778213e-03,  1.74780949e-01,9.86132381e-02,  6.32906418e-01,  9.59358950e-01,  1.07281771e-03,1.79619992e-01,  7.59601285e-02,  3.87892262e-01,  9.34443524e-03,9.34443524e-03,  4.07202842e-02,  7.12829774e-04,  2.85047579e-03,1.76490578e-01,  1.12575502e-01 , 3.13944811e-01 , 5.66255906e-03,1.24444126e-02,  1.15679531e-02,  1.33299114e-02,  2.22361611e-02,2.95016156e-03,  6.11273546e-05,  7.12085940e-04,  9.28989335e-02,1.06437753e-03 , 1.06437753e-03 , 1.06437753e-03,  1.06437753e-03,1.06437753e-03,  1.06437753e-03,  1.06437753e-03 , 1.06437753e-03,1.03924477e-01,  1.63372809e-03};
constexpr static float pre1[74] = {0.05046022, 0.05105401, 0.0684047,  0.17188865, 0.06502496, 0.17274986,0.0701306,  0.06089356, 0.10045873, 0.16158118, 0.0553664 , 0.0556593,0.08188175, 0.08499303, 0.08326727, 0.09965727, 0.10156866, 0.21251572,0.1025256,  0.10230645, 0.07179727, 0.0719774,  0.07256878 ,0.07274813,0.201449,   0.08754821, 0.20392074, 0.08234746, 0.0825428,  0.08331802,0.09112975, 0.08924203, 0.20697896, 0.08465086, 0.08483877, 0.06862802,0.06959147, 0.07054563, 0.07002713, 0.19384981, 0.08836345 ,0.2006433,0.20379936 ,0.09973473, 0.19840741, 0.08791977 ,0.19940027, 0.08114249,0.08136153, 0.08520349, 0.08179267 ,0.09315431, 0.10066618, 0.09994601,0.21295205 ,0.09985329 ,0.09483529 ,0.08921118, 0.08700576, 0.08758114,0.09187094, 0.10827178, 0.2379001,  0.09289054, 0.09955788, 0.09978868, 0.10001672 ,0.10024199, 0.10046449, 0.10068422, 0.10090117, 0.10111533,0.10978037 ,0.13523739};


namespace Ui {
class CCQ_MainWindow;
}

class CCQ_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CCQ_MainWindow(QWidget *parent = 0);
    QWidget *bg_Widget;
    QPushButton *CXXZ_BUtton, *MNXL_BUtton, *ZLPX_BUtton,
                *CFD_BUtton, *BQKZ_BUtton, *ZLYC_BUtton,
                *CXXZ_BUtton_R, *CWMN_BUtton, *CXXZ_BUtton_B, *JGFX_BUtton, *YCJG_BUtton,
                *Block_A, *Block_B, *Block_C, *Block_D, *CWFGL_Val,
                *monitor_ItemA_val, *monitor_ItemB_val,
                *monitor_ItemC_val, *monitor_ItemD_val,
                *monitor_ItemA, *monitor_ItemB,
                *monitor_ItemC, *monitor_ItemD,
                *JGFX_MNCS_Label, *JGFX_CWCS_Label,
                *JGFX_QTCW_Label, *JGFX_JCL_Label,*o_BUtton,*m_BUtton,*j_BUtton,*r_BUtton,
                *CWFGL_Lable1, *CWFGL_Lable2;
    QTextEdit *Code_Text1, *Code_Text2, *Code_Text3, *Code_Text4, *Code_Text5;
    QLineEdit *DMSC_Label, *CFD_Label, *CWMN_Label, *MNCS_Edit, *JGFX_Label;
    QStandardItemModel* model;
    QTableView* tableView;

    QProcess *jg_process, *jg_process1;

    QString jg_filename, jg_filepath, jg_efilename, jg_efilepath, jg_index_path, jg_llfilename,
            jg_idllfilename, jg_dfllfile, jg_directory, jg_arg_to_IR, jg_command1, jg_command2,
            jg_command3, jg_command4, jg_ryld_path, jg_source_path, jg_python_path;

    bool jg_flag=false, jg_flag1=false, jg_flag2=false, jg_flag3=false;
    QStringList jg_arg_to_run;


    QProcess *gzzr_process, *gzzr_process2, *gzzr_f_process;
    QString gzzr_filename, gzzr_filepath, gzzr_efilename, gzzr_efilepath, gzzr_directory, gzzr_command1, gzzr_command2;

    QProcess *jgfx_process;
    QString jgfx_fx_path, jgfx_command1, jgfx_filepath;
    QStringList jgfx_arg_c;
    QLabel *JGFX_LableImg;
    QString gzzr_count="100";
    QLineSeries *RealValue, *OurMethod, *DFRMR;
    QTimer *m_time;


    void readCode(QString directory, QString EditLine_name);
    void global_setStyleSheet();
    void global_setSizePolicy(QSizePolicy policy_00_Fixed_Fixed);
    ~CCQ_MainWindow();

    int TimeCount = 20;
    void Oneaction();
    void addone(QLineSeries *target,QLineSeries *target1,QLineSeries *target2, int count, float value,float value1,float value2);

private:
    Ui::CCQ_MainWindow *ui;

private slots:
    void outlog();

};

#endif // CCQ_MAINWINDOW_H
