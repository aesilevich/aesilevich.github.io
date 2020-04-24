#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent):
QMainWindow(parent)
{
    auto cWidget = new QWidget;
    setCentralWidget(cWidget);
    auto layout = new QVBoxLayout{cWidget};

    auto hlayout = new QHBoxLayout;
    layout->addLayout(hlayout);
    hlayout->addWidget(new QLabel("Введите имя:"));
    auto text = new QLineEdit;
    hlayout->addWidget(text);
    auto button = new QPushButton("Ok");
    button->setDefault(true);
    button->setAutoDefault(true);
    hlayout->addWidget(button);
    hlayout->addStretch(1);

    auto label = new QLabel;
    layout->addWidget(label);

    layout->addStretch(1);

    connect(button, &QPushButton::clicked, [label, text] {
        label->setText(text->text() + ", ты пидор!");
    });
}

