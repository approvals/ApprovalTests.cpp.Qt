#include <QColor>
#include <Catch.hpp>
#include "ApprovalTestsQt/integrations/catch/Catch2QtStringMaker.h"

TEST_CASE("StringMaker pretty-prints QColor")
{
    QColor red("red");
    REQUIRE(Catch::StringMaker<QColor>::convert(red) == "(1, 0, 0), alpha = 1");
}

TEST_CASE("StringMaker pretty-prints QString")
{
    QString string("Some long text\nthat spans multiple lines");
    REQUIRE(Catch::StringMaker<QString>::convert(string) ==
            "Some long text\nthat spans multiple lines");
}
