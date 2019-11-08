#include "Catch.hpp"
#include <QImage>
#include "ApprovalTestsQt/ApprovalsQt.h"
#include "ApprovalTestsQt/comparators/QImageApprovalComparator.h"

TEST_CASE("It approves a QImage") {

    auto disposer =
            ApprovalTests::FileApprover::registerComparatorForExtension(
                    ".png",
                    std::make_shared<ApprovalTestsQt::QImageApprovalComparator>());

    // begin-snippet: verify_qimage
    QImage image(10, 20, QImage::Format_RGB32);
    image.fill(Qt::red);
    ApprovalTestsQt::verifyQImage(image);
    // end-snippet
}
