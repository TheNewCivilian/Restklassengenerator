#ifndef CANVAS_H_INCLUDED   // if x.h hasn't been included yet...
#define CANVAS_H_INCLUDED   //   #define this so the compiler knows it has been included
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPainter>
#include <QPixmap>
#include <QtGui>
#include <QMainWindow>
#include <QWidget>
#include <stdio.h>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    Canvas();
    int mod_wx;
    QRect rect[65536];
    int mod_info[65536];
    int zoom;
    int invert;

public slots:
  void setValue(int);
  void setZoom(int);
  void setInvert();
protected:
    void paintEvent(QPaintEvent *);
};


#endif
