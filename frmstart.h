#ifndef FRMSTART_H
#define FRMSTART_H

#include <QDialog>
#include <QKeyEvent>


namespace Ui {
class FrmStart;
}

class FrmStart : public QDialog
{
    Q_OBJECT
    
public:
    explicit FrmStart(QWidget *parent = 0);
    ~FrmStart();

protected:
    void closeEvent(QCloseEvent *);
    void keyPressEvent(QKeyEvent *e);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::FrmStart *ui;

};

#endif // FRMSTART_H
