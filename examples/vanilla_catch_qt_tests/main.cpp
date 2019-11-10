// Demonstrate how to create a Catch main() for testing Qt GUI code

#define CATCH_CONFIG_RUNNER
#include <Catch.hpp>

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    int result = Catch::Session().run(argc, argv);
    return result;
}
