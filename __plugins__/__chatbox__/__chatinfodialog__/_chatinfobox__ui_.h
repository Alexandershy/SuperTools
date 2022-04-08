/********************************************************************************
** Form generated from reading UI file '_chatinfobox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _CHATINFOBOX__UI__H
#define _CHATINFOBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChatInfoBox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QFrame *ChatInfoBox)
    {
        if (ChatInfoBox->objectName().isEmpty())
            ChatInfoBox->setObjectName(QString::fromUtf8("ChatInfoBox"));
        ChatInfoBox->resize(300, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatInfoBox->sizePolicy().hasHeightForWidth());
        ChatInfoBox->setSizePolicy(sizePolicy);
        ChatInfoBox->setMinimumSize(QSize(300, 300));
        verticalLayout = new QVBoxLayout(ChatInfoBox);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        label = new QLabel(ChatInfoBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(ChatInfoBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 99);
        verticalLayout->setStretch(1, 1);

        retranslateUi(ChatInfoBox);

        QMetaObject::connectSlotsByName(ChatInfoBox);
    } // setupUi

    void retranslateUi(QFrame *ChatInfoBox)
    {
        ChatInfoBox->setWindowTitle(QCoreApplication::translate("ChatInfoBox", "Frame", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("ChatInfoBox", "change profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatInfoBox: public Ui_ChatInfoBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _CHATINFOBOX__UI__H
