#include "_supercore_.h"

SuperCore::SuperCore(QObject *parent)
    : QObject(parent)
{

}

SuperCore::~SuperCore()
{

}

//**************************************************QString********************************************************//

QString SuperCore::Firstwordupper(QString str)
{
    for(int i = 0;i < str.count();i++)
    {
        if(!i)
        {
            str[i] = str.at(i).toUpper();
        }
    }
    return str;
}

/*  set QString first word upper;*/

QString SuperCore::Firstwordlower(QString str)
{
    for(int i = 0;i < str.count();i++)
    {
        if(!i)
        {
            str[i] = str.at(i).toLower();
        }
    }
    return str;
}

/*  set QString first word lower;*/

QString SuperCore::Allwordupper(QString str)
{
    for(int i = 0;i < str.count();i++)
    {
        str[i] = str.at(i).toUpper();
    }
    return str;
}

/*  set QString all word upper;*/

QString SuperCore::Allwordlower(QString str)
{
    for(int i = 0;i < str.count();i++)
    {
        str[i] = str.at(i).toLower();
    }
    return str;
}

/*  set QString all word lower;*/

bool SuperCore::Checkiprules(QString strip)
{
    QRegularExpression iprules("^((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)$");
    QRegularExpressionMatch match = iprules.match(strip);
    return match.hasMatch();
}

/*  check whether the QString complies with ip rules;*/

bool SuperCore::Checkfilename(QString filename)
{
    QStringList filerules = {"\\","/",":","*","?","\"","<",">","|"};
    for(int i = 0;i < filerules.count();i++)
    {
        if(filename.contains(filerules.at(i)) || filename.isEmpty())
        {
            return false;
        }
    }
    return true;
}

/*  check filename is standard;*/

//************************************************QStringList******************************************************//

QString SuperCore::Getlistlastmember(QStringList *list)
{
    return list->at(list->count() - 1);
}

/*  get the current list last member;*/

int SuperCore::Findlistmember(QStringList *list,QString str)
{
    for(int i = 0;i < list->count();i++)
    {
        if(list->at(i) == str)
        {
            return i;
        }
    }
    return -1;
}

/*  determine whether the member is in the list and return index;*/

//**************************************************QSystem********************************************************//

void SuperCore::Runcommand(QString strpath, QString strcommand)
{
    QProcess *process = new QProcess();
    connect(process,&QProcess::finished,process,&QObject::deleteLater);
    Writeonlyfile(strpath,strcommand);
    process->start("cmd",{"/c",strcommand});
}

/*  run command and output result;*/

bool SuperCore::Creatfolder(QString strfolder)
{
    QDir dir(QDir::currentPath());
    return dir.mkdir(strfolder);
}

/*  creat folder using Qstring path;*/

bool SuperCore::Creatfile(QString strfile)
{
    QFile file(strfile);
    if(file.exists())
    {
        return true;
    }
    file.open(QIODevice::ReadWrite);
    file.setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOwner | QFile::WriteOwner);
    file.close();
    return true;
}

/*  creat file using Qstring path;*/

//***************************************************QFile*********************************************************//

void SuperCore::Getfileinfolist(QString filename,QStringList *fileinfo)
{
    fileinfo->clear();
    QFileInfo file(filename);
    if(file.exists() == true)
    {
        fileinfo->append(Fixfilepath(file.absolutePath()));
        fileinfo->append(file.completeBaseName() + "." + file.suffix());
        fileinfo->append(QString::number(file.size()));
        fileinfo->append(file.birthTime().toString("yyyyMMddhhmmss"));
        fileinfo->append(Getfilehash(file.absoluteFilePath()));
        fileinfo->append("available");
    }
    else
    {
        QStringList filepathlist = filename.split("/");
        fileinfo->append("unavailable");
        fileinfo->append(Getlistlastmember(&filepathlist));
        fileinfo->append("unavailable");
        fileinfo->append("unavailable");
        fileinfo->append("unavailable");
        fileinfo->append("unavailable");
    }
}

/*  get file info by stringlist;*/

void SuperCore::Getfileinfobyte(QString filename,QByteArray *fileinfo)
{
    fileinfo->clear();
    QFileInfo file(filename);
    if(file.exists() == true)
    {
        QByteArray filenamebyte = (file.completeBaseName() + "." + file.suffix()).toUtf8();
        fileinfo->append(Fixfilepath(file.absolutePath()).toUtf8() + "<split>");
        fileinfo->append(filenamebyte + "<split>");
        fileinfo->append(QByteArray::number(file.size()) + "<split>");
        fileinfo->append(file.birthTime().toString("yyyyMMddhhmmss").toUtf8() + "<split>");
        fileinfo->append(Getfilehash(file.absoluteFilePath()) + "<split>");
        fileinfo->append("available");
    }
    else
    {
        QStringList filepathlist = filename.split("/");
        fileinfo->append("unavailable<split>");
        fileinfo->append(Getlistlastmember(&filepathlist).toUtf8() + "<split>");
        fileinfo->append("unavailable<split>");
        fileinfo->append("unavailable<split>");
        fileinfo->append("unavailable<split>");
        fileinfo->append("unavailable");
    }
}

