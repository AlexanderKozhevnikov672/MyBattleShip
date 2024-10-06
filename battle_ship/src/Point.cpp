#include <iostream>
#include "Point.hpp"

std::vector<Point> Point::getNeibPoints(const size_t kMaxCoord) const {
  std::vector<Point> result;
  for (int dx = -1; dx <= 1; ++dx) {
    for (int dy = -1; dy <= 1; ++dy) {
      std::optional<Point> nowPoint = checkLimits(static_cast<int>(row) + dx, static_cast<int>(column) + dy, kMaxCoord);
      if ((dx != 0 || dy != 0) && nowPoint.has_value()) {
        result.push_back(nowPoint.value());
      }
    }
  }
  return result;
}

Point::Point(size_t xCoord, size_t yCoord) : row(xCoord), column(yCoord) {}

std::optional<Point> Point::checkLimits(int xCoord, int yCoord, const size_t kMaxCoord) const {
  if (xCoord >= 0 && xCoord < kMaxCoord && yCoord >= 0 && yCoord < kMaxCoord) {
    return {Point(static_cast<size_t>(xCoord), static_cast<size_t>(yCoord))};
  }
  return {};
}

bool operator==(const Point& first, const Point& second) {
  return first.row == second.row && first.column == second.column;
}
