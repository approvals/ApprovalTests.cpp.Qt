#include "Catch.hpp"

#include "samplewidgets03.h"

#include <QToolButton>

// OPINION: This offers the best combination of being:
//  1.  least intrusive on the interface for users of SampleWidgets03
//  2.  Least maintenance effort here... no need to update the signature of
//      goButton() here if it changes in the base class.
//  3.  Easy to add 'using' statements for any new private methods added
//      to the class being tested.
//
// One possible confusion, though, is that it is not obvious to those reading
// the TEST_CASE_METHOD tests below that it is generating a class that
// inherits SampleWidgets03. It might have been clearer to have a
// SampleWidgets03 instance visible for calling.

// By inheriting SampleWidgets03, we can expose access to its protected interface
class SampleWidgets03FixtureInheritance : public SampleWidgets03
{
public:
    // Bump visibility from private to public, for testing (via friendship)
    // We need to do this because friendship isn't inherited, and any tests
    // that use this fixture do so by Catch generating code that inherits it.
    using SampleWidgets03::goButton;
};

TEST_CASE_METHOD(SampleWidgets03FixtureInheritance, "SampleWidgets03 gobutton is initially unchecked")
{
    auto gobutton = goButton();
    CHECK(!gobutton->isChecked());
    CHECK(answer() == 42);
}
