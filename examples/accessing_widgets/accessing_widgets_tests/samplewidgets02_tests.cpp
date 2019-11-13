#include "Catch.hpp"

#include "samplewidgets02.h"

#include <QToolButton>

// By inheriting SampleWidgets02, we can expose access to its protected interface
class SampleWidgets02Fixture : public SampleWidgets02
{
public:
    // Bump visibility from protected to public, for testing
    // Pro: The public interface of SampleWidgets02 doesn't contain
    //      things only required for testing
    // Con: Future developers may be tempted to inherit SampleWidgets02
    //      in order to break encapsulatiom and use things enabled only for
    //      testing
    using SampleWidgets02::goButton;
};

TEST_CASE_METHOD(
    SampleWidgets02Fixture, "SampleWidgets02 gobutton is initially unchecked")
{
    auto gobutton = goButton();
    CHECK(!gobutton->isChecked());
    CHECK(answer() == 42);
}
