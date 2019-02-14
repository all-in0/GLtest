#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <QLineEdit>
#include <QInputDialog>
#include <QRegExp>
#include <QMultiHash>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void addNewSub();
    void doWork();

private:
    void refreshList();
    Ui::MainWindow *ui;
    QMultiMap<size_t, QString> words;
};

#endif // MAINWINDOW_HPP
