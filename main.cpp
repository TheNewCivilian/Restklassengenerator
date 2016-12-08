#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>

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

    //Definitionen
    spinBox->setRange(0,130);
    slider->setRange(0,130);
    spinBox->setValue(35);
    slider->setValue(35);

    //Definitionen_Layout
    layout_hbox01->addWidget(spinBox);
    layout_hbox01->addWidget(slider);
    layout_hbox01->addWidget(button_generate);
    layout_vbox01->addLayout(layout_hbox01);
    layout_vbox01->addWidget(button_quit);
    window->setLayout(layout_vbox01);

    //Connections
    QObject::connect(button_generate,SIGNAL(clicked()), &app, SLOT(quit()));
    QObject::connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)), spinBox,SLOT(setValue(int)));
    QObject::connect(button_quit,SIGNAL(clicked()), &app, SLOT(quit()));
    //QLabel *label = new QLabel("Hello Qt!");

    window->show();
    return app.exec();
}
