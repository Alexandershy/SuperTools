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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModuleB
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_3;
    QTreeWidget *treeWidget;

    void setupUi(QFrame *ModuleB)
    {
        if (ModuleB->objectName().isEmpty())
            ModuleB->setObjectName(QString::fromUtf8("ModuleB"));
        ModuleB->resize(252, 300);
        verticalLayout = new QVBoxLayout(ModuleB);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_3 = new QLineEdit(ModuleB);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);
        lineEdit_3->setMinimumSize(QSize(80, 25));
        lineEdit_3->setMaximumSize(QSize(16777215, 25));
        lineEdit_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEdit_3);

        treeWidget = new QTreeWidget(ModuleB);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setAutoExpandDelay(-1);

        verticalLayout->addWidget(treeWidget);


        retranslateUi(ModuleB);

        QMetaObject::connectSlotsByName(ModuleB);
    } // setupUi

    void retranslateUi(QFrame *ModuleB)
    {
        ModuleB->setWindowTitle(QCoreApplication::translate("ModuleB", "Frame", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("ModuleB", "here for search contacts...", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("ModuleB", "Time", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("ModuleB", "Ipaddress", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("ModuleB", "Contacts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleB: public Ui_ModuleB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _MODULEB__UI__H
