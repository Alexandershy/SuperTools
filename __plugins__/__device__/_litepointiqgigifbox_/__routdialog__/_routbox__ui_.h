/********************************************************************************
** Form generated from reading UI file '_routbox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _ROUTBOX__UI__H
#define _ROUTBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RoutBox
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *pushButton_3;

    void setupUi(QFrame *RoutBox)
    {
        if (RoutBox->objectName().isEmpty())
            RoutBox->setObjectName(QString::fromUtf8("RoutBox"));
        RoutBox->resize(300, 80);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RoutBox->sizePolicy().hasHeightForWidth());
        RoutBox->setSizePolicy(sizePolicy);
        RoutBox->setMinimumSize(QSize(300, 80));
        verticalLayout = new QVBoxLayout(RoutBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_2 = new QLabel(RoutBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setMaximumSize(QSize(16777215, 25));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        label_4 = new QLabel(RoutBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(0, 25));
        label_4->setMaximumSize(QSize(16777215, 25));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(RoutBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(25, 25));
        pushButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(RoutBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(25, 25));
        pushButton_2->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(pushButton_2);

        label = new QLabel(RoutBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(25, 25));
        label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(label);

        pushButton_3 = new QPushButton(RoutBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(25, 25));
        pushButton_3->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(pushButton_3);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(RoutBox);

        QMetaObject::connectSlotsByName(RoutBox);
    } // setupUi

    void retranslateUi(QFrame *RoutBox)
    {
        RoutBox->setWindowTitle(QCoreApplication::translate("RoutBox", "Frame", nullptr));
        label_2->setText(QCoreApplication::translate("RoutBox", "RF1A: Closed", nullptr));
        label_4->setText(QCoreApplication::translate("RoutBox", "RF2A: Closed", nullptr));
        pushButton->setText(QCoreApplication::translate("RoutBox", "VSA", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RoutBox", "VSG", nullptr));
        label->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("RoutBox", "VSG", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoutBox: public Ui_RoutBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _ROUTBOX__UI__H
