#include "welcomewindow.h"
#include "mainwindow.h"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_startButton_clicked()
{
    MainWindow* win = new MainWindow(0);
    win->showNormal();
    this->setParent(win);
    this->close();
}
