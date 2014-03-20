#include "frmurl.h"
#include <QEventLoop>
#include <QNetworkCookie>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QUrlQuery>
#endif
#include <QTimer>
#include <QDebug>

FrmURL::FrmURL(QObject *parent):  QObject(parent), reply(NULL)
{

}
FrmURL::~FrmURL()
{

}
QByteArray FrmURL::OpenURL(QString host,int *web, QUrlQuery postData)
{
    QNetworkAccessManager manager;

    QNetworkRequest request(host);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

    QUrl url;
    url.setQuery(postData);
    QNetworkReply *reply = manager.post(request, url.toEncoded());

    QEventLoop loop;

    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    QTimer::singleShot(10000, &loop, SLOT(quit()));
    loop.exec();
    *web = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    QByteArray result(reply->readAll());
    reply->deleteLater();
    return result;
}
