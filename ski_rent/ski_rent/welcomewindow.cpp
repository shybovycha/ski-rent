#include "welcomewindow.h"
#include "configurationwindow.h"
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
    QWidget* win = new MainWindow(0);
    win->showNormal();
}

void WelcomeWindow::on_configureButton_clicked()
{
    QWidget* win = new ConfigurationWindow(0);
    win->showNormal();
}
