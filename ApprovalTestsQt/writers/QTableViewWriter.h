#ifndef APPROVALTESTS_CPP_QT_QTABLEVIEWWRITER_H
#define APPROVALTESTS_CPP_QT_QTABLEVIEWWRITER_H

#include "ApprovalTestsQt/integrations/LoadApprovals.h"

#include <QTableView>
#include <QFile>
#include <QTextStream>

namespace ApprovalTestsQt
{
    class QTableViewWriter : public ApprovalTests::ApprovalWriter
    {
    public:
        explicit QTableViewWriter(const QTableView& tableView,
                                  std::string fileExtensionWithDot = ".tsv")
            : tableView_(tableView), fileExtensionWithDot_(fileExtensionWithDot)
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
            QAbstractItemModel* model = tableView_.model();
            if (file.open(QFile::WriteOnly | QFile::Truncate))
            {
                QTextStream data(&file);
                QStringList strList;
                for (int i = 0; i < model->columnCount(); i++)
                {
                    QVariant variant =
                        model->headerData(i, Qt::Horizontal, Qt::DisplayRole);
                    strList.append(quoteString(variant));
                }
                data << strList.join(separator) << "\n";
                for (int i = 0; i < model->rowCount(); i++)
                {
                    strList.clear();
                    for (int j = 0; j < model->columnCount(); j++)
                    {
                        QVariant variant = model->data(model->index(i, j));
                        strList.append(quoteString(variant));
                    }
                    data << strList.join(separator) + "\n";
                }
                file.close();
            }
            else
            {
                throw std::runtime_error("Unable to table write to file " +
                                         path);
            }
        }

        void cleanUpReceived(std::string receivedPath) const override
        {
            remove(receivedPath.c_str());
        }

    private:
        QString quoteString(const QVariant& data) const
        {
            if (data.toString().length() > 0)
                return "\"" + data.toString() + "\"";
            else
                return "";
        }

    private:
        const QTableView& tableView_;
        std::string fileExtensionWithDot_;
    };
} // namespace ApprovalTestsQt

#endif //APPROVALTESTS_CPP_QT_QTABLEVIEWWRITER_H
