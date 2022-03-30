/********************************************************************************
** Form generated from reading UI file '_supertitle_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERTITLE__UI__H
#define _SUPERTITLE__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SuperTitle
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_6;

    void setupUi(QFrame *SuperTitle)
    {
        if (SuperTitle->objectName().isEmpty())
            SuperTitle->setObjectName(QString::fromUtf8("SuperTitle"));
        SuperTitle->resize(500, 26);
        SuperTitle->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(SuperTitle);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        pushButton_5 = new QPushButton(SuperTitle);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setMinimumSize(QSize(20, 20));
        pushButton_5->setMaximumSize(QSize(20, 20));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        pushButton_5->setFlat(false);

        horizontalLayout_5->addWidget(pushButton_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 98);

        horizontalLayout->addLayout(horizontalLayout_5);

        label_2 = new QLabel(SuperTitle);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        font.setKerning(true);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(10);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));

        horizontalLayout->addLayout(horizontalLayout_6);


        retranslateUi(SuperTitle);

        QMetaObject::connectSlotsByName(SuperTitle);
    } // setupUi

    void retranslateUi(QFrame *SuperTitle)
    {
        SuperTitle->setWindowTitle(QCoreApplication::translate("SuperTitle", "Frame", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_5->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_5->setText(QString());
#if QT_CONFIG(tooltip)
        label_2->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SuperTitle: public Ui_SuperTitle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERTITLE__UI__H
