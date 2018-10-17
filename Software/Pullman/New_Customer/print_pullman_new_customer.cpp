#include "print_pullman_new_customer.h"
#include <QString>
#include <QPrinter>
#include "pullman_new_customer.h"
#include <QPageSetupDialog>
#include <QFileDialog>
#include <QPrintPreviewDialog>

void pullman_new_customer::setUpPage()
{
    QPrinter printer;
    QPageSetupDialog pageSetUpdlg(&printer, this);
    if(pageSetUpdlg.exec() == QDialog::Accepted)
    {
        printer.setOrientation(QPrinter::Landscape);
    }
    else
    {
        printer.setOrientation(QPrinter::Portrait);
    }
}

void pullman_new_customer::createPdf()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Output PDF"), QString(), "*.pdf");
    if(!filename.isEmpty())
    {
        if(QFileInfo(filename).suffix().isEmpty())
        {
            filename.append(".pdf");
        }

        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filename);


    }
}

void pullman_new_customer::doPrintPreview()
{
    QPrinter printer;
    QPrintPreviewDialog preview(&printer, this);
    connect(&preview, SIGNAL(paintRequest(QPrinter*)),this,SLOT(printPreview(QPrinter*)));
    preview.exec();
}




