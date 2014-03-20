#ifndef FRMNATAIJ_H
#define FRMNATAIJ_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class FrmNataij;
}

class FrmNataij : public QDialog
{
    Q_OBJECT
    
public:
    explicit FrmNataij(QWidget *parent = 0);
    ~FrmNataij();

protected:
    void closeEvent(QCloseEvent *);
    void keyPressEvent(QKeyEvent *e);
    
private:
    Ui::FrmNataij *ui;
};

#endif // FRMNATAIJ_H
