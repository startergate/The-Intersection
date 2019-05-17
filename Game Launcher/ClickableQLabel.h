#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
	Q_OBJECT

public:
	explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~ClickableLabel();
	int target;

signals:
	void clicked(int);
	void changeStackedWidgetIndex(int);

protected:
	void mousePressEvent(QMouseEvent* event);

};

#endif // CLICKABLELABEL_H