/*  get file info by bytearray;*/

QByteArray SuperCore::Getfilehash(QString filename)
{
    QByteArray hashvalue;
    QCryptographicHash hash(QCryptographicHash::Md5);
    QFile file(filename);
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        hash.addData(file.read(1024000));
        hashvalue = hash.result().toHex();
        file.close();
    }
    return hashvalue;
}

/*  get file 1 MBits hash value;*/

QString SuperCore::Fixfilepath(QString filepath)
{
    if(filepath.at(filepath.count() - 1) != '/' && !filepath.isEmpty())
    {
        return filepath + "/";
    }
    return filepath;
}

/*  add // at path last;*/

void SuperCore::Writeonlyfile(QString strpath, QString strtext)
{
    QFile file(strpath);
    file.open(QIODevice::WriteOnly);
    file.setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOwner | QFile::WriteOwner);
    file.write(strtext.toUtf8());
    file.close();
}

/*  write only for Qstring text and using QString path;*/

void SuperCore::Writeonlyfilelist(QString strpath, QStringList *list,QString parameters,bool addlast)
{
    QString temp;
    QFile file(strpath);
    file.open(QIODevice::WriteOnly);
    file.setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOwner | QFile::WriteOwner);
    for(int i = 0;i < list->count();i++)
    {
        if(addlast)
        {
            temp = temp + list->at(i) + parameters;
        }
        else
        {
            if(i < list->count() - 1)
            {
                temp = temp + list->at(i) + parameters;
            }
            else
            {
                temp = temp + list->at(i);
            }
        }
    }
    file.write(temp.toUtf8());
    file.close();
}

/*  write only for QstringList and using QString path;*/

void SuperCore::Writebytes(QString strpath,QByteArray bytes)
{
    QFile file(strpath);
    file.open(QIODevice::WriteOnly);
    file.setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOwner | QFile::WriteOwner);
    file.write(bytes);
    file.close();
}

/*  write only for QByteArray and using QString path;*/

void SuperCore::Appendfile(QString strpath, QString strtext)
{
    QFile file(strpath);
    file.open(QIODevice::Append);
    file.setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOwner | QFile::WriteOwner);
    file.write(strtext.toUtf8());
    file.close();
}

/*  append QString and using QString path;*/

void SuperCore::Appendbytes(QString strpath,QByteArray bytes)
{
    QFile file(strpath);
    file.open(QIODevice::Append);
    file.setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOwner | QFile::WriteOwner);
    file.write(bytes);
    file.close();
}

/*  read only return QByteArray and using QString path;*/

QString SuperCore::Readonlyfile(QString strpath)
{
    QFile file(strpath);
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        file.setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOwner | QFile::WriteOwner);
        QByteArray result = file.readAll();
        file.close();
        return result;
    }
    return "";
}

/*  read only return QString and using QString path;*/

QByteArray SuperCore::Readbytesint64(QString strpath,qint64 fileseek,qint64 datasize)
{
    QFile file(strpath);
    file.open( QIODevice::ReadOnly);
    file.setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOwner | QFile::WriteOwner);
    file.seek(fileseek);
    QByteArray result = file.read(datasize);
    file.close();
    return result;
}

/*  read only return QByteArray and using QString path;*/

void SuperCore::Replacefile(QString srcfile, QString targetfile)
{
    QFile file(targetfile);
    if(!file.exists())
    {
        QFile::copy(srcfile,targetfile);
    }
    else
    {
        QByteArray oldhash = Getfilehash(targetfile);
        QByteArray newhash = Getfilehash(srcfile);
        if(oldhash != newhash)
        {
            QFile::remove(targetfile);
            QFile::copy(srcfile,targetfile);
        }
    }
    file.setPermissions(QFile::ReadOther | QFile::WriteOther | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOwner | QFile::WriteOwner);
}

/*  creat qrc file for use;*/

QString SuperCore::Getfilepath(QString filepath)
{
    QFileInfo fileinfo(filepath);
    if(fileinfo.isFile() || fileinfo.isDir())
    {
        return fileinfo.absoluteFilePath();
    }
    else
    {
        return QDir::currentPath();
    }
}

/*  change file path to absolutely path;*/

//**************************************************QVector********************************************************//

