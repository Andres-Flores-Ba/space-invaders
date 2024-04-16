#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

using namespace ftxui;

int main (){

    Element label = text("Hola mundo");
    Element container = hbox({label});

    auto screen = Screen::Create(
        Dimension::Full(),
        Dimension::Fit(container)
    );
    Render(screen,container);
    screen.Print();

    return 0;

    getchar();
}