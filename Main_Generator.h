#pragma once

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
#include <QDialog>
#include <QScrollArea>

class Main_Generator : public QWidget
{
  Q_OBJECT

public:
  int mod_x;
  int value() const { return mod_x; }

public slots:
  void generateWasClicked();
  void setValue(int);

signals:
  void valueChanged(int);
};
