#include "General.h"
#include "ui_frmnataij.h"


void FrmNataij::closeEvent(QCloseEvent *)
{
    frmstart->show();
    delete frmconn;
    frmconn = NULL;
}
void FrmNataij::keyPressEvent(QKeyEvent *e)
{
    if(e->key() != Qt::Key_Escape){
        FrmNataij::keyPressEvent(e);
    }
}

FrmNataij::FrmNataij(QWidget *parent) : QDialog(parent), ui(new Ui::FrmNataij)
{
    ui->setupUi(this);
    ui->table1->setColumnWidth(0,300);
    ui->table1->setColumnWidth(1,140);
    ui->table1->setColumnWidth(2,40);
    ui->table1->setColumnWidth(3,0);
    ui->table1->setColumnWidth(4,0);

    ui->table1->setColumnHidden(3,true);
    ui->table1->setColumnHidden(4,true);

    ui->table1->horizontalHeader()->setStretchLastSection(true);
    ui->table1->setIconSize(QSize(19,16));
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    ui->table1->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
#else
    ui->table1->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
#endif


}
FrmNataij::~FrmNataij()
{
    delete ui;
}

