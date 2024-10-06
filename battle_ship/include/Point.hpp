#pragma once

#include <iostream>
#include <optional>
#include <vector>

class Point {
 public:
  size_t row;
  size_t column;

  std::vector<Point> getNeibPoints(const size_t kMaxCoord) const;

  Point(size_t xCoord, size_t yCoord);

  Point() = default;

  ~Point() = default;

 private:
  std::optional<Point> checkLimits(int xCoord, int yCoord, const size_t kMaxCoord) const;
};

bool operator==(const Point& first, const Point& second);
