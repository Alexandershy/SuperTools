/********************************************************************************
** Form generated from reading UI file '_supernotebox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERNOTEBOX__UI__H
#define _SUPERNOTEBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SuperNoteBox
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QFrame *SuperNoteBox)
    {
        if (SuperNoteBox->objectName().isEmpty())
            SuperNoteBox->setObjectName(QString::fromUtf8("SuperNoteBox"));
        SuperNoteBox->resize(200, 50);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SuperNoteBox->sizePolicy().hasHeightForWidth());
        SuperNoteBox->setSizePolicy(sizePolicy);
        SuperNoteBox->setMinimumSize(QSize(200, 50));
        SuperNoteBox->setStyleSheet(QString::fromUtf8(""));
        SuperNoteBox->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(SuperNoteBox);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        textBrowser = new QTextBrowser(SuperNoteBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(10, 10));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(SuperNoteBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(60, 25));
        pushButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(SuperNoteBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(60, 25));
        pushButton_2->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 99);
        verticalLayout->setStretch(1, 1);

        retranslateUi(SuperNoteBox);

        QMetaObject::connectSlotsByName(SuperNoteBox);
    } // setupUi

    void retranslateUi(QFrame *SuperNoteBox)
    {
        SuperNoteBox->setWindowTitle(QCoreApplication::translate("SuperNoteBox", "Frame", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("SuperNoteBox", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("SuperNoteBox", "Cancel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SuperNoteBox", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuperNoteBox: public Ui_SuperNoteBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERNOTEBOX__UI__H
