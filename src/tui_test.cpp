/*#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
 
int main(void) {
  using namespace ftxui;
 
  // Define the document
  Element document =
    hbox({
      text("left")   | border,
      text("middle") | border | flex,
      text("right")  | border,
    });
 
  auto screen = Screen::Create(
    Dimension::Full(),       // Width
    Dimension::Fit(document) // Height
  );
  Render(screen, document);
  screen.Print();
 
  return EXIT_SUCCESS;
}*/

#include <iostream>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <thread>
using namespace std;
using namespace ftxui; 

int main(int argc, char const *argv[])
{

  int posicionInicialX = 10;
  int posicionInicialY = 10;
  string prueba = "DVD";
  string p2 = "CD";

  auto Pantalla = Screen::Create(Dimension::Full(),Dimension::Full());

  while(true)
  {
    this_thread::sleep_for(0.1s);
        
    int posicionPalabraX = 0;
    int posicionPalabraY = 0;
                       
    for (auto &&letra : prueba)
    {
      int posicionfinalX= posicionInicialX+posicionPalabraX;
      int posicionfinalY= posicionInicialY+posicionPalabraY;

      Pantalla.PixelAt(

        posicionfinalX,
        posicionfinalY
      ).character = letra;
      posicionPalabraX++;
    }

    for (auto &&letra : p2)
    {
      int posicionfinalX= posicionInicialX+posicionPalabraX+2;
      int posicionfinalY= posicionInicialY+posicionPalabraY+2;

      Pantalla.PixelAt(
        posicionfinalX,
        posicionfinalY
      ).character = letra;
      posicionPalabraX++;
    }

    Pantalla.Print();
    Pantalla.Clear();
    cout<<Pantalla.ResetPosition();

    posicionInicialX++;
    posicionInicialY++;

    }
    return 0;
}