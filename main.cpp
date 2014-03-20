#include "General.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
        if(strcmp(argv[1],"-v")==0){
            cout << ver;
            return 0;
        }

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/Resources/Internet.png"));
    #if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    #endif
    a.setLayoutDirection(Qt::RightToLeft);


    QString txt = "bouhssini\r\nfddsdf\r\n youssef";

    TestImtDisplay(txt);


    frmstart = new FrmStart;
    frmstart->show();
    
    return a.exec();
}
