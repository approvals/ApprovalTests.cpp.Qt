#ifndef APPROVALTESTS_CPP_QT_QIMAGEAPPROVALWRITER_H
#define APPROVALTESTS_CPP_QT_QIMAGEAPPROVALWRITER_H

#include "ApprovalTestsQt/integrations/LoadApprovals.h"

#include <QImage>

namespace ApprovalTestsQt
{
    class QImageApprovalWriter : public ApprovalTests::ApprovalWriter
    {
    public:
        explicit QImageApprovalWriter(QImage image,
                                      std::string fileExtensionWithDot = ".png")
            : image_(image), fileExtensionWithDot_(fileExtensionWithDot)
        {
        }

        std::string getFileExtensionWithDot() const override
        {
            return fileExtensionWithDot_;
        }

        void write(std::string path) const override
        {
            // Have to convert std::string to QString
            image_.save(QString::fromStdString(path));
        }

        void cleanUpReceived(std::string receivedPath) const override
        {
            remove(receivedPath.c_str());
        }

        static void createEmptyImage(std::string fileName)
        {
            QImage image(1, 1, QImage::Format_ARGB32);
            image.fill(Qt::transparent);
            ApprovalTestsQt::QImageApprovalWriter image_writer(image);
            image_writer.write(fileName);
        }

    private:
        QImage image_;
        std::string fileExtensionWithDot_;
    };
} // namespace ApprovalTestsQt

#endif //APPROVALTESTS_CPP_QT_QIMAGEAPPROVALWRITER_H
