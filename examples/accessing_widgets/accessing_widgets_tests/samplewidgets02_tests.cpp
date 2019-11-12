#include "Catch.hpp"

#include "samplewidgets02.h"

#include <QToolButton>

// By inheriting SampleWidgets02, we can expose access to its protected interface
class SampleWidgets02Fixture : public SampleWidgets02
{
public:
    // Bump visibility from protected to public, for testing
    using SampleWidgets02::goButton;
};

TEST_CASE_METHOD(
    SampleWidgets02Fixture, "SampleWidgets02 gobutton is initially unchecked")
{
    auto gobutton = goButton();
    CHECK(!gobutton->isChecked());
}
