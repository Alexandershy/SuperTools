/********************************************************************************
** Form generated from reading UI file '_supersender_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERSENDER__UI__H
#define _SUPERSENDER__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SuperSender
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QCheckBox *checkBox;
    QSpinBox *spinBox;

    void setupUi(QFrame *SuperSender)
    {
        if (SuperSender->objectName().isEmpty())
            SuperSender->setObjectName(QString::fromUtf8("SuperSender"));
        SuperSender->resize(304, 80);
        SuperSender->setMinimumSize(QSize(0, 80));
        SuperSender->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(SuperSender);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(SuperSender);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(60, 25));
        pushButton->setMaximumSize(QSize(100, 25));
        pushButton->setFocusPolicy(Qt::StrongFocus);
        pushButton->setCheckable(false);

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        lineEdit = new QLineEdit(SuperSender);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(150, 25));
        lineEdit->setMaximumSize(QSize(800, 25));
        lineEdit->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        label = new QLabel(SuperSender);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 20));
        label->setMaximumSize(QSize(16777215, 20));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        checkBox = new QCheckBox(SuperSender);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(false);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);
        checkBox->setMinimumSize(QSize(20, 20));
        checkBox->setMaximumSize(QSize(16777215, 20));
        checkBox->setFocusPolicy(Qt::StrongFocus);
        checkBox->setLayoutDirection(Qt::RightToLeft);
        checkBox->setAutoFillBackground(false);
        checkBox->setText(QString::fromUtf8("Is Cyc:"));

        gridLayout->addWidget(checkBox, 2, 0, 1, 1);

        spinBox = new QSpinBox(SuperSender);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        spinBox->setMinimumSize(QSize(0, 20));
        spinBox->setMaximumSize(QSize(16777215, 20));
        spinBox->setFocusPolicy(Qt::StrongFocus);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMinimum(100);
        spinBox->setMaximum(5000);
        spinBox->setSingleStep(100);
        spinBox->setValue(1000);
        spinBox->setDisplayIntegerBase(10);

        gridLayout->addWidget(spinBox, 2, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 99);
        gridLayout->setColumnStretch(1, 1);

        verticalLayout->addLayout(gridLayout);


        retranslateUi(SuperSender);

        QMetaObject::connectSlotsByName(SuperSender);
    } // setupUi

    void retranslateUi(QFrame *SuperSender)
    {
        SuperSender->setWindowTitle(QCoreApplication::translate("SuperSender", "Frame", nullptr));
        pushButton->setText(QCoreApplication::translate("SuperSender", "Send", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("SuperSender", "waiting for command ...", nullptr));
        label->setText(QCoreApplication::translate("SuperSender", "Input line xx", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuperSender: public Ui_SuperSender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERSENDER__UI__H
