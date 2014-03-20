#include "General.h"
#include "ui_frmstart.h"
#include <QUrlQuery>
#include <QMessageBox>

void FrmStart::keyPressEvent(QKeyEvent *e)
{
    if(e->key() != Qt::Key_Escape){
        FrmStart::keyPressEvent(e);
    }
}
void FrmStart::closeEvent(QCloseEvent *)
{

}
FrmStart::FrmStart(QWidget *parent) : QDialog(parent),ui(new Ui::FrmStart)
{
    ui->setupUi(this);
    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags helpFlag = Qt::WindowContextHelpButtonHint;
    flags = flags & (~helpFlag);
    setWindowFlags(flags);

    #ifdef Q_OS_WIN32
    SetWindowLong((HWND)this->winId(), GWL_EXSTYLE, GetWindowLong((HWND)this->winId(), GWL_EXSTYLE) | WS_EX_LAYOUTRTL);
    SetWindowLong((HWND)ui->widget->winId(), GWL_EXSTYLE, GetWindowLong((HWND)ui->widget->winId(), GWL_EXSTYLE) & (~WS_EX_LAYOUTRTL));
    #endif
    this->setLayoutDirection(qApp->layoutDirection());
    /*
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(":/res/0000.png")));
    this->setPalette(palette);
    */

}
FrmStart::~FrmStart()
{
    delete ui;
}
void FrmStart::on_pushButton_2_clicked()
{
    FrmURL frmurl;
    QByteArray result;
    int web=0;

    QByteArray  usr = QTextCodec::codecForName("CP-1256")->fromUnicode(ui->Tuser->text());
    QByteArray  mail = QTextCodec::codecForName("CP-1256")->fromUnicode(ui->Tmail->text());
    QString user(usr);
    QString email(mail);

    QUrlQuery postData(Url_php);

    postData.addQueryItem("user",user);
    postData.addQueryItem("email",email);
    if (ui->Op1->isChecked())
        postData.addQueryItem("cmd","login3");
    else
        postData.addQueryItem("cmd","getimtihan");

    frmconn = new frmConnect;
    frmconn->show();
    frmstart->hide();

    result = frmurl.OpenURL(Url_php,&web,postData);
    if(web != 200){
        QMessageBox::information(0,"title","فشل الاتصال لانقطاع الخط حاول من جديد");
        frmconn->close();
        return;
    }
    QString  txt = QTextCodec::codecForName("CP-1256")->toUnicode(result);
    if(txt == ""){
        QMessageBox::information(0,"title","حدث خلل ما الرجاء المحاولة من جديد");
        frmconn->close();
        return;
    }
    txt = TestStr(txt);
    qDebug() << "result: " << txt;

    if (ui->Op1->isChecked()){
       // Call ExtracTxt(TestStr(St))
        frmconn->close();
    }else{
        frmnataij = new FrmNataij;
        frmnataij->show();
        frmstart->hide();
       // FrmNataij.Show
       // Call FrmNataij.ExtracTxt(TestStr(St))
    }


}
void FrmStart::on_pushButton_clicked()
{
    frmconn = new frmConnect;
    frmconn->show();
    frmstart->hide();
}
