/********************************************************************************
** Form generated from reading UI file '_superwindow_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _SUPERWINDOW__UI__H
#define _SUPERWINDOW__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SuperWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *TitleBox;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *Titlelayout;
    QGroupBox *PluginBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *Pluginlayout;

    void setupUi(QWidget *SuperWindow)
    {
        if (SuperWindow->objectName().isEmpty())
            SuperWindow->setObjectName(QString::fromUtf8("SuperWindow"));
        SuperWindow->setWindowModality(Qt::NonModal);
        SuperWindow->setEnabled(true);
        SuperWindow->resize(94, 32);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SuperWindow->sizePolicy().hasHeightForWidth());
        SuperWindow->setSizePolicy(sizePolicy);
        SuperWindow->setMinimumSize(QSize(0, 0));
        QFont font;
        SuperWindow->setFont(font);
        SuperWindow->setMouseTracking(false);
        SuperWindow->setLayoutDirection(Qt::LeftToRight);
        SuperWindow->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(SuperWindow);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TitleBox = new QGroupBox(SuperWindow);
        TitleBox->setObjectName(QString::fromUtf8("TitleBox"));
        horizontalLayout_4 = new QHBoxLayout(TitleBox);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Titlelayout = new QHBoxLayout();
        Titlelayout->setSpacing(5);
        Titlelayout->setObjectName(QString::fromUtf8("Titlelayout"));

        horizontalLayout_4->addLayout(Titlelayout);


        verticalLayout->addWidget(TitleBox);

        PluginBox = new QGroupBox(SuperWindow);
        PluginBox->setObjectName(QString::fromUtf8("PluginBox"));
        PluginBox->setMouseTracking(false);
        PluginBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(PluginBox);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        Pluginlayout = new QHBoxLayout();
        Pluginlayout->setSpacing(0);
        Pluginlayout->setObjectName(QString::fromUtf8("Pluginlayout"));
        Pluginlayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addLayout(Pluginlayout);

        verticalLayout_2->setStretch(0, 99);

        verticalLayout->addWidget(PluginBox);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 99);

        retranslateUi(SuperWindow);

        QMetaObject::connectSlotsByName(SuperWindow);
    } // setupUi

    void retranslateUi(QWidget *SuperWindow)
    {
        SuperWindow->setWindowTitle(QCoreApplication::translate("SuperWindow", "SuperTools", nullptr));
#if QT_CONFIG(tooltip)
        SuperWindow->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        TitleBox->setTitle(QString());
        PluginBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class SuperWindow: public Ui_SuperWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _SUPERWINDOW__UI__H
