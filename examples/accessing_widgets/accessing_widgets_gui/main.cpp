#include <QApplication>
#include "samplewidgets00.h"
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    SampleWidgets00 sampleWidgets;
    sampleWidgets.show();
    sampleWidgets.raise();

    return app.exec();
}
