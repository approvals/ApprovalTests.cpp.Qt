#ifndef APPROVALTESTS_CPP_QT_QTABLEWIDGETWRITER_H
#define APPROVALTESTS_CPP_QT_QTABLEWIDGETWRITER_H

#include "ApprovalTests.hpp"

#include <QTableWidget>
#include <QFile>
#include <QTextStream>

namespace ApprovalTestsQt
{
    class QTableWidgetWriter : public ApprovalTests::ApprovalWriter
    {
    public:
        explicit QTableWidgetWriter(const QTableWidget& tableWidget,
            std::string fileExtensionWithDot = ".tsv")
            : tableWidget_(tableWidget),
              fileExtensionWithDot_(fileExtensionWithDot)
        {
        }

        std::string getFileExtensionWithDot() const override
        {
            return fileExtensionWithDot_;
        }

        void write(std::string path) const override
        {
            // Code adapted from https://stackoverflow.com/a/46236672/104370
            QFile file(QString::fromStdString(path));

            QString separator("\t");
            QAbstractItemModel* model = tableWidget_.model();
            if (file.open(QFile::WriteOnly | QFile::Truncate))
            {
                QTextStream data(&file);
                QStringList strList;
                for (int i = 0; i < model->columnCount(); i++)
                {
                    if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole)
                            .toString()
                            .length() > 0)
                        strList.append(
                            "\"" +
                            model->headerData(
                                     i, Qt::Horizontal, Qt::DisplayRole)
                                .toString() +
                            "\"");
                    else
                        strList.append("");
                }
                data << strList.join(separator) << "\n";
                for (int i = 0; i < model->rowCount(); i++)
                {
                    strList.clear();
                    for (int j = 0; j < model->columnCount(); j++)
                    {

                        if (model->data(model->index(i, j))
                                .toString()
                                .length() > 0)
                            strList.append(
                                "\"" +
                                model->data(model->index(i, j)).toString() +
                                "\"");
                        else
                            strList.append("");
                    }
                    data << strList.join(separator) + "\n";
                }
                file.close();
            }
        }

        void cleanUpReceived(std::string receivedPath) const override
        {
            remove(receivedPath.c_str());
        }

    private:
        const QTableWidget& tableWidget_;
        std::string fileExtensionWithDot_;
    };
} // namespace ApprovalTestsQt

#endif //APPROVALTESTS_CPP_QT_QTABLEWIDGETWRITER_H
