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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModuleA
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QPushButton *pushButton_36;
    QPushButton *pushButton_37;
    QPushButton *pushButton;
    QPushButton *pushButton_38;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_4;

    void setupUi(QFrame *ModuleA)
    {
        if (ModuleA->objectName().isEmpty())
            ModuleA->setObjectName(QString::fromUtf8("ModuleA"));
        ModuleA->resize(255, 180);
        gridLayout = new QGridLayout(ModuleA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_2 = new QComboBox(ModuleA);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setMinimumSize(QSize(100, 25));
        comboBox_2->setMaximumSize(QSize(1080, 25));

        gridLayout->addWidget(comboBox_2, 0, 0, 1, 4);

        comboBox_3 = new QComboBox(ModuleA);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy);
        comboBox_3->setMinimumSize(QSize(100, 25));
        comboBox_3->setMaximumSize(QSize(1080, 25));
        comboBox_3->setEditable(true);

        gridLayout->addWidget(comboBox_3, 1, 0, 1, 4);

        pushButton_36 = new QPushButton(ModuleA);
        pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));
        sizePolicy.setHeightForWidth(pushButton_36->sizePolicy().hasHeightForWidth());
        pushButton_36->setSizePolicy(sizePolicy);
        pushButton_36->setMinimumSize(QSize(80, 25));
        pushButton_36->setMaximumSize(QSize(500, 25));
        pushButton_36->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_36, 2, 0, 1, 2);

        pushButton_37 = new QPushButton(ModuleA);
        pushButton_37->setObjectName(QString::fromUtf8("pushButton_37"));
        pushButton_37->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_37->sizePolicy().hasHeightForWidth());
        pushButton_37->setSizePolicy(sizePolicy);
        pushButton_37->setMinimumSize(QSize(80, 25));
        pushButton_37->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_37, 2, 2, 1, 2);

        pushButton = new QPushButton(ModuleA);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(80, 25));
        pushButton->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton, 3, 0, 1, 2);

        pushButton_38 = new QPushButton(ModuleA);
        pushButton_38->setObjectName(QString::fromUtf8("pushButton_38"));
        pushButton_38->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_38->sizePolicy().hasHeightForWidth());
        pushButton_38->setSizePolicy(sizePolicy);
        pushButton_38->setMinimumSize(QSize(80, 25));
        pushButton_38->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_38, 3, 2, 1, 2);

        checkBox_1 = new QCheckBox(ModuleA);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_1->sizePolicy().hasHeightForWidth());
        checkBox_1->setSizePolicy(sizePolicy);
        checkBox_1->setMinimumSize(QSize(25, 25));
        checkBox_1->setMaximumSize(QSize(16777215, 25));
        checkBox_1->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_1, 4, 3, 1, 1);

        checkBox_3 = new QCheckBox(ModuleA);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);
        checkBox_3->setMinimumSize(QSize(25, 25));
        checkBox_3->setMaximumSize(QSize(16777215, 25));
        checkBox_3->setLayoutDirection(Qt::RightToLeft);
        checkBox_3->setChecked(true);

        gridLayout->addWidget(checkBox_3, 4, 2, 1, 1);

        checkBox_2 = new QCheckBox(ModuleA);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);
        checkBox_2->setMinimumSize(QSize(25, 25));
        checkBox_2->setMaximumSize(QSize(16777215, 25));
        checkBox_2->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_2, 5, 3, 1, 1);

        checkBox_4 = new QCheckBox(ModuleA);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_4->sizePolicy().hasHeightForWidth());
        checkBox_4->setSizePolicy(sizePolicy);
        checkBox_4->setMinimumSize(QSize(25, 25));
        checkBox_4->setMaximumSize(QSize(16777215, 25));
        checkBox_4->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_4, 5, 2, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);

        retranslateUi(ModuleA);

        QMetaObject::connectSlotsByName(ModuleA);
    } // setupUi

    void retranslateUi(QFrame *ModuleA)
    {
        ModuleA->setWindowTitle(QCoreApplication::translate("ModuleA", "Frame", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("ModuleA", "select serial port name", nullptr));

        comboBox_3->setItemText(0, QCoreApplication::translate("ModuleA", "select or input serial port baudrate", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("ModuleA", "9600", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("ModuleA", "19200", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("ModuleA", "38400", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("ModuleA", "57600", nullptr));
        comboBox_3->setItemText(5, QCoreApplication::translate("ModuleA", "115200", nullptr));
        comboBox_3->setItemText(6, QCoreApplication::translate("ModuleA", "1000000", nullptr));

        pushButton_36->setText(QCoreApplication::translate("ModuleA", "Get Serial Port", nullptr));
        pushButton_37->setText(QCoreApplication::translate("ModuleA", "Connect Serial Port", nullptr));
        pushButton->setText(QCoreApplication::translate("ModuleA", "Scan Serial Port", nullptr));
        pushButton_38->setText(QCoreApplication::translate("ModuleA", "Disconnect Serial Port", nullptr));
        checkBox_1->setText(QCoreApplication::translate("ModuleA", "Add \\ r:", nullptr));
        checkBox_3->setText(QCoreApplication::translate("ModuleA", "String:", nullptr));
        checkBox_2->setText(QCoreApplication::translate("ModuleA", "Add \\ n:", nullptr));
        checkBox_4->setText(QCoreApplication::translate("ModuleA", "Hex:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleA: public Ui_ModuleA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEA__UI__H
