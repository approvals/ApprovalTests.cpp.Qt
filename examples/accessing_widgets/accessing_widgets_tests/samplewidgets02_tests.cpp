#include "Catch.hpp"

#include "samplewidgets02.h"

#include <QCheckBox>

// By inheriting SampleWidgets02, we can expose access to its protected interface
class SampleWidgets02Fixture : public SampleWidgets02
{
public:
    QCheckBox* getCheckBox() { return checkBox(); }
};

TEST_CASE_METHOD(
    SampleWidgets02Fixture,
    "SampleWidgets02 checkbox is initially unchecked")
{
    auto checkbox = getCheckBox();
    REQUIRE(checkbox != nullptr);
    CHECK(! checkbox->isChecked());
}
