/********************************************************************************
** Form generated from reading UI file '_moduleb_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _MODULEB__UI__H
#define _MODULEB__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModuleB
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_16;
    QPushButton *pushButton;

    void setupUi(QFrame *ModuleB)
    {
        if (ModuleB->objectName().isEmpty())
            ModuleB->setObjectName(QString::fromUtf8("ModuleB"));
        ModuleB->resize(280, 56);
        gridLayout = new QGridLayout(ModuleB);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_2 = new QComboBox(ModuleB);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setMinimumSize(QSize(80, 25));
        comboBox_2->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(comboBox_2, 0, 0, 1, 2);

        lineEdit_16 = new QLineEdit(ModuleB);
        lineEdit_16->setObjectName(QString::fromUtf8("lineEdit_16"));
        lineEdit_16->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_16->sizePolicy().hasHeightForWidth());
        lineEdit_16->setSizePolicy(sizePolicy);
        lineEdit_16->setMaximumSize(QSize(16777215, 25));
        lineEdit_16->setReadOnly(true);

        gridLayout->addWidget(lineEdit_16, 1, 0, 1, 1);

        pushButton = new QPushButton(ModuleB);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(25, 25));
        pushButton->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(ModuleB);

        QMetaObject::connectSlotsByName(ModuleB);
    } // setupUi

    void retranslateUi(QFrame *ModuleB)
    {
        ModuleB->setWindowTitle(QCoreApplication::translate("ModuleB", "Frame", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("ModuleB", "select relay model", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("ModuleB", "gtk relay 15 channels ( aa 11 / aa 10)", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("ModuleB", "gtk relay 34 channels ( close001 / open001)", nullptr));

        pushButton->setText(QCoreApplication::translate("ModuleB", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleB: public Ui_ModuleB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEB__UI__H
