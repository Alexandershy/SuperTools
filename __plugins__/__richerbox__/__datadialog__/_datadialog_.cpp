#include "_datadialog_.h"

DataDialog::DataDialog(QString richerfile)
{
    Richerfile = richerfile;
    setAttribute(Qt::WA_DeleteOnClose);
    Settitle(Richerfile);
    Init();
}

DataDialog::~DataDialog()
{

}

void DataDialog::keyPressEvent(QKeyEvent *event)
{
    if((event->modifiers() == Qt::ControlModifier))
    {
        switch(event->key())
        {
            case Qt::Key_S:
            {
                if(Plugin->ui->pushButton_5->isEnabled())
                {
                    Apply();
                }
                break;
            }
            case Qt::Key_G:
            {
                Getformat();
                break;
            }
            case Qt::Key_B:
            {
                Brushtext();
                break;
            }
            case Qt::Key_F:
            {
                Openfinddialog();
                break;
            }
        }
    }
}

/*  rich files editor's shortcut key;*/

void DataDialog::Init()
{
    Objectinit();
    Icoinit();
    Textinit();
    Timerinit();
}

void DataDialog::Objectinit()
{
    Plugin = new DataDialogui(this);
    Pluginlayout->addWidget(Plugin);
    connect(Plugin->ui->pushButton_5,   &QPushButton::clicked,              this,   &DataDialog::Apply);
    connect(Plugin->ui->textEdit_2,     &QTextEdit::textChanged,            this,   &DataDialog::Enableapply);
    connect(Plugin->ui->textEdit_2,     &QTextEdit::cursorPositionChanged,  this,   &DataDialog::Checkcharformat);
    connect(Plugin->ui->pushButton_9,   &QPushButton::clicked,              this,   &DataDialog::Families);
    connect(Plugin->ui->doubleSpinBox,  &QDoubleSpinBox::editingFinished,   this,   &DataDialog::Size);
    connect(Plugin->ui->pushButton,     &QPushButton::clicked,              this,   &DataDialog::Bold);
    connect(Plugin->ui->pushButton_2,   &QPushButton::clicked,              this,   &DataDialog::Italic);
    connect(Plugin->ui->pushButton_3,   &QPushButton::clicked,              this,   &DataDialog::Underline);
    connect(Plugin->ui->pushButton_8,   &QPushButton::clicked,              this,   &DataDialog::Opencolordialog);
    connect(Plugin->ui->pushButton_4,   &QPushButton::clicked,              this,   &DataDialog::Textleftalign);
    connect(Plugin->ui->pushButton_6,   &QPushButton::clicked,              this,   &DataDialog::Textrightalign);
    connect(Plugin->ui->pushButton_7,   &QPushButton::clicked,              this,   &DataDialog::Textcenteralign);
    connect(Plugin->ui->pushButton_11,  &QPushButton::clicked,              this,   &DataDialog::Textjustifyalign);
    connect(Plugin->ui->pushButton_12,  &QPushButton::clicked,              this,   &DataDialog::Getformat);
    connect(Plugin->ui->pushButton_13,  &QPushButton::clicked,              this,   &DataDialog::Brushtext);
    connect(Plugin->ui->pushButton_10,  &QPushButton::clicked,              this,   &DataDialog::Selectimage);
    connect(Plugin->ui->pushButton_14,  &QPushButton::clicked,              this,   &DataDialog::Printtopdf);
    connect(Plugin->ui->pushButton_15,  &QPushButton::clicked,              this,   &DataDialog::Openpath);
    connect(Plugin->ui->pushButton_16,  &QPushButton::clicked,              this,   &DataDialog::Openfinddialog);
}

/*  creat new object and connect its slots;*/

void DataDialog::Icoinit()
{
    Plugin->ui->pushButton_4->setIcon(QIcon(":/__supericon__/_left_.svg"));
    Plugin->ui->pushButton_6->setIcon(QIcon(":/__supericon__/_right_.svg"));
    Plugin->ui->pushButton_7->setIcon(QIcon(":/__supericon__/_center_.svg"));
    Plugin->ui->pushButton_11->setIcon(QIcon(":/__supericon__/_justify_.svg"));
    Plugin->ui->pushButton_8->setIcon(QIcon(":/__supericon__/_painter_.svg"));
    Plugin->ui->pushButton_12->setIcon(QIcon(":/__supericon__/_getformat_.svg"));
    Plugin->ui->pushButton_13->setIcon(QIcon(":/__supericon__/_brush_.svg"));
    Plugin->ui->pushButton_10->setIcon(QIcon(":/__supericon__/_insert_.svg"));
    Plugin->ui->pushButton_14->setIcon(QIcon(":/__supericon__/_print_.svg"));
    Plugin->ui->pushButton_15->setIcon(QIcon(":/__supericon__/_openpath_.svg"));
    Plugin->ui->pushButton_16->setIcon(QIcon(":/__supericon__/_find_.svg"));
}

