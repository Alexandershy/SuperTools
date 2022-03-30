/********************************************************************************
** Form generated from reading UI file '_superprogressbarbox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERPROGRESSBARBOX__UI__H
#define _SUPERPROGRESSBARBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SuperProgressBarBox
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QLabel *label;

    void setupUi(QFrame *SuperProgressBarBox)
    {
        if (SuperProgressBarBox->objectName().isEmpty())
            SuperProgressBarBox->setObjectName(QString::fromUtf8("SuperProgressBarBox"));
        SuperProgressBarBox->resize(500, 50);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SuperProgressBarBox->sizePolicy().hasHeightForWidth());
        SuperProgressBarBox->setSizePolicy(sizePolicy);
        SuperProgressBarBox->setMinimumSize(QSize(500, 50));
        verticalLayout = new QVBoxLayout(SuperProgressBarBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(SuperProgressBarBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        label = new QLabel(SuperProgressBarBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 20));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        retranslateUi(SuperProgressBarBox);

        QMetaObject::connectSlotsByName(SuperProgressBarBox);
    } // setupUi

    void retranslateUi(QFrame *SuperProgressBarBox)
    {
        SuperProgressBarBox->setWindowTitle(QCoreApplication::translate("SuperProgressBarBox", "Frame", nullptr));
        label->setText(QCoreApplication::translate("SuperProgressBarBox", "wait message...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuperProgressBarBox: public Ui_SuperProgressBarBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERPROGRESSBARBOX__UI__H
