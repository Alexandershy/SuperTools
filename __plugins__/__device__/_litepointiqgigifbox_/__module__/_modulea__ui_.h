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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModuleA
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QComboBox *comboBox;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_29;
    QCheckBox *checkBox_27;
    QLineEdit *lineEdit;

    void setupUi(QFrame *ModuleA)
    {
        if (ModuleA->objectName().isEmpty())
            ModuleA->setObjectName(QString::fromUtf8("ModuleA"));
        ModuleA->resize(253, 144);
        gridLayout = new QGridLayout(ModuleA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(ModuleA);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(0, 25));
        pushButton_2->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 2);

        pushButton_8 = new QPushButton(ModuleA);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setMinimumSize(QSize(0, 25));
        pushButton_8->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 2);

        pushButton_3 = new QPushButton(ModuleA);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(25, 25));
        pushButton_3->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton = new QPushButton(ModuleA);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setMinimumSize(QSize(25, 25));
        pushButton->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        pushButton_4 = new QPushButton(ModuleA);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(25, 25));
        pushButton_4->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_4, 2, 2, 1, 1);

        pushButton_5 = new QPushButton(ModuleA);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setMinimumSize(QSize(25, 25));
        pushButton_5->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_5, 2, 3, 1, 1);

        pushButton_7 = new QPushButton(ModuleA);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setMinimumSize(QSize(25, 25));
        pushButton_7->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_6 = new QPushButton(ModuleA);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setMinimumSize(QSize(25, 25));
        pushButton_6->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_6, 3, 1, 1, 1);

        comboBox = new QComboBox(ModuleA);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(0, 25));
        comboBox->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(comboBox, 3, 2, 1, 2);

        lineEdit_3 = new QLineEdit(ModuleA);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setMinimumSize(QSize(100, 25));
        lineEdit_3->setMaximumSize(QSize(800, 25));

        gridLayout->addWidget(lineEdit_3, 4, 0, 1, 2);

        checkBox_29 = new QCheckBox(ModuleA);
        checkBox_29->setObjectName(QString::fromUtf8("checkBox_29"));
        checkBox_29->setEnabled(false);
        checkBox_29->setMinimumSize(QSize(55, 15));
        checkBox_29->setMaximumSize(QSize(300, 25));
        checkBox_29->setLayoutDirection(Qt::RightToLeft);
        checkBox_29->setChecked(true);

        gridLayout->addWidget(checkBox_29, 4, 2, 1, 1);

        checkBox_27 = new QCheckBox(ModuleA);
        checkBox_27->setObjectName(QString::fromUtf8("checkBox_27"));
        checkBox_27->setEnabled(false);
        checkBox_27->setMinimumSize(QSize(55, 15));
        checkBox_27->setMaximumSize(QSize(300, 25));
        checkBox_27->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_27, 4, 3, 1, 1);

        lineEdit = new QLineEdit(ModuleA);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

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
        pushButton_2->setText(QCoreApplication::translate("ModuleA", "Connect Litepoint", nullptr));
        pushButton_8->setText(QCoreApplication::translate("ModuleA", "Disconnect Litepoint", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ModuleA", "Tech", nullptr));
        pushButton->setText(QCoreApplication::translate("ModuleA", "Pathloss", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ModuleA", "Info", nullptr));
        pushButton_5->setText(QCoreApplication::translate("ModuleA", "VSA/G", nullptr));
        pushButton_7->setText(QCoreApplication::translate("ModuleA", "Generate", nullptr));
        pushButton_6->setText(QCoreApplication::translate("ModuleA", "Analysis", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ModuleA", "CHAN1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ModuleA", "CHAN2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ModuleA", "CHAN3", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("ModuleA", "CHAN4", nullptr));

        lineEdit_3->setPlaceholderText(QCoreApplication::translate("ModuleA", "waiting for command ...", nullptr));
        checkBox_29->setText(QCoreApplication::translate("ModuleA", "String:", nullptr));
        checkBox_27->setText(QCoreApplication::translate("ModuleA", "Option:", nullptr));
        lineEdit->setText(QCoreApplication::translate("ModuleA", "192.168.100.254", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("ModuleA", "here for input litepoint ipaddress...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleA: public Ui_ModuleA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEA__UI__H
