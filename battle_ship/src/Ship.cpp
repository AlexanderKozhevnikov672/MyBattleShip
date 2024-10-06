#include "Ship.hpp"

Ship::Ship(Point begin, Point end) : begin_(begin), end_(end),
                                     size_(std::max(end.row - begin.row, end.column - begin.column) + 1) {}

ShotResult Ship::hitShip() {
  if (--size_ == 0) {
    return ShotResult::Killed;
  }
  return ShotResult::Hit;
}

std::vector<Point> Ship::getNeibPoints(const size_t kMaxCoord) const {
  std::vector<Point> result;
  for (const Point& shipPoint : getBodyPoints()) {
    for (const Point& neibPoint : shipPoint.getNeibPoints(kMaxCoord)) {
      result.push_back(neibPoint);
    }
  }
  return result;
}

std::vector<Point> Ship::getBodyPoints() const {
  std::vector<Point> result;
  for (size_t row = begin_.row; row <= end_.row; ++row) {
    for (size_t column = begin_.column; column <= end_.column; ++column) {
      result.push_back(Point(row, column));
    }
  }
  return result;
}
