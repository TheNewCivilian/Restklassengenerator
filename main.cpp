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
    QPushButton *button_invert = new QPushButton("Invert");
    QHBoxLayout *layout_hbox01 = new QHBoxLayout;
    QHBoxLayout *layout_hbox02 = new QHBoxLayout;
    QVBoxLayout *layout_vbox01 = new QVBoxLayout;
    QVBoxLayout *layout_scrollo = new QVBoxLayout;
    Main_Generator *main_Generator = new Main_Generator();
    Canvas *canvas = new Canvas();
    QLabel *label_generator = new QLabel("Modulo value:");
    QLabel *label_zoom = new QLabel("Zoom value:");
    QWidget *scrollo_widget = new QWidget();
    QScrollArea *scrollo = new QScrollArea();

    //Definitionen
    spinBox->setRange(1,256);
    slider_generator->setRange(1,256);
    slider_zoom->setRange(1,20);
    spinBox->setValue(10);
    slider_generator->setValue(10);
    slider_zoom->setValue(1);
    main_Generator->mod_x = slider_generator->value();
    scrollo->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    scrollo->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    scrollo->setWidgetResizable( true );
    scrollo->setGeometry( 2, 2, 512, 512);

    //Definitionen_Layout
    layout_hbox01->addWidget(spinBox);
    layout_hbox01->addWidget(slider_generator);
    layout_hbox01->addWidget(button_generate);
    layout_vbox01->addWidget(label_generator);
    layout_vbox01->addLayout(layout_hbox01);
    layout_vbox01->addWidget(label_zoom);
    layout_hbox02->addWidget(button_invert);
    layout_hbox02->addWidget(slider_zoom);
    layout_vbox01->addLayout(layout_hbox02);
    layout_vbox01->addWidget(button_quit);
    window->setLayout(layout_vbox01);
    layout_scrollo->addWidget(canvas);
    scrollo_widget->setLayout(layout_scrollo);
    scrollo->setWidget(scrollo_widget);
    button_invert->setCheckable(true);

    //Connections
    QObject::connect(button_generate,SIGNAL(clicked()),main_Generator,SLOT(generateWasClicked()));
    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider_generator,SLOT(setValue(int)));
    QObject::connect(slider_generator,SIGNAL(valueChanged(int)), spinBox,SLOT(setValue(int)));
    QObject::connect(slider_generator,SIGNAL(valueChanged(int)), main_Generator,SLOT(setValue(int)));
    QObject::connect(slider_zoom,SIGNAL(valueChanged(int)), canvas,SLOT(setZoom(int)));
    QObject::connect(button_quit,SIGNAL(clicked()), &app, SLOT(quit()));
    QObject::connect(button_invert,SIGNAL(clicked()), button_invert, SLOT(on_clicked()));
    QObject::connect(button_invert,SIGNAL(clicked()), canvas, SLOT(setInvert()));
    QObject::connect(main_Generator,SIGNAL(valueChanged(int)), canvas, SLOT(setValue(int)));
    QObject::connect(main_Generator,SIGNAL(valueChanged(int)), canvas, SLOT(update()));

    //Draw Windows
    scrollo->show();
    window->show();
    return app.exec();
}
