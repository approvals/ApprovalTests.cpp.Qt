#ifndef APPROVALTESTS_CPP_QT_SAMPLEWIDGETS04_H
#define APPROVALTESTS_CPP_QT_SAMPLEWIDGETS04_H

#include <QGroupBox>
class QToolButton;

namespace Ui
{
    class SampleWidgets;
}

//! Ui::SampleWidgets is a private data member - but we provide private accessors to widgets that we want to be tested, and make the test fixture a friend
class SampleWidgets04 : public QGroupBox
{
    Q_OBJECT

public:
    explicit SampleWidgets04(QWidget* parent = nullptr);
    ~SampleWidgets04();

private:
    friend class SampleWidgets04Fixture;
    QToolButton* goButton();

private:
    Ui::SampleWidgets* ui;
};

#endif //APPROVALTESTS_CPP_QT_SAMPLEWIDGETS04_H
