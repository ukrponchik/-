#include "window/window.h"
#include <iostream>

POINT::POINT(short x, short y) : x{x}, y{y} {}

Window::Window(POINT left, POINT right, COLOR bgColor)
  : left{left}, right{right}, bgColor{bgColor} {}

Window::Window(const Window& parent)
  : left{parent.left},
    right{parent.right},
    bgColor{parent.bgColor} {}

std::string Window::bgcolor() const {
  switch (bgColor) {
    case COLOR::RED:
      return "red";
    case COLOR::GREEN:
      return "green";
    case COLOR::BLUE:
      return "blue";
    case COLOR::YELLOW:
      return "yellow";
    default:
      return "none";
  }
}

void Window::Show() const {
  std::cout << "(" << left.x << ", " << left.y <<
                ", " << right.x << ", " << right.y << "), color: " << bgcolor() << std::endl;
}

void Window::background(COLOR color) {
  this->bgColor = color;
}

Menu::Menu(POINT left, POINT right, COLOR bgColor, LINE typeField)
  : Window{left, right, bgColor},
    fieldLine{typeField} {}

Menu::Menu(const Window& parent, LINE typeField)
  : Window(parent),
    fieldLine(typeField) {}

std::string Menu::line() const {
  switch (fieldLine) {
    case LINE::Context:
      return "context";
    case LINE::Default:
      return "default";
    case LINE::Input:
      return "input";
    case LINE::Output:
      return "output";
    default:
      return "none";
  }
}

void Menu::Show() const {
  Window::Show();
  std::cout << "line: " << line() << std::endl;
}

void Menu::background(COLOR color) {
  Window::background(color);
}

void Menu::field(LINE typeField) {
  this->fieldLine = typeField;
}