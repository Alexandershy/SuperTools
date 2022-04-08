/********************************************************************************
** Form generated from reading UI file '_itembox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _ITEMBOX__UI__H
#define _ITEMBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ItemBox
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;

    void setupUi(QFrame *ItemBox)
    {
        if (ItemBox->objectName().isEmpty())
            ItemBox->setObjectName(QString::fromUtf8("ItemBox"));
        ItemBox->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ItemBox->sizePolicy().hasHeightForWidth());
        ItemBox->setSizePolicy(sizePolicy);
        ItemBox->setMinimumSize(QSize(400, 300));
        verticalLayout = new QVBoxLayout(ItemBox);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(ItemBox);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        verticalLayout->setStretch(0, 99);

        retranslateUi(ItemBox);

        QMetaObject::connectSlotsByName(ItemBox);
    } // setupUi

    void retranslateUi(QFrame *ItemBox)
    {
        ItemBox->setWindowTitle(QCoreApplication::translate("ItemBox", "Frame", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ItemBox", "items", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ItemBox", "counts", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ItemBox", "index", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ItemBox: public Ui_ItemBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _ITEMBOX__UI__H
