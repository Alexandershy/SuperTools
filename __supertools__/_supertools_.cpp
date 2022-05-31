/*
 *  using lib;
 *
 *      c/c++ qt library;
 *      http://www.fftw.org/;
 *      http://www.mpg123.de/;
 *      https://github.com/xiph/flac;
 *      https://github.com/gcp/libogg;
 *      https://monkeysaudio.com/;
 *      https://www.qcustomplot.com/index.php;
 *
 *  supertools rules;
 *
 *      class parameter,first word upper ,other word lower, and do not use "_",such as "QString Stra";
 *      function parameter,all word lower, do not use "_",such as "function(QString stra)";
 *      class and function parameter name,use class name abbreviation and function,if no function,replace with "a","b","c",such as "QString strpath" or "QString stra";
 *      groupbox design,add readmeinit function,creat ./__readme__/__xml__/ *.pdf file as import way;
 *      *.pdf name set "_" first and "_" end, such as "_serialport_.pdf";
 *      *.h file interface class name set as "Interface" and function name set as "Loadplugin";
 *      *.dll file all in folder "./__plugins__/__device__/";
 *
 *  version format,exp <V6.22.0201.S019.A102>;
 *
 *      <V6>    qt version greater than 6.00;
 *      <22>    year 2022,replace "2022" with "22";
 *      <0201>  month 02,day 01;
 *      <S019>  superdll 019th compile out;
 *      <A102>  superapi 102nd update;
 */

#include "__superframe__/_superframe_.h"
#include <QTextCodec>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSharedMemory sharedmemory("SuperTools");
    QDir::setCurrent(app.applicationDirPath());
    if(sharedmemory.attach())
    {
        SuperRepeat *repeat = new SuperRepeat(nullptr);
        repeat->Init();
    }
    else if(sharedmemory.create(1))
    {
        app.setApplicationVersion("V6.22.0531.S058.A130");
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
        SuperFrame *frame = new SuperFrame(nullptr);
        frame->show();
    }
    return app.exec();
}