/*  set icon;*/

void DataDialog::Textinit()
{
    QFileInfo fileinfo(Richerfile);
    Richerfilepath = fileinfo.absolutePath();
    Richerfilename = fileinfo.completeBaseName();
    QString filestring = Core->Readonlyfile(Richerfile);
    Plugin->ui->textEdit_2->setHtml(filestring);
    Plugin->ui->plainTextEdit->setPlainText(filestring);
}

/*  get and read rich file;*/

void DataDialog::Timerinit()
{
    Timer = new QTimer(this);
    Timer->setInterval(1000);
    connect(Timer,&QTimer::timeout,this,&DataDialog::Addprogressvalue);
    Timer->start();
}

/*  timer for save progress;*/

void DataDialog::Enableapply()
{
    if(!Plugin->ui->pushButton_5->isEnabled())
    {
        Plugin->ui->pushButton_5->setEnabled(true);
    }
}

/*  enable apply button when textchanged;*/

void DataDialog::Apply()
{
    QString filestring = Plugin->ui->textEdit_2->toHtml();
    Core->Writeonlyfile(Richerfile,filestring);
    Plugin->ui->plainTextEdit->setPlainText(filestring);
    Plugin->ui->pushButton_5->setEnabled(false);
    Savevalue = 0;
}

/*  save richer files,update source html and reset save progress;*/

void DataDialog::Checkcharformat()
{
    Fontformat.clear();
    QTextCharFormat editorformat = Plugin->ui->textEdit_2->currentCharFormat();
    Checkfamilies(&editorformat,&Fontformat);
    Checksize(&editorformat,&Fontformat);
    Checkbold(&editorformat,&Fontformat);
    Checkitalic(&editorformat,&Fontformat);
    Checkunderline(&editorformat,&Fontformat);
    Checkcolor(&Fontformat);
    Checkalign();
}

/*  check char format by cursor;*/

void DataDialog::Checkfamilies(QTextCharFormat *editorformat,QStringList *fontformat)
{
    QFont font = Plugin->ui->pushButton_9->font();
    if(!editorformat->font().families().isEmpty())
    {
        font.setFamilies(QStringList(editorformat->font().families().at(0)));
        fontformat->append(editorformat->font().families().at(0));
        Plugin->ui->pushButton_9->setFont(font);
    }
}

/*  check char format families;*/

void DataDialog::Families()
{
    Fontfamilies = Plugin->ui->pushButton_9->font().families();
    SuperFontDialog *fontdialog = new SuperFontDialog(nullptr,&Fontfamilies);
    connect(fontdialog,&SuperFontDialog::Signalfa,this,&DataDialog::Setfamilies);
    fontdialog->Show();
}

/*  open font families dialog;*/

void DataDialog::Setfamilies(QStringList fontfamilies)
{
    QTextCharFormat editorformat;
    QFont font = Plugin->ui->pushButton_9->font();
    font.setFamilies(fontfamilies);
    editorformat.setFontFamilies(fontfamilies);
    Plugin->ui->pushButton_9->setFont(font);
    Plugin->ui->textEdit_2->textCursor().mergeCharFormat(editorformat);
    Plugin->ui->textEdit_2->setFocus();
}

/*  set char format families;*/

void DataDialog::Checksize(QTextCharFormat *editorformat,QStringList *fontformat)
{
    Plugin->ui->doubleSpinBox->setValue(editorformat->font().pointSizeF());
    fontformat->append(QString::number(editorformat->font().pointSizeF()));
}

/*  check char format size;*/

void DataDialog::Size()
{
    QTextCharFormat editorformat;
    editorformat.setFontPointSize(Plugin->ui->doubleSpinBox->value());
    Plugin->ui->textEdit_2->textCursor().mergeCharFormat(editorformat);
}

/*  set char format size;*/

void DataDialog::Checkbold(QTextCharFormat *editorformat,QStringList *fontformat)
{
    QFont font = Plugin->ui->pushButton->font();
    font.setBold(editorformat->font().bold());
    fontformat->append(QString::number(editorformat->font().weight()));
    Plugin->ui->pushButton->setFont(font);
}

/*  check char format weight;*/

