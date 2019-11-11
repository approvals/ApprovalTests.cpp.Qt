#ifndef APPROVALTESTS_CPP_QT_samplewidgets02_H
#define APPROVALTESTS_CPP_QT_samplewidgets02_H

#include <QGroupBox>
class QCheckBox;

namespace Ui {
class SampleWidgets;
}

//! Ui::SampleWidgets is a private data member - but we provide protected accessors to widgets that we want to be tested
class SampleWidgets02 : public QGroupBox
{
    Q_OBJECT

public:
    explicit SampleWidgets02(QWidget *parent = nullptr);
    ~SampleWidgets02();

protected:
    QCheckBox* checkBox();

private:
    Ui::SampleWidgets *ui;
};

#endif //APPROVALTESTS_CPP_QT_samplewidgets02_H
