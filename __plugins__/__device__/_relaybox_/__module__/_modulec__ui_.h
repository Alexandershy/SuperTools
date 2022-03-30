/********************************************************************************
** Form generated from reading UI file '_modulec_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _MODULEC__UI__H
#define _MODULEC__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModuleC
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *ModuleC)
    {
        if (ModuleC->objectName().isEmpty())
            ModuleC->setObjectName(QString::fromUtf8("ModuleC"));
        ModuleC->resize(354, 300);
        verticalLayout = new QVBoxLayout(ModuleC);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(ModuleC);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 354, 300));
        verticalLayout_10 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(5);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));

        verticalLayout_10->addLayout(verticalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 9);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(ModuleC);

        QMetaObject::connectSlotsByName(ModuleC);
    } // setupUi

    void retranslateUi(QFrame *ModuleC)
    {
        ModuleC->setWindowTitle(QCoreApplication::translate("ModuleC", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleC: public Ui_ModuleC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEC__UI__H
