#ifndef SAMPLEWIDGETS_H
#define SAMPLEWIDGETS_H

#include <QGroupBox>

namespace Ui {
class SampleWidgets;
}

//! Ui::SampleWidgets is a private data member - tests will use findChild*()
class SampleWidgets01 : public QGroupBox
{
    Q_OBJECT

public:
    explicit SampleWidgets01(QWidget *parent = nullptr);
    ~SampleWidgets01();

private:
    Ui::SampleWidgets *ui;
};

#endif // SAMPLEWIDGETS_H
