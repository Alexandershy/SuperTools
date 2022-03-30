
#ifndef SUPERCORE_H
#define SUPERCORE_H

#include <QCryptographicHash>
#include <QFileIconProvider>
#include <QDesktopServices>
#include <QTableWidget>
#include <QHeaderView>
#include <QCheckBox>
#include <QProcess>
#include <QThread>
#include <QLayout>
#include <QUrl>
#include <QMenu>
#include <QDir>

class SuperCore : public QObject
{
    Q_OBJECT

public:

    SuperCore(
        QObject *parent = nullptr);

    ~SuperCore();

public slots:

    /*  QString */

    QString Firstwordupper(
        QString str);

    QString Firstwordlower(
        QString str);

    QString Allwordupper(
        QString str);

    QString Allwordlower(
        QString str);

    bool Checkiprules(
        QString strip);

    bool Checkfilename(
        QString filename);

    /*  QStringList */

    QString Getlistlastmember(
        QStringList *list);

    int Findlistmember(
        QStringList *list,
        QString str);

    /*  QSystem */

    void Runcommand(
        QString strpath,
        QString strcommand);

    bool Creatfolder(
        QString strfolder);

    bool Creatfile(
        QString strfile);

    /*  QFile */

    void Getfileinfolist(
        QString filename,
        QStringList *fileinfo);

    void Getfileinfobyte(
        QString filename,
        QByteArray *fileinfo);

    QByteArray Getfilehash(
        QString filename);

    QString Fixfilepath(
        QString filepath);

    void Writeonlyfile(
        QString strpath,
        QString strtext);

    void Writeonlyfilelist(
        QString strpath,
        QStringList *list,
        QString parameters,
        bool addlast);

    void Writebytes(
        QString strpath,
        QByteArray bytes);

    void Appendfile(
        QString strpath,
        QString strtext);

    void Appendbytes(
        QString strpath,
        QByteArray bytes);

    QString Readonlyfile(
        QString strpath);

    QByteArray Readbytesint64(
        QString strpath,
        qint64 fileseek,
        qint64 datasize);

    void Replacefile(
        QString srcfile,
        QString targetfile);

    /*  QVector */

    QVector<double> Linspace(
        double doublemin,
        double doublemax,
        int intnum);

    QVector<double> Arange(
        double doublemin,
        double doublemax,
        double step);

    double Getqvectormaxvalue(
        QVector<double> *qvectord,
        int intsize);

    double Getqvectorminvalue(
        QVector<double> *qvectord,
        int intsize);

    double Getqvectormeanvalue(
        QVector<double> *qvectord,
        int intsize);

    double Getqvectorstandarddeviation(
        QVector<double> *qvectord,
        int intsize,
        double mean);

    /*  doublearray */

    double Getdoublearraymaxvalue(
        double* doublearray,
        int intcount);

    double Getdoublearrayminvalue(
        double* doublearray,
        int intcount);

    double Getdoublearraymeanvalue(
        double* doublearray,
        int intcount);

    /*  QColor*/

    QString Rgbcolor(
        QColor *color);

    /*  QMenu*/

    void Addmenu(
        QMenu* parent,
        QMenu* menu,
        QString menuname);

    void Addaction(
        QMenu* parent,
        QAction* action,
        QString actionname,
        QString objectname);

    /*  QTablewidget*/

    void Settablewidgetitem(
        int rowcounts,
        int columncounts,
        int height,
        QTableWidget *tablewidget);

    /*SuperTools Plugins*/

    void Colorinit(
        QColor *backgroundcolor,
        QColor *fontcolor,
        QColor *concolor,
        QString *strrgbbackgroundcolor,
        QString *strrgbfontcolor,
        QString *strconcolor);

    void Enablewidgetlist(
        QList<QWidget*> *widgetlist,
        bool boola);

    void Checkedwidgetlist(
        QList<QCheckBox*>* checkboxlist,
        bool boola);

    void Closethread(
        QThread *threada);

    void Deleteobject(
        QObject* object);

    QPoint Widgetleftbottompoint(
        QWidget* widget);

    QPoint Widgetrightbottompoint(
        QWidget* widget);

    void Openpath(
        QString path);

    void Deleteallitemsoflayout(
        QLayout *layout);

};

#endif // SUPERCORE_H
