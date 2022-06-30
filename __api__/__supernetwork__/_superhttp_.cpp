#include "_superhttp_.h"

SuperHttp::SuperHttp(QObject *parent)
    :QObject(parent)
{
    init();
}

SuperHttp::~SuperHttp()
{

}

void SuperHttp::init()

{
    objectInit();
    parameterInit();
}

void SuperHttp::objectInit()
{
    Manager = new QNetworkAccessManager(this);
}

/*  creat new object for this;*/

void SuperHttp::parameterInit()
{
    connect(Manager,&QNetworkAccessManager::authenticationRequired, this,&SuperHttp::setAuthentication);
    connect(Manager,&QNetworkAccessManager::finished,               this,&SuperHttp::reply);
}

/*  object parameter init;*/

void SuperHttp::setNetworkAccessible(QNetworkAccessManager::NetworkAccessibility accessibility)
{
    Manager->setNetworkAccessible(accessibility);
}

/*  set network accessible;*/

void SuperHttp::setAccountInfo(const QVariantMap &map)
{
    Authenticator.setUser(map.value("username").toString());
    Authenticator.setPassword(map.value("password").toString());
}

/*  set account info;*/

void SuperHttp::setAccountUser(const QString &username)
{
    Authenticator.setUser(username);
}

/*  set account username;*/

void SuperHttp::setAccountPassword(const QString &password)
{
    Authenticator.setPassword(password);
}

/*  set account password;*/

QVariantMap SuperHttp::accountInfo()
{
    QVariantMap map;
    map.insert("username",Authenticator.user());
    map.insert("password",Authenticator.password());
    return map;
}

/*  return account info;*/

QString SuperHttp::accountUser()
{
    return Authenticator.user();
}

/*  return account username;*/

QString SuperHttp::accountPassword()
{
    return Authenticator.password();
}

/*  return account password;*/

void SuperHttp::getRequestApi(const QString &url, const QJsonObject &headerobject)
{
    if(setRequestUrl(url))
    {
        setRequestHeader(headerobject);
        newGetRequest();
    }
}

/*  get request api;*/

void SuperHttp::postRequestApi(const QString &url, const QJsonObject &headerobject, const QJsonObject &bodyobject)
{
    if(setRequestUrl(url))
    {
        setRequestHeader(headerobject);
        setRequestBody(bodyobject);
        newPostRequest();
    }
}

/*  post request api;*/

void SuperHttp::setAuthentication(QNetworkReply *reply,QAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    if(Authenticator.isNull())
    {

    }
    else
    {
        authenticator->setUser(Authenticator.user());
        authenticator->setPassword(Authenticator.password());
    }
}

/*  set authentication;*/

QNetworkRequest SuperHttp::setRequestType(const QUrl &url)
{
    QNetworkRequest request(url);
    if(url.url().contains("https"),Qt::CaseSensitive)
    {
        QSslConfiguration sslconfig;
        sslconfig.setPeerVerifyMode(QSslSocket::VerifyNone);
        sslconfig.setProtocol(QSsl::AnyProtocol);
        request.setSslConfiguration(sslconfig);
    }
    return request;
}

/*  set request type;*/

bool SuperHttp::setRequestUrl(const QString &url)
{
    if(Urlvector.contains(url))
    return false;
    Url.setUrl(url);
    Urlvector.append(Url);
    return true;
}

/*  only has one same url request in class;*/

void SuperHttp::setRequestHeader(const QJsonObject &headerobject)
{
    Headerobject = headerobject;
}

/*  set http header;*/

void SuperHttp::addRequestHeader(const QString &key,const QJsonValue &value)
{
    Headerobject.insert(key,value);
}

/*  add http header;*/

void SuperHttp::clearRequestHeader()
{
    QStringList list = Headerobject.keys();
    for(int i = 0;i < list.count();i++)
    {
        Headerobject.remove(list.at(i));
    }
}

/*  clear http header;*/

void SuperHttp::setRequestBody(const QJsonObject &bodyobject)
{
    Bodyobject = bodyobject;
}

/*  set http body;*/

void SuperHttp::addRequestBody(const QString &key, const QJsonValue &value)
{
    Bodyobject.insert(key,value);
}

/*  add http body;*/

void SuperHttp::clearRequestBody()
{
    QStringList bodylist = Bodyobject.keys();
    for(int i = 0;i < bodylist.count();i++)
    {
        Bodyobject.remove(bodylist.at(i));
    }
}

/*  clear http body;*/

void SuperHttp::newGetRequest()
{
    QNetworkRequest request = setRequestType(Url);
    QStringList list = Headerobject.keys();
    for(int i = 0;i < list.count();i++)
    {
        request.setRawHeader(list.at(i).toUtf8(),Headerobject.value(list.at(i)).toString().toUtf8());
    }
    Manager->get(request);
}

/*  new get request;*/

void SuperHttp::newPostRequest()
{
    QByteArray body;
    QNetworkRequest request = setRequestType(Url);
    QJsonDocument bodydocument(Bodyobject);
    QStringList list = Headerobject.keys();
    for(int i = 0;i < list.count();i++)
    {
        request.setRawHeader(list.at(i).toUtf8(),Headerobject.value(list.at(i)).toString().toUtf8());
    }
    if(!bodydocument.isEmpty())
    {
        body.append(bodydocument.toJson());
    }
    Manager->post(request,body);
}

/*  new post request;*/

void SuperHttp::newPostRequestPart()
{
    QHttpPart part;
    QNetworkRequest request = setRequestType(Url);
    QJsonDocument bodydocument(Bodyobject);
    QStringList headerlist = Headerobject.keys();
    QHttpMultiPart *multipart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QByteArray body = bodydocument.toJson();
    for(int i = 0;i < headerlist.count();i++)
    {
        request.setRawHeader(headerlist.at(i).toUtf8(),Headerobject.value(headerlist.at(i)).toString().toUtf8());
    }
    part.setBody(body);
    multipart->append(part);
    QNetworkReply *reply = Manager->post(request,multipart);
    multipart->setParent(reply);
}

/*  new post request with http part;*/

void SuperHttp::reply(QNetworkReply *reply)
{
    Urlvector.remove(Urlvector.indexOf(reply->url()));
    emit replyFinished(reply);
}

/*  only has one same url request in class;*/



