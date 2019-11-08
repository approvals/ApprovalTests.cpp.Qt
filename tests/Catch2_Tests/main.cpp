// begin-snippet: catch_2_qt_main
// main.cpp:
#define APPROVALS_CATCH_QT
#include "ApprovalTestsQt/integrations/catch/Catch2QtApprovals.h"
// end-snippet

using namespace ApprovalTests;

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");
