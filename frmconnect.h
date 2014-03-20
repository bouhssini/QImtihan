#ifndef FRMCONNECT_H
#define FRMCONNECT_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class frmConnect;
}

class frmConnect : public QDialog
{
    Q_OBJECT
    
public:
    explicit frmConnect(QWidget *parent = 0);
    ~frmConnect();

protected:
    void closeEvent(QCloseEvent *);
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::frmConnect *ui;
};

#endif // FRMCONNECT_H
