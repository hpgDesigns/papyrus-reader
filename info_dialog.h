#ifndef INFO_DIALOG_H
#define INFO_DIALOG_H

#include <QDialog>
#include <QTextBrowser>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class info_dialog;
}

class info_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit info_dialog(QWidget *parent = nullptr);
    ~info_dialog();

private slots:
    void on_info_closeButton_clicked();

private:
    Ui::info_dialog *ui;
    QTextBrowser *infotext;

};

#endif // INFO_DIALOG_H
