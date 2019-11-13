#include "samplewidgets00.h"
#include "ui_samplewidgets.h"

SampleWidgets00::SampleWidgets00(QWidget* parent)
    : QGroupBox(parent), ui(new Ui::SampleWidgets)
{
    ui->setupUi(this);
}

SampleWidgets00::~SampleWidgets00()
{
    delete ui;
}
