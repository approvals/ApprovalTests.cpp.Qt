#ifndef APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H
#define APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H

#if defined(APPROVALS_CATCH_QT)

#include "ApprovalTestsQt/integrations/LoadApprovals.h"
#include <QApplication>
#include "ApprovalTestsQt/comparators/QImageApprovalComparator.h"
#include "ApprovalTestsQt/ApprovalsQt.h"

int main(int argc, char* argv[])
{
    // Any tests that create Qt widgets require a QApplication
    // to already have been created, to avoid the following message:
    //  QWidget: Must construct a QApplication before a QWidget
    // So we follow the lead of the Qt Test framework and create it in main().
    QApplication app(argc, argv);

    ApprovalTestsQt::initializeQtApprovals();

    // your existing setup...
    int result = Catch::Session().run(argc, argv);

    // your existing clean-up...
    return result;
}
#endif // APPROVALS_CATCH_QT

#endif //APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H
