#include <QApplication>
#include "samplewidgets.h"
int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    SampleWidgets01 sampleWidgets;
    sampleWidgets.show();
    sampleWidgets.raise();

    return app.exec();
}
