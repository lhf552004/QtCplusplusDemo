#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomWidget(QWidget *parent = nullptr);

protected:
    // Override the paintEvent method for custom painting
    void paintEvent(QPaintEvent *event) override;
};

#endif // CUSTOMWIDGET_H
