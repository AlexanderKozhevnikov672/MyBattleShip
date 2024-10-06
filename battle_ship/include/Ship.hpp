#pragma once

#include <iostream>
#include "ShotResult.hpp"
#include "Point.hpp"

class Ship {
 public:
  Ship(Point begin, Point end);

  Ship() = default;

  ~Ship() = default;

  ShotResult hitShip();

  std::vector<Point> getNeibPoints(const size_t kMaxCoord) const;

  std::vector<Point> getBodyPoints() const;

 private:
  Point begin_;
  Point end_;
  size_t size_;
};
