#include "Catch.hpp"

#include "samplewidgets02.h"

#include <QCheckBox>

// By inheriting SampleWidgets02, we can expose access to its protected interface
class SampleWidgets02Fixture : public SampleWidgets02
{
public:
    // Bump visibility from protected to public, for testing
    using SampleWidgets02::checkBox;
};

TEST_CASE_METHOD(
    SampleWidgets02Fixture,
    "SampleWidgets02 checkbox is initially unchecked")
{
    auto checkbox = checkBox();
    REQUIRE(checkbox != nullptr);
    CHECK(! checkbox->isChecked());
}
