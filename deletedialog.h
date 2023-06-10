#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H


#include <QDialog>

namespace Ui {
class deleteDialog;
}

class deleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit deleteDialog(QString name, QWidget *parent = nullptr);
    ~deleteDialog();

private:
    Ui::deleteDialog *ui;
    QString name;
};

#endif // DELETEDIALOG_H
