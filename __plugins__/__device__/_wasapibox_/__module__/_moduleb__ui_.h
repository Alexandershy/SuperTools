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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModuleB
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QComboBox *comboBox;
    QPushButton *pushButton_100;
    QComboBox *comboBox_32;
    QComboBox *comboBox_34;
    QPushButton *pushButton_97;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_3;
    QCheckBox *checkBox_24;
    QHBoxLayout *horizontalLayout_98;
    QLineEdit *lineEdit_34;
    QPushButton *pushButton_98;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QFrame *ModuleB)
    {
        if (ModuleB->objectName().isEmpty())
            ModuleB->setObjectName(QString::fromUtf8("ModuleB"));
        ModuleB->resize(266, 159);
        verticalLayout = new QVBoxLayout(ModuleB);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 0, -1, -1);
        doubleSpinBox_2 = new QDoubleSpinBox(ModuleB);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy);
        doubleSpinBox_2->setMinimumSize(QSize(40, 25));
        doubleSpinBox_2->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_2->setDecimals(0);
        doubleSpinBox_2->setMinimum(100.000000000000000);
        doubleSpinBox_2->setMaximum(20000.000000000000000);
        doubleSpinBox_2->setSingleStep(100.000000000000000);
        doubleSpinBox_2->setValue(1000.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_2, 2, 1, 1, 1);

        comboBox = new QComboBox(ModuleB);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(20, 25));
        comboBox->setMaximumSize(QSize(16777215, 25));

        gridLayout_4->addWidget(comboBox, 1, 2, 1, 1);

        pushButton_100 = new QPushButton(ModuleB);
        pushButton_100->setObjectName(QString::fromUtf8("pushButton_100"));
        pushButton_100->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_100->sizePolicy().hasHeightForWidth());
        pushButton_100->setSizePolicy(sizePolicy);
        pushButton_100->setMinimumSize(QSize(80, 25));
        pushButton_100->setMaximumSize(QSize(16777215, 25));

        gridLayout_4->addWidget(pushButton_100, 0, 2, 1, 2);

        comboBox_32 = new QComboBox(ModuleB);
        comboBox_32->addItem(QString());
        comboBox_32->addItem(QString());
        comboBox_32->addItem(QString());
        comboBox_32->addItem(QString());
        comboBox_32->setObjectName(QString::fromUtf8("comboBox_32"));
        comboBox_32->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_32->sizePolicy().hasHeightForWidth());
        comboBox_32->setSizePolicy(sizePolicy);
        comboBox_32->setMinimumSize(QSize(20, 25));
        comboBox_32->setMaximumSize(QSize(16777215, 25));

        gridLayout_4->addWidget(comboBox_32, 1, 3, 1, 1);

        comboBox_34 = new QComboBox(ModuleB);
        comboBox_34->addItem(QString());
        comboBox_34->setObjectName(QString::fromUtf8("comboBox_34"));
        comboBox_34->setEnabled(false);
        comboBox_34->setMinimumSize(QSize(40, 25));

        gridLayout_4->addWidget(comboBox_34, 2, 3, 1, 1);

        pushButton_97 = new QPushButton(ModuleB);
        pushButton_97->setObjectName(QString::fromUtf8("pushButton_97"));
        pushButton_97->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_97->sizePolicy().hasHeightForWidth());
        pushButton_97->setSizePolicy(sizePolicy);
        pushButton_97->setMinimumSize(QSize(80, 25));
        pushButton_97->setMaximumSize(QSize(16777215, 25));

        gridLayout_4->addWidget(pushButton_97, 0, 0, 1, 2);

        doubleSpinBox = new QDoubleSpinBox(ModuleB);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy);
        doubleSpinBox->setMinimumSize(QSize(40, 25));
        doubleSpinBox->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox->setWrapping(false);
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setDecimals(3);
        doubleSpinBox->setMaximum(1.000000000000000);
        doubleSpinBox->setSingleStep(0.010000000000000);
        doubleSpinBox->setValue(0.121000000000000);

        gridLayout_4->addWidget(doubleSpinBox, 2, 0, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(ModuleB);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy);
        doubleSpinBox_3->setMinimumSize(QSize(40, 25));
        doubleSpinBox_3->setMaximumSize(QSize(16777215, 25));
        doubleSpinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_3->setMaximum(10.000000000000000);
        doubleSpinBox_3->setSingleStep(0.100000000000000);

        gridLayout_4->addWidget(doubleSpinBox_3, 2, 2, 1, 1);

        checkBox_24 = new QCheckBox(ModuleB);
        checkBox_24->setObjectName(QString::fromUtf8("checkBox_24"));
        checkBox_24->setEnabled(false);
        checkBox_24->setMinimumSize(QSize(20, 25));
        checkBox_24->setMaximumSize(QSize(16777215, 25));
        checkBox_24->setLayoutDirection(Qt::LeftToRight);
        checkBox_24->setChecked(true);

        gridLayout_4->addWidget(checkBox_24, 1, 0, 1, 2);

        gridLayout_4->setRowStretch(0, 1);
        gridLayout_4->setRowStretch(1, 1);
        gridLayout_4->setRowStretch(2, 1);
        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1);
        gridLayout_4->setColumnStretch(2, 1);
        gridLayout_4->setColumnStretch(3, 1);

        verticalLayout->addLayout(gridLayout_4);

        horizontalLayout_98 = new QHBoxLayout();
        horizontalLayout_98->setSpacing(5);
        horizontalLayout_98->setObjectName(QString::fromUtf8("horizontalLayout_98"));
        lineEdit_34 = new QLineEdit(ModuleB);
        lineEdit_34->setObjectName(QString::fromUtf8("lineEdit_34"));
        lineEdit_34->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_34->sizePolicy().hasHeightForWidth());
        lineEdit_34->setSizePolicy(sizePolicy);
        lineEdit_34->setMinimumSize(QSize(80, 25));
        lineEdit_34->setMaximumSize(QSize(16777215, 25));
        lineEdit_34->setReadOnly(true);

        horizontalLayout_98->addWidget(lineEdit_34);

        pushButton_98 = new QPushButton(ModuleB);
        pushButton_98->setObjectName(QString::fromUtf8("pushButton_98"));
        pushButton_98->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_98->sizePolicy().hasHeightForWidth());
        pushButton_98->setSizePolicy(sizePolicy);
        pushButton_98->setMinimumSize(QSize(25, 25));
        pushButton_98->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_98->addWidget(pushButton_98);

        horizontalLayout_98->setStretch(0, 99);
        horizontalLayout_98->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_98);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(ModuleB);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(80, 25));
        pushButton_2->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(pushButton_2);

        label = new QLabel(ModuleB);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(251, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        retranslateUi(ModuleB);

        comboBox_32->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModuleB);
    } // setupUi

    void retranslateUi(QFrame *ModuleB)
    {
        ModuleB->setWindowTitle(QCoreApplication::translate("ModuleB", "Frame", nullptr));
        doubleSpinBox_2->setSuffix(QCoreApplication::translate("ModuleB", "(hz)", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ModuleB", "peak", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ModuleB", "rms", nullptr));

        pushButton_100->setText(QCoreApplication::translate("ModuleB", "Stop Play Audio", nullptr));
        comboBox_32->setItemText(0, QCoreApplication::translate("ModuleB", "sine", nullptr));
        comboBox_32->setItemText(1, QCoreApplication::translate("ModuleB", "square", nullptr));
        comboBox_32->setItemText(2, QCoreApplication::translate("ModuleB", "sawtooth", nullptr));
        comboBox_32->setItemText(3, QCoreApplication::translate("ModuleB", "triangular", nullptr));

        comboBox_34->setItemText(0, QCoreApplication::translate("ModuleB", "channel", nullptr));

        pushButton_97->setText(QCoreApplication::translate("ModuleB", "Play", nullptr));
        doubleSpinBox->setSuffix(QCoreApplication::translate("ModuleB", "(db)", nullptr));
        doubleSpinBox_3->setSuffix(QCoreApplication::translate("ModuleB", "(s)", nullptr));
        checkBox_24->setText(QCoreApplication::translate("ModuleB", "signal", nullptr));
        lineEdit_34->setPlaceholderText(QCoreApplication::translate("ModuleB", "here for audio files.wav path...", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_98->setToolTip(QCoreApplication::translate("ModuleB", "select wav file", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_98->setText(QCoreApplication::translate("ModuleB", "...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ModuleB", "Generate Wavfile", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ModuleB: public Ui_ModuleB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEB__UI__H
