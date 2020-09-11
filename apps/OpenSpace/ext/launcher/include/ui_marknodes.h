/********************************************************************************
** Form generated from reading UI file 'markNodes.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKNODES_H
#define UI_MARKNODES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_markNodes
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *list;
    QPushButton *button_remove;
    QLabel *label_node;
    QLineEdit *line_node;
    QPushButton *button_add;

    void setupUi(QDialog *markNodes)
    {
        if (markNodes->objectName().isEmpty())
            markNodes->setObjectName(QString::fromUtf8("markNodes"));
        markNodes->resize(295, 335);
        buttonBox = new QDialogButtonBox(markNodes);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 290, 251, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        list = new QListWidget(markNodes);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 10, 271, 120));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(list->sizePolicy().hasHeightForWidth());
        list->setSizePolicy(sizePolicy);
        list->setMinimumSize(QSize(0, 50));
        list->setMaximumSize(QSize(16777215, 120));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        list->setFont(font);
        list->setAlternatingRowColors(true);
        list->setMovement(QListView::Free);
        list->setResizeMode(QListView::Adjust);
        button_remove = new QPushButton(markNodes);
        button_remove->setObjectName(QString::fromUtf8("button_remove"));
        button_remove->setGeometry(QRect(10, 140, 111, 25));
        label_node = new QLabel(markNodes);
        label_node->setObjectName(QString::fromUtf8("label_node"));
        label_node->setGeometry(QRect(10, 190, 131, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        label_node->setFont(font1);
        line_node = new QLineEdit(markNodes);
        line_node->setObjectName(QString::fromUtf8("line_node"));
        line_node->setGeometry(QRect(10, 210, 271, 25));
        button_add = new QPushButton(markNodes);
        button_add->setObjectName(QString::fromUtf8("button_add"));
        button_add->setGeometry(QRect(10, 240, 111, 25));

        retranslateUi(markNodes);
        QObject::connect(buttonBox, SIGNAL(accepted()), markNodes, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), markNodes, SLOT(reject()));

        QMetaObject::connectSlotsByName(markNodes);
    } // setupUi

    void retranslateUi(QDialog *markNodes)
    {
        markNodes->setWindowTitle(QCoreApplication::translate("markNodes", "Mark Interesting Nodes", nullptr));
        button_remove->setText(QCoreApplication::translate("markNodes", "Remove", nullptr));
        label_node->setText(QCoreApplication::translate("markNodes", "Node to add:", nullptr));
#if QT_CONFIG(tooltip)
        line_node->setToolTip(QCoreApplication::translate("markNodes", "<html><head/><body><p>Name of scenegraph node to add to list of &quot;interesting&quot; nodes</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        button_add->setText(QCoreApplication::translate("markNodes", "Add New", nullptr));
    } // retranslateUi

};

namespace Ui {
    class markNodes: public Ui_markNodes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKNODES_H