QVector <double> SuperCore::Linspace(double doublemin, double doublemax, int intnum)
{
    QVector <double> matharray = {};
    double discrepancy = (doublemax - doublemin) / intnum;
    for(int i = 0;i < intnum;i++)
    {
        matharray.append(doublemin + i * discrepancy);
    }
    return matharray;
}

/*  return arithmetic discrepancy by min,max,number;*/

QVector <double> SuperCore::Arange(double doublemin, double doublemax, double step)
{
    QVector <double> matharray = {};
    int intnum = (doublemax - doublemin) / step;
    for(int i = 0;i < intnum;i++)
    {
        matharray.append(doublemin + i * step);
    }
    return matharray;
}

/*  return arithmetic discrepancy by min,max,step;*/

double SuperCore::Getqvectormaxvalue(QVector<double> *qvectord,int intsize)
{
    double temp = qvectord->at(0);
    for(int i = 0;i < intsize;i++)
    {
        if(temp < qvectord->at(i))
        {
            temp = qvectord->at(i);
        }
    }
    return temp;
}

/*  return qvector max value;*/

double SuperCore::Getqvectorminvalue(QVector<double> *qvectord,int intsize)
{
    double temp = qvectord->at(0);
    for(int i = 0;i < intsize;i++)
    {
        if(temp > qvectord->at(i))
        {
            temp = qvectord->at(i);
        }
    }
    return temp;
}

/*  return qvector min value;*/

double SuperCore::Getqvectormeanvalue(QVector<double> *qvectord,int intsize)
{
    double temp = 0;
    for(int i = 0;i < intsize;i++)
    {
        temp = temp + qvectord->at(i);
    }
    return temp / intsize;
}

/*  return qvector mean value;*/

double SuperCore::Getqvectorstandarddeviation(QVector<double> *qvectord,int intsize,double mean)
{
    double tempa = 0;
    double tempb = 0;
    for(int i = 0;i < intsize;i++)
    {
        tempa = (qvectord->at(i) - mean);
        tempb = tempb + tempa * tempa;
    }
    return sqrt(tempb / (intsize - 1));
}

/*  return qvector standard deviation value;*/

//*****************************************************QPointF***********************************************************//

QPointF SuperCore::Getqvectormaxpointf(QVector<QPointF> *qvectorpf,int intsize)
{
    QPointF pointftemp = qvectorpf->at(0);
    for(int i = 0;i < intsize;i++)
    {
        if(pointftemp.x() < qvectorpf->at(i).x())
        {
            pointftemp.setX(qvectorpf->at(i).x());
        }
        if(pointftemp.y() < qvectorpf->at(i).y())
        {
            pointftemp.setY(qvectorpf->at(i).y());
        }
    }
    return pointftemp;
}

/*  return qvector max pointf;*/

QPointF SuperCore::Getqvectorminpointf(QVector<QPointF> *qvectorpf,int intsize)
{
    QPointF pointftemp = qvectorpf->at(0);
    for(int i = 0;i < intsize;i++)
    {
        if(pointftemp.x() > qvectorpf->at(i).x())
        {
            pointftemp.setX(qvectorpf->at(i).x());
        }
        if(pointftemp.y() > qvectorpf->at(i).y())
        {
            pointftemp.setY(qvectorpf->at(i).y());
        }
    }
    return pointftemp;
}

/*  return qvector min pointf;*/

//***************************************************doublearray*********************************************************//

double SuperCore::Getdoublearraymaxvalue(double* doublearray,int intcount)
{
    double temp = 0;
    if(intcount > 0)
    {
        temp = doublearray[0];
    }
    for(int i = 0;i < intcount;i++)
    {
        if(temp < doublearray[i])
        {
            temp = doublearray[i];
        }
    }
    return temp;
}

/*  return double array max value;*/

double SuperCore::Getdoublearrayminvalue(double* doublearray,int intcount)
{
    double temp = 0;
    if(intcount > 0)
    {
        temp = doublearray[0];
    }
    for(int i = 0;i<intcount;i++)
    {
        if(temp > doublearray[i])
        {
            temp = doublearray[i];
        }
    }
    return temp;
}

/*  return double array min value;*/

double SuperCore::Getdoublearraymeanvalue(double* doublearray,int intcount)
{
    double temp = 0;
    for(int i = 0;i < intcount;i++)
    {
        temp = temp + doublearray[i];
    }
    temp = temp / intcount;
    return temp;
}

/*  return double array mean value;*/

//****************************************************QMenu********************************************************//

void SuperCore::Addmenu(QMenu* parent,QMenu* menu,QString menuname)
{
    menu->setTitle(menuname);
    parent->addMenu(menu);
}

