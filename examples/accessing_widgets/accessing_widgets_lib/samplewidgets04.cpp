#include "samplewidgets04.h"
#include "ui_samplewidgets.h"

SampleWidgets04::SampleWidgets04(QWidget* parent)
    : QGroupBox(parent), ui(new Ui::SampleWidgets)
{
    ui->setupUi(this);
}

SampleWidgets04::~SampleWidgets04()
{
    delete ui;
}

QToolButton* SampleWidgets04::goButton()
{
    return ui->goButton_;
}
