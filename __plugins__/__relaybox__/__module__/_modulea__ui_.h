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
    QComboBox *comboBox_1;
    QComboBox *comboBox;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QPushButton *pushButton_45;
    QPushButton *pushButton_33;
    QPushButton *pushButton_35;
    QPushButton *pushButton_57;
    QPushButton *pushButton_44;
    QPushButton *pushButton_34;
    QCheckBox *checkBox_29;
    QCheckBox *checkBox_27;
    QLineEdit *lineEdit;

    void setupUi(QFrame *ModuleA)
    {
        if (ModuleA->objectName().isEmpty())
            ModuleA->setObjectName(QString::fromUtf8("ModuleA"));
        ModuleA->resize(276, 211);
        gridLayout = new QGridLayout(ModuleA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_1 = new QComboBox(ModuleA);
        comboBox_1->addItem(QString());
        comboBox_1->setObjectName(QString::fromUtf8("comboBox_1"));
        comboBox_1->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_1->sizePolicy().hasHeightForWidth());
        comboBox_1->setSizePolicy(sizePolicy);
        comboBox_1->setMinimumSize(QSize(100, 25));
        comboBox_1->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(comboBox_1, 0, 0, 1, 4);

        comboBox = new QComboBox(ModuleA);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(100, 25));
        comboBox->setMaximumSize(QSize(16777215, 25));
        comboBox->setEditable(true);

        gridLayout->addWidget(comboBox, 1, 0, 1, 4);

        pushButton_31 = new QPushButton(ModuleA);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
        pushButton_31->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_31->sizePolicy().hasHeightForWidth());
        pushButton_31->setSizePolicy(sizePolicy);
        pushButton_31->setMinimumSize(QSize(50, 25));
        pushButton_31->setMaximumSize(QSize(16777215, 25));
        pushButton_31->setCheckable(false);

        gridLayout->addWidget(pushButton_31, 2, 2, 1, 2);

        pushButton_32 = new QPushButton(ModuleA);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        pushButton_32->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_32->sizePolicy().hasHeightForWidth());
        pushButton_32->setSizePolicy(sizePolicy);
        pushButton_32->setMinimumSize(QSize(50, 25));
        pushButton_32->setMaximumSize(QSize(16777215, 25));
        pushButton_32->setCheckable(false);

        gridLayout->addWidget(pushButton_32, 3, 2, 1, 2);

        pushButton_45 = new QPushButton(ModuleA);
        pushButton_45->setObjectName(QString::fromUtf8("pushButton_45"));
        pushButton_45->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_45->sizePolicy().hasHeightForWidth());
        pushButton_45->setSizePolicy(sizePolicy);
        pushButton_45->setMinimumSize(QSize(50, 25));
        pushButton_45->setMaximumSize(QSize(16777215, 25));
        pushButton_45->setCheckable(false);

        gridLayout->addWidget(pushButton_45, 4, 2, 1, 2);

        pushButton_33 = new QPushButton(ModuleA);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
        pushButton_33->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_33->sizePolicy().hasHeightForWidth());
        pushButton_33->setSizePolicy(sizePolicy);
        pushButton_33->setMinimumSize(QSize(50, 25));
        pushButton_33->setMaximumSize(QSize(16777215, 25));
        pushButton_33->setCheckable(false);

        gridLayout->addWidget(pushButton_33, 5, 2, 1, 2);

        pushButton_35 = new QPushButton(ModuleA);
        pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));
        pushButton_35->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_35->sizePolicy().hasHeightForWidth());
        pushButton_35->setSizePolicy(sizePolicy);
        pushButton_35->setMinimumSize(QSize(50, 25));
        pushButton_35->setMaximumSize(QSize(16777215, 25));
        pushButton_35->setCheckable(false);

        gridLayout->addWidget(pushButton_35, 2, 0, 1, 2);

        pushButton_57 = new QPushButton(ModuleA);
        pushButton_57->setObjectName(QString::fromUtf8("pushButton_57"));
        pushButton_57->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_57->sizePolicy().hasHeightForWidth());
        pushButton_57->setSizePolicy(sizePolicy);
        pushButton_57->setMinimumSize(QSize(50, 25));
        pushButton_57->setMaximumSize(QSize(16777215, 25));
        pushButton_57->setCheckable(false);

        gridLayout->addWidget(pushButton_57, 3, 0, 1, 2);

        pushButton_44 = new QPushButton(ModuleA);
        pushButton_44->setObjectName(QString::fromUtf8("pushButton_44"));
        pushButton_44->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_44->sizePolicy().hasHeightForWidth());
        pushButton_44->setSizePolicy(sizePolicy);
        pushButton_44->setMinimumSize(QSize(50, 25));
        pushButton_44->setMaximumSize(QSize(16777215, 25));
        pushButton_44->setCheckable(false);

        gridLayout->addWidget(pushButton_44, 4, 0, 1, 2);

        pushButton_34 = new QPushButton(ModuleA);
        pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));
        pushButton_34->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_34->sizePolicy().hasHeightForWidth());
        pushButton_34->setSizePolicy(sizePolicy);
        pushButton_34->setMinimumSize(QSize(50, 25));
        pushButton_34->setMaximumSize(QSize(16777215, 25));
        pushButton_34->setCheckable(false);

        gridLayout->addWidget(pushButton_34, 5, 0, 1, 2);

        checkBox_29 = new QCheckBox(ModuleA);
        checkBox_29->setObjectName(QString::fromUtf8("checkBox_29"));
        checkBox_29->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_29->sizePolicy().hasHeightForWidth());
        checkBox_29->setSizePolicy(sizePolicy);
        checkBox_29->setMinimumSize(QSize(50, 25));
        checkBox_29->setMaximumSize(QSize(16777215, 25));
        checkBox_29->setLayoutDirection(Qt::RightToLeft);
        checkBox_29->setChecked(false);

        gridLayout->addWidget(checkBox_29, 6, 3, 1, 1);

        checkBox_27 = new QCheckBox(ModuleA);
        checkBox_27->setObjectName(QString::fromUtf8("checkBox_27"));
        checkBox_27->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_27->sizePolicy().hasHeightForWidth());
        checkBox_27->setSizePolicy(sizePolicy);
        checkBox_27->setMinimumSize(QSize(50, 25));
        checkBox_27->setMaximumSize(QSize(16777215, 25));
        checkBox_27->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_27, 6, 2, 1, 1);

        lineEdit = new QLineEdit(ModuleA);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(50, 25));
        lineEdit->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(lineEdit, 6, 0, 1, 2);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);

        retranslateUi(ModuleA);

        comboBox_1->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModuleA);
    } // setupUi

    void retranslateUi(QFrame *ModuleA)
    {
        ModuleA->setWindowTitle(QCoreApplication::translate("ModuleA", "Frame", nullptr));
        comboBox_1->setItemText(0, QCoreApplication::translate("ModuleA", "select serial port name", nullptr));

        comboBox_1->setCurrentText(QCoreApplication::translate("ModuleA", "select serial port name", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ModuleA", "9600", nullptr));

        pushButton_31->setText(QCoreApplication::translate("ModuleA", "Connect Relay Port", nullptr));
        pushButton_32->setText(QCoreApplication::translate("ModuleA", "Disconnect Relay Port", nullptr));
        pushButton_45->setText(QCoreApplication::translate("ModuleA", "Open Selected Channel", nullptr));
        pushButton_33->setText(QCoreApplication::translate("ModuleA", " Reset All Channel", nullptr));
        pushButton_35->setText(QCoreApplication::translate("ModuleA", "Get Relay Port", nullptr));
        pushButton_57->setText(QCoreApplication::translate("ModuleA", "Scan Relay Port", nullptr));
        pushButton_44->setText(QCoreApplication::translate("ModuleA", "Close Selected Channel", nullptr));
        pushButton_34->setText(QCoreApplication::translate("ModuleA", "Close All Channel", nullptr));
        checkBox_29->setText(QCoreApplication::translate("ModuleA", "String:", nullptr));
        checkBox_27->setText(QCoreApplication::translate("ModuleA", "Option:", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("ModuleA", "waiting for command ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleA: public Ui_ModuleA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEA__UI__H
