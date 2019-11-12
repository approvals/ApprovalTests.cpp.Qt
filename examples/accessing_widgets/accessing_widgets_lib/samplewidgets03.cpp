#include "samplewidgets03.h"
#include "ui_samplewidgets.h"

SampleWidgets03::SampleWidgets03(QWidget* parent)
    : QGroupBox(parent), ui(new Ui::SampleWidgets)
{
    ui->setupUi(this);
}

SampleWidgets03::~SampleWidgets03()
{
    delete ui;
}

QToolButton* SampleWidgets03::goButton()
{
    return ui->goButton_;
}
