#include "General.h"
#include "ui_frmconnect.h"

void frmConnect::closeEvent(QCloseEvent *)
{
    frmstart->show();
    delete frmconn;
    frmconn = NULL;

}
void frmConnect::keyPressEvent(QKeyEvent *e)
{
    if(e->key() != Qt::Key_Escape){
        frmConnect::keyPressEvent(e);
    }
}
frmConnect::frmConnect(QWidget *parent) :   QDialog(parent), ui(new Ui::frmConnect)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags helpFlag = Qt::WindowContextHelpButtonHint;
    flags = flags & (~helpFlag);
    setWindowFlags(flags);
    this->setLayoutDirection(qApp->layoutDirection());

    #ifdef Q_OS_WIN32
    SetWindowLong((HWND)this->winId(), GWL_EXSTYLE, GetWindowLong((HWND)this->winId(), GWL_EXSTYLE) | WS_EX_LAYOUTRTL);
    SetWindowLong((HWND)ui->widget->winId(), GWL_EXSTYLE, GetWindowLong((HWND)ui->widget->winId(), GWL_EXSTYLE) & (~WS_EX_LAYOUTRTL));
    #endif
}
frmConnect::~frmConnect()
{
    delete ui;
}
