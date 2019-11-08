#ifndef APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H
#define APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H

#if defined(APPROVALS_CATCH_QT)

#define APPROVALS_CATCH_EXISTING_MAIN
#include "ApprovalTests.hpp"
#include <QApplication>

int main( int argc, char* argv[] )
{
    // Any tests that creation of Qt widgets requires a QApplication
    // to already have been created, so we follow the lead of the
    // Qt Test framework and create it in main().
    QApplication app(argc, argv);

    // your existing setup...
    int result = Catch::Session().run( argc, argv );

    // your existing clean-up...
    return result;
}

#endif

#endif //APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H
