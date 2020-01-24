#include "Catch.hpp"

#include "samplewidgets01_public_accessor.h"

#include <QToolButton>

//! Ui::SampleWidgets is a private data member - but there is a public accessor for it
class SampleWidgets01Fixture
{
public:
    SampleWidgets01 widget;

    QToolButton* goButton()
    {
        return widget.goButton();
    }
};

TEST_CASE_METHOD(
    SampleWidgets01Fixture,
    "SampleWidgets01 gobutton is initially unchecked - with fixture")
{
    auto gobutton = goButton();
    CHECK(!gobutton->isChecked());
    CHECK(widget.answer() == 42);
}
