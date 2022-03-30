/********************************************************************************
** Form generated from reading UI file '_infobox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _INFOBOX__UI__H
#define _INFOBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_InfoBox
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QSpinBox *spinBox_3;
    QLabel *label_4;
    QSpinBox *spinBox_4;
    QLabel *label_5;
    QSpinBox *spinBox_5;
    QLabel *label_6;
    QSpinBox *spinBox_6;
    QLabel *label_7;
    QSpinBox *spinBox_7;

    void setupUi(QFrame *InfoBox)
    {
        if (InfoBox->objectName().isEmpty())
            InfoBox->setObjectName(QString::fromUtf8("InfoBox"));
        InfoBox->resize(200, 240);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InfoBox->sizePolicy().hasHeightForWidth());
        InfoBox->setSizePolicy(sizePolicy);
        InfoBox->setMinimumSize(QSize(200, 240));
        InfoBox->setMaximumSize(QSize(200, 240));
        gridLayout = new QGridLayout(InfoBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(InfoBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(80, 25));
        label->setMaximumSize(QSize(16777215, 25));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(InfoBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimumSize(QSize(80, 25));
        spinBox->setMaximumSize(QSize(16777215, 25));
        spinBox->setMaximum(16777215);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        label_2 = new QLabel(InfoBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(80, 25));
        label_2->setMaximumSize(QSize(16777215, 25));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox_2 = new QSpinBox(InfoBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        sizePolicy.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy);
        spinBox_2->setMinimumSize(QSize(80, 25));
        spinBox_2->setMaximumSize(QSize(16777215, 25));
        spinBox_2->setMinimum(0);
        spinBox_2->setMaximum(16777215);
        spinBox_2->setValue(1);

        gridLayout->addWidget(spinBox_2, 1, 1, 1, 1);

        label_3 = new QLabel(InfoBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(80, 25));
        label_3->setMaximumSize(QSize(16777215, 25));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinBox_3 = new QSpinBox(InfoBox);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        sizePolicy.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy);
        spinBox_3->setMinimumSize(QSize(80, 25));
        spinBox_3->setMaximumSize(QSize(16777215, 25));
        spinBox_3->setMinimum(0);
        spinBox_3->setMaximum(16777215);
        spinBox_3->setValue(2);

        gridLayout->addWidget(spinBox_3, 2, 1, 1, 1);

        label_4 = new QLabel(InfoBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(80, 25));
        label_4->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        spinBox_4 = new QSpinBox(InfoBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        sizePolicy.setHeightForWidth(spinBox_4->sizePolicy().hasHeightForWidth());
        spinBox_4->setSizePolicy(sizePolicy);
        spinBox_4->setMinimumSize(QSize(80, 25));
        spinBox_4->setMaximumSize(QSize(16777215, 25));
        spinBox_4->setMaximum(16777215);
        spinBox_4->setValue(3);

        gridLayout->addWidget(spinBox_4, 3, 1, 1, 1);

        label_5 = new QLabel(InfoBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(80, 25));
        label_5->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        spinBox_5 = new QSpinBox(InfoBox);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        sizePolicy.setHeightForWidth(spinBox_5->sizePolicy().hasHeightForWidth());
        spinBox_5->setSizePolicy(sizePolicy);
        spinBox_5->setMinimumSize(QSize(80, 25));
        spinBox_5->setMaximumSize(QSize(16777215, 25));
        spinBox_5->setMaximum(16777215);
        spinBox_5->setValue(0);

        gridLayout->addWidget(spinBox_5, 4, 1, 1, 1);

        label_6 = new QLabel(InfoBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(80, 25));
        label_6->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        spinBox_6 = new QSpinBox(InfoBox);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        sizePolicy.setHeightForWidth(spinBox_6->sizePolicy().hasHeightForWidth());
        spinBox_6->setSizePolicy(sizePolicy);
        spinBox_6->setMinimumSize(QSize(80, 25));
        spinBox_6->setMaximumSize(QSize(16777215, 25));
        spinBox_6->setMaximum(16777215);
        spinBox_6->setValue(1);

        gridLayout->addWidget(spinBox_6, 5, 1, 1, 1);

        label_7 = new QLabel(InfoBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(80, 25));
        label_7->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        spinBox_7 = new QSpinBox(InfoBox);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        sizePolicy.setHeightForWidth(spinBox_7->sizePolicy().hasHeightForWidth());
        spinBox_7->setSizePolicy(sizePolicy);
        spinBox_7->setMinimumSize(QSize(80, 25));
        spinBox_7->setMaximumSize(QSize(16777215, 25));
        spinBox_7->setMaximum(16777215);
        spinBox_7->setValue(2);

        gridLayout->addWidget(spinBox_7, 6, 1, 1, 1);


        retranslateUi(InfoBox);

        QMetaObject::connectSlotsByName(InfoBox);
    } // setupUi

    void retranslateUi(QFrame *InfoBox)
    {
        InfoBox->setWindowTitle(QCoreApplication::translate("InfoBox", "Frame", nullptr));
        label->setText(QCoreApplication::translate("InfoBox", "Test Items:", nullptr));
        spinBox->setSuffix(QCoreApplication::translate("InfoBox", " (rows)", nullptr));
        label_2->setText(QCoreApplication::translate("InfoBox", "Upper Limit:", nullptr));
        spinBox_2->setSuffix(QCoreApplication::translate("InfoBox", " (rows)", nullptr));
        label_3->setText(QCoreApplication::translate("InfoBox", "Lower Limit:", nullptr));
        spinBox_3->setSuffix(QCoreApplication::translate("InfoBox", " (rows)", nullptr));
        label_4->setText(QCoreApplication::translate("InfoBox", "Data Start:", nullptr));
        spinBox_4->setSuffix(QCoreApplication::translate("InfoBox", " (rows)", nullptr));
        label_5->setText(QCoreApplication::translate("InfoBox", "Serial Number: ", nullptr));
        spinBox_5->setSuffix(QCoreApplication::translate("InfoBox", " (columns)", nullptr));
        label_6->setText(QCoreApplication::translate("InfoBox", "Tester Name:", nullptr));
        spinBox_6->setSuffix(QCoreApplication::translate("InfoBox", " (columns)", nullptr));
        label_7->setText(QCoreApplication::translate("InfoBox", "Appraiser: ", nullptr));
        spinBox_7->setSuffix(QCoreApplication::translate("InfoBox", " (columns)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoBox: public Ui_InfoBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _INFOBOX__UI__H
