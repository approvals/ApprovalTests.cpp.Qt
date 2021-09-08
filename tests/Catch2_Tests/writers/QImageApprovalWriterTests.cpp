#include <catch2/catch.hpp>
#include "ApprovalTestsQt/ApprovalsQt.h"

using namespace ApprovalTests;
using namespace ApprovalTestsQt;

TEST_CASE("It creates an empty image")
{
    std::string receivedFile = Approvals::getDefaultNamer()->getReceivedFile(".png");
    QImageApprovalWriter::createEmptyImage(receivedFile);
    Approvals::verifyExistingFile(receivedFile);
}
