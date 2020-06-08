#include "QTreeWIDgetWindow.h"

QTreeWIDgetWindow::QTreeWIDgetWindow(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	display();
}

void QTreeWIDgetWindow::init() {
    ui.treeWidget->clear();
    QTreeWidgetItem* group1 = new QTreeWidgetItem(ui.treeWidget);
    group1->setText(0, "group1");
    group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group1->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem* subItem11 = new QTreeWidgetItem(group1);
    subItem11->setText(0,"subItem11");
	subItem11->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem11->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem* subItem12 = new QTreeWidgetItem(group1);
    subItem12->setText(0, "subItem12");
	subItem12->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem12->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem* subItem13 = new QTreeWidgetItem(group1);
	subItem13->setText(0, "subItem13");
	subItem13->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem13->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem* subItem14 = new QTreeWidgetItem(group1);
	subItem14->setText(0, "subItem14");
	subItem14->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem14->setCheckState(0, Qt::Unchecked);

	QTreeWidgetItem* group2 = new QTreeWidgetItem(ui.treeWidget);
	group2->setText(0, "group2");
	group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	group2->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem* subItem21 = new QTreeWidgetItem(group2);
	subItem21->setText(0, "subItem21");
	subItem21->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem21->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem* subItem22 = new QTreeWidgetItem(group2);
	subItem22->setText(0, "subItem22");
	subItem22->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem22->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem* subItem23 = new QTreeWidgetItem(group2);
	subItem23->setText(0, "subItem23");
	subItem23->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem23->setCheckState(0, Qt::Unchecked);
	QTreeWidgetItem* subItem24 = new QTreeWidgetItem(group2);
	subItem24->setText(0, "subItem24");
	subItem24->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	subItem24->setCheckState(0, Qt::Unchecked);
}

void QTreeWIDgetWindow::treeItemChanged(QTreeWidgetItem* item, int column) {
	QString itemText = item->text(0);
	if (Qt::Checked == item->checkState(0)) {
		QTreeWidgetItem* parent = item->parent();
		int count = item->childCount();
		if (count > 0) {
			for (int i = 0; i < count; i++) {
				item->child(i)->setCheckState(0, Qt::Checked);
			}
		}
		else {
			updateParentItem(item);
		}
	}
	else if (Qt::Unchecked == item->checkState(0)) {
		int count = item->childCount();
		if (count > 0) {
			for (int i = 0; i < count; i++) {
				item->child(i)->setCheckState(0, Qt::Unchecked);
			}
		}
		else {
			updateParentItem(item);
		}
	}
}

void QTreeWIDgetWindow::updateParentItem(QTreeWidgetItem* item) {
	QTreeWidgetItem* parent = item->parent();
	if (parent == NULL) {
		return;
	}
	int selectCount = 0;
	int childCount = parent->childCount();
	for (int i = 0; i < childCount; i++) {
		QTreeWidgetItem* childItem = parent->child(i);
		if (Qt::Checked == childItem->checkState(0)) {
			selectCount++;
		}
	}
	if (selectCount <= 0) {
		parent->setCheckState(0, Qt::Unchecked);
	
	}
	else if (selectCount > 0 && childCount > selectCount) {
		parent->setCheckState(0, Qt::PartiallyChecked);
	}
	else if (selectCount==childCount){
		parent->setCheckState(0, Qt::Checked);
	}
}

void QTreeWIDgetWindow::display() {
	init();
	connect(ui.treeWidget, SIGNAL(itemChanged()), this, SLOT(treeItemChanged()));
}