void DataDialog::Bold()
{
    QTextCharFormat editorformat;
    QFont font = Plugin->ui->pushButton->font();
    if(font.bold())
    {
        editorformat.setFontWeight(QFont::Normal);
        font.setBold(false);
    }
    else
    {
        editorformat.setFontWeight(QFont::Bold);
        font.setBold(true);
    }
    Plugin->ui->pushButton->setFont(font);
    Plugin->ui->textEdit_2->textCursor().mergeCharFormat(editorformat);
}

/*  set char format bold or not;*/

void DataDialog::Checkitalic(QTextCharFormat *editorformat,QStringList *fontformat)
{
    QFont font = Plugin->ui->pushButton_2->font();
    font.setItalic(editorformat->font().italic());
    fontformat->append(QString::number(editorformat->font().italic()));
    Plugin->ui->pushButton_2->setFont(font);
}

/*  check char format italic;*/

void DataDialog::Italic()
{
    QTextCharFormat editorformat;
    QFont font = Plugin->ui->pushButton_2->font();
    if(font.italic())
    {
        editorformat.setFontItalic(false);
        font.setItalic(false);
    }
    else
    {
        editorformat.setFontItalic(true);
        font.setItalic(true);
    }
    Plugin->ui->pushButton_2->setFont(font);
    Plugin->ui->textEdit_2->textCursor().mergeCharFormat(editorformat);
}

/*  set char format italic or not;*/

void DataDialog::Checkunderline(QTextCharFormat *editorformat,QStringList *fontformat)
{
    QFont font = Plugin->ui->pushButton_3->font();
    font.setUnderline(editorformat->font().underline());
    fontformat->append(QString::number(editorformat->font().underline()));
    Plugin->ui->pushButton_3->setFont(font);
}

/*  set char format underline;*/

void DataDialog::Underline()
{
    QTextCharFormat editorformat;
    QFont font = Plugin->ui->pushButton_3->font();
    if(font.underline())
    {
        editorformat.setFontUnderline(false);
        font.setUnderline(false);
    }
    else
    {
        editorformat.setFontUnderline(true);
        font.setUnderline(true);
    }
    Plugin->ui->pushButton_3->setFont(font);
    Plugin->ui->textEdit_2->textCursor().mergeCharFormat(editorformat);
}

/*  set char format underline or not;*/

void DataDialog::Checkcolor(QStringList *fontformat)
{
    QColor color(Plugin->ui->textEdit_2->textColor());
    fontformat->append(Core->Rgbcolor(&color));
    Plugin->ui->label_2->setPalette(color);
}

/*  check char format color;*/

void DataDialog::Opencolordialog()
{
    SuperColorDialog *colordialog = new SuperColorDialog(nullptr,Plugin->ui->textEdit_2->textColor());
    connect(colordialog,&SuperColorDialog::Signalsa,this,       &DataDialog::Setcolor);
    connect(colordialog,&SuperColorDialog::Signalsa,colordialog,&QObject::deleteLater);
    colordialog->Show();
}

/*  open color dialog and select color;*/

void DataDialog::Setcolor(QColor color)
{
    Plugin->ui->label_2->setPalette(color);
    Plugin->ui->textEdit_2->setTextColor(color);
    Plugin->ui->textEdit_2->setFocus();
}

/*  set color;*/

void DataDialog::Checkalign()
{
    switch (Plugin->ui->textEdit_2->alignment())
    {
        case Qt::AlignLeft:
        {
            Textalignapi(false,true,true,true);
            break;
        }
        case Qt::AlignRight:
        {
            Textalignapi(true,false,true,true);
            break;
        }
        case Qt::AlignHCenter:
        {
            Textalignapi(true,true,false,true);
            break;
        }
        case Qt::AlignJustify:
        {
            Textalignapi(true,true,true,false);
            break;
        }
    }
}

/*  check current row's align;*/

void DataDialog::Textalignapi(bool boola,bool boolb,bool boolc,bool boold)
{
    Plugin->ui->pushButton_4->setEnabled(boola);
    Plugin->ui->pushButton_6->setEnabled(boolb);
    Plugin->ui->pushButton_7->setEnabled(boolc);
    Plugin->ui->pushButton_11->setEnabled(boold);
}

/*  enable align button api;*/

void DataDialog::Textleftalign()
{
    Textalignapi(false,true,true,true);
    Plugin->ui->textEdit_2->setAlignment(Qt::AlignLeft);
}

/*  set current row's left align;*/

void DataDialog::Textrightalign()
{
    Textalignapi(true,false,true,true);
    Plugin->ui->textEdit_2->setAlignment(Qt::AlignRight);
}

