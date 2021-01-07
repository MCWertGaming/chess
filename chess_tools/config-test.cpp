#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
 
int main()
{
  // Define the document
  ftxui::Element document =
    ftxui::hbox({
      ftxui::text(L"left")   | ftxui::border,
      ftxui::text(L"middle") | ftxui::border | ftxui::flex,
      ftxui::text(L"right")  | ftxui::border,
    });
 
  auto screen = ftxui::Screen::Create(
    ftxui::Dimension::Full(),       // Width
    ftxui::Dimension::Fit(document) // Height
  );
  Render(screen, document);
  std::cout << screen.ToString() << std::endl;
 
  return 0;
}
/*
#include <iostream>

#include <folf-namespace/folf.hpp>
#include <folf-namespace/folf-info.hpp>
#include "information.hpp"

int main()
{
    std::cout << "Starting config test...\n";
    std::cout << "Running with FOLF-namespace version: " << FOLF_VERSION_COMPLETE << "\n";
    std::cout << "And chess version: " << CHESS_VERSION_COMPLETE << "\n";


    return 0;
}
*/