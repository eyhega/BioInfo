#include "tabwidget.h"
#include "ui_tabwidget.h"

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);
}

TabWidget::~TabWidget()
{
    delete ui;
}

void TabWidget::on_pushButton_clicked()
{
    stringstream * stream= new stringstream();
    if(ui->lineEdit->text() != QString())
    {
        if(_traductor.isChainFormated(ui->lineEdit->text().toStdString().c_str()))
        {
            string res;
            if(ui->groupBox_fileDialog->isChecked() && !ui->lineEdit_2->text().isEmpty())
            {
                res=_traductor.translate_all_ORC(ui->lineEdit->text().toStdString().c_str(),ui->lineEdit_2->text().toStdString().c_str(),stream);
                QMessageBox msgBox;
                msgBox.setText("Enregistrement effectué avec succés.");
                msgBox.setInformativeText("Voulez-vous ouvrir le fichier sortie ?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::No);
                int ret = msgBox.exec();
                if(ret == QMessageBox::Yes)
                {
                    _process.start("notepad.exe " + ui->lineEdit_2->text());
                }

            }
            else
                res=_traductor.translate_all_ORC(ui->lineEdit->text().toStdString().c_str(),NULL,stream);
            ui->plainTextEdit->appendHtml(QString(res.c_str()));
            ui->console->appendHtml(stream->str().c_str());
            ui->retranslateUi(this);
        }
    }
    delete stream;

}

void TabWidget::on_pushButton_2_clicked()
{
    if(ui->console->isHidden())
    {
        ui->console->show(); }
    else
    {
        ui->console->hide();
    }
}

//Click sur parcourir
void TabWidget::on_pushButton_3_clicked()
{
    _fileName = QFileDialog::getOpenFileName(this,
                                             tr("Fichier sortie"),
                                             "C:\\",
                                             tr("Fichier Texte (*.txt *.dat)"));
    ui->lineEdit_2->setText(_fileName);
}
