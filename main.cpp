#include "Main_Generator.h"

class MyWidget : public QWidget
{
public:
    MyWidget();

protected:
    void paintEvent(QPaintEvent *);
};

MyWidget::MyWidget()
{
    QPalette palette(MyWidget::palette());
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);
    // x,y,with,height
    painter.drawRect(1, 1, 10, 10);

    QRect rect = QRect(10, 10, 45, 20);
    painter.drawText(rect, Qt::AlignCenter,"123");
    //RgB(r,g,b)
    painter.fillRect(rect,qRgb(232,121,10));
    painter.setPen(Qt::darkGray);
    painter.drawLine(2, 8, 6, 2);
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Restklassengenerator");

    // Dekleration der Objekte
    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    QPushButton *button_generate = new QPushButton("Generate");
    QPushButton *button_quit = new QPushButton("Quit");
    QHBoxLayout *layout_hbox01 = new QHBoxLayout;
    QVBoxLayout *layout_vbox01 = new QVBoxLayout;
    Main_Generator *main_Generator = new Main_Generator();

    //Definitionen
    spinBox->setRange(0,130);
    slider->setRange(0,130);
    spinBox->setValue(35);
    slider->setValue(35);
    main_Generator->mod_x = slider->value();

    //Definitionen_Layout
    layout_hbox01->addWidget(spinBox);
    layout_hbox01->addWidget(slider);
    layout_hbox01->addWidget(button_generate);
    layout_vbox01->addLayout(layout_hbox01);
    layout_vbox01->addWidget(button_quit);
    window->setLayout(layout_vbox01);

    //Connections
    QObject::connect(button_generate,SIGNAL(clicked()),main_Generator,SLOT(generateWasClicked()));
    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)), spinBox,SLOT(setValue(int)));
    QObject::connect(button_quit,SIGNAL(clicked()), &app, SLOT(quit()));

    MyWidget widget;
    window->show();
    widget.show();
    return app.exec();
}
