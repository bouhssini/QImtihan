#ifndef GENERAL_H
#define GENERAL_H

#ifdef WIN32
#include <windows.h>
#endif
#include <QDebug>
#include <QApplication>
#include <QIcon>
#include <QTextCodec>
#include <QKeyEvent>
#include <QUrlQuery>

#include "frmstart.h"
#include "frmurl.h"
#include "frmconnect.h"
#include "frmnataij.h"

#include <iostream>
#include <string.h>

using namespace std;

extern QString Url_php;
extern string ver;
extern QString ALFA;

extern FrmStart *frmstart;
extern frmConnect *frmconn;
extern FrmNataij *frmnataij;


extern QString TestStr(QString txt);
extern QString TestImtDisplay(QString txt);

#endif // GENERAL_H
