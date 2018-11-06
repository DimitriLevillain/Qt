#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Linux_clicked();

    void on_pushButton_Windows_clicked();

    void on_pushButton_OS_X_Lion_clicked();

    void on_radioButton_Linux_clicked();

    void on_radioButton_OS_X_Lion_clicked();

    void on_radioButton_Windows_clicked();

    void on_lineEditCode_textChanged(const QString &arg1);

    void on_actionJava_triggered();

    void on_actionC_triggered();

    void on_actionC_2_triggered();

    void on_actionJava_script_triggered();

    void on_comboBoxOs_currentTextChanged(const QString &arg1);

    void on_checkBox_OS_X_Lion_clicked();

    void on_checkBox_Windows_clicked();

    void on_chekBox_Linux_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
