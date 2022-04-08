/********************************************************************************
** Form generated from reading UI file '_formatbox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _FORMATBOX__UI_H
#define _FORMATBOX__UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormatBox
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_5;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_5;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_6;

    void setupUi(QFrame *FormatBox)
    {
        if (FormatBox->objectName().isEmpty())
            FormatBox->setObjectName(QString::fromUtf8("FormatBox"));
        FormatBox->resize(193, 154);
        horizontalLayout = new QHBoxLayout(FormatBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        tabWidget = new QTabWidget(FormatBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        doubleSpinBox_2 = new QDoubleSpinBox(tab);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy);
        doubleSpinBox_2->setMinimumSize(QSize(80, 25));
        doubleSpinBox_2->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_2->setDecimals(0);
        doubleSpinBox_2->setMinimum(100.000000000000000);
        doubleSpinBox_2->setMaximum(96000.000000000000000);
        doubleSpinBox_2->setSingleStep(100.000000000000000);
        doubleSpinBox_2->setValue(44100.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 2);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(80, 25));
        label->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(tab);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        sizePolicy.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy);
        doubleSpinBox_3->setMinimumSize(QSize(80, 25));
        doubleSpinBox_3->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_3->setDecimals(0);
        doubleSpinBox_3->setMinimum(8.000000000000000);
        doubleSpinBox_3->setMaximum(32.000000000000000);
        doubleSpinBox_3->setSingleStep(1.000000000000000);
        doubleSpinBox_3->setValue(16.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_3, 4, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(80, 25));
        label_3->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(80, 25));
        label_2->setMaximumSize(QSize(16777215, 25));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(tab);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        sizePolicy.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy);
        doubleSpinBox->setMinimumSize(QSize(80, 25));
        doubleSpinBox->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setDecimals(0);
        doubleSpinBox->setMinimum(1.000000000000000);
        doubleSpinBox->setMaximum(10.000000000000000);
        doubleSpinBox->setValue(2.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 0, 1, 2);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setRowStretch(3, 1);
        gridLayout_2->setRowStretch(4, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);

        verticalLayout->addLayout(gridLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(80, 25));
        label_6->setMaximumSize(QSize(16777215, 25));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        sizePolicy.setHeightForWidth(doubleSpinBox_5->sizePolicy().hasHeightForWidth());
        doubleSpinBox_5->setSizePolicy(sizePolicy);
        doubleSpinBox_5->setMinimumSize(QSize(80, 25));
        doubleSpinBox_5->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_5->setDecimals(0);
        doubleSpinBox_5->setMinimum(100.000000000000000);
        doubleSpinBox_5->setMaximum(96000.000000000000000);
        doubleSpinBox_5->setSingleStep(100.000000000000000);
        doubleSpinBox_5->setValue(44100.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_5, 2, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 3, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 1, 0, 1, 2);

        doubleSpinBox_4 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        sizePolicy.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy);
        doubleSpinBox_4->setMinimumSize(QSize(80, 25));
        doubleSpinBox_4->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_4->setDecimals(0);
        doubleSpinBox_4->setMinimum(1.000000000000000);
        doubleSpinBox_4->setMaximum(10.000000000000000);
        doubleSpinBox_4->setValue(2.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_4, 0, 1, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(80, 25));
        label_5->setMaximumSize(QSize(16777215, 25));

        gridLayout_3->addWidget(label_5, 4, 0, 1, 1);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(80, 25));
        label_4->setMaximumSize(QSize(16777215, 25));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        sizePolicy.setHeightForWidth(doubleSpinBox_6->sizePolicy().hasHeightForWidth());
        doubleSpinBox_6->setSizePolicy(sizePolicy);
        doubleSpinBox_6->setMinimumSize(QSize(80, 25));
        doubleSpinBox_6->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox_6->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_6->setDecimals(0);
        doubleSpinBox_6->setMinimum(8.000000000000000);
        doubleSpinBox_6->setMaximum(32.000000000000000);
        doubleSpinBox_6->setValue(16.000000000000000);

        gridLayout_3->addWidget(doubleSpinBox_6, 4, 1, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setRowStretch(2, 1);
        gridLayout_3->setRowStretch(3, 1);
        gridLayout_3->setRowStretch(4, 1);
        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1);

        verticalLayout_2->addLayout(gridLayout_3);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(FormatBox);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FormatBox);
    } // setupUi

    void retranslateUi(QFrame *FormatBox)
    {
        FormatBox->setWindowTitle(QCoreApplication::translate("FormatBox", "Frame", nullptr));
        doubleSpinBox_2->setSuffix(QCoreApplication::translate("FormatBox", "(hz)", nullptr));
        label->setText(QCoreApplication::translate("FormatBox", "Channels: ", nullptr));
        doubleSpinBox_3->setSuffix(QCoreApplication::translate("FormatBox", "(bits)", nullptr));
        label_3->setText(QCoreApplication::translate("FormatBox", "Bits: ", nullptr));
        label_2->setText(QCoreApplication::translate("FormatBox", "Samplerate: ", nullptr));
        doubleSpinBox->setSuffix(QCoreApplication::translate("FormatBox", "(channel)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("FormatBox", "Output", nullptr));
        label_6->setText(QCoreApplication::translate("FormatBox", "Samplerate: ", nullptr));
        doubleSpinBox_5->setSuffix(QCoreApplication::translate("FormatBox", "(hz)", nullptr));
        doubleSpinBox_4->setSuffix(QCoreApplication::translate("FormatBox", "(channel)", nullptr));
        label_5->setText(QCoreApplication::translate("FormatBox", "Bits: ", nullptr));
        label_4->setText(QCoreApplication::translate("FormatBox", "Channels: ", nullptr));
        doubleSpinBox_6->setSuffix(QCoreApplication::translate("FormatBox", "(bits)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FormatBox", "Input", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormatBox: public Ui_FormatBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _FORMATBOX__UI_H
