#define APPROVALS_CATCH
#include "ApprovalTests.hpp"

// Unused for now - just test that Qt is found by builds
#include <QApplication>

using namespace ApprovalTests;

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");
