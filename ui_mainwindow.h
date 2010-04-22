/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 21. Apr 22:46:36 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOtw_rz_Dicom;
    QAction *actionZamknij;
    QAction *actionZako_cz;
    QAction *actionO_Programie;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuPomoc;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(447, 379);
        actionOtw_rz_Dicom = new QAction(MainWindow);
        actionOtw_rz_Dicom->setObjectName(QString::fromUtf8("actionOtw_rz_Dicom"));
        actionZamknij = new QAction(MainWindow);
        actionZamknij->setObjectName(QString::fromUtf8("actionZamknij"));
        actionZako_cz = new QAction(MainWindow);
        actionZako_cz->setObjectName(QString::fromUtf8("actionZako_cz"));
        actionO_Programie = new QAction(MainWindow);
        actionO_Programie->setObjectName(QString::fromUtf8("actionO_Programie"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(centralWidget);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(1, font1);
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignJustify|Qt::AlignVCenter);
        __qtreewidgetitem->setFont(0, font);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        font2.setStyleStrategy(QFont::PreferAntialias);
        treeWidget->setFont(font2);
        treeWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        treeWidget->setAutoFillBackground(true);
        treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        treeWidget->header()->setDefaultSectionSize(170);
        treeWidget->header()->setHighlightSections(true);
        treeWidget->header()->setMinimumSectionSize(35);

        horizontalLayout->addWidget(treeWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 447, 20));
        menuPlik = new QMenu(menuBar);
        menuPlik->setObjectName(QString::fromUtf8("menuPlik"));
        menuPomoc = new QMenu(menuBar);
        menuPomoc->setObjectName(QString::fromUtf8("menuPomoc"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlik->menuAction());
        menuBar->addAction(menuPomoc->menuAction());
        menuPlik->addAction(actionOtw_rz_Dicom);
        menuPlik->addAction(actionZamknij);
        menuPlik->addSeparator();
        menuPlik->addAction(actionZako_cz);
        menuPomoc->addAction(actionO_Programie);

        retranslateUi(MainWindow);
        QObject::connect(actionZako_cz, SIGNAL(activated()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOtw_rz_Dicom->setText(QApplication::translate("MainWindow", "Otw\303\263rz Dicom...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOtw_rz_Dicom->setToolTip(QApplication::translate("MainWindow", "Otw\303\263rz Plik Dicom", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionZamknij->setText(QApplication::translate("MainWindow", "Zamknij", 0, QApplication::UnicodeUTF8));
        actionZako_cz->setText(QApplication::translate("MainWindow", "Zako\305\204cz", 0, QApplication::UnicodeUTF8));
        actionO_Programie->setText(QApplication::translate("MainWindow", "O Programie...", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Zawarto\305\233\304\207 Tekstowa Item'u", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Grupa/Podgrupa Item'u", 0, QApplication::UnicodeUTF8));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", 0, QApplication::UnicodeUTF8));
        menuPomoc->setTitle(QApplication::translate("MainWindow", "Pomoc", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
