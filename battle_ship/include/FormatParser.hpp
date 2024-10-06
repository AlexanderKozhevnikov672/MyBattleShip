#pragma once

#include <algorithm>
#include "Field.hpp"

class FormatParser {
 public:
  std::optional<Point> parsePointFormat(const std::string& coords) const;

  std::optional<Ship> parseShipFormat(Point begin, Point end,
                                      const size_t kMaxShipLength) const;

  std::optional<Field> parseFieldFormat(const std::vector<Ship>& ships,
                                        std::vector<size_t> kShipsFixedLengthNeed,
                                        const size_t kMaxCoord) const;
};
