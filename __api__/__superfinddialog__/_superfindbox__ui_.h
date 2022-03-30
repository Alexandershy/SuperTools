/********************************************************************************
** Form generated from reading UI file '_superfindbox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERFINDBOX__UI__H
#define _SUPERFINDBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SuperFindBox
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QFrame *SuperFindBox)
    {
        if (SuperFindBox->objectName().isEmpty())
            SuperFindBox->setObjectName(QString::fromUtf8("SuperFindBox"));
        SuperFindBox->resize(300, 100);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SuperFindBox->sizePolicy().hasHeightForWidth());
        SuperFindBox->setSizePolicy(sizePolicy);
        SuperFindBox->setMinimumSize(QSize(300, 100));
        horizontalLayout_2 = new QHBoxLayout(SuperFindBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(SuperFindBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(SuperFindBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(80, 25));
        comboBox->setMaximumSize(QSize(16777215, 25));
        comboBox->setEditable(true);

        horizontalLayout->addWidget(comboBox);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 9);

        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_3 = new QPushButton(SuperFindBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(80, 25));
        pushButton_3->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(SuperFindBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(80, 25));
        pushButton->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(SuperFindBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(80, 25));
        pushButton_2->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(SuperFindBox);

        QMetaObject::connectSlotsByName(SuperFindBox);
    } // setupUi

    void retranslateUi(QFrame *SuperFindBox)
    {
        SuperFindBox->setWindowTitle(QCoreApplication::translate("SuperFindBox", "Frame", nullptr));
        label->setText(QCoreApplication::translate("SuperFindBox", "search:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SuperFindBox", "Next", nullptr));
        pushButton->setText(QCoreApplication::translate("SuperFindBox", "Last", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SuperFindBox", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuperFindBox: public Ui_SuperFindBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERFINDBOX__UI__H
