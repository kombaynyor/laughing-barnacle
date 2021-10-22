#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtSql>
QSqlDatabase db;
QSqlTableModel * model;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("basse");
    if(db.open()){
        qDebug() << "open";
    }
    model = new QSqlTableModel();
    QSqlQuery qwe;
    //qwe.exec("CREATE TABLE PROBA(id PRIMARY KEY NOT NULL, pole VARCHAR(40),nepole INT);");
    model->setTable("tybl");
    model->select();
    ui->tableView->setModel(model);
    //qwe.exec("INSERT INTO tybl VALUES(1,'wew','4')");
    qDebug() << qwe.lastError().text();
}

MainWindow::~MainWindow()
{
    delete ui;
}

