#ifndef APPROVALTESTS_CPP_QT_QIMAGEAPPROVALCOMPARATOR_H
#define APPROVALTESTS_CPP_QT_QIMAGEAPPROVALCOMPARATOR_H

#include "ApprovalTestsQt/integrations/catch/LoadApprovals.h"
#include <QImage>

namespace ApprovalTestsQt
{
    class QImageApprovalComparator : public ApprovalTests::ApprovalComparator
    {
    public:
        bool contentsAreEquivalent(
            std::string receivedPath, std::string approvedPath) const override
        {
            const QImage receivedImage(QString::fromStdString(receivedPath));
            const QImage approvedImage(QString::fromStdString(approvedPath));
            return receivedImage == approvedImage;
        }
    };
} // namespace ApprovalTestsQt

#endif //APPROVALTESTS_CPP_QT_QIMAGEAPPROVALCOMPARATOR_H
