#ifndef APPROVALTESTS_CPP_QT_SAMPLEWIDGETS00_H
#define APPROVALTESTS_CPP_QT_SAMPLEWIDGETS00_H

#include <QGroupBox>

namespace Ui
{
    class SampleWidgets;
}

//! Ui::SampleWidgets is a private data member - tests will use findChild*()
class SampleWidgets00 : public QGroupBox
{
    Q_OBJECT

public:
    explicit SampleWidgets00(QWidget* parent = nullptr);
    ~SampleWidgets00();

    int answer()
    {
        return 42;
    }

private:
    Ui::SampleWidgets* ui;
};

#endif //APPROVALTESTS_CPP_QT_SAMPLEWIDGETS00_H