/*  set current row's right align;*/

void DataDialog::Textcenteralign()
{
    Textalignapi(true,true,false,true);
    Plugin->ui->textEdit_2->setAlignment(Qt::AlignHCenter);
}

/*  set current row's center align;*/

void DataDialog::Textjustifyalign()
{
    Textalignapi(true,true,true,false);
    Plugin->ui->textEdit_2->setAlignment(Qt::AlignJustify);
}

/*  set current row's justify align;*/

void DataDialog::Addprogressvalue()
{
    Savevalue = Savevalue + 1;
    Plugin->ui->progressBar->setValue(Savevalue);
    if(Savevalue == 100)
    {
        Apply();
    }
}

/*  timer timeout slot,add progress value;*/

void DataDialog::Getformat()
{
    QString fontinfo;
    for(int i = 0;i < Fontformat.count();i++)
    {
        fontinfo.append(Fontformat.at(i));
        if(i < Fontformat.count() - 1)
        {
            fontinfo.append(",");
        }
    }
    Plugin->ui->label->setText(fontinfo);
    Plugin->ui->textEdit_2->setFocus();
}

/*  get current char's format;*/

void DataDialog::Brushtext()
{
    QTextCharFormat editorformat;
    QStringList fontformat = Plugin->ui->label->text().split(",");
    QColor color(fontformat.at(5).toInt(),fontformat.at(6).toInt(),fontformat.at(7).toInt());
    editorformat.setFontFamilies(QStringList(fontformat.at(0)));
    editorformat.setFontPointSize(fontformat.at(1).toDouble());
    editorformat.setFontWeight(fontformat.at(2).toDouble());
    editorformat.setFontItalic(fontformat.at(3).toInt());
    editorformat.setFontUnderline(fontformat.at(4).toInt());
    Plugin->ui->textEdit_2->setTextColor(color);
    Plugin->ui->textEdit_2->textCursor().mergeCharFormat(editorformat);
}

/*  use current font format brush height light text;*/

void DataDialog::Selectimage()
{
    SuperFileDialog *filedialog = new SuperFileDialog(nullptr,"./__htmllibary__/",{"*.png"});
    connect(filedialog,&SuperFileDialog::Signalfb,this,         &DataDialog::Insertimage);
    connect(filedialog,&SuperFileDialog::Signalfb,filedialog,   &QObject::deleteLater);
    filedialog->Setsinglefile();
    filedialog->Show();
}

/*  select image file;*/

void DataDialog::Insertimage(QString file)
{
    QString newfile;
    if(!file.isEmpty())
    {
        if(file.contains("__htmllibary__") && file.contains("_.png"))
        {
            QFileInfo fileinfo(file);
            newfile = "__htmllibary__/" + fileinfo.completeBaseName();
        }
        else
        {
            Core->Creatfolder("./__htmllibary__");
            QString time = QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz");
            newfile = "__htmllibary__/_" + time + "_.png";
            QFile::copy(file,newfile);
        }
        QUrl url(newfile);
        QImage image = QImageReader(newfile).read();
        QTextCursor cursor = Plugin->ui->textEdit_2->textCursor();
        QTextImageFormat imageFormat;
        Plugin->ui->textEdit_2->document()->addResource(QTextDocument::ImageResource,url,QVariant(image));
        imageFormat.setWidth(image.width());
        imageFormat.setHeight(image.height());
        imageFormat.setName(newfile);
        cursor.insertImage(imageFormat);
    }
}

/*  insert picture to textedit and save a copy to local folder;*/

void DataDialog::Printtopdf()
{
    Apply();
    QTextDocument text_document;
    QFile file(Richerfilepath + "/" + Richerfilename + ".pdf");
    QPdfWriter pdfwriter(&file);
    file.open(QIODevice::WriteOnly);
    pdfwriter.setPageSize(QPageSize(QPageSize::A3));
    pdfwriter.setResolution(QPrinter::ScreenResolution);
    pdfwriter.setPageMargins(QMarginsF(0, 0, 0, 0));
    text_document.setHtml(Plugin->ui->plainTextEdit->toPlainText());
    text_document.print(&pdfwriter);
    text_document.end();
    file.close();
}

/*  print as pdf to current directory;*/

void DataDialog::Openpath()
{
    Core->Openpath(Richerfilepath);
}

/*  open local folder;*/

void DataDialog::Openfinddialog()
{
    SuperFindDialog *finddialog = new SuperFindDialog(nullptr,Plugin->ui->textEdit_2);
    finddialog->Show();
}

/*  open find text dialog;*/
