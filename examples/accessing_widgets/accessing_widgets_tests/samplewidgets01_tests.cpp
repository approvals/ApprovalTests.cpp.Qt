#include "Catch.hpp"

#include "samplewidgets01.h"

#include <QToolButton>

// By inheriting SampleWidgets02, we can expose access to its protected interface
class SampleWidgets01Fixture : public SampleWidgets01
{
public:
    // The Ui is private, so we have to "cheat" and search for the contained
    // widgets ourselves.
    // This makes for potential maintenance pain in future, if the widget
    // internals are modified
    QToolButton* goButton()
    {
        auto gobutton = findChild<QToolButton*>();
        // Will give a run-time test failure if SampleWidgets01 no longer has
        // a QToolButton
        // But won't detect a change to use a QToolButton for a totally different
        // purpose
        REQUIRE(gobutton != nullptr);
        return gobutton;
    }
};

TEST_CASE_METHOD(
    SampleWidgets01Fixture, "SampleWidgets01 gobutton is initially unchecked")
{
    auto gobutton = goButton();
    CHECK(!gobutton->isChecked());
}
