/********************************************************************************
** Form generated from reading UI file '_modulec_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _MODULEC__UI__H
#define _MODULEC__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ModuleC
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_101;
    QLabel *label_3;
    QComboBox *comboBox_33;
    QSpinBox *spinBox;
    QLabel *label_2;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit_42;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_49;
    QPushButton *pushButton_99;
    QLineEdit *lineEdit_47;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QFrame *ModuleC)
    {
        if (ModuleC->objectName().isEmpty())
            ModuleC->setObjectName(QString::fromUtf8("ModuleC"));
        ModuleC->resize(258, 217);
        gridLayout = new QGridLayout(ModuleC);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_101 = new QPushButton(ModuleC);
        pushButton_101->setObjectName(QString::fromUtf8("pushButton_101"));
        pushButton_101->setEnabled(false);
        pushButton_101->setMinimumSize(QSize(80, 25));

        gridLayout->addWidget(pushButton_101, 0, 2, 1, 2);

        label_3 = new QLabel(ModuleC);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        comboBox_33 = new QComboBox(ModuleC);
        comboBox_33->addItem(QString());
        comboBox_33->addItem(QString());
        comboBox_33->setObjectName(QString::fromUtf8("comboBox_33"));
        comboBox_33->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_33->sizePolicy().hasHeightForWidth());
        comboBox_33->setSizePolicy(sizePolicy);
        comboBox_33->setMinimumSize(QSize(25, 25));
        comboBox_33->setMaximumSize(QSize(16777215, 25));
        comboBox_33->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(comboBox_33, 2, 1, 1, 1);

        spinBox = new QSpinBox(ModuleC);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(false);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimumSize(QSize(0, 25));
        spinBox->setMaximumSize(QSize(16777215, 25));
        spinBox->setWrapping(false);
        spinBox->setFrame(true);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox->setMinimum(0);
        spinBox->setMaximum(0);
        spinBox->setSingleStep(0);
        spinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        spinBox->setValue(0);

        gridLayout->addWidget(spinBox, 1, 2, 1, 2);

        label_2 = new QLabel(ModuleC);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        checkBox_2 = new QCheckBox(ModuleC);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setEnabled(false);
        checkBox_2->setMinimumSize(QSize(40, 25));
        checkBox_2->setMaximumSize(QSize(16777215, 25));
        checkBox_2->setChecked(true);

        gridLayout->addWidget(checkBox_2, 5, 0, 1, 2);

        lineEdit_42 = new QLineEdit(ModuleC);
        lineEdit_42->setObjectName(QString::fromUtf8("lineEdit_42"));
        lineEdit_42->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_42->sizePolicy().hasHeightForWidth());
        lineEdit_42->setSizePolicy(sizePolicy);
        lineEdit_42->setMinimumSize(QSize(40, 25));
        lineEdit_42->setMaximumSize(QSize(16777215, 25));
        lineEdit_42->setReadOnly(true);

        gridLayout->addWidget(lineEdit_42, 2, 2, 1, 2);

        label_4 = new QLabel(ModuleC);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(false);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_5 = new QLabel(ModuleC);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(false);

        gridLayout->addWidget(label_5, 6, 0, 1, 2);

        doubleSpinBox_4 = new QDoubleSpinBox(ModuleC);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy);
        doubleSpinBox_4->setMinimumSize(QSize(40, 25));
        doubleSpinBox_4->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_4->setDecimals(0);
        doubleSpinBox_4->setMinimum(2000.000000000000000);
        doubleSpinBox_4->setMaximum(6000.000000000000000);
        doubleSpinBox_4->setSingleStep(100.000000000000000);
        doubleSpinBox_4->setValue(4000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_4, 6, 2, 1, 2);

        doubleSpinBox_5 = new QDoubleSpinBox(ModuleC);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox_5->sizePolicy().hasHeightForWidth());
        doubleSpinBox_5->setSizePolicy(sizePolicy1);
        doubleSpinBox_5->setMinimumSize(QSize(40, 25));
        doubleSpinBox_5->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_5->setDecimals(0);
        doubleSpinBox_5->setMinimum(0.000000000000000);
        doubleSpinBox_5->setMaximum(20.000000000000000);
        doubleSpinBox_5->setSingleStep(1.000000000000000);
        doubleSpinBox_5->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_5, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 4);

        lineEdit_49 = new QLineEdit(ModuleC);
        lineEdit_49->setObjectName(QString::fromUtf8("lineEdit_49"));
        lineEdit_49->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_49->sizePolicy().hasHeightForWidth());
        lineEdit_49->setSizePolicy(sizePolicy);
        lineEdit_49->setMinimumSize(QSize(40, 25));
        lineEdit_49->setMaximumSize(QSize(16777215, 25));
        lineEdit_49->setReadOnly(true);

        gridLayout->addWidget(lineEdit_49, 4, 2, 1, 2);

        pushButton_99 = new QPushButton(ModuleC);
        pushButton_99->setObjectName(QString::fromUtf8("pushButton_99"));
        pushButton_99->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_99->sizePolicy().hasHeightForWidth());
        pushButton_99->setSizePolicy(sizePolicy);
        pushButton_99->setMinimumSize(QSize(80, 25));
        pushButton_99->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_99, 0, 0, 1, 2);

        lineEdit_47 = new QLineEdit(ModuleC);
        lineEdit_47->setObjectName(QString::fromUtf8("lineEdit_47"));
        lineEdit_47->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_47->sizePolicy().hasHeightForWidth());
        lineEdit_47->setSizePolicy(sizePolicy);
        lineEdit_47->setMinimumSize(QSize(40, 25));
        lineEdit_47->setMaximumSize(QSize(16777215, 25));
        lineEdit_47->setReadOnly(true);

        gridLayout->addWidget(lineEdit_47, 3, 2, 1, 2);

        comboBox = new QComboBox(ModuleC);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(25, 25));
        comboBox->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        label = new QLabel(ModuleC);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);

        gridLayout->addWidget(label, 1, 0, 1, 1);


        retranslateUi(ModuleC);

        comboBox_33->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModuleC);
    } // setupUi

    void retranslateUi(QFrame *ModuleC)
    {
        ModuleC->setWindowTitle(QCoreApplication::translate("ModuleC", "Frame", nullptr));
        pushButton_101->setText(QCoreApplication::translate("ModuleC", "Stop Analysis Audio", nullptr));
        label_3->setText(QCoreApplication::translate("ModuleC", " frequency: ", nullptr));
        comboBox_33->setItemText(0, QCoreApplication::translate("ModuleC", "peak", nullptr));
        comboBox_33->setItemText(1, QCoreApplication::translate("ModuleC", "rms", nullptr));

        spinBox->setSpecialValueText(QCoreApplication::translate("ModuleC", "wait for enabled...", nullptr));
        spinBox->setSuffix(QString());
        spinBox->setPrefix(QString());
        label_2->setText(QCoreApplication::translate("ModuleC", " dbv:", nullptr));
        checkBox_2->setText(QCoreApplication::translate("ModuleC", "autoplot", nullptr));
        lineEdit_42->setText(QString());
        lineEdit_42->setPlaceholderText(QCoreApplication::translate("ModuleC", "wait for dbv value...", nullptr));
        label_4->setText(QCoreApplication::translate("ModuleC", " thd: ", nullptr));
        label_5->setText(QCoreApplication::translate("ModuleC", " samplecounts: ", nullptr));
        doubleSpinBox_4->setSuffix(QCoreApplication::translate("ModuleC", "(sample)", nullptr));
        doubleSpinBox_5->setSuffix(QCoreApplication::translate("ModuleC", "(degree)", nullptr));
        lineEdit_49->setText(QString());
        lineEdit_49->setPlaceholderText(QCoreApplication::translate("ModuleC", "wait for thd value...", nullptr));
        pushButton_99->setText(QCoreApplication::translate("ModuleC", "Analysis", nullptr));
        lineEdit_47->setText(QString());
        lineEdit_47->setPlaceholderText(QCoreApplication::translate("ModuleC", "wait for freq value...", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ModuleC", "disabled", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ModuleC", "size", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ModuleC", "length", nullptr));

        label->setText(QCoreApplication::translate("ModuleC", " record: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleC: public Ui_ModuleC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEC__UI__H
