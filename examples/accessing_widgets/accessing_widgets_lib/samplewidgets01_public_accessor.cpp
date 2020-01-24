#include "samplewidgets01_public_accessor.h"
#include "ui_samplewidgets.h"

SampleWidgets01::SampleWidgets01(QWidget* parent)
    : QGroupBox(parent), ui(new Ui::SampleWidgets)
{
    ui->setupUi(this);
}

SampleWidgets01::~SampleWidgets01()
{
    delete ui;
}

QToolButton* SampleWidgets01::goButton()
{
    return ui->goButton_;
}
