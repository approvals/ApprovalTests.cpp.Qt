#define APPROVALS_CATCH_EXISTING_MAIN
#include "ApprovalTests.hpp"

// Unused for now - just test that Qt is found by builds
#include <QApplication>

using namespace ApprovalTests;

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");

int main( int argc, char* argv[] )
{
    QApplication app(argc, argv);

    // your existing setup...
    int result = Catch::Session().run( argc, argv );

    // your existing clean-up...
    return result;
}
