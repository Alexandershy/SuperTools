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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ModuleB
{
public:
    QGridLayout *gridLayout;
    QComboBox *comboBox_8;
    QComboBox *comboBox_9;
    QLineEdit *lineEdit_19;
    QLineEdit *lineEdit_18;
    QLabel *label_59;
    QComboBox *comboBox_6;
    QLabel *label_60;
    QCheckBox *checkBox_28;
    QLabel *label_62;
    QPushButton *pushButton_47;
    QComboBox *comboBox_5;
    QLineEdit *lineEdit_21;
    QLabel *label_58;
    QLineEdit *lineEdit_33;
    QComboBox *comboBox_7;
    QPushButton *pushButton_49;
    QPushButton *pushButton_50;
    QLineEdit *lineEdit_17;
    QLabel *label_61;
    QPushButton *pushButton_46;
    QLineEdit *lineEdit_20;
    QCheckBox *checkBox_30;
    QPushButton *pushButton_48;
    QSpacerItem *verticalSpacer;
    QLabel *Blank_1;

    void setupUi(QFrame *ModuleB)
    {
        if (ModuleB->objectName().isEmpty())
            ModuleB->setObjectName(QString::fromUtf8("ModuleB"));
        ModuleB->resize(268, 346);
        gridLayout = new QGridLayout(ModuleB);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_8 = new QComboBox(ModuleB);
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));
        comboBox_8->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_8->sizePolicy().hasHeightForWidth());
        comboBox_8->setSizePolicy(sizePolicy);
        comboBox_8->setMinimumSize(QSize(30, 25));
        comboBox_8->setMaximumSize(QSize(200, 25));
        comboBox_8->setEditable(true);

        gridLayout->addWidget(comboBox_8, 2, 3, 1, 1);

        comboBox_9 = new QComboBox(ModuleB);
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->setObjectName(QString::fromUtf8("comboBox_9"));
        comboBox_9->setEnabled(false);
        comboBox_9->setMinimumSize(QSize(30, 25));
        comboBox_9->setMaximumSize(QSize(500, 25));
        comboBox_9->setEditable(true);

        gridLayout->addWidget(comboBox_9, 3, 2, 1, 2);

        lineEdit_19 = new QLineEdit(ModuleB);
        lineEdit_19->setObjectName(QString::fromUtf8("lineEdit_19"));
        lineEdit_19->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_19->sizePolicy().hasHeightForWidth());
        lineEdit_19->setSizePolicy(sizePolicy);
        lineEdit_19->setMinimumSize(QSize(50, 25));
        lineEdit_19->setMaximumSize(QSize(500, 25));
        lineEdit_19->setReadOnly(true);

        gridLayout->addWidget(lineEdit_19, 8, 2, 1, 2);

        lineEdit_18 = new QLineEdit(ModuleB);
        lineEdit_18->setObjectName(QString::fromUtf8("lineEdit_18"));
        lineEdit_18->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_18->sizePolicy().hasHeightForWidth());
        lineEdit_18->setSizePolicy(sizePolicy);
        lineEdit_18->setMinimumSize(QSize(50, 25));
        lineEdit_18->setMaximumSize(QSize(500, 25));
        lineEdit_18->setReadOnly(true);

        gridLayout->addWidget(lineEdit_18, 7, 2, 1, 2);

        label_59 = new QLabel(ModuleB);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        sizePolicy.setHeightForWidth(label_59->sizePolicy().hasHeightForWidth());
        label_59->setSizePolicy(sizePolicy);
        label_59->setMinimumSize(QSize(110, 25));
        label_59->setMaximumSize(QSize(16777215, 25));
        label_59->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_59, 7, 0, 1, 2);

        comboBox_6 = new QComboBox(ModuleB);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_6->sizePolicy().hasHeightForWidth());
        comboBox_6->setSizePolicy(sizePolicy);
        comboBox_6->setMinimumSize(QSize(30, 25));
        comboBox_6->setMaximumSize(QSize(200, 25));
        comboBox_6->setEditable(true);

        gridLayout->addWidget(comboBox_6, 2, 1, 1, 1);

        label_60 = new QLabel(ModuleB);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        sizePolicy.setHeightForWidth(label_60->sizePolicy().hasHeightForWidth());
        label_60->setSizePolicy(sizePolicy);
        label_60->setMinimumSize(QSize(110, 25));
        label_60->setMaximumSize(QSize(16777215, 25));
        label_60->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_60, 8, 0, 1, 2);

        checkBox_28 = new QCheckBox(ModuleB);
        checkBox_28->setObjectName(QString::fromUtf8("checkBox_28"));
        checkBox_28->setEnabled(false);
        checkBox_28->setMinimumSize(QSize(55, 25));
        checkBox_28->setMaximumSize(QSize(300, 25));
        checkBox_28->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(checkBox_28, 5, 3, 1, 1);

        label_62 = new QLabel(ModuleB);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        sizePolicy.setHeightForWidth(label_62->sizePolicy().hasHeightForWidth());
        label_62->setSizePolicy(sizePolicy);
        label_62->setMinimumSize(QSize(110, 25));
        label_62->setMaximumSize(QSize(16777215, 25));
        label_62->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_62, 10, 0, 1, 2);

        pushButton_47 = new QPushButton(ModuleB);
        pushButton_47->setObjectName(QString::fromUtf8("pushButton_47"));
        pushButton_47->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_47->sizePolicy().hasHeightForWidth());
        pushButton_47->setSizePolicy(sizePolicy);
        pushButton_47->setMinimumSize(QSize(80, 25));
        pushButton_47->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_47, 0, 2, 1, 2);

        comboBox_5 = new QComboBox(ModuleB);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_5->sizePolicy().hasHeightForWidth());
        comboBox_5->setSizePolicy(sizePolicy);
        comboBox_5->setMinimumSize(QSize(30, 25));
        comboBox_5->setMaximumSize(QSize(200, 25));
        comboBox_5->setEditable(true);

        gridLayout->addWidget(comboBox_5, 2, 0, 1, 1);

        lineEdit_21 = new QLineEdit(ModuleB);
        lineEdit_21->setObjectName(QString::fromUtf8("lineEdit_21"));
        lineEdit_21->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_21->sizePolicy().hasHeightForWidth());
        lineEdit_21->setSizePolicy(sizePolicy);
        lineEdit_21->setMinimumSize(QSize(50, 25));
        lineEdit_21->setMaximumSize(QSize(500, 25));
        lineEdit_21->setReadOnly(true);

        gridLayout->addWidget(lineEdit_21, 10, 2, 1, 2);

        label_58 = new QLabel(ModuleB);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        sizePolicy.setHeightForWidth(label_58->sizePolicy().hasHeightForWidth());
        label_58->setSizePolicy(sizePolicy);
        label_58->setMinimumSize(QSize(110, 25));
        label_58->setMaximumSize(QSize(16777215, 25));
        label_58->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_58, 6, 0, 1, 2);

        lineEdit_33 = new QLineEdit(ModuleB);
        lineEdit_33->setObjectName(QString::fromUtf8("lineEdit_33"));
        lineEdit_33->setEnabled(false);
        lineEdit_33->setMinimumSize(QSize(100, 20));
        lineEdit_33->setMaximumSize(QSize(500, 25));
        lineEdit_33->setReadOnly(true);

        gridLayout->addWidget(lineEdit_33, 4, 2, 1, 2);

        comboBox_7 = new QComboBox(ModuleB);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_7->sizePolicy().hasHeightForWidth());
        comboBox_7->setSizePolicy(sizePolicy);
        comboBox_7->setMinimumSize(QSize(30, 25));
        comboBox_7->setMaximumSize(QSize(200, 25));
        comboBox_7->setEditable(true);

        gridLayout->addWidget(comboBox_7, 2, 2, 1, 1);

        pushButton_49 = new QPushButton(ModuleB);
        pushButton_49->setObjectName(QString::fromUtf8("pushButton_49"));
        pushButton_49->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_49->sizePolicy().hasHeightForWidth());
        pushButton_49->setSizePolicy(sizePolicy);
        pushButton_49->setMinimumSize(QSize(80, 25));
        pushButton_49->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_49, 3, 0, 1, 2);

        pushButton_50 = new QPushButton(ModuleB);
        pushButton_50->setObjectName(QString::fromUtf8("pushButton_50"));
        pushButton_50->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_50->sizePolicy().hasHeightForWidth());
        pushButton_50->setSizePolicy(sizePolicy);
        pushButton_50->setMinimumSize(QSize(80, 25));
        pushButton_50->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_50, 4, 0, 1, 2);

        lineEdit_17 = new QLineEdit(ModuleB);
        lineEdit_17->setObjectName(QString::fromUtf8("lineEdit_17"));
        lineEdit_17->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_17->sizePolicy().hasHeightForWidth());
        lineEdit_17->setSizePolicy(sizePolicy);
        lineEdit_17->setMinimumSize(QSize(50, 25));
        lineEdit_17->setMaximumSize(QSize(500, 25));
        lineEdit_17->setReadOnly(true);

        gridLayout->addWidget(lineEdit_17, 6, 2, 1, 2);

        label_61 = new QLabel(ModuleB);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        sizePolicy.setHeightForWidth(label_61->sizePolicy().hasHeightForWidth());
        label_61->setSizePolicy(sizePolicy);
        label_61->setMinimumSize(QSize(110, 25));
        label_61->setMaximumSize(QSize(16777215, 25));
        label_61->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_61, 9, 0, 1, 2);

        pushButton_46 = new QPushButton(ModuleB);
        pushButton_46->setObjectName(QString::fromUtf8("pushButton_46"));
        pushButton_46->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_46->sizePolicy().hasHeightForWidth());
        pushButton_46->setSizePolicy(sizePolicy);
        pushButton_46->setMinimumSize(QSize(80, 25));
        pushButton_46->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_46, 0, 0, 1, 2);

        lineEdit_20 = new QLineEdit(ModuleB);
        lineEdit_20->setObjectName(QString::fromUtf8("lineEdit_20"));
        lineEdit_20->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_20->sizePolicy().hasHeightForWidth());
        lineEdit_20->setSizePolicy(sizePolicy);
        lineEdit_20->setMinimumSize(QSize(50, 25));
        lineEdit_20->setMaximumSize(QSize(500, 25));
        lineEdit_20->setReadOnly(true);

        gridLayout->addWidget(lineEdit_20, 9, 2, 1, 2);

        checkBox_30 = new QCheckBox(ModuleB);
        checkBox_30->setObjectName(QString::fromUtf8("checkBox_30"));
        checkBox_30->setEnabled(false);
        checkBox_30->setMinimumSize(QSize(55, 25));
        checkBox_30->setMaximumSize(QSize(300, 25));
        checkBox_30->setLayoutDirection(Qt::RightToLeft);
        checkBox_30->setChecked(true);

        gridLayout->addWidget(checkBox_30, 5, 2, 1, 1);

        pushButton_48 = new QPushButton(ModuleB);
        pushButton_48->setObjectName(QString::fromUtf8("pushButton_48"));
        pushButton_48->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_48->sizePolicy().hasHeightForWidth());
        pushButton_48->setSizePolicy(sizePolicy);
        pushButton_48->setMinimumSize(QSize(80, 25));
        pushButton_48->setMaximumSize(QSize(500, 25));

        gridLayout->addWidget(pushButton_48, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 11, 0, 1, 4);

        Blank_1 = new QLabel(ModuleB);
        Blank_1->setObjectName(QString::fromUtf8("Blank_1"));
        Blank_1->setMinimumSize(QSize(0, 25));
        Blank_1->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(Blank_1, 1, 2, 1, 2);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);

        retranslateUi(ModuleB);

        QMetaObject::connectSlotsByName(ModuleB);
    } // setupUi

    void retranslateUi(QFrame *ModuleB)
    {
        ModuleB->setWindowTitle(QCoreApplication::translate("ModuleB", "Frame", nullptr));
        comboBox_8->setItemText(0, QCoreApplication::translate("ModuleB", "Number", nullptr));
        comboBox_8->setItemText(1, QCoreApplication::translate("ModuleB", "1000", nullptr));

        comboBox_9->setItemText(0, QCoreApplication::translate("ModuleB", "Frequency", nullptr));
        comboBox_9->setItemText(1, QCoreApplication::translate("ModuleB", "2402", nullptr));
        comboBox_9->setItemText(2, QCoreApplication::translate("ModuleB", "2440", nullptr));
        comboBox_9->setItemText(3, QCoreApplication::translate("ModuleB", "2442", nullptr));
        comboBox_9->setItemText(4, QCoreApplication::translate("ModuleB", "2478", nullptr));
        comboBox_9->setItemText(5, QCoreApplication::translate("ModuleB", "2480", nullptr));

#if QT_CONFIG(whatsthis)
        lineEdit_19->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        lineEdit_19->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(whatsthis)
        lineEdit_18->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        lineEdit_18->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        label_59->setText(QCoreApplication::translate("ModuleB", "Corrupt_Package_Rx :", nullptr));
        comboBox_6->setItemText(0, QCoreApplication::translate("ModuleB", "Power", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("ModuleB", "-8", nullptr));
        comboBox_6->setItemText(2, QCoreApplication::translate("ModuleB", "-4", nullptr));
        comboBox_6->setItemText(3, QCoreApplication::translate("ModuleB", "0", nullptr));
        comboBox_6->setItemText(4, QCoreApplication::translate("ModuleB", "4", nullptr));

        label_60->setText(QCoreApplication::translate("ModuleB", "Min_RSSI :", nullptr));
        checkBox_28->setText(QCoreApplication::translate("ModuleB", "Option:", nullptr));
        label_62->setText(QCoreApplication::translate("ModuleB", "AVG_RSSI :", nullptr));
        pushButton_47->setText(QCoreApplication::translate("ModuleB", "Check Version", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("ModuleB", "Freq", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("ModuleB", "2402", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("ModuleB", "2440", nullptr));
        comboBox_5->setItemText(3, QCoreApplication::translate("ModuleB", "2442", nullptr));
        comboBox_5->setItemText(4, QCoreApplication::translate("ModuleB", "2478", nullptr));
        comboBox_5->setItemText(5, QCoreApplication::translate("ModuleB", "2480", nullptr));

#if QT_CONFIG(whatsthis)
        lineEdit_21->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        lineEdit_21->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        label_58->setText(QCoreApplication::translate("ModuleB", "Valid_Package_Rx :", nullptr));
        lineEdit_33->setPlaceholderText(QCoreApplication::translate("ModuleB", "waiting for command ...", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("ModuleB", "Length", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("ModuleB", "20", nullptr));

        pushButton_49->setText(QCoreApplication::translate("ModuleB", "Start Rx Test", nullptr));
        pushButton_50->setText(QCoreApplication::translate("ModuleB", "End Rx Test", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_17->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        lineEdit_17->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        label_61->setText(QCoreApplication::translate("ModuleB", "Max_RSSI :", nullptr));
        pushButton_46->setText(QCoreApplication::translate("ModuleB", "Help", nullptr));
#if QT_CONFIG(whatsthis)
        lineEdit_20->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        lineEdit_20->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        checkBox_30->setText(QCoreApplication::translate("ModuleB", "String:", nullptr));
        pushButton_48->setText(QCoreApplication::translate("ModuleB", "Run Tx Test", nullptr));
        Blank_1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ModuleB: public Ui_ModuleB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEB__UI__H
