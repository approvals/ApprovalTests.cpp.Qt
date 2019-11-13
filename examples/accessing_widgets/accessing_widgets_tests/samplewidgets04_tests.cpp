#include "Catch.hpp"

#include "samplewidgets04.h"

#include <QToolButton>

// No iheritance - we can access the private interface of SampleWidgets04
// due to friendship.
class SampleWidgets04Fixture
{
public:
    SampleWidgets04 widget;

    // Wrapper to bump visibility from private to public, for testing (via
    // friendship). We need to do this because friendship isn't inherited, and
    // any tests that use this fixture do so by Catch generating code that
    // inherits it.
    QToolButton* goButton()
    {
        // We are calling a private method, but are allowed to do so here
        // because this test fixture is a friend of SampleWidgets04
        return widget.goButton();
    }
};

TEST_CASE_METHOD(
    SampleWidgets04Fixture, "SampleWidgets04 gobutton is initially unchecked")
{
    auto gobutton = goButton();
    CHECK(!gobutton->isChecked());
}
