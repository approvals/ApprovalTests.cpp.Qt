#ifndef APPROVALTESTS_CPP_QT_LOADAPPROVALS_H
#define APPROVALTESTS_CPP_QT_LOADAPPROVALS_H

// Never #include "ApprovalTests.hpp" directly in this project:
// #include "ApprovalTestsQt/integrations/LoadApprovals.h" instead

// <SingleHpp unalterable>
#if defined(APPROVALS_CATCH_QT)
#define CATCH_CONFIG_RUNNER
#include <Catch.hpp>
#define APPROVALS_CATCH_EXISTING_MAIN
#endif

#include "ApprovalTests.hpp"
// </SingleHpp>

#endif //APPROVALTESTS_CPP_QT_LOADAPPROVALS_H