void SuperCore::Addaction(QMenu* parent,QAction* action,QString actionname,QString objectname)
{
    action->setText(actionname);
    action->setObjectName(objectname);
    parent->addAction(action);
}

//****************************************************QColor*******************************************************//

QString SuperCore::Rgbcolor(QColor *color)
{
    return QString::number(color->red()) + "," + QString::number(color->green()) + "," + QString::number(color->blue());
}

/*  get qbytearray rgb color;*/

void SuperCore::Settablewidgetitem(int rowcounts,int columncounts,int height,QTableWidget *tablewidget)
{
    tablewidget->clear();
    tablewidget->setRowCount(rowcounts);
    tablewidget->setColumnCount(columncounts);
    tablewidget->verticalHeader()->setMinimumSectionSize(height);
    tablewidget->verticalHeader()->setDefaultSectionSize(height);
    for(int i = 0;i < rowcounts;i++)
    {
        for(int j = 0;j < columncounts;j++)
        {
            QTableWidgetItem* item = new QTableWidgetItem();
            tablewidget->setItem(i,j,item);
        }
    }
}

/*  set table widget item;*/

//**********************************************SuperTools Plugin**************************************************//

void SuperCore::Colorinit(QColor *backgroundcolor,QColor *fontcolor,QColor *concolor,QString *strrgbbackgroundcolor,QString *strrgbfontcolor,QString *strconcolor)
{
    QStringList rgbbackgroundcolor = Readonlyfile("./__depycache__/__cache__/__ini__/_backgroundcolor_.ini").split(",");
    QStringList rgbfontcolor = Readonlyfile("./__depycache__/__cache__/__ini__/_fontcolor_.ini").split(",");
    if(rgbbackgroundcolor.count() >= 3 && rgbfontcolor.count() >= 3)
    {
        backgroundcolor->setRgb(rgbbackgroundcolor.at(0).toInt(),rgbbackgroundcolor.at(1).toInt(),rgbbackgroundcolor.at(2).toInt());
        fontcolor->setRgb(rgbfontcolor.at(0).toInt(),rgbfontcolor.at(1).toInt(),rgbfontcolor.at(2).toInt());
        concolor->setRgb(255 - rgbbackgroundcolor.at(0).toInt(),255 - rgbbackgroundcolor.at(1).toInt(),255 - rgbbackgroundcolor.at(2).toInt());
    }
    strrgbbackgroundcolor->clear();
    strrgbfontcolor->clear();
    strconcolor->clear();
    strrgbbackgroundcolor->append("rgb(" + Rgbcolor(backgroundcolor) + ")");
    strrgbfontcolor->append("rgb(" + Rgbcolor(fontcolor) + ")");
    strconcolor->append("rgb(" + Rgbcolor(concolor) + ")");
}

/*  if rgb file exist,use color saved,else use default color;*/

void SuperCore::Enablewidgetlist(QList<QWidget*>* widgetlist,bool boola)
{
    for(int i = 0;i < widgetlist->count();i++)
    {
        widgetlist->at(i)->setEnabled(boola);
    }
}

/*  enable widget in a list or not;*/

void SuperCore::Checkedwidgetlist(QList<QCheckBox*>* checkboxlist,bool boola)
{
    for(int i = 0;i < checkboxlist->count();i++)
    {
        checkboxlist->at(i)->setChecked(boola);
    }
}

/*  check widget in a list or not;*/

void SuperCore::Closethread(QThread *threada)
{
    if(threada != nullptr)
    {
        while(true)
        {
            if(threada->isRunning())
            {
                QThread::msleep(100);
            }
            else
            {
                delete threada;
                threada = nullptr;
                break;
            }
        }
    }
}

/*  close thread api;*/

void SuperCore::Deleteobject(QObject *object)
{
    if(object != nullptr)
    {
        delete object;
        object = nullptr;
    }
}

/*  super delete;*/

QPoint SuperCore::Widgetleftbottompoint(QWidget* widget)
{
    return widget->mapToGlobal(QPoint(0,widget->height()));
}

/*  return widget clicked point;*/

QPoint SuperCore::Widgetrightbottompoint(QWidget* widget)
{
    return widget->mapToGlobal(QPoint(widget->width(),widget->height()));
}

/*  return widget right bottom point;*/

void SuperCore::Openpath(QString path)
{
    QDesktopServices::openUrl(QUrl(Getfilepath(path), QUrl::TolerantMode));
}

/*  open folder;*/

void SuperCore::Deleteallitemsoflayout(QLayout *layout)
{
    QLayoutItem *child = nullptr;
    while ((child = layout->takeAt(0)) != nullptr)
    {
        if(child->widget())
        {
            child->widget()->setParent(nullptr);
            delete child;
        }
    }
}

/*  delete all item;*/
