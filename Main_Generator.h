#ifndef MAIN_GENERTOR_H_INCLUDED   // if x.h hasn't been included yet...
#define MAIN_GENERATOR_H_INCLUDED   //   #define this so the compiler knows it has been included

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

class Main_Generator : public QWidget
{
  Q_OBJECT
public:
  int mod_x;
  //Main_Generator();

public slots:
  void generateWasClicked();
};

#endif
