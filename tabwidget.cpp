#include "tabwidget.h"
#include "ui_tabwidget.h"

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);
    QObject::connect(&_traductor,SIGNAL(consoleChanged(QString)),ui->console,SLOT(appendHtml(QString)));
}

TabWidget::~TabWidget()
{
    delete ui;
}

void TabWidget::openNotepad(QString fileName)
{
    QMessageBox msgBox;
    msgBox.setText("Enregistrement effectué avec succés.");
    msgBox.setInformativeText("Voulez-vous ouvrir le fichier "+ fileName + " ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Yes)
    {
        _process.start("notepad.exe " +fileName);
    }
}

void TabWidget::on_pushButton_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
    {
        if(_traductor.isChainFormated(ui->lineEdit->text().toStdString().c_str()))
        {
            string res;
            if(ui->groupBox_fileDialog->isChecked() && !ui->lineEdit_2->text().isEmpty())
            {
                launchTimer();
                res=_traductor.translate_all_ORC(ui->lineEdit->text().toStdString().c_str(),ui->lineEdit_2->text().toStdString().c_str());
                stopTimer();
                openNotepad(ui->lineEdit_2->text());
            }
            else
            {
                launchTimer();
                res=_traductor.translate_all_ORC(ui->lineEdit->text().toStdString().c_str(),NULL);
                stopTimer();
            }
            ui->plainTextEdit->appendHtml(QString(res.c_str()));
        }
    }
}

//Click sur détail
void TabWidget::on_pushButton_2_clicked()
{
    if(ui->console->isHidden())
    {
        ui->console->show();
    }
    else
    {
        ui->console->hide();
    }
}

//Click sur parcourir manuelle
void TabWidget::on_pushButton_3_clicked()
{
    _fileName =callFileDialog("Fichier sortie");
    ui->lineEdit_2->setText(_fileName);
}

QString TabWidget::callFileDialog(QString title)
{
    return QFileDialog::getOpenFileName(this,
                                        tr(title.toUtf8().constData()),
                                        "C:\\",
                                        tr("Fichier Texte (*.txt *.dat)"));
}

//Click sur parcourir batch entrée
void TabWidget::on_pushButton_4_clicked()
{
    ui->lineEdit_3->setText(callFileDialog("Fichier entré"));
}

void TabWidget::on_pushButton_5_clicked()
{
    ui->lineEdit_4->setText(callFileDialog("Fichier sortie"));
}

void TabWidget::launchTimer()
{
    _time.restart();
}

void TabWidget::stopTimer()
{
    ui->lcdNumber->display((float)_time.elapsed()/1000);
}

//Traduire batch clicked
void TabWidget::on_pushButton_6_clicked()
{
    if(!ui->lineEdit_3->text().isEmpty() && !ui->lineEdit_4->text().isEmpty())
    {
        launchTimer();
        _traductor.translateFiles(ui->lineEdit_3->text().toStdString().c_str(),ui->lineEdit_4->text().toStdString().c_str());
        stopTimer();
    }
}
