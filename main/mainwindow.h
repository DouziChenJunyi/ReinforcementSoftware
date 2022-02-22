#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QImage>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void global_setStyleSheet();
    explicit MainWindow(QWidget *parent = 0);
    QWidget *bg_Widget;
    QPushButton *CPU_Button, *ZX_Button, *JCQ_Button, *CCQ_Button, *IO_Button;
    QLabel *test;
    QWidget *win;
    void Sleep(unsigned int msec);
    QImage *image;


    ~MainWindow();

private:
    void initInfo();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
