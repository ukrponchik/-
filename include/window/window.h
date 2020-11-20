#pragma once
#include <string>

/// Struct for point on plane
struct POINT {
  short x, y;

  POINT(short x, short y);
};

/// Enums of colors
enum class COLOR { RED, GREEN, BLUE, YELLOW };

/// Window class
class Window {
private:
  POINT left;    /// Coords of upper left corner
  POINT right;   /// Coords of lower right corner
  COLOR bgColor; /// Background color

public:
  /**
   * Create a window
   * 
   * @param left      Coords of upper left corner
   * @param right     Coords of lower right corner
   * @param bgColor   Background color
   */
  Window(POINT left, POINT right, COLOR bgColor);

  /// Delete window
  ~Window() = default;

  Window(const Window& parent);

  /// Displays window info to the console
  virtual void Show() const;

  /// Returns background color name
  std::string bgcolor() const;

  /// Sets the background color
  virtual void background(COLOR color);
};

enum class LINE { Default, Input, Output, Context };

class Menu : public Window {
private:
  LINE fieldLine; /// Line fied
public:
  /// Create window with menu
  Menu(POINT left, POINT right, COLOR bgColor, LINE typeField);

  /// Create menu on the window
  Menu(const Window& parent, LINE typeField);

  ~Menu() = default;

  /// Displays menu info to the console
  void Show() const override;

  /// Sets the background color
  void background(COLOR color) override;
  
  /// Change line field
  void field(LINE typeField);

  /// Returns the type of line
  std::string line() const;
};