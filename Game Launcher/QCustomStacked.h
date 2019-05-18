#pragma once

#ifndef QCUSTOMSTACKED_H
#define QCUSTOMSTACKED_H
#include <QStackedWidget>
#include <QLabel>

class QCustomStacked : public QStackedWidget {
	Q_OBJECT

public:
	explicit QCustomStacked(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~QCustomStacked();

public slots:
	void setGamePage(int gameid);
};

#endif