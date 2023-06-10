#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include "teammodel.h"
#include <QMainWindow>
#include "deletedialog.h"
#include "dialogadd.h"
#include "editdialog.h"

namespace Ui {
class secondwindow;
}

class secondwindow : public QMainWindow
{
    Q_OBJECT

public:
    secondwindow(QString name, QWidget *parent = nullptr);
    ~secondwindow();
    void renderTable();

private slots:
    void on_button_add_clicked();

    void on_comboBox_currentIndexChanged(int index);
    void dialog_delete_finished(int code);
    void on_button_delete_clicked();

    void on_table_team_doubleClicked(const QModelIndex &index);

private:
    Ui::secondwindow *ui;
    QString name;
    TeamModel *model;

};

#endif // SECONDWINDOW_H
