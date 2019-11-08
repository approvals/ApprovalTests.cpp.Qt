#ifndef APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H
#define APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H

#if defined(APPROVALS_CATCH_QT)

#define APPROVALS_CATCH_EXISTING_MAIN
#include "ApprovalTests.hpp"
#include <QApplication>

int main( int argc, char* argv[] )
{
    // Any tests that creation of Qt widgets requires a QApplication
    // to already have been created, so we follow the lead of the
    // Qt Test framework and create it in main().
    QApplication app(argc, argv);

    // your existing setup...
    int result = Catch::Session().run( argc, argv );

    // your existing clean-up...
    return result;
}
#endif // APPROVALS_CATCH_QT

#ifdef CATCH_VERSION_MAJOR
#include <QColor>
#include <QStringBuilder>
namespace Catch {
template <> struct StringMaker<QColor> {
    static std::string convert(QColor const& color) {
        // clang-format off
        const QString result = "(" %
                               QString::number(color.redF()) % ", " %
                               QString::number(color.greenF()) % ", " %
                               QString::number(color.blueF()) %
                               "), alpha = " %
                               QString::number(color.alphaF(), 'g', 20);
        // clang-format on
        return result.toStdString();
    }
};
}
#endif // CATCH_VERSION_MAJOR

#endif //APPROVALTESTS_CPP_QT_CATCH2QTAPPROVALS_H
