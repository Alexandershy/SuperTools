/********************************************************************************
** Form generated from reading UI file '_databox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _DATABOX__UI__H
#define _DATABOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataBox
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QSpacerItem *verticalSpacer_3;
    QProgressBar *progressBar;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_9;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_11;
    QPushButton *pushButton_8;
    QLabel *label_2;
    QPushButton *pushButton_12;
    QPushButton *pushButton_10;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QFrame *DataBox)
    {
        if (DataBox->objectName().isEmpty())
            DataBox->setObjectName(QString::fromUtf8("DataBox"));
        DataBox->resize(900, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DataBox->sizePolicy().hasHeightForWidth());
        DataBox->setSizePolicy(sizePolicy);
        DataBox->setMinimumSize(QSize(900, 600));
        verticalLayout = new QVBoxLayout(DataBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(DataBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton_13 = new QPushButton(tab);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy1);
        pushButton_13->setMinimumSize(QSize(30, 30));
        pushButton_13->setMaximumSize(QSize(30, 30));

        verticalLayout_4->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(tab);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        sizePolicy1.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy1);
        pushButton_14->setMinimumSize(QSize(30, 30));
        pushButton_14->setMaximumSize(QSize(30, 30));

        verticalLayout_4->addWidget(pushButton_14);

        pushButton_15 = new QPushButton(tab);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        sizePolicy1.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy1);
        pushButton_15->setMinimumSize(QSize(30, 30));
        pushButton_15->setMaximumSize(QSize(30, 30));
        pushButton_15->setSizeIncrement(QSize(0, 0));

        verticalLayout_4->addWidget(pushButton_15);

        pushButton_16 = new QPushButton(tab);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        sizePolicy1.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy1);
        pushButton_16->setMinimumSize(QSize(30, 30));
        pushButton_16->setMaximumSize(QSize(30, 30));

        verticalLayout_4->addWidget(pushButton_16);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setMinimumSize(QSize(30, 30));
        progressBar->setMaximumSize(QSize(30, 30));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);
        progressBar->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(progressBar);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_4);

        textEdit_2 = new QTextEdit(tab);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setFrameShape(QFrame::Box);
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_2->addWidget(textEdit_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setEnabled(false);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setMinimumSize(QSize(60, 25));
        pushButton_5->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(pushButton_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 98);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 0, -1, -1);
        pushButton_9 = new QPushButton(tab);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy1.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy1);
        pushButton_9->setMinimumSize(QSize(30, 30));
        pushButton_9->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        pushButton_9->setFont(font1);

        verticalLayout_3->addWidget(pushButton_9);

        doubleSpinBox = new QDoubleSpinBox(tab);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        sizePolicy1.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy1);
        doubleSpinBox->setMinimumSize(QSize(30, 30));
        doubleSpinBox->setMaximumSize(QSize(30, 30));
        doubleSpinBox->setWrapping(false);
        doubleSpinBox->setAlignment(Qt::AlignCenter);
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setAccelerated(true);
        doubleSpinBox->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(1.000000000000000);
        doubleSpinBox->setMaximum(100.000000000000000);
        doubleSpinBox->setSingleStep(0.500000000000000);
        doubleSpinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        doubleSpinBox->setValue(8.000000000000000);

        verticalLayout_3->addWidget(doubleSpinBox);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setStyleStrategy(QFont::PreferDefault);
        pushButton->setFont(font2);

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(30, 30));
        pushButton_2->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setStyleStrategy(QFont::PreferDefault);
        pushButton_2->setFont(font3);

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(30, 30));
        pushButton_3->setMaximumSize(QSize(30, 30));
        QFont font4;
        font4.setPointSize(16);
        font4.setUnderline(false);
        font4.setStrikeOut(false);
        font4.setKerning(true);
        font4.setStyleStrategy(QFont::PreferDefault);
        pushButton_3->setFont(font4);

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setMinimumSize(QSize(30, 30));
        pushButton_4->setMaximumSize(QSize(30, 30));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setStrikeOut(false);
        pushButton_4->setFont(font5);

        verticalLayout_3->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy1.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy1);
        pushButton_6->setMinimumSize(QSize(30, 30));
        pushButton_6->setMaximumSize(QSize(30, 16777215));
        QFont font6;
        font6.setPointSize(10);
        pushButton_6->setFont(font6);

        verticalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy1.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy1);
        pushButton_7->setMinimumSize(QSize(30, 30));
        pushButton_7->setMaximumSize(QSize(30, 16777215));

        verticalLayout_3->addWidget(pushButton_7);

        pushButton_11 = new QPushButton(tab);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        sizePolicy1.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy1);
        pushButton_11->setMinimumSize(QSize(30, 30));
        pushButton_11->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(pushButton_11);

        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);
        pushButton_8->setMinimumSize(QSize(30, 30));
        pushButton_8->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(pushButton_8);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(30, 30));
        label_2->setMaximumSize(QSize(30, 30));
        label_2->setFont(font);
        label_2->setAutoFillBackground(true);
        label_2->setTextFormat(Qt::PlainText);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        pushButton_12 = new QPushButton(tab);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        sizePolicy1.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy1);
        pushButton_12->setMinimumSize(QSize(30, 30));
        pushButton_12->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(pushButton_12);

        pushButton_10 = new QPushButton(tab);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        sizePolicy1.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy1);
        pushButton_10->setMinimumSize(QSize(30, 30));
        pushButton_10->setMaximumSize(QSize(30, 30));

        verticalLayout_3->addWidget(pushButton_10);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 98);
        horizontalLayout->setStretch(2, 1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(plainTextEdit);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(DataBox);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DataBox);
    } // setupUi

    void retranslateUi(QFrame *DataBox)
    {
        DataBox->setWindowTitle(QCoreApplication::translate("DataBox", "Frame", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_13->setToolTip(QCoreApplication::translate("DataBox", "replace format", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_13->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_14->setToolTip(QCoreApplication::translate("DataBox", "print", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_14->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_15->setToolTip(QCoreApplication::translate("DataBox", "open path", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_15->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_16->setToolTip(QCoreApplication::translate("DataBox", "search word", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_16->setText(QString());
        label->setText(QCoreApplication::translate("DataBox", "Microsoft Yahei,8,50,0,0,0,0,0", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("DataBox", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        pushButton_5->setText(QCoreApplication::translate("DataBox", "Apply", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_9->setToolTip(QCoreApplication::translate("DataBox", "family", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_9->setText(QCoreApplication::translate("DataBox", "F", nullptr));
#if QT_CONFIG(tooltip)
        doubleSpinBox->setToolTip(QCoreApplication::translate("DataBox", "size", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButton->setToolTip(QCoreApplication::translate("DataBox", "bold", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("DataBox", "B", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("DataBox", "italic", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_2->setText(QCoreApplication::translate("DataBox", "I", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_3->setToolTip(QCoreApplication::translate("DataBox", "underline", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_3->setText(QCoreApplication::translate("DataBox", "U", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_4->setToolTip(QCoreApplication::translate("DataBox", "left align", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_4->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_6->setToolTip(QCoreApplication::translate("DataBox", "right align", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_6->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_7->setToolTip(QCoreApplication::translate("DataBox", "center", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_7->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_11->setToolTip(QCoreApplication::translate("DataBox", "justify", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_11->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_8->setToolTip(QCoreApplication::translate("DataBox", "color", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_8->setText(QString());
        label_2->setText(QCoreApplication::translate("DataBox", "Color", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_12->setToolTip(QCoreApplication::translate("DataBox", "get format", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_12->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_10->setToolTip(QCoreApplication::translate("DataBox", "load picture", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_10->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DataBox", "Editor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DataBox", "Source", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataBox: public Ui_DataBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _DATABOX__UI__H
