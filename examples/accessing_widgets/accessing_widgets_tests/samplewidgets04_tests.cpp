#include "Catch.hpp"

#include "samplewidgets04.h"

#include <QToolButton>

// By inheriting SampleWidgets04, we can expose access to its protected interface
class SampleWidgets04Fixture : public SampleWidgets04
{
public:
    // Bump visibility from private to public, for testing (via friendship)
    // We need to do this because friendship isn't inherited, and any tests
    // that use this fixture do so by Catch generating code that inherits it.
    using SampleWidgets04::goButton;
};

TEST_CASE_METHOD(
    SampleWidgets04Fixture, "SampleWidgets04 gobutton is initially unchecked")
{
    auto gobutton = goButton();
    CHECK(!gobutton->isChecked());
}
