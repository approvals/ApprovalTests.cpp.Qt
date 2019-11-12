#include "Catch.hpp"

#include "samplewidgets01.h"

#include <QCheckBox>

// By inheriting SampleWidgets02, we can expose access to its protected interface
class SampleWidgets01Fixture : public SampleWidgets01
{
public:
    // The Ui is private, so we have to "cheat" and search for the contained
    // widgets ourselves.
    // This makes for potential maintenance pain in future, if the widget
    // internals are modified
    QCheckBox* checkBox()
    {
        auto checkbox = findChild<QCheckBox*>();
        // Will give a run-time test failure if SampleWidgets01 no longer has
        // a QCheckBox
        // But won't detect a change to use a QCheckBox for a totally different
        // purpose
        REQUIRE(checkbox != nullptr);
        return checkbox;
    }
};

TEST_CASE_METHOD(
    SampleWidgets01Fixture, "SampleWidgets01 checkbox is initially unchecked")
{
    auto checkbox = checkBox();
    CHECK(!checkbox->isChecked());
}
