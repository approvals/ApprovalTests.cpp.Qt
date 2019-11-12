#ifndef APPROVALTESTS_CPP_QT_SAMPLEWIDGETS03_H
#define APPROVALTESTS_CPP_QT_SAMPLEWIDGETS03_H

#include <QGroupBox>
class QCheckBox;

namespace Ui
{
    class SampleWidgets;
}

//! Ui::SampleWidgets is a private data member - but we provide private accessors to widgets that we want to be tested, and make the test fixture a friend
class SampleWidgets03 : public QGroupBox
{
    Q_OBJECT

public:
    explicit SampleWidgets03(QWidget* parent = nullptr);
    ~SampleWidgets03();

private:
    friend class SampleWidgets03Fixture;
    QCheckBox* checkBox();

private:
    Ui::SampleWidgets* ui;
};

#endif //APPROVALTESTS_CPP_QT_SAMPLEWIDGETS03_H
