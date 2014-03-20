#include "General.h"

frmConnect *frmconn = NULL;
FrmStart *frmstart = NULL;
FrmNataij *frmnataij = NULL;

QString Url_php = "http://maahad.net/maahad.php";
string ver = "2.0.0";
QString ALFA = "0123456789azertyuiopqsdfghjklmwxcvbn@._-";

QString TestStr(QString txt)
{
    const QString St1("debut|");
    const QString St2("|fin");
    QString stxt = "";
    int ps1 = 0,ps2 = 0;

    ps1 = txt.indexOf(St1,0);
    if (ps1 == -1) return stxt;
    ps2 = txt.indexOf(St2,ps1+1);
    if (ps2 == -1) return stxt;
    ps1 = ps1+St1.size();
    stxt = txt.mid(ps1,ps2 -ps1);
    stxt = TestImtDisplay(stxt);
    return stxt;
}
QString TestImtDisplay(QString txt)
{
    int ps1 = 0,ps2 = 0, p = 0;
    QString imtihanew = "";
    bool BB = false;
    QString imtihan = txt.toLower();
    ps1 = -1;
    while(true)
    {
        ps1 = imtihan.indexOf("\r\n",ps1+1);
        if (ps1 == -1) break;
        ps2 = imtihan.indexOf("\r\n",ps1+1);
        if (ps2 == -1) break;
        imtihanew = imtihan.mid(ps1,ps2 - ps1 + 2);
        for(int i = 2;i < imtihanew.size()-2;i++)
        {
            p = ALFA.indexOf(imtihanew.mid(i,1));
            if (p != -1){
                BB = true;
            }else{
                BB = false;
                break;
            }
        }
        if(BB){
            imtihan = imtihan.replace(imtihanew,"");
        }
    }
    return imtihan;

}
