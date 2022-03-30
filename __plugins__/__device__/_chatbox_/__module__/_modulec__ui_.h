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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModuleC
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *ModuleC)
    {
        if (ModuleC->objectName().isEmpty())
            ModuleC->setObjectName(QString::fromUtf8("ModuleC"));
        ModuleC->resize(292, 300);
        gridLayout = new QGridLayout(ModuleC);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_2 = new QLineEdit(ModuleC);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(80, 25));
        lineEdit_2->setMaximumSize(QSize(16777215, 25));
        lineEdit_2->setFrame(true);
        lineEdit_2->setReadOnly(true);

        gridLayout->addWidget(lineEdit_2, 0, 0, 1, 1);

        comboBox = new QComboBox(ModuleC);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(80, 25));
        comboBox->setMaximumSize(QSize(16777215, 25));
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setEditable(true);
        comboBox->setMaxCount(10);
        comboBox->setInsertPolicy(QComboBox::InsertAtTop);
        comboBox->setFrame(true);

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        scrollArea = new QScrollArea(ModuleC);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 292, 275));
        verticalLayout_10 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(20);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));

        verticalLayout_10->addLayout(verticalLayout_9);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 9);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 2);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        retranslateUi(ModuleC);

        QMetaObject::connectSlotsByName(ModuleC);
    } // setupUi

    void retranslateUi(QFrame *ModuleC)
    {
        ModuleC->setWindowTitle(QCoreApplication::translate("ModuleC", "Frame", nullptr));
        lineEdit_2->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("ModuleC", "no new message...", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ModuleC: public Ui_ModuleC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEC__UI__H
