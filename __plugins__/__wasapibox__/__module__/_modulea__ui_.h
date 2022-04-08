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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ModuleA
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox_25;
    QComboBox *comboBox_24;
    QLineEdit *lineEdit_40;
    QLineEdit *lineEdit_41;
    QPushButton *pushButton_95;
    QPushButton *pushButton;

    void setupUi(QFrame *ModuleA)
    {
        if (ModuleA->objectName().isEmpty())
            ModuleA->setObjectName(QString::fromUtf8("ModuleA"));
        ModuleA->resize(258, 89);
        gridLayout = new QGridLayout(ModuleA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox_25 = new QComboBox(ModuleA);
        comboBox_25->addItem(QString());
        comboBox_25->setObjectName(QString::fromUtf8("comboBox_25"));
        comboBox_25->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_25->sizePolicy().hasHeightForWidth());
        comboBox_25->setSizePolicy(sizePolicy);
        comboBox_25->setMinimumSize(QSize(100, 25));
        comboBox_25->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(comboBox_25, 1, 0, 1, 1);

        comboBox_24 = new QComboBox(ModuleA);
        comboBox_24->addItem(QString());
        comboBox_24->setObjectName(QString::fromUtf8("comboBox_24"));
        comboBox_24->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_24->sizePolicy().hasHeightForWidth());
        comboBox_24->setSizePolicy(sizePolicy);
        comboBox_24->setMinimumSize(QSize(100, 25));
        comboBox_24->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(comboBox_24, 0, 0, 1, 1);

        lineEdit_40 = new QLineEdit(ModuleA);
        lineEdit_40->setObjectName(QString::fromUtf8("lineEdit_40"));
        lineEdit_40->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_40->sizePolicy().hasHeightForWidth());
        lineEdit_40->setSizePolicy(sizePolicy);
        lineEdit_40->setMinimumSize(QSize(25, 25));
        lineEdit_40->setMaximumSize(QSize(25, 25));
        lineEdit_40->setAlignment(Qt::AlignCenter);
        lineEdit_40->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_40, 0, 1, 1, 1);

        lineEdit_41 = new QLineEdit(ModuleA);
        lineEdit_41->setObjectName(QString::fromUtf8("lineEdit_41"));
        lineEdit_41->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_41->sizePolicy().hasHeightForWidth());
        lineEdit_41->setSizePolicy(sizePolicy);
        lineEdit_41->setMinimumSize(QSize(25, 25));
        lineEdit_41->setMaximumSize(QSize(25, 25));
        lineEdit_41->setAlignment(Qt::AlignCenter);
        lineEdit_41->setReadOnly(true);

        gridLayout_2->addWidget(lineEdit_41, 1, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setColumnStretch(0, 99);
        gridLayout_2->setColumnStretch(1, 1);

        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 2);

        pushButton_95 = new QPushButton(ModuleA);
        pushButton_95->setObjectName(QString::fromUtf8("pushButton_95"));
        pushButton_95->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_95->sizePolicy().hasHeightForWidth());
        pushButton_95->setSizePolicy(sizePolicy);
        pushButton_95->setMinimumSize(QSize(80, 25));
        pushButton_95->setMaximumSize(QSize(16777215, 25));
        pushButton_95->setFlat(false);

        gridLayout->addWidget(pushButton_95, 1, 0, 1, 1);

        pushButton = new QPushButton(ModuleA);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(80, 25));
        pushButton->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);


        retranslateUi(ModuleA);

        QMetaObject::connectSlotsByName(ModuleA);
    } // setupUi

    void retranslateUi(QFrame *ModuleA)
    {
        ModuleA->setWindowTitle(QCoreApplication::translate("ModuleA", "Frame", nullptr));
        comboBox_25->setItemText(0, QCoreApplication::translate("ModuleA", "select input audio device endpoint", nullptr));

        comboBox_24->setItemText(0, QCoreApplication::translate("ModuleA", "select output audio device endpoint", nullptr));

        lineEdit_40->setText(QString());
        lineEdit_40->setPlaceholderText(QCoreApplication::translate("ModuleA", "ID", nullptr));
        lineEdit_41->setText(QString());
        lineEdit_41->setPlaceholderText(QCoreApplication::translate("ModuleA", "ID", nullptr));
        pushButton_95->setText(QCoreApplication::translate("ModuleA", "Refresh Audio Devices", nullptr));
        pushButton->setText(QCoreApplication::translate("ModuleA", "Format Config", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleA: public Ui_ModuleA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEA__UI__H
