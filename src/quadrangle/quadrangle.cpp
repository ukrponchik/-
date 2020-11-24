#include "quadrangle/quadrangle.h"
#include <sys/types.h>

Quadrangle::Quadrangle(vdouble sides, vdouble angles)
    : sides{sides}, angles{angles} {}

Quadrangle::Quadrangle(const Quadrangle &quad)
    : sides{quad.sides}, angles{quad.angles} {}

Quadrangle::Quadrangle(Quadrangle &&quad) {
  sides = quad.sides;
  angles = quad.angles;
}

std::ostream &operator<<(std::ostream &os, const Quadrangle &quad) {
  os << "sides: ";
  for (const auto &el : quad.sides) {
    os << el << ' ';
  }
  os << "\nangels: ";
  for (const auto &el : quad.angles) {
    os << el << ' ';
  }
  return os;
}

std::istream &operator>>(std::istream &is, Quadrangle &quad) {
  for (int i = 0; i < 4; i++)
    is >> quad.sides[i];
  for (int i = 0; i < 4; i++)
    is >> quad.angles[i];
  return is;
}

Square::Square(vdouble sides) : Quadrangle(sides, vdouble{90, 90}) {}

Square::Square(const Square &square)
    : Quadrangle(square.sides, square.angles) {}

Square::Square(Square &&square) : Quadrangle{square.sides, square.angles} {}

std::istream &operator>>(std::istream &is, Square &sq) {
  is >> sq.sides[0] >> sq.sides[1];
  sq.sides[2] = sq.sides[0];
  sq.sides[3] = sq.sides[1];

  is >> sq.angles[0] >> sq.angles[1];
  sq.angles[2] = sq.angles[0];
  sq.angles[3] = sq.angles[1];
  return is;
}

const Quadrangle &Quadrangle::operator=(const Quadrangle &quad) {
  sides = quad.sides;
  angles = quad.angles;

  return *this;
}

const Square &Square::operator=(const Square &sq) {
  this->sides[0] = this->sides[2] = sq.sides[0];
  this->sides[1] = this->sides[3] = sq.sides[1];

  this->angles[0] = this->angles[2] = sq.angles[0];
  this->angles[1] = this->angles[3] = sq.angles[1];
  return *this;
}

const Square &Square::operator=(const Quadrangle &quad) {
  this->sides[0] = quad.left();
  this->sides[1] = quad.top();

  this->angles[0] = this->angles[1] = 90;
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Square &sq) {
  os << "sides: ";
  for (const auto &el : sq.sides) {
    os << el << ' ';
  }
  os << "\nangels: ";
  for (const auto &el : sq.angles) {
    os << el << ' ';
  }
  return os;
}