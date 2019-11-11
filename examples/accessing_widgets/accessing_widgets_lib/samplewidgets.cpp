#include "samplewidgets.h"
#include "ui_samplewidgets.h"

SampleWidgets::SampleWidgets(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::SampleWidgets)
{
    ui->setupUi(this);
}

SampleWidgets::~SampleWidgets()
{
    delete ui;
}
