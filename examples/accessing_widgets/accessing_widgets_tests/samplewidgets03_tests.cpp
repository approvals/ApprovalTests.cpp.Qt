#include "Catch.hpp"

#include "samplewidgets03.h"

#include <QToolButton>

// By inheriting SampleWidgets03, we can expose access to its protected interface
class SampleWidgets03Fixture : public SampleWidgets03
{
public:
    // Bump visibility from private to public, for testing (via friendship)
    // We need to do this because friendship isn't inherited, and any tests
    // that use this fixture do so by Catch generating code that inherits it.
    using SampleWidgets03::goButton;
};

TEST_CASE_METHOD(
    SampleWidgets03Fixture, "SampleWidgets03 gobutton is initially unchecked")
{
    auto gobutton = goButton();
    CHECK(!gobutton->isChecked());
}
