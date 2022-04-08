/********************************************************************************
** Form generated from reading UI file '_modulea_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _MODULEA__UI__H
#define _MODULEA__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModuleA
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox_4;
    QComboBox *comboBox_31;
    QPushButton *pushButton_51;
    QPushButton *pushButton_54;
    QPushButton *pushButton_56;
    QPushButton *pushButton_55;

    void setupUi(QFrame *ModuleA)
    {
        if (ModuleA->objectName().isEmpty())
            ModuleA->setObjectName(QString::fromUtf8("ModuleA"));
        ModuleA->resize(270, 118);
        gridLayout = new QGridLayout(ModuleA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_4 = new QComboBox(ModuleA);
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_4->sizePolicy().hasHeightForWidth());
        comboBox_4->setSizePolicy(sizePolicy);
        comboBox_4->setMinimumSize(QSize(100, 25));
        comboBox_4->setMaximumSize(QSize(1080, 25));

        gridLayout->addWidget(comboBox_4, 0, 0, 1, 2);

        comboBox_31 = new QComboBox(ModuleA);
        comboBox_31->addItem(QString());
        comboBox_31->setObjectName(QString::fromUtf8("comboBox_31"));
        comboBox_31->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_31->sizePolicy().hasHeightForWidth());
        comboBox_31->setSizePolicy(sizePolicy);
        comboBox_31->setMinimumSize(QSize(100, 25));
        comboBox_31->setMaximumSize(QSize(16777215, 25));
        comboBox_31->setEditable(true);

        gridLayout->addWidget(comboBox_31, 1, 0, 1, 2);

        pushButton_51 = new QPushButton(ModuleA);
        pushButton_51->setObjectName(QString::fromUtf8("pushButton_51"));
        sizePolicy.setHeightForWidth(pushButton_51->sizePolicy().hasHeightForWidth());
        pushButton_51->setSizePolicy(sizePolicy);
        pushButton_51->setMinimumSize(QSize(80, 25));
        pushButton_51->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_51, 2, 0, 1, 1);

        pushButton_54 = new QPushButton(ModuleA);
        pushButton_54->setObjectName(QString::fromUtf8("pushButton_54"));
        pushButton_54->setEnabled(false);
        pushButton_54->setMinimumSize(QSize(80, 25));
        pushButton_54->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_54, 2, 1, 1, 1);

        pushButton_56 = new QPushButton(ModuleA);
        pushButton_56->setObjectName(QString::fromUtf8("pushButton_56"));
        sizePolicy.setHeightForWidth(pushButton_56->sizePolicy().hasHeightForWidth());
        pushButton_56->setSizePolicy(sizePolicy);
        pushButton_56->setMinimumSize(QSize(80, 25));
        pushButton_56->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_56, 3, 0, 1, 1);

        pushButton_55 = new QPushButton(ModuleA);
        pushButton_55->setObjectName(QString::fromUtf8("pushButton_55"));
        pushButton_55->setEnabled(false);
        pushButton_55->setMinimumSize(QSize(80, 25));
        pushButton_55->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_55, 3, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);

        retranslateUi(ModuleA);

        QMetaObject::connectSlotsByName(ModuleA);
    } // setupUi

    void retranslateUi(QFrame *ModuleA)
    {
        ModuleA->setWindowTitle(QCoreApplication::translate("ModuleA", "Frame", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("ModuleA", "select serial port name", nullptr));

        comboBox_31->setItemText(0, QCoreApplication::translate("ModuleA", "1000000", nullptr));

        pushButton_51->setText(QCoreApplication::translate("ModuleA", "Get Gemini Port", nullptr));
        pushButton_54->setText(QCoreApplication::translate("ModuleA", "Connect Gemini Port", nullptr));
        pushButton_56->setText(QCoreApplication::translate("ModuleA", "Scan Gemini Port", nullptr));
        pushButton_55->setText(QCoreApplication::translate("ModuleA", "Disconnect Gemini Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleA: public Ui_ModuleA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEA__UI__H
