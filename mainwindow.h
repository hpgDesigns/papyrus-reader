#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGridLayout>
#include <QFile>
#include <QFileDialog>
#include <QFont>
#include <QList>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QTextBlockFormat>
#include <QTextCharFormat>
#include <QTextList>
#include <QTextTableFormat>
#include <QTextTable>
#include <QTextTableCell>
#include <QTextList>
#include <QTextCursor>
#include <QTextEdit>
#include <QTextLength>
#include <QTextDocument>
#include <QMessageBox>

#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPrinterInfo>

#include <QColor>
#include <QColorDialog>
#include <QFontDialog>
#include <QPalette>
#include <QPainter>
#include <QImageReader>

#include <QStatusBar>
#include <QAction>
#include <QStyle>
#include <QList>

#include <QVector>
#include <QRect>
#include <QRectF>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class button : public QDialog
{
    Q_OBJECT

private slots:
    void pushButton_clicked();


};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    //void newtable();

    //void paintRequested (QPrinter *printer);
    void print(QPrinter*)
    {
        QPrinterInfo def = QPrinterInfo::defaultPrinter();

        //if there is no default printer set the print preview won't show
        if(def.isNull() || def.printerName().isEmpty())
        {
            if(QPrinterInfo::availablePrinters().isEmpty())
            {
                QMessageBox::critical(this, tr("Print error"), tr("Cannot proceed because there are no available printers in your system."), QMessageBox::Ok);
            }
            else
            {
                def = QPrinterInfo::availablePrinters().first ();
            }
        }

        //   QPrinter printer(def, QPrinter::ScreenResolution);
        //   QPainter painter( &printer );
        //   painter.setRenderHint(QPainter::Antialiasing);


        //scene is a QGraphicsScene
        //ui->textEdit->render(&painter,400,ui->textEdit->itemsBoundingRect());
        return;
    }


private slots:
    void on_actionOpen_triggered();

    void on_actionMarkdown_triggered();

    void on_actionPrint_triggered();

    void on_actionPrint_Preview_triggered();

    void on_actionExit_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionFAQ_triggered();

    void on_actionInfo_triggered();

private:
    Ui::MainWindow *ui;

    QString currentFile = "";
    QPrinter *printer;
    QTextDocument *document;
    QDialog *faq = new QDialog;
    QDialog *info = new QDialog;
    QTextEdit *textbox = new QTextEdit;
};
#endif // MAINWINDOW_H
