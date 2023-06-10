#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "teamsmodel.h"
#include <QMainWindow>
#include "secondwindow.h"
#include <QFile>
#include <QDialog>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPalette>
#include <QColor>
#include <QPainter>
#include "dialog.h"
#include "predictiondialog.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    TeamsModel* teamsModel;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_playerTableView_doubleClicked(const QModelIndex& index);
    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
