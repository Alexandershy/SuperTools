/********************************************************************************
** Form generated from reading UI file '_superfontbox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERFONTBOX__UI__H
#define _SUPERFONTBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SuperFontBox
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QLabel *label;

    void setupUi(QFrame *SuperFontBox)
    {
        if (SuperFontBox->objectName().isEmpty())
            SuperFontBox->setObjectName(QString::fromUtf8("SuperFontBox"));
        SuperFontBox->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SuperFontBox->sizePolicy().hasHeightForWidth());
        SuperFontBox->setSizePolicy(sizePolicy);
        SuperFontBox->setMinimumSize(QSize(400, 300));
        verticalLayout = new QVBoxLayout(SuperFontBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(SuperFontBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setMaximumSize(QSize(16777215, 25));
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(SuperFontBox);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        horizontalLayout->addWidget(treeWidget);

        label = new QLabel(SuperFontBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("QLabel{background:#FFFFFF;}"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SuperFontBox);

        QMetaObject::connectSlotsByName(SuperFontBox);
    } // setupUi

    void retranslateUi(QFrame *SuperFontBox)
    {
        SuperFontBox->setWindowTitle(QCoreApplication::translate("SuperFontBox", "Frame", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("SuperFontBox", "here for search font...", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("SuperFontBox", "Font", nullptr));
        label->setText(QCoreApplication::translate("SuperFontBox", "SuperTools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuperFontBox: public Ui_SuperFontBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERFONTBOX__UI__H
