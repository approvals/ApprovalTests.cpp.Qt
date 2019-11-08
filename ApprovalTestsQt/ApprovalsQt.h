#ifndef APPROVALTESTS_CPP_QT_APPROVALSQT_H
#define APPROVALTESTS_CPP_QT_APPROVALSQT_H

#include "ApprovalTests.hpp"
#include "ApprovalTestsQt/writers/QImageApprovalWriter.h"
#include "ApprovalTestsQt/writers/QTableWidgetWriter.h"

namespace ApprovalTestsQt
{
    void verifyQImage(const QImage& image,
        const ApprovalTests::Reporter& reporter = ApprovalTests::DiffReporter())
    {
        QImageApprovalWriter image_writer(image);
        ApprovalTests::Approvals::verify(image_writer, reporter);
    }

    void verifyQTableWidget(const QTableWidget& tableWidget,
        const ApprovalTests::Reporter& reporter = ApprovalTests::DiffReporter())
    {
        QTableWidgetWriter table_writer(tableWidget);
        ApprovalTests::Approvals::verify(table_writer, reporter);
    }
} // namespace ApprovalTestsQt

#endif //APPROVALTESTS_CPP_QT_APPROVALSQT_H
