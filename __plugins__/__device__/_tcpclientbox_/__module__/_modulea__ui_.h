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
    QCheckBox *checkBox_1;
    QComboBox *comboBox;
    QCheckBox *checkBox_2;
    QComboBox *comboBox_2;
    QCheckBox *checkBox_4;
    QPushButton *pushButton_38;
    QPushButton *pushButton_37;
    QCheckBox *checkBox_3;
    QPushButton *pushButton;

    void setupUi(QFrame *ModuleA)
    {
        if (ModuleA->objectName().isEmpty())
            ModuleA->setObjectName(QString::fromUtf8("ModuleA"));
        ModuleA->resize(261, 180);
        gridLayout = new QGridLayout(ModuleA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_1 = new QCheckBox(ModuleA);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox_1->sizePolicy().hasHeightForWidth());
        checkBox_1->setSizePolicy(sizePolicy);
        checkBox_1->setMinimumSize(QSize(25, 25));
        checkBox_1->setMaximumSize(QSize(300, 25));
        checkBox_1->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_1, 4, 3, 1, 1);

        comboBox = new QComboBox(ModuleA);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        comboBox->setMinimumSize(QSize(80, 25));
        comboBox->setMaximumSize(QSize(500, 25));
        comboBox->setEditable(true);

        gridLayout->addWidget(comboBox, 0, 0, 1, 4);

        checkBox_2 = new QCheckBox(ModuleA);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);
        checkBox_2->setMinimumSize(QSize(25, 25));
        checkBox_2->setMaximumSize(QSize(300, 25));
        checkBox_2->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_2, 5, 3, 1, 1);

        comboBox_2 = new QComboBox(ModuleA);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setMinimumSize(QSize(80, 25));
        comboBox_2->setMaximumSize(QSize(500, 25));
        comboBox_2->setEditable(true);

        gridLayout->addWidget(comboBox_2, 1, 0, 1, 4);

        checkBox_4 = new QCheckBox(ModuleA);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_4->sizePolicy().hasHeightForWidth());
        checkBox_4->setSizePolicy(sizePolicy);
        checkBox_4->setMinimumSize(QSize(25, 25));
        checkBox_4->setMaximumSize(QSize(300, 25));
        checkBox_4->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_4, 5, 2, 1, 1);

        pushButton_38 = new QPushButton(ModuleA);
        pushButton_38->setObjectName(QString::fromUtf8("pushButton_38"));
        pushButton_38->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_38->sizePolicy().hasHeightForWidth());
        pushButton_38->setSizePolicy(sizePolicy);
        pushButton_38->setMinimumSize(QSize(80, 25));
        pushButton_38->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_38, 3, 2, 1, 2);

        pushButton_37 = new QPushButton(ModuleA);
        pushButton_37->setObjectName(QString::fromUtf8("pushButton_37"));
        pushButton_37->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_37->sizePolicy().hasHeightForWidth());
        pushButton_37->setSizePolicy(sizePolicy);
        pushButton_37->setMinimumSize(QSize(80, 25));
        pushButton_37->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_37, 2, 2, 1, 2);

        checkBox_3 = new QCheckBox(ModuleA);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);
        checkBox_3->setMinimumSize(QSize(25, 25));
        checkBox_3->setMaximumSize(QSize(300, 25));
        checkBox_3->setLayoutDirection(Qt::RightToLeft);
        checkBox_3->setChecked(true);

        gridLayout->addWidget(checkBox_3, 4, 2, 1, 1);

        pushButton = new QPushButton(ModuleA);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(80, 25));
        pushButton->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton, 2, 0, 1, 2);

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
        checkBox_1->setText(QCoreApplication::translate("ModuleA", "Add \\ r:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ModuleA", "select or input server ip address", nullptr));

        checkBox_2->setText(QCoreApplication::translate("ModuleA", "Add \\ n:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("ModuleA", "select or input server listen port", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("ModuleA", "6666", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("ModuleA", "8888", nullptr));

        checkBox_4->setText(QCoreApplication::translate("ModuleA", "Hex:", nullptr));
        pushButton_38->setText(QCoreApplication::translate("ModuleA", "Disconnect Server", nullptr));
        pushButton_37->setText(QCoreApplication::translate("ModuleA", "Connect Server", nullptr));
        checkBox_3->setText(QCoreApplication::translate("ModuleA", "String:", nullptr));
        pushButton->setText(QCoreApplication::translate("ModuleA", "Get Local Ipaddress", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleA: public Ui_ModuleA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEA__UI__H
