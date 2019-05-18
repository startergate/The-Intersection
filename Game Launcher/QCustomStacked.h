#pragma once

#ifndef QCUSTOMSTACKED_H
#define QCUSTOMSTACKED_H
#include <QStackedWidget>

class QCustomStacked : public QStackedWidget {
	Q_OBJECT

public:
	explicit QCustomStacked(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~QCustomStacked();

public slots:
	void setGameLayer(int gameid);
};

#endif