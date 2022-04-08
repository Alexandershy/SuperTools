/********************************************************************************
** Form generated from reading UI file '_audioformatbox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _AUDIOFORMATBOX__UI_H
#define _AUDIOFORMATBOX__UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AudioFormatBox
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QFrame *AudioFormatBox)
    {
        if (AudioFormatBox->objectName().isEmpty())
            AudioFormatBox->setObjectName(QString::fromUtf8("AudioFormatBox"));
        AudioFormatBox->resize(300, 100);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AudioFormatBox->sizePolicy().hasHeightForWidth());
        AudioFormatBox->setSizePolicy(sizePolicy);
        AudioFormatBox->setMinimumSize(QSize(300, 100));
        verticalLayout = new QVBoxLayout(AudioFormatBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        comboBox = new QComboBox(AudioFormatBox);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(comboBox, 0, 0, 1, 1);

        checkBox = new QCheckBox(AudioFormatBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        gridLayout_2->addWidget(checkBox, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(AudioFormatBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AudioFormatBox);

        QMetaObject::connectSlotsByName(AudioFormatBox);
    } // setupUi

    void retranslateUi(QFrame *AudioFormatBox)
    {
        AudioFormatBox->setWindowTitle(QCoreApplication::translate("AudioFormatBox", "Frame", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("AudioFormatBox", ".wav", nullptr));

        checkBox->setText(QCoreApplication::translate("AudioFormatBox", "local path", nullptr));
        pushButton->setText(QCoreApplication::translate("AudioFormatBox", "Convert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioFormatBox: public Ui_AudioFormatBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _AUDIOFORMATBOX__UI_H
