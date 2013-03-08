#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QtGui/QTableWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QTime>
#include <time.h>
#include <QObject>


#include <traduction.hpp>
#include <ReverseTraduction.hpp>

namespace Ui {
class TabWidget;
}

//!\brief Classe gérant l'interface.

class TabWidget : public QTabWidget
{
    Q_OBJECT
    
public:
    explicit TabWidget(QWidget *parent = 0);
    ~TabWidget();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_reset_clicked();

public slots:
    void timerLaunched();
    void timerStoped();

private:
    Ui::TabWidget *ui;
    Traduction _traductor;
    ReverseTraduction _reverseTraductor;
    QString _fileName;
    QProcess _process;
    QTime _time;
    bool _notepad;

    //methods
    void openNotepad(QString fileName);
    QString callFileDialog(QString title);

};

#endif // TABWIDGET_H
