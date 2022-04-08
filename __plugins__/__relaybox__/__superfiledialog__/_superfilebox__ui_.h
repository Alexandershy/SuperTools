/********************************************************************************
** Form generated from reading UI file '_superfilebox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERFILEBOX__UI__H
#define _SUPERFILEBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuperFileBox
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *SuperFileBoxColor;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_9;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_10;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QComboBox *comboBox_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QComboBox *comboBox;

    void setupUi(QFrame *SuperFileBox)
    {
        if (SuperFileBox->objectName().isEmpty())
            SuperFileBox->setObjectName(QString::fromUtf8("SuperFileBox"));
        SuperFileBox->resize(900, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SuperFileBox->sizePolicy().hasHeightForWidth());
        SuperFileBox->setSizePolicy(sizePolicy);
        SuperFileBox->setMinimumSize(QSize(900, 600));
        SuperFileBox->setStyleSheet(QString::fromUtf8("QWidget#SuperFileBoxColor{background: white}"));
        horizontalLayout_2 = new QHBoxLayout(SuperFileBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(9, 9, 9, 9);
        SuperFileBoxColor = new QWidget(SuperFileBox);
        SuperFileBoxColor->setObjectName(QString::fromUtf8("SuperFileBoxColor"));
        gridLayout_2 = new QGridLayout(SuperFileBoxColor);
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        groupBox_4 = new QGroupBox(SuperFileBoxColor);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_9 = new QVBoxLayout(groupBox_4);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(9, 9, 9, 9);
        treeWidget = new QTreeWidget(groupBox_4);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setFrameShape(QFrame::NoFrame);
        treeWidget->setAutoScroll(false);
        treeWidget->setHeaderHidden(false);

        verticalLayout_9->addWidget(treeWidget);


        verticalLayout->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(SuperFileBoxColor);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_10 = new QVBoxLayout(groupBox_5);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(9, 9, 9, 9);
        treeView = new QTreeView(groupBox_5);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setFrameShape(QFrame::NoFrame);
        treeView->setAutoScroll(false);
        treeView->setHeaderHidden(true);
        treeView->header()->setVisible(false);
        treeView->header()->setStretchLastSection(false);

        verticalLayout_10->addWidget(treeView);


        verticalLayout->addWidget(groupBox_5);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, 0);
        groupBox = new QGroupBox(SuperFileBoxColor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(9, 9, 9, 9);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setMinimumSize(QSize(25, 25));
        pushButton_5->setMaximumSize(QSize(25, 25));
        pushButton_5->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setMinimumSize(QSize(25, 25));
        pushButton_7->setMaximumSize(QSize(25, 25));
        pushButton_7->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(lineEdit);

        horizontalLayout_3->setStretch(2, 6);
        horizontalLayout_3->setStretch(4, 4);

        verticalLayout_6->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::NoPen);
        tableWidget->horizontalHeader()->setMinimumSectionSize(150);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(32);
        tableWidget->verticalHeader()->setDefaultSectionSize(32);

        verticalLayout_6->addWidget(tableWidget);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 99);

        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SuperFileBoxColor);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setMinimumSize(QSize(80, 25));
        comboBox_2->setMaximumSize(QSize(16777215, 25));
        comboBox_2->setEditable(true);

        gridLayout->addWidget(comboBox_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(false);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(false);
        sizePolicy.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy);
        comboBox_3->setMinimumSize(QSize(80, 25));
        comboBox_3->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(comboBox_3, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setMinimumSize(QSize(0, 25));
        pushButton_2->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_2, 1, 3, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 25));
        pushButton_3->setMaximumSize(QSize(16777215, 25));

        gridLayout->addWidget(pushButton_3, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(188, 52, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 2, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 4);
        gridLayout->setColumnStretch(2, 3);
        gridLayout->setColumnStretch(3, 1);
        gridLayout->setColumnStretch(4, 1);

        verticalLayout_3->addWidget(groupBox_2);

        verticalLayout_3->setStretch(0, 99);
        verticalLayout_3->setStretch(1, 1);

        gridLayout_2->addLayout(verticalLayout_3, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(SuperFileBoxColor);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(30, 30));
        pushButton_4->setMaximumSize(QSize(16777215, 30));
        pushButton_4->setFlat(true);

        horizontalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(16777215, 30));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setMinimumSize(QSize(30, 30));
        pushButton_6->setMaximumSize(QSize(16777215, 30));
        pushButton_6->setFlat(true);

        horizontalLayout->addWidget(pushButton_6);

        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(80, 30));
        comboBox->setMaximumSize(QSize(16777215, 30));
        comboBox->setEditable(true);
        comboBox->setFrame(true);

        horizontalLayout->addWidget(comboBox);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 99);

        gridLayout_2->addWidget(groupBox_3, 0, 0, 1, 2);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 99);
        gridLayout_2->setColumnStretch(0, 2);
        gridLayout_2->setColumnStretch(1, 8);

        horizontalLayout_2->addWidget(SuperFileBoxColor);


        retranslateUi(SuperFileBox);

        QMetaObject::connectSlotsByName(SuperFileBox);
    } // setupUi

    void retranslateUi(QFrame *SuperFileBox)
    {
        SuperFileBox->setWindowTitle(QCoreApplication::translate("SuperFileBox", "Frame", nullptr));
        groupBox_4->setTitle(QString());
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("SuperFileBox", "Quick access", nullptr));
        groupBox_5->setTitle(QString());
        groupBox->setTitle(QString());
        pushButton_5->setText(QString());
        pushButton_7->setText(QString());
        label_2->setText(QCoreApplication::translate("SuperFileBox", "Search:  ", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("SuperFileBox", "here for search files...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SuperFileBox", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SuperFileBox", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SuperFileBox", "Creat date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SuperFileBox", "Type", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("SuperFileBox", "filename: ", nullptr));
        label_3->setText(QCoreApplication::translate("SuperFileBox", "filter: ", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SuperFileBox", "Open", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SuperFileBox", "Cancel", nullptr));
        groupBox_3->setTitle(QString());
        pushButton_4->setText(QString());
        pushButton->setText(QString());
        pushButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SuperFileBox: public Ui_SuperFileBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERFILEBOX__UI__H
