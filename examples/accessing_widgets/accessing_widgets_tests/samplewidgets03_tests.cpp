#include "Catch.hpp"

#include "samplewidgets03.h"

#include <QCheckBox>

// By inheriting SampleWidgets03, we can expose access to its protected interface
class SampleWidgets03Fixture : public SampleWidgets03
{
public:
    // Bump visibility from protected to public, for testing
    using SampleWidgets03::checkBox;
};

TEST_CASE_METHOD(
    SampleWidgets03Fixture,
    "SampleWidgets03 checkbox is initially unchecked")
{
    auto checkbox = checkBox();
    REQUIRE(checkbox != nullptr);
    CHECK(! checkbox->isChecked());
}
