/********************************************************************************
** Form generated from reading UI file '_hitbricksbox_.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef _HITBRICKSBOX__UI__H
#define _HITBRICKSBOX__UI__H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HitBricksBox
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QFrame *HitBricksBox)
    {
        if (HitBricksBox->objectName().isEmpty())
            HitBricksBox->setObjectName(QString::fromUtf8("HitBricksBox"));
        HitBricksBox->resize(900, 600);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HitBricksBox->sizePolicy().hasHeightForWidth());
        HitBricksBox->setSizePolicy(sizePolicy);
        HitBricksBox->setMinimumSize(QSize(900, 600));
        verticalLayout = new QVBoxLayout(HitBricksBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(HitBricksBox);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        retranslateUi(HitBricksBox);

        QMetaObject::connectSlotsByName(HitBricksBox);
    } // setupUi

    void retranslateUi(QFrame *HitBricksBox)
    {
        HitBricksBox->setWindowTitle(QCoreApplication::translate("HitBricksBox", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HitBricksBox: public Ui_HitBricksBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // _HITBRICKSBOX__UI__H
