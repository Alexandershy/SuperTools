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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ModuleB
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *ModuleB)
    {
        if (ModuleB->objectName().isEmpty())
            ModuleB->setObjectName(QString::fromUtf8("ModuleB"));
        ModuleB->resize(256, 76);
        gridLayout = new QGridLayout(ModuleB);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(ModuleB);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(ModuleB);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(0, 25));
        pushButton_3->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 2);

        pushButton = new QPushButton(ModuleB);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(25, 25));
        pushButton->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setColumnStretch(0, 99);
        gridLayout->setColumnStretch(1, 1);

        retranslateUi(ModuleB);

        QMetaObject::connectSlotsByName(ModuleB);
    } // setupUi

    void retranslateUi(QFrame *ModuleB)
    {
        ModuleB->setWindowTitle(QCoreApplication::translate("ModuleB", "Frame", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ModuleB", "Process", nullptr));
        pushButton->setText(QCoreApplication::translate("ModuleB", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleB: public Ui_ModuleB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEB__UI__H
