#include <catch2/catch.hpp>

#include <QString>

TEST_CASE("String::toUpper")
{
    QString str = "Hello";
    CHECK(str.toUpper() == "HELLO");
}
