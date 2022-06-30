#ifndef SUPERHTTP_H
#define SUPERHTTP_H
#define SUPERHTTP_EXPORT Q_DECL_EXPORT

#include <QUrl>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QHttpMultiPart>
#include <QNetworkAccessManager>

class SUPERHTTP_EXPORT SuperHttp : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ accountUser WRITE setAccountUser)
    Q_PROPERTY(QString passWord READ accountPassword WRITE setAccountPassword)

public:

    explicit SuperHttp(
            QObject *parent = nullptr);

    ~SuperHttp();

public slots:

    void setNetworkAccessible(
            QNetworkAccessManager::NetworkAccessibility accessibility);

    void setAccountInfo(
            const QVariantMap &accountmap);

    void setAccountUser(
            const QString &user);

    void setAccountPassword(
            const QString &password);

    QVariantMap accountInfo();

    QString accountUser();

    QString accountPassword();

    void getRequestApi(
            const QString &url,
            const QJsonObject &headerobject);

    void postRequestApi(
            const QString &url,
            const QJsonObject &headerobject,
            const QJsonObject &bodyobject);

private:

    QNetworkAccessManager *Manager              = nullptr;
    QAuthenticator Authenticator                = {};
    QUrl Url                                    = {};
    QJsonObject Headerobject                    = {};
    QJsonObject Bodyobject                      = {};
    QVector<QUrl> Urlvector                     = {};

private slots:

    void init();

    void objectInit();

    void parameterInit();

    void setAuthentication(
            QNetworkReply *reply,
            QAuthenticator *authenticator);

    QNetworkRequest setRequestType(
            const QUrl &url);

    bool setRequestUrl(
            const QString &url);

    void setRequestHeader(
            const QJsonObject &headerobject);

    void addRequestHeader(
            const QString &key,
            const QJsonValue &value);

    void clearRequestHeader();

    void setRequestBody(
            const QJsonObject &bodyobject);

    void addRequestBody(
            const QString &key,
            const QJsonValue &value);

    void clearRequestBody();

    void newGetRequest();

    void newPostRequest();

    void newPostRequestPart();

    void reply(
            QNetworkReply *reply);

signals:

    void replyFinished(
            QNetworkReply *reply);

};

#endif // SUPERHTTP_H
