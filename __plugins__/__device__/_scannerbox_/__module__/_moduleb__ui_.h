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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModuleB
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_10;
    QComboBox *comboBox_12;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_63;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;

    void setupUi(QFrame *ModuleB)
    {
        if (ModuleB->objectName().isEmpty())
            ModuleB->setObjectName(QString::fromUtf8("ModuleB"));
        ModuleB->resize(303, 330);
        verticalLayout = new QVBoxLayout(ModuleB);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_10 = new QComboBox(ModuleB);
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->setObjectName(QString::fromUtf8("comboBox_10"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_10->sizePolicy().hasHeightForWidth());
        comboBox_10->setSizePolicy(sizePolicy);
        comboBox_10->setMinimumSize(QSize(200, 25));
        comboBox_10->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(comboBox_10);

        comboBox_12 = new QComboBox(ModuleB);
        comboBox_12->addItem(QString());
        comboBox_12->setObjectName(QString::fromUtf8("comboBox_12"));
        comboBox_12->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_12->sizePolicy().hasHeightForWidth());
        comboBox_12->setSizePolicy(sizePolicy);
        comboBox_12->setMinimumSize(QSize(200, 25));
        comboBox_12->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(comboBox_12);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        label_63 = new QLabel(ModuleB);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        sizePolicy.setHeightForWidth(label_63->sizePolicy().hasHeightForWidth());
        label_63->setSizePolicy(sizePolicy);
        label_63->setMinimumSize(QSize(25, 25));
        label_63->setMaximumSize(QSize(16777215, 16777215));
        label_63->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_63, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 98);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 98);
        gridLayout->setColumnStretch(2, 1);

        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSlider = new QSlider(ModuleB);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setEnabled(false);
        horizontalSlider->setMinimum(50);
        horizontalSlider->setMaximum(200);
        horizontalSlider->setValue(200);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        lineEdit = new QLineEdit(ModuleB);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(50, 25));
        lineEdit->setMaximumSize(QSize(16777215, 25));
        lineEdit->setFrame(false);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit);

        horizontalLayout->setStretch(0, 99);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 97);
        verticalLayout->setStretch(3, 1);

        retranslateUi(ModuleB);

        QMetaObject::connectSlotsByName(ModuleB);
    } // setupUi

    void retranslateUi(QFrame *ModuleB)
    {
        ModuleB->setWindowTitle(QCoreApplication::translate("ModuleB", "Frame", nullptr));
        comboBox_10->setItemText(0, QCoreApplication::translate("ModuleB", "select scanner", nullptr));
        comboBox_10->setItemText(1, QCoreApplication::translate("ModuleB", "fs36-1415r", nullptr));
        comboBox_10->setItemText(2, QCoreApplication::translate("ModuleB", "honeywell-1900", nullptr));

        comboBox_12->setItemText(0, QCoreApplication::translate("ModuleB", "select scanner function", nullptr));

        label_63->setText(QString());
        lineEdit->setText(QCoreApplication::translate("ModuleB", "100%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleB: public Ui_ModuleB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEB__UI__H
