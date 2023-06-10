#ifndef PREDICTIONDIALOG_H
#define PREDICTIONDIALOG_H
#include "teammodel.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class predictionDialog;
}

class predictionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit predictionDialog(QWidget *parent = nullptr);
    ~predictionDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::predictionDialog *ui;
};

#endif // PREDICTIONDIALOG_H
