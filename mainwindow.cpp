#include "mainwindow.h"
#include "info_dialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Papyrus Document Reader V1.0");
    this->setCentralWidget (ui->textBrowser);
    ui->textBrowser->setFontFamily("Comformta");
    ui->textBrowser->setFontPointSize(12);
    ui->textBrowser->setLineWidth(250);
    ui->textBrowser->setFontWeight(QFont::Normal);
    ui->textBrowser->setText(QString());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file" , "$HOME",
                                                    tr("Supported Files (*.txt *.md *.html *.rtdoc)"));

/*   QString fileName = QFileDialog::getOpenFileName(this, tr("Open the file" ),"$HOME",
                                                    tr("Text Files (*.txt);;Markdown files (*.md);; HTML files (*.html *.htm);;RichText files (*.rtf *.rtdoc)"));
*/
    QFile file(fileName);
    currentFile = fileName;//store the file
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    // Set the title for the window to the file name
    setWindowTitle(fileName);

    // Interface for reading text
     QTextStream in(&file);
    //QTextDocument in(&file);
    // Copy text in the string
     QString text = in.readAll ();

    //accept Rich Text Formatting if available
    ui->textBrowser->acceptRichText ();
    ui->textBrowser->setAcceptRichText (true);
    // Put the text in the textBrowser widget
    ui->textBrowser->setText(text);

    // Close the file
    file.close();
    //ui->textEdit->setPlainText(text);
    //QTextCursor cursor = ui->textEdit->textCursor();
    //cursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor);
    statusBar()->showMessage(QString(currentFile) +" file has been opened!", 7000);

}


void MainWindow::on_actionMarkdown_triggered()
{
    QString text = ui->textBrowser->toMarkdown ();
    ui->textBrowser->setText(text);

}

/*void MainWindow::on_actionHTML_triggered()
{

    QString text = ui->textBrowser->toHtml ();
    ui->textBrowser->acceptRichText ();
    ui->textBrowser->setAcceptRichText (true);
    ui->textBrowser->setText(text);

}
*/

/* void MainWindow::on_actionHTML_changed()
{

    QString text = ui->textBrowser->toHtml ();
    ui->textBrowser->acceptRichText ();
    ui->textBrowser->setAcceptRichText (true);
    ui->textBrowser->setText(text);

}
*/

void MainWindow::on_actionPrint_triggered()
{
    //print the file to printer or PDF File
    // Allows for interacting with printer
    QPrinter printer;

    // You'll put your printer name here
    printer.setPrinterName("Printer Name");

    // Create the print dialog and pass the name and parent
    QPrintDialog pDialog(&printer, this);

    if(pDialog.exec() == QDialog::Rejected)
    {
        QMessageBox::warning(this, "Warning", "Cannot Access Printer");
        return;
    }
    ui->textBrowser->print (&printer);

}


void MainWindow::on_actionPrint_Preview_triggered()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer);

    printer.setPaperSource (QPrinter::OnlyOne);
    printer.setFullPage(true);

    preview.setWindowFlags( Qt::Window );
    preview.setWindowTitle(tr("Print Preview"));
    preview.activateWindow ();

    connect(&preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));
    preview.setMinimumHeight(600);
    preview.setVisible (true);
    preview.exec();

    ui->textBrowser->print (&printer);
}


void MainWindow::on_actionExit_triggered()
{
    close ();
}


void MainWindow::on_actionZoom_In_triggered()
{
    ui->textBrowser->zoomIn ();
}

void MainWindow::on_actionZoom_Out_triggered()
{
    ui->textBrowser->zoomOut (1);
}

void MainWindow::on_actionFAQ_triggered()
{
    //faq = new QDialog;
    faq->setWindowTitle ("Papyrus Faq");
    faq->setGeometry (128, 64, 500, 600);

    QTextBrowser *faqtext = new QTextBrowser;
    faqtext->setParent(faq);
    faqtext->setGeometry (10, 10, 480, 500);

 /*   QPushButton *button = new QPushButton;
//  connect(button,SIGNAL (clicked()), button, SLOT (pushButton_clicked()));
    button->setParent (faq);
    button->setGeometry (200,530,96,32);
    button->setText ("Close");
*/
    //open document for reading
    QFile file("/home/hughdev/QT_Projects/papyrus/faq.md");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
    }
    // Put the text in the faq textbrowser dialog
    QTextStream in(&file);
    QString text = in.readAll();
    faqtext->acceptRichText ();
    faqtext->setMarkdown (text);

    // Close the file
    file.close();

    faq->show ();
}


void MainWindow::on_actionInfo_triggered()
{
    info = new info_dialog;
    info->setWindowTitle ("Papyrus Info");

    info->show ();
}

void button::pushButton_clicked()
{
    close();
}




