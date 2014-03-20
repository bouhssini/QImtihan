#ifndef FRMURL_H
#define FRMURL_H

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

class FrmURL : public QObject
{
    Q_OBJECT
public:
    explicit FrmURL(QObject *parent = 0);
    ~FrmURL();
    QByteArray OpenURL(QString url,int *web, QUrlQuery parameters);

private:
    QNetworkReply *reply;
    QNetworkRequest request;
    QNetworkAccessManager *manager;
    
signals:
    
public slots:
    
};

#endif // FRMURL_H
