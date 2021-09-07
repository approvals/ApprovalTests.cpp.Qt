#include <catch2/catch.hpp>
#include <QImage>
#include <QTableWidget>
#include <utility>
#include "ApprovalTestsQt/ApprovalsQt.h"

namespace
{
    void populateTable(QTableWidget& tableWidget)
    {
        const int rows = 2;
        const int columns = 3;
        tableWidget.setRowCount(rows);
        tableWidget.setColumnCount(columns);
        tableWidget.setHorizontalHeaderLabels(QStringList() << "Column 1"
                                                            << "Column 2"
                                                            << "Column 3");
        for (int i = 0; i != rows; ++i)
        {
            for (int j = 0; j != columns; ++j)
            {
                tableWidget.setItem(
                    i, j, new QTableWidgetItem(QString::number((i + 1) * (j + 1))));
            }
        }
    }
} // namespace

TEST_CASE("It approves a QImage")
{
    auto approved = ApprovalTests::Approvals::getDefaultNamer()->getApprovedFile(".png");
    //    remove(approved.c_str());

    // begin-snippet: verify_qimage
    QImage image(10, 20, QImage::Format_RGB32);
    image.fill(Qt::red);
    ApprovalTestsQt::verifyQImage(
        image, ApprovalTests::Options(ApprovalTests::Mac::BeyondCompareReporter()));
    // end-snippet
}

TEST_CASE("It approves a QTableWidget")
{
    // A note on naming: QTableWidget is a concrete class that implements
    // the more general QTableView. Here we create a QTableWidget,
    // for convenience.

    // begin-snippet: verify_table_view
    QTableWidget tableWidget;
    populateTable(tableWidget);
    ApprovalTestsQt::verifyQTableView(tableWidget);
    // end-snippet
}
