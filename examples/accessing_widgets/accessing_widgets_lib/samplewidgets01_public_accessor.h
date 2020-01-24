#ifndef APPROVALTESTS_CPP_QT_SAMPLEWIDGETS01_PUBLIC_ACCESSOR_H
#define APPROVALTESTS_CPP_QT_SAMPLEWIDGETS01_PUBLIC_ACCESSOR_H

#include <QGroupBox>
class QToolButton;

namespace Ui
{
    class SampleWidgets;
}

//! Ui::SampleWidgets is a private data member - but we provide protected accessors to widgets that we want to be tested
class SampleWidgets01 : public QGroupBox
{
    Q_OBJECT

public:
    explicit SampleWidgets01(QWidget* parent = nullptr);
    ~SampleWidgets01();

    int answer()
    {
        return 42;
    }

    QToolButton* goButton();

private:
    Ui::SampleWidgets* ui;
};

#endif //APPROVALTESTS_CPP_QT_SAMPLEWIDGETS01_PUBLIC_ACCESSOR_H
