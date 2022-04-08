/********************************************************************************
** Form generated from reading UI file '_pathlossbox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _PATHLOSSBOX__UI__H
#define _PATHLOSSBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PathLossBox
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;

    void setupUi(QFrame *PathLossBox)
    {
        if (PathLossBox->objectName().isEmpty())
            PathLossBox->setObjectName(QString::fromUtf8("PathLossBox"));
        PathLossBox->resize(700, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PathLossBox->sizePolicy().hasHeightForWidth());
        PathLossBox->setSizePolicy(sizePolicy);
        PathLossBox->setMinimumSize(QSize(700, 300));
        verticalLayout = new QVBoxLayout(PathLossBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(PathLossBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(0, 25));
        pushButton_2->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(PathLossBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(0, 25));
        pushButton_4->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_7 = new QPushButton(PathLossBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setMinimumSize(QSize(0, 25));
        pushButton_7->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(pushButton_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(PathLossBox);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

        horizontalLayout->addWidget(treeWidget);

        tableWidget = new QTableWidget(PathLossBox);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout->addWidget(tableWidget);

        tableWidget_2 = new QTableWidget(PathLossBox);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        if (tableWidget_2->rowCount() < 3)
            tableWidget_2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        tableWidget_2->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        tableWidget_2->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidget_2->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        tableWidget_2->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        tableWidget_2->setItem(2, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        tableWidget_2->setItem(2, 1, __qtablewidgetitem12);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout->addWidget(tableWidget_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PathLossBox);

        QMetaObject::connectSlotsByName(PathLossBox);
    } // setupUi

    void retranslateUi(QFrame *PathLossBox)
    {
        PathLossBox->setWindowTitle(QCoreApplication::translate("PathLossBox", "Frame", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PathLossBox", "Load", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PathLossBox", "Save", nullptr));
        pushButton_7->setText(QCoreApplication::translate("PathLossBox", "Refresh", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("PathLossBox", "Datasize", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("PathLossBox", "Pathlossconfig", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PathLossBox", "Frequency(mhz)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PathLossBox", "Correction(db)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PathLossBox", "Port Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("PathLossBox", "Loss Config", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("PathLossBox", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("PathLossBox", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("PathLossBox", "3", nullptr));

        const bool __sortingEnabled = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->item(0, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("PathLossBox", "VSA1: RF1A", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->item(1, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("PathLossBox", "VSG1: RF1A", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->item(2, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("PathLossBox", "VSG1: RF2A", nullptr));
        tableWidget_2->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class PathLossBox: public Ui_PathLossBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _PATHLOSSBOX__UI__H
