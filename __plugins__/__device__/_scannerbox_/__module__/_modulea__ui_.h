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
    QPushButton *pushButton_58;
    QPushButton *pushButton_60;
    QCheckBox *checkBox_31;
    QPushButton *pushButton_61;
    QPushButton *pushButton_59;
    QComboBox *comboBox_35;
    QComboBox *comboBox_11;
    QCheckBox *checkBox;
    QPushButton *pushButton_63;
    QPushButton *pushButton_62;
    QLineEdit *lineEdit_35;

    void setupUi(QFrame *ModuleA)
    {
        if (ModuleA->objectName().isEmpty())
            ModuleA->setObjectName(QString::fromUtf8("ModuleA"));
        ModuleA->resize(258, 180);
        gridLayout = new QGridLayout(ModuleA);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_58 = new QPushButton(ModuleA);
        pushButton_58->setObjectName(QString::fromUtf8("pushButton_58"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_58->sizePolicy().hasHeightForWidth());
        pushButton_58->setSizePolicy(sizePolicy);
        pushButton_58->setMinimumSize(QSize(80, 25));
        pushButton_58->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_58, 2, 0, 1, 2);

        pushButton_60 = new QPushButton(ModuleA);
        pushButton_60->setObjectName(QString::fromUtf8("pushButton_60"));
        sizePolicy.setHeightForWidth(pushButton_60->sizePolicy().hasHeightForWidth());
        pushButton_60->setSizePolicy(sizePolicy);
        pushButton_60->setMinimumSize(QSize(80, 25));
        pushButton_60->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_60, 3, 0, 1, 2);

        checkBox_31 = new QCheckBox(ModuleA);
        checkBox_31->setObjectName(QString::fromUtf8("checkBox_31"));
        checkBox_31->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox_31->sizePolicy().hasHeightForWidth());
        checkBox_31->setSizePolicy(sizePolicy);
        checkBox_31->setMinimumSize(QSize(0, 25));
        checkBox_31->setMaximumSize(QSize(16777215, 25));
        checkBox_31->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_31, 5, 3, 1, 1);

        pushButton_61 = new QPushButton(ModuleA);
        pushButton_61->setObjectName(QString::fromUtf8("pushButton_61"));
        pushButton_61->setEnabled(false);
        pushButton_61->setMinimumSize(QSize(80, 25));
        pushButton_61->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_61, 3, 2, 1, 2);

        pushButton_59 = new QPushButton(ModuleA);
        pushButton_59->setObjectName(QString::fromUtf8("pushButton_59"));
        pushButton_59->setEnabled(false);
        pushButton_59->setMinimumSize(QSize(80, 25));
        pushButton_59->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_59, 2, 2, 1, 2);

        comboBox_35 = new QComboBox(ModuleA);
        comboBox_35->addItem(QString());
        comboBox_35->setObjectName(QString::fromUtf8("comboBox_35"));
        comboBox_35->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_35->sizePolicy().hasHeightForWidth());
        comboBox_35->setSizePolicy(sizePolicy);
        comboBox_35->setMinimumSize(QSize(100, 25));
        comboBox_35->setMaximumSize(QSize(16777215, 25));
        comboBox_35->setEditable(true);

        gridLayout->addWidget(comboBox_35, 1, 0, 1, 4);

        comboBox_11 = new QComboBox(ModuleA);
        comboBox_11->addItem(QString());
        comboBox_11->setObjectName(QString::fromUtf8("comboBox_11"));
        comboBox_11->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_11->sizePolicy().hasHeightForWidth());
        comboBox_11->setSizePolicy(sizePolicy);
        comboBox_11->setMinimumSize(QSize(100, 25));
        comboBox_11->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(comboBox_11, 0, 0, 1, 4);

        checkBox = new QCheckBox(ModuleA);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);
        checkBox->setMinimumSize(QSize(0, 25));
        checkBox->setMaximumSize(QSize(16777215, 25));
        checkBox->setLayoutDirection(Qt::RightToLeft);
        checkBox->setChecked(true);

        gridLayout->addWidget(checkBox, 5, 2, 1, 1);

        pushButton_63 = new QPushButton(ModuleA);
        pushButton_63->setObjectName(QString::fromUtf8("pushButton_63"));
        pushButton_63->setEnabled(false);
        pushButton_63->setMinimumSize(QSize(80, 25));
        pushButton_63->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_63, 5, 0, 1, 2);

        pushButton_62 = new QPushButton(ModuleA);
        pushButton_62->setObjectName(QString::fromUtf8("pushButton_62"));
        pushButton_62->setEnabled(false);
        pushButton_62->setMinimumSize(QSize(80, 25));
        pushButton_62->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_62, 4, 0, 1, 2);

        lineEdit_35 = new QLineEdit(ModuleA);
        lineEdit_35->setObjectName(QString::fromUtf8("lineEdit_35"));
        lineEdit_35->setEnabled(false);
        lineEdit_35->setMinimumSize(QSize(100, 20));
        lineEdit_35->setMaximumSize(QSize(800, 25));

        gridLayout->addWidget(lineEdit_35, 4, 2, 1, 2);

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
        pushButton_58->setText(QCoreApplication::translate("ModuleA", "Get Scanner Port", nullptr));
        pushButton_60->setText(QCoreApplication::translate("ModuleA", "Scan Scanner Port", nullptr));
        checkBox_31->setText(QCoreApplication::translate("ModuleA", "Option:", nullptr));
        pushButton_61->setText(QCoreApplication::translate("ModuleA", "Disconnect Scanner Port", nullptr));
        pushButton_59->setText(QCoreApplication::translate("ModuleA", "Connect Scanner Port", nullptr));
        comboBox_35->setItemText(0, QCoreApplication::translate("ModuleA", "115200", nullptr));

        comboBox_11->setItemText(0, QCoreApplication::translate("ModuleA", "select scanner port", nullptr));

        checkBox->setText(QCoreApplication::translate("ModuleA", "Hex:", nullptr));
        pushButton_63->setText(QCoreApplication::translate("ModuleA", "Close Scanner", nullptr));
        pushButton_62->setText(QCoreApplication::translate("ModuleA", "Open Scanner", nullptr));
        lineEdit_35->setPlaceholderText(QCoreApplication::translate("ModuleA", "waiting for command ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleA: public Ui_ModuleA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEA__UI__H
