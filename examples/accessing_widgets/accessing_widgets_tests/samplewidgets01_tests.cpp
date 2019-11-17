#include "Catch.hpp"

#include "samplewidgets00.h"

#include <QToolButton>

//! Ui::SampleWidgets is a private data member - tests will use findChild*()
class SampleWidgets00Fixture
{
public:
    SampleWidgets00 widget;

    // The Ui is private, and the Go button is not in the public interface,
    // so we"cheat" and search for the contained widgets ourselves.
    // NOT A RECOMMENDED PRACTICE!!
    // This makes for potential maintenance pain in future, if the widget
    // internals are modified.
    QToolButton* goButton()
    {
        auto gobutton = widget.findChild<QToolButton*>();
        // Will give a run-time test failure if SampleWidgets00 no longer has
        // a QToolButton
        // But won't detect a change to use a QToolButton for a totally different
        // purpose
        REQUIRE(gobutton != nullptr);
        return gobutton;
    }
};

TEST_CASE_METHOD(
    SampleWidgets00Fixture, "SampleWidgets00 gobutton is initially unchecked")
{
    auto gobutton = goButton();
    CHECK(!gobutton->isChecked());
    CHECK(widget.answer() == 42);
}
