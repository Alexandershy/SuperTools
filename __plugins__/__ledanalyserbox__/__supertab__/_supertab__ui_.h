/********************************************************************************
** Form generated from reading UI file '_supertab_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERTAB__UI__H
#define _SUPERTAB__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SuperTab
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *Leftlayout;
    QVBoxLayout *Rightlayout;

    void setupUi(QGroupBox *SuperTab)
    {
        if (SuperTab->objectName().isEmpty())
            SuperTab->setObjectName(QString::fromUtf8("SuperTab"));
        SuperTab->resize(700, 500);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SuperTab->sizePolicy().hasHeightForWidth());
        SuperTab->setSizePolicy(sizePolicy);
        SuperTab->setMinimumSize(QSize(700, 500));
        horizontalLayout = new QHBoxLayout(SuperTab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Leftlayout = new QVBoxLayout();
        Leftlayout->setObjectName(QString::fromUtf8("Leftlayout"));

        horizontalLayout->addLayout(Leftlayout);

        Rightlayout = new QVBoxLayout();
        Rightlayout->setObjectName(QString::fromUtf8("Rightlayout"));

        horizontalLayout->addLayout(Rightlayout);

        horizontalLayout->setStretch(0, 385);
        horizontalLayout->setStretch(1, 615);

        retranslateUi(SuperTab);

        QMetaObject::connectSlotsByName(SuperTab);
    } // setupUi

    void retranslateUi(QGroupBox *SuperTab)
    {
        SuperTab->setWindowTitle(QCoreApplication::translate("SuperTab", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuperTab: public Ui_SuperTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERTAB__UI__H
