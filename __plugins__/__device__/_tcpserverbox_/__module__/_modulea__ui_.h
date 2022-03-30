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
    QComboBox *comboBox_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;

    void setupUi(QFrame *ModuleA)
    {
        if (ModuleA->objectName().isEmpty())
            ModuleA->setObjectName(QString::fromUtf8("ModuleA"));
        ModuleA->resize(235, 149);
        gridLayout = new QGridLayout(ModuleA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_2 = new QComboBox(ModuleA);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setMinimumSize(QSize(0, 25));
        comboBox_2->setMaximumSize(QSize(16777215, 25));
        comboBox_2->setEditable(true);

        gridLayout->addWidget(comboBox_2, 1, 0, 1, 4);

        pushButton_3 = new QPushButton(ModuleA);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(50, 25));
        pushButton_3->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 2);

        comboBox = new QComboBox(ModuleA);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(0, 25));
        comboBox->setMaximumSize(QSize(16777215, 25));
        comboBox->setEditable(true);

        gridLayout->addWidget(comboBox, 0, 0, 1, 4);

        pushButton_4 = new QPushButton(ModuleA);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(50, 25));
        pushButton_4->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_4, 3, 2, 1, 2);

        checkBox_2 = new QCheckBox(ModuleA);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);
        checkBox_2->setMinimumSize(QSize(50, 25));
        checkBox_2->setMaximumSize(QSize(16777215, 25));
        checkBox_2->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_2, 4, 3, 1, 1);

        checkBox = new QCheckBox(ModuleA);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);
        checkBox->setMinimumSize(QSize(50, 25));
        checkBox->setMaximumSize(QSize(16777215, 25));
        checkBox->setLayoutDirection(Qt::RightToLeft);
        checkBox->setChecked(true);

        gridLayout->addWidget(checkBox, 4, 2, 1, 1);

        pushButton_2 = new QPushButton(ModuleA);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(50, 25));
        pushButton_2->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 2);

        lineEdit_2 = new QLineEdit(ModuleA);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(50, 25));
        lineEdit_2->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(lineEdit_2, 3, 0, 1, 2);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);

        retranslateUi(ModuleA);

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModuleA);
    } // setupUi

    void retranslateUi(QFrame *ModuleA)
    {
        ModuleA->setWindowTitle(QCoreApplication::translate("ModuleA", "Frame", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("ModuleA", "select or input server listen port", nullptr));

        pushButton_3->setText(QCoreApplication::translate("ModuleA", "Start Tcpserver", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ModuleA", "select or input server ip address", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("ModuleA", "select or input server ip address", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ModuleA", "Close Tcpserver", nullptr));
        checkBox_2->setText(QCoreApplication::translate("ModuleA", "Option", nullptr));
        checkBox->setText(QCoreApplication::translate("ModuleA", "String", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ModuleA", "Get Local Ipaddress", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("ModuleA", "waiting for command ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleA: public Ui_ModuleA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEA__UI__H
