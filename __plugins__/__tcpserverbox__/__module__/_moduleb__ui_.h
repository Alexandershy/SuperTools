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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModuleB
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;

    void setupUi(QFrame *ModuleB)
    {
        if (ModuleB->objectName().isEmpty())
            ModuleB->setObjectName(QString::fromUtf8("ModuleB"));
        ModuleB->resize(225, 222);
        verticalLayout = new QVBoxLayout(ModuleB);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(ModuleB);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(1, QString::fromUtf8("Address"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);


        retranslateUi(ModuleB);

        QMetaObject::connectSlotsByName(ModuleB);
    } // setupUi

    void retranslateUi(QFrame *ModuleB)
    {
        ModuleB->setWindowTitle(QCoreApplication::translate("ModuleB", "Frame", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ModuleB", "Port", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ModuleB", "Index", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleB: public Ui_ModuleB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEB__UI__H
