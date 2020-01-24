#ifndef APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H
#define APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H

#if defined(APPROVALS_CATCH_QT)

#include "ApprovalTestsQt/integrations/LoadApprovals.h"
#include <QApplication>
#include <QApplication>
#include "ApprovalTestsQt/comparators/QImageApprovalComparator.h"

int main(int argc, char* argv[])
{
    // Any tests that create Qt widgets require a QApplication
    // to already have been created, to avoid the following message:
    //  QWidget: Must construct a QApplication before a QWidget
    // So we follow the lead of the Qt Test framework and create it in main().
    QApplication app(argc, argv);

    // When comparing PNG files, get Qt to read the two image files and
    // compare the QImage objects, instead of using the built-in
    // character-based file comparison, which may fail for two
    // exactly equivalent .png files.
    auto pngComparatorDisposer =
        ApprovalTests::FileApprover::registerComparatorForExtension(
            ".png",
            std::make_shared<ApprovalTestsQt::QImageApprovalComparator>());

    // your existing setup...
    int result = Catch::Session().run(argc, argv);

    // your existing clean-up...
    return result;
}
#endif // APPROVALS_CATCH_QT

#endif //APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H
