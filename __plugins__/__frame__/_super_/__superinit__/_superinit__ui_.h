/********************************************************************************
** Form generated from reading UI file '_superinit_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERINIT__UI__H
#define _SUPERINIT__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SuperInit
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *SuperSetting_Edit;
    QPushButton *SuperSetting_Select;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *Default_SuperSetting;
    QPushButton *Local_SuperSetting;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_7;

    void setupUi(QFrame *SuperInit)
    {
        if (SuperInit->objectName().isEmpty())
            SuperInit->setObjectName(QString::fromUtf8("SuperInit"));
        SuperInit->resize(300, 80);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SuperInit->sizePolicy().hasHeightForWidth());
        SuperInit->setSizePolicy(sizePolicy);
        SuperInit->setMinimumSize(QSize(300, 80));
        horizontalLayout = new QHBoxLayout(SuperInit);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(SuperInit);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout->addWidget(label_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        SuperSetting_Edit = new QLineEdit(SuperInit);
        SuperSetting_Edit->setObjectName(QString::fromUtf8("SuperSetting_Edit"));
        SuperSetting_Edit->setMinimumSize(QSize(25, 25));
        SuperSetting_Edit->setMaximumSize(QSize(16777215, 25));
        SuperSetting_Edit->setReadOnly(true);

        horizontalLayout_2->addWidget(SuperSetting_Edit);

        SuperSetting_Select = new QPushButton(SuperInit);
        SuperSetting_Select->setObjectName(QString::fromUtf8("SuperSetting_Select"));
        SuperSetting_Select->setMinimumSize(QSize(25, 25));
        SuperSetting_Select->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(SuperSetting_Select);

        horizontalLayout_2->setStretch(0, 99);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        Default_SuperSetting = new QPushButton(SuperInit);
        Default_SuperSetting->setObjectName(QString::fromUtf8("Default_SuperSetting"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Default_SuperSetting->sizePolicy().hasHeightForWidth());
        Default_SuperSetting->setSizePolicy(sizePolicy1);
        Default_SuperSetting->setMinimumSize(QSize(25, 25));
        Default_SuperSetting->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(Default_SuperSetting);

        Local_SuperSetting = new QPushButton(SuperInit);
        Local_SuperSetting->setObjectName(QString::fromUtf8("Local_SuperSetting"));
        Local_SuperSetting->setEnabled(false);
        Local_SuperSetting->setMinimumSize(QSize(25, 25));
        Local_SuperSetting->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(Local_SuperSetting);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        label_7 = new QLabel(SuperInit);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(label_7);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 8);
        horizontalLayout->setStretch(2, 1);

        retranslateUi(SuperInit);

        QMetaObject::connectSlotsByName(SuperInit);
    } // setupUi

    void retranslateUi(QFrame *SuperInit)
    {
        SuperInit->setWindowTitle(QCoreApplication::translate("SuperInit", "Frame", nullptr));
        label_6->setText(QString());
#if QT_CONFIG(tooltip)
        SuperSetting_Edit->setToolTip(QCoreApplication::translate("SuperInit", "custom setting file", nullptr));
#endif // QT_CONFIG(tooltip)
        SuperSetting_Edit->setPlaceholderText(QCoreApplication::translate("SuperInit", "_setting_.ini file", nullptr));
#if QT_CONFIG(tooltip)
        SuperSetting_Select->setToolTip(QCoreApplication::translate("SuperInit", "select setting", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        SuperSetting_Select->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        SuperSetting_Select->setText(QCoreApplication::translate("SuperInit", "...", nullptr));
#if QT_CONFIG(tooltip)
        Default_SuperSetting->setToolTip(QCoreApplication::translate("SuperInit", "default setting", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        Default_SuperSetting->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        Default_SuperSetting->setText(QCoreApplication::translate("SuperInit", "Default Setting", nullptr));
#if QT_CONFIG(tooltip)
        Local_SuperSetting->setToolTip(QCoreApplication::translate("SuperInit", "custom setting", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        Local_SuperSetting->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        Local_SuperSetting->setText(QCoreApplication::translate("SuperInit", "Local Setting", nullptr));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SuperInit: public Ui_SuperInit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERINIT__UI__H
