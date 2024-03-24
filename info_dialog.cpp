#include "info_dialog.h"
#include "ui_info_dialog.h"

info_dialog::info_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::info_dialog)
{
    ui->setupUi(this);

    //open document for reading
    QFile infofile("/home/hughdev/QT_Projects/papyrus/Info_papyrus.html");
    if(!infofile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", infofile.errorString());
    }
    // Put the text in the faq textbrowser dialog
    QTextStream in(&infofile);
    QString textinfo = in.readAll();
    ui->infotextBrowser->acceptRichText ();
    ui->infotextBrowser->setHtml (textinfo);

    // Close the file
    infofile.close();
    ui->infotextBrowser->setText (textinfo);

}

info_dialog::~info_dialog()
{
    delete ui;
}

void info_dialog::on_info_closeButton_clicked()
{
    close();
    return;
}

