#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CutterCommand.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_btnEnter_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    CutterCommand controler;
    int indexHistory = 0;
};

#endif // MAINWINDOW_H
