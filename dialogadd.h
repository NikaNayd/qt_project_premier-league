#ifndef DIALOGADD_H
#define DIALOGADD_H
#include <QFile>
#include <QDialog>
#include <QValidator>
#include <QIntValidator>
#include <QMessageBox>
namespace Ui {
class dialogAdd;
}

class dialogAdd : public QDialog
{
    Q_OBJECT

public:
    explicit dialogAdd(QString teamName, QWidget *parent = nullptr);
    ~dialogAdd();

private slots:
    void on_buttonAdd_clicked();

private:
    Ui::dialogAdd *ui;
    QString teamName;
    QWidget *myparent;
    QIntValidator intvalid;
};

#endif // DIALOGADD_H
