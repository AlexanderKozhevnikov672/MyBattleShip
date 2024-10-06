#include "FormatParser.hpp"

std::optional<Point> FormatParser::parsePointFormat(
                                  const std::string& coords) const {
  if (coords[0] >= 'A' && coords[0] <= 'J' &&
      coords[1] >= '0' && coords[1] <= '9') {
    return {Point(coords[0] - 'A', coords[1] - '0')};
  }
  return {};
}

std::optional<Ship> FormatParser::parseShipFormat(Point begin, Point end,
                                 const size_t kMaxShipLenght) const {
  if (begin.row != end.row && begin.column != end.column) {
    return {};
  }
  if (begin.row > end.row || begin.column > end.column) {
    std::swap(begin, end);
  }
  if (std::max(end.row - begin.row, end.column - begin.column) < kMaxShipLenght) {
    return {Ship(begin, end)};
  }
  return {};
}

std::optional<Field> FormatParser::parseFieldFormat(const std::vector<Ship>& ships,
                                  std::vector<size_t> shipsEachLengthNeed,
                                  const size_t kMaxCoord) const {
  for (size_t shipNum = 1; shipNum < ships.size(); ++shipNum) {
    std::vector<Point> shipBody = ships[shipNum].getBodyPoints();
    for (size_t otherShipNum = shipNum + 1; otherShipNum < ships.size(); ++otherShipNum) {
      for (const Point& otherShipNeib : ships[otherShipNum].getNeibPoints(kMaxCoord)) {
        if (std::find(shipBody.begin(),
                      shipBody.end(), otherShipNeib) != shipBody.end()) {
          return {};
        }
      }
    }
    if (shipBody.size() >= shipsEachLengthNeed.size() ||
        shipsEachLengthNeed[shipBody.size()] == 0) {
      return {};
    }
    --shipsEachLengthNeed[shipBody.size()];
  }
  return {Field(ships)};
}
