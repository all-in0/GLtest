#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(addNewSub()));
    connect(ui->pushButton_2, SIGNAL(pressed()), this, SLOT(doWork()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewSub()
{
    bool bOk;
    QString str = QInputDialog::getText( 0, "Input", "Word:", QLineEdit::Normal, "Enter new word", &bOk);
    if (!bOk) {
        return ;
    }
    str = str.simplified();
    str = str.split(QRegExp(" "))[0];
    if (str.isEmpty() || str.length() < 1) {
        return ;
    }
    words.insert( str.length(), str );
    QMessageBox::information(0, "Add new word", str, QMessageBox::Ok);
    refreshList();
}

void MainWindow::doWork()
{
    QString str = ui->textEdit->toPlainText();
    if (words.size() < 1 || str.length() < 1)
        return ;
    for (auto m = words.end() - 1; ; m--)
    {
      if (str.contains(m.value())){
          QMessageBox::information(0, "Longest word", QString("longest word is:\n\"%0\"").arg(m.value()), QMessageBox::Ok);
          return ;
      }
      if (m == words.begin()){
          QMessageBox::information(0, "No matches", "No sub from list in string", QMessageBox::Ok);
          return ;
      }
    }
}

void MainWindow::refreshList()
{
   QString str;
  // std::sort(words);
   for(QString w : words){
       str+= w;
       str+= '\n';
   }
   ui->textBrowser->setText(str);
}
