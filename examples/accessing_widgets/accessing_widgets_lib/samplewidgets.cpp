#include "samplewidgets.h"
#include "ui_samplewidgets.h"

SampleWidgets01::SampleWidgets01(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::SampleWidgets01)
{
    ui->setupUi(this);
}

SampleWidgets01::~SampleWidgets01()
{
    delete ui;
}
