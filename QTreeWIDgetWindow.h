#pragma once

#include <QtWidgets/QWidget>
#include <QTreeWidgetItem>
#include "ui_QTreeWIDgetWindow.h"
#ifdef WIN32
#pragma exection_character_ser("utf-8")
#endif // WIN32


class QTreeWIDgetWindow : public QWidget
{
    Q_OBJECT

public:
    QTreeWIDgetWindow(QWidget *parent = Q_NULLPTR);
    void init();
    void updateParentItem(QTreeWidgetItem* item);
    void display();
private slots:
    void treeItemChanged(QTreeWidgetItem* item, int column);
private:
    Ui::QTreeWIDgetWindowClass ui;
};
