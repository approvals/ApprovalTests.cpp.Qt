#ifndef APPROVALTESTS_CPP_QT_APPROVALSQT_H
#define APPROVALTESTS_CPP_QT_APPROVALSQT_H

#include "ApprovalTestsQt/integrations/LoadApprovals.h"
#include "ApprovalTestsQt/writers/QImageApprovalWriter.h"
#include "ApprovalTestsQt/writers/QTableViewWriter.h"
#include "ApprovalTestsQt/comparators/QImageApprovalComparator.h"
#include "EmptyFileCreatorByType.h"

namespace ApprovalTestsQt
{

    inline void initializeQtApprovals()
    {
        // When comparing PNG files, get Qt to read the two image files and
        // compare the QImage objects, instead of using the built-in
        // character-based file comparison, which may fail for two
        // exactly equivalent .png files.
        static auto pngComparatorDisposer =
            ApprovalTests::FileApprover::registerComparatorForExtension(
                ".png", std::make_shared<ApprovalTestsQt::QImageApprovalComparator>());

        ApprovalTests::EmptyFileCreator pngCreator = [](std::string fileName)
        {
            QImage image(1, 1, QImage::Format_ARGB32);
            image.fill(Qt::transparent);
            ApprovalTestsQt::QImageApprovalWriter image_writer(image);
            image_writer.write(fileName);
        };
        ApprovalTestsQt::EmptyFileCreatorByType::registerCreator(".png", pngCreator);

        static auto disposer = ApprovalTests::FileUtils::useEmptyFileCreator(
            EmptyFileCreatorByType::createFile);
    }

    inline void
    verifyQImage(const QImage& image,
                 const ApprovalTests::Options& options = ApprovalTests::Options())
    {
        QImageApprovalWriter image_writer(image);
        ApprovalTests::Approvals::verify(image_writer, options);
    }

    inline void
    verifyQTableView(const QTableView& tableWidget,
                     const ApprovalTests::Options& options = ApprovalTests::Options())
    {
        QTableViewWriter table_writer(tableWidget);
        ApprovalTests::Approvals::verify(table_writer, options);
    }
} // namespace ApprovalTestsQt

#endif //APPROVALTESTS_CPP_QT_APPROVALSQT_H
