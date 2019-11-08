#include <QColor>
#include <QPoint>
#include <Catch.hpp>
#include "ApprovalTestsQt/integrations/catch/Catch2QtStringMaker.h"

TEST_CASE("StringMaker pretty-prints QColor")
{
    QColor red("red");
    REQUIRE(Catch::StringMaker<QColor>::convert(red) == "(1, 0, 0), alpha = 1");
}

TEST_CASE("StringMaker pretty-prints QPoint")
{
    const QPoint point(10, 327);
    REQUIRE(Catch::StringMaker<QPoint>::convert(point) ==
            "QPoint(10,327)");
}

TEST_CASE("StringMaker pretty-prints QString")
{
    QString string("Some long text\nthat spans multiple lines");
    REQUIRE(Catch::StringMaker<QString>::convert(string) ==
            "Some long text\nthat spans multiple lines");
}
