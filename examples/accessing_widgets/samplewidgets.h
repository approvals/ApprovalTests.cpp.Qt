#ifndef SAMPLEWIDGETS_H
#define SAMPLEWIDGETS_H

#include <QGroupBox>

namespace Ui {
class SampleWidgets;
}

class SampleWidgets : public QGroupBox
{
    Q_OBJECT

public:
    explicit SampleWidgets(QWidget *parent = nullptr);
    ~SampleWidgets();

private:
    Ui::SampleWidgets *ui;
};

#endif // SAMPLEWIDGETS_H
