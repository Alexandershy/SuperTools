/********************************************************************************
** Form generated from reading UI file '_chatsharebox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _CHATSHAREBOX__UI__H
#define _CHATSHAREBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChatShareBox
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QFrame *ChatShareBox)
    {
        if (ChatShareBox->objectName().isEmpty())
            ChatShareBox->setObjectName(QString::fromUtf8("ChatShareBox"));
        ChatShareBox->resize(900, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChatShareBox->sizePolicy().hasHeightForWidth());
        ChatShareBox->setSizePolicy(sizePolicy);
        ChatShareBox->setMinimumSize(QSize(900, 600));
        verticalLayout = new QVBoxLayout(ChatShareBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(ChatShareBox);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setFrameShape(QFrame::NoFrame);
        treeWidget->setAlternatingRowColors(true);
        treeWidget->header()->setMinimumSectionSize(150);
        treeWidget->header()->setDefaultSectionSize(150);

        verticalLayout->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(ChatShareBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(80, 25));
        pushButton->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChatShareBox);

        QMetaObject::connectSlotsByName(ChatShareBox);
    } // setupUi

    void retranslateUi(QFrame *ChatShareBox)
    {
        ChatShareBox->setWindowTitle(QCoreApplication::translate("ChatShareBox", "Frame", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("ChatShareBox", "Vaild", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("ChatShareBox", "Hashvalue(1MBits)", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("ChatShareBox", "Creattime", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ChatShareBox", "Filesize", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ChatShareBox", "Completebasename", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ChatShareBox", "Absolutepath", nullptr));
        pushButton->setText(QCoreApplication::translate("ChatShareBox", "Add Files", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatShareBox: public Ui_ChatShareBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _CHATSHAREBOX__UI__H
