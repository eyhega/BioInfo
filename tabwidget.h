#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QtGui/QTableWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>

#include <traduction.hpp>
#include <ReverseTraduction.hpp>

namespace Ui {
class TabWidget;
}

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

private:
    Ui::TabWidget *ui;
    Traduction _traductor;
    ReverseTraduction _reverseTraductor;
    QString _fileName;
    QProcess _process;
};

#endif // TABWIDGET_H
