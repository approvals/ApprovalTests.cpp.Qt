#include "Catch.hpp"

#include "samplewidgets03.h"

#include <QCheckBox>

// By inheriting SampleWidgets03, we can expose access to its protected interface
class SampleWidgets03Fixture : public SampleWidgets03
{
public:
    // Bump visibility from private to public, for testing (via friendship)
    // We need to do this because friendship isn't inherited, and any tests
    // that use this fixture do so by Catch generating code that inherits it.
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
