#pragma once
#include <iostream>
#include <vector>

using vdouble = std::vector<double>;

class Quadrangle {
protected:
  vdouble sides;  // All sides
  vdouble angles; // All angels

public:
  Quadrangle() = default;
  Quadrangle(vdouble sides, vdouble angles);

  Quadrangle(const Quadrangle &quad);

  Quadrangle(Quadrangle &&quad);

  friend std::ostream &operator<<(std::ostream &os, const Quadrangle &quad);

  friend std::istream &operator>>(std::istream &is, Quadrangle &quad);

  const Quadrangle& operator=(const Quadrangle &quad);

  double left() const{ return sides[0]; }
  double top() const { return sides[1]; }
  double right() const { return sides[2]; }
  double bottom() const { return sides[3]; }

  double langle() const { return angles[0]; }
  double tangle() const { return angles[1]; }
  double rangle() const { return angles[2]; }
  double bangle() const { return angles[3]; }

};

class Square : protected Quadrangle {
public:
  Square() = default;

  Square(vdouble sides);

  Square(const Square &square);

  Square(Square &&square);

  friend std::istream &operator>>(std::istream &is, Square &sq);

  friend std::ostream &operator<<(std::ostream &os, const Square &sq);

  const Square &operator=(const Quadrangle &quad);

  const Square &operator=(const Square &sq);
};