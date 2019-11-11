#include "samplewidgets02.h"
#include "ui_samplewidgets.h"

SampleWidgets02::SampleWidgets02(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::SampleWidgets)
{
    ui->setupUi(this);
}

SampleWidgets02::~SampleWidgets02()
{
    delete ui;
}

QCheckBox* SampleWidgets02::checkBox() { return ui->checkBox1; }
