#pragma once

#include <QStackedWidget>

class QCustomStacked : public QStackedWidget {
	explicit QCustomStacked(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~QCustomStacked();


};