#include "Catch.hpp"
#include <QImage>
#include <QTableWidget>
#include "ApprovalTestsQt/ApprovalsQt.h"

TEST_CASE("It approves a QImage")
{
    // begin-snippet: verify_qimage
    QImage image(10, 20, QImage::Format_RGB32);
    image.fill(Qt::red);
    ApprovalTestsQt::verifyQImage(image);
    // end-snippet
}

TEST_CASE("It approves a QTableWidget")
{
    QTableWidget tableWidget;
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
    ApprovalTestsQt::verifyQTableWidget(tableWidget);
}
