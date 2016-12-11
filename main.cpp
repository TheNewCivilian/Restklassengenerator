#include "Main_Generator.h"
#include "canvas.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window->setWindowTitle("Restklassengenerator");

    // Dekleration der Objekte
    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider_generator = new QSlider(Qt::Horizontal);
    QSlider *slider_zoom = new QSlider(Qt::Horizontal);
    QPushButton *button_generate = new QPushButton("Generate");
    QPushButton *button_quit = new QPushButton("Quit");
    QHBoxLayout *layout_hbox01 = new QHBoxLayout;
    QVBoxLayout *layout_vbox01 = new QVBoxLayout;
    Main_Generator *main_Generator = new Main_Generator();
    Canvas *canvas = new Canvas();
    QLabel *label_generator = new QLabel("Modulo value:");
    QLabel *label_zoom = new QLabel("Zoom value:");

    //Definitionen
    spinBox->setRange(1,256);
    slider_generator->setRange(1,256);
    slider_zoom->setRange(1,10);
    spinBox->setValue(10);
    slider_generator->setValue(10);
    slider_zoom->setValue(1);
    main_Generator->mod_x = slider_generator->value();

    //Definitionen_Layout
    layout_hbox01->addWidget(spinBox);
    layout_hbox01->addWidget(slider_generator);

    layout_hbox01->addWidget(button_generate);
    layout_vbox01->addWidget(label_generator);
    layout_vbox01->addLayout(layout_hbox01);
    layout_vbox01->addWidget(label_zoom);
    layout_vbox01->addWidget(slider_zoom);
    layout_vbox01->addWidget(button_quit);
    window->setLayout(layout_vbox01);

    //Connections
    QObject::connect(button_generate,SIGNAL(clicked()),main_Generator,SLOT(generateWasClicked()));
    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider_generator,SLOT(setValue(int)));
    QObject::connect(slider_generator,SIGNAL(valueChanged(int)), spinBox,SLOT(setValue(int)));
    QObject::connect(slider_generator,SIGNAL(valueChanged(int)), main_Generator,SLOT(setValue(int)));
    QObject::connect(slider_zoom,SIGNAL(valueChanged(int)), canvas,SLOT(setZoom(int)));
    QObject::connect(button_quit,SIGNAL(clicked()), &app, SLOT(quit()));
    QObject::connect(main_Generator,SIGNAL(valueChanged(int)), canvas, SLOT(setValue(int)));
    QObject::connect(main_Generator,SIGNAL(valueChanged(int)), canvas, SLOT(update()));

    //Draw Windows
    canvas->show();
    window->show();
    return app.exec();
}
