#include "tabwidget.h"
#include "ui_tabwidget.h"

TabWidget::TabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidget)
{
    ui->setupUi(this);
    QObject::connect(&_traductor,SIGNAL(consoleChanged(QString)),ui->console,SLOT(appendHtml(QString)));
    QObject::connect(&_traductor,SIGNAL(proteineDecrypted(QString)),ui->plainTextEdit,SLOT(appendHtml(QString)));
    QObject::connect(&_reverseTraductor,SIGNAL(chainDecrypted(QString)),ui->plainTextEdit,SLOT(appendHtml(QString)));
    QObject::connect(&_traductor,SIGNAL(startTimer()),this,SLOT(timerLaunched()));
    QObject::connect(&_traductor,SIGNAL(stopTimer()),this,SLOT(timerStoped()));
    QObject::connect(&_reverseTraductor,SIGNAL(startTimer()),this,SLOT(timerLaunched()));
    QObject::connect(&_reverseTraductor,SIGNAL(stopTimer()),this,SLOT(timerStoped()));
    QObject::connect(&_reverseTraductor,SIGNAL(consoleChanged(QString)),ui->console,SLOT(appendHtml(QString)));
    _notepad=false;
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

//clique traduire mode manuel
void TabWidget::on_pushButton_clicked()
{
    if(!ui->lineEdit->text().isEmpty())
    {
        if(_traductor.isChainFormated(ui->lineEdit->text().toStdString().c_str()))
        {
            if(ui->groupBox_fileDialog->isChecked() && !ui->lineEdit_2->text().isEmpty())
            {
                if(ui->radioButtonTraduction->isChecked())
                {
                    _traductor.start(translate_all,ui->lineEdit->text().toStdString().c_str(),ui->lineEdit_2->text().toStdString().c_str());
                }
                else
                {
                     _reverseTraductor.start(reverseTranslateM,ui->lineEdit->text().toStdString().c_str(),ui->lineEdit_2->text().toStdString().c_str());
                }
                _notepad = true;
                _fileName=ui->lineEdit_2->text();
            }
            else
            {
                if(ui->radioButtonTraduction->isChecked())
                {
                    _traductor.start(translate_all,ui->lineEdit->text().toStdString().c_str());
                }
                else
                {
                    _reverseTraductor.start(reverseTranslateM,ui->lineEdit->text().toStdString().c_str());
                }
            }
        }
    }
}

//Click sur détail
void TabWidget::on_pushButton_2_clicked()
{
    if(ui->console->isHidden())
    {
        ui->console->show();
        setMinimumSize(this->width(),this->height()+ui->console->height());
        setMaximumSize(this->width(),this->height()+ui->console->height());


    }
    else
    {
        ui->console->hide();
        setMinimumSize(this->width(),this->height()-ui->console->height());
        setMaximumSize(this->width(),this->height()-ui->console->height());

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
                                        tr("Fichier Texte ou FASTA (*.txt *.dat *.fasta *.fas *.fa)"));
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

void TabWidget::timerLaunched()
{
    _time.restart();
}

void TabWidget::timerStoped()
{
    ui->lcdNumber->display((float)_time.elapsed()/1000);
    if(_notepad)
    {
        openNotepad(_fileName);
        _notepad=false;
    }
}

//Traduire batch clicked
void TabWidget::on_pushButton_6_clicked()
{
    if(!ui->lineEdit_3->text().isEmpty() && !ui->lineEdit_4->text().isEmpty())
    {
        if(ui->radioButtonTraduction->isChecked())
            _traductor.start(translate_files,ui->lineEdit_3->text().toStdString().c_str(),ui->lineEdit_4->text().toStdString().c_str());
        else
            _reverseTraductor.start(loadFileAndTranslate,ui->lineEdit_3->text().toStdString().c_str(),ui->lineEdit_4->text().toStdString().c_str());

        _notepad=true;
       _fileName=ui->lineEdit_4->text().toStdString().c_str();
    }
}

void TabWidget::on_pushButton_reset_clicked()
{
    ui->plainTextEdit->clear();
    ui->console->clear();
    ui->lcdNumber->display(0);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}
