#ifndef REMOVEDIALOG_H
#define REMOVEDIALOG_H

#include <QDialog>

namespace Ui {
class removeDialog;
}

class removeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit removeDialog(QString name, QWidget *parent = nullptr);
    ~removeDialog();

private:
    Ui::removeDialog *ui;
    QString name;
};

#endif // REMOVEDIALOG_H
