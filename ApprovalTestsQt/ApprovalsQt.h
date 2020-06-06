#ifndef APPROVALTESTS_CPP_QT_APPROVALSQT_H
#define APPROVALTESTS_CPP_QT_APPROVALSQT_H

#include "ApprovalTestsQt/integrations/LoadApprovals.h"
#include "ApprovalTestsQt/writers/QImageApprovalWriter.h"
#include "ApprovalTestsQt/writers/QTableViewWriter.h"

namespace ApprovalTestsQt
{
    inline void verifyQImage(
        const QImage& image,
        const ApprovalTests::Reporter& reporter = ApprovalTests::DiffReporter())
    {
        QImageApprovalWriter image_writer(image);
        ApprovalTests::Approvals::verify(image_writer,
                                         ApprovalTests::Options(reporter));
    }

    inline void verifyQTableView(
        const QTableView& tableWidget,
        const ApprovalTests::Reporter& reporter = ApprovalTests::DiffReporter())
    {
        QTableViewWriter table_writer(tableWidget);
        ApprovalTests::Approvals::verify(table_writer,
                                         ApprovalTests::Options(reporter));
    }
} // namespace ApprovalTestsQt

#endif //APPROVALTESTS_CPP_QT_APPROVALSQT_H
