#include "Catch.hpp"
#include <QImage>
#include "ApprovalTestsQt/ApprovalsQt.h"

TEST_CASE("It approves a QImage") {
    QImage image(10, 20, QImage::Format_RGB32);
    image.fill(Qt::red);
    ApprovalTestsQt::verifyQImage(image);
}
