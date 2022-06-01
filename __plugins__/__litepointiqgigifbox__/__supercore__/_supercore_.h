#ifndef _SUPERCORE__H
#define _SUPERCORE__H
#define _SUPERCORE__EXPORT Q_DECL_EXPORT

#include <QCryptographicHash>
#include <QFileIconProvider>
#include <QDesktopServices>
#include <QTableWidget>
#include <QHeaderView>
#include <QCheckBox>
#include <QProcess>
#include <QThread>
#include <QLayout>
#include <QMenu>
#include <QUrl>
#include <QDir>

class _SUPERCORE__EXPORT SuperCore : public QObject
{
    Q_OBJECT

public:

    SuperCore(
        QObject *parent = nullptr);

    ~SuperCore();

public slots:

    /*  QString */
    QString firstWordUpper(
        QString str);

    QString firstWordLower(
        QString str);

    QString allWordUpper(
        QString str);

    QString allWordLower(
        QString str);

    bool checkIpRules(
        QString strip);

    bool checkFileName(
        QString filename);

    /*  QStringList */
    QString getListLastMember(
        QStringList *list);

    int findListMember(
        QStringList *list,
        QString str);

    /*  QSystem */
    void runCommand(
        QString strpath,
        QString strcommand);

    bool creatFolder(
        QString strfolder);

    bool creatFile(
        QString strfile);

    /*  QFile */
    void getFileInfoList(
        QString filename,
        QStringList *fileinfo);

    void getFileInfoByte(
        QString filename,
        QByteArray *fileinfo);

    QByteArray getFileHash(
        QString filename);

    QString fixFilePath(
        QString filepath);

    void writeOnlyFile(
        QString strpath,
        QString strtext);

    void writeOnlyFileList(
        QString strpath,
        QStringList *list,
        QString parameters,
        bool addlast);

    void writeBytes(
        QString strpath,
        QByteArray bytes);

    void appendFile(
        QString strpath,
        QString strtext);

    void appendBytes(
        QString strpath,
        QByteArray bytes);

    QString readOnlyFile(
        QString strpath);

    QByteArray readBytesInt64(
        QString strpath,
        qint64 fileseek,
        qint64 datasize);

    void replaceFile(
        QString srcfile,
        QString targetfile);

    QString getFilePath(
        QString filepath);

    void setPermissions(
        QFile *file);

    /*  QVector */
    QVector<double> linspace(
        double doublemin,
        double doublemax,
        int intnum);

    QVector<double> arange(
        double doublemin,
        double doublemax,
        double step);

    int getVectorMaxValue(
        QVector<int> *qvectord,
        int intsize);

    int getVectorMinValue(
        QVector<int> *qvectord,
        int intsize);

    double getVectorMaxValue(
        QVector<double> *qvectord,
        int intsize);

    double getVectorMinValue(
        QVector<double> *qvectord,
        int intsize);

    double getVectorMeanValue(
        QVector<double> *qvectord,
        int intsize);

    double getVectorStandardDeviation(
        QVector<double> *qvectord,
        int intsize,
        double mean);

    /*  QPointF */
    QPointF getVectorMaxPointF(
        QVector<QPointF> *qvectorpf,int intsize);

    QPointF getVectorMinPointF(
        QVector<QPointF> *qvectorpf,int intsize);

    /*  doublearray */
    double getDoubleArrayMaxValue(
        double* doublearray,
        int intcount);

    double getDoubleArrayMinValue(
        double* doublearray,
        int intcount);

    double getDoubleArrayMeanValue(
        double* doublearray,
        int intcount);

    /*  QColor*/
    QString rgbColor(
        QColor *color);

    /*  QMenu*/
    void addMenu(
        QMenu* parent,
        QMenu* menu,
        QString menuname);

    void addAction(
        QMenu* parent,
        QAction* action,
        QString actionname,
        QString objectname);

    /*  QTablewidget*/
    void setTableWidgetItem(
        int rowcounts,
        int columncounts,
        int height,
        QTableWidget *tablewidget);

    /*SuperTools Plugins*/
    void colorInit(
        QColor *backgroundcolor,
        QColor *fontcolor,
        QColor *concolor,
        QString *strrgbbackgroundcolor,
        QString *strrgbfontcolor,
        QString *strconcolor);

    void enableWidgetList(
        QList<QWidget*> *widgetlist,
        bool boola);

    void checkedWidgetList(
        QList<QCheckBox*>* checkboxlist,
        bool boola);

    void closeThread(
        QThread *threada);

    void deleteObject(
        QObject* object);

    QPoint widgetLeftBottomPoint(
        QWidget* widget);

    QPoint widgetRightBottomPoint(
        QWidget* widget);

    void openPath(
        QString path);

    void deleteAllItemsOfLayout(
        QLayout *layout);

};

#endif // _SUPERCORE__H
