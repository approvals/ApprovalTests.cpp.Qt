#include "Catch.hpp"

#include "samplewidgets.h"

#include <QCheckBox>

TEST_CASE( "SampleWidgets01 checkbox is initially unchecked")
{
    SampleWidgets01 sampleWidgets;

    // The Ui is private, so we have to "cheat" and search for the contained
    // widgets ourselves.
    // This makes for potential maintenance pain in future, if the widget
    // internals are modified
    auto checkbox = sampleWidgets.findChild<QCheckBox*>();
    REQUIRE(checkbox != nullptr);
    CHECK(! checkbox->isChecked());
}
