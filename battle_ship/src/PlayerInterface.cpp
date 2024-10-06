#include "PlayerInterface.hpp"

Point PlayerInterface::askPointCoords() const {
  std::optional<Point> result = {};
  while (!result.has_value()) {
    std::string coords;
    std::cin >> coords;
    result = FormatParser().parsePointFormat(coords);
    if (!result.has_value()) {
      std::cout << std::endl << "Wrong cord format! Try again:" << std::endl;
    }
  }
  return result.value();
}

Ship PlayerInterface::askShipCoords(const size_t kMaxShipLength) const {
  std::optional<Ship> result = {};
  while (!result.has_value()) {
    Point begin = askPointCoords();
    Point end = askPointCoords();
    result = FormatParser().parseShipFormat(begin, end, kMaxShipLength);
    if (!result.has_value()) {
      std::cout << std::endl << "Wrong ship format! Try anain:" << std::endl;
    }
  }
  return result.value();
}

Field PlayerInterface::askFieldDescription(size_t playerNum,
                      const size_t kShipsCnt, const size_t kMaxShipLength,
                      const std::vector<size_t> kShipsFixedLengthNeed,
                      const size_t kMaxCoord) const {
  std::cout << std::endl << "Player" << playerNum <<
               ", enter extreme coords of your ships:" << std::endl;
  std::optional<Field> result = {};
  while (!result.has_value()) {
    std::vector<Ship> ships(kShipsCnt + 1);
    for (size_t shipNum = 1; shipNum <= kShipsCnt; ++shipNum) {
      ships[shipNum] = askShipCoords(kMaxShipLength);
    }
    result = FormatParser().parseFieldFormat(ships, kShipsFixedLengthNeed, kMaxCoord);
    if (!result.has_value()) {
      std::cout << std::endl << "Wrong field format! Try again:" << std::endl;
    }
  }
  return result.value();
}

void PlayerInterface::showField(
                     const std::vector<std::vector<CellImagine>>& fieldImagine) const {
  const size_t kFieldSize = fieldImagine.size();
  std::cout << std::endl << " ";
  for (char column = '0'; column < '0' + kFieldSize; ++column) {
    std::cout << column;
  }
  std::cout << std::endl;
  for (size_t row = 0; row < kFieldSize; ++row) {
    std::cout << static_cast<char>(row + 'A');
    for (size_t column = 0; column < kFieldSize; ++column) {
      if (fieldImagine[row][column] == CellImagine::Closed) {
        std::cout << kClosedCell;
      } else if (fieldImagine[row][column] == CellImagine::HitShip) {
        std::cout << kHitShipCell;
      } else {
        std::cout << kHitEmptyCell;
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

Point PlayerInterface::askShotCoords(bool isFirstAttempt, size_t playerNum,
                      const std::vector<std::vector<CellImagine>>& fieldImagine) const {
  if (isFirstAttempt) {
    std::cout << std::endl << "Player" << playerNum <<
                 ", enter your shot coordinates:" << std::endl;
    showField(fieldImagine);
  } else {
    std::cout << std::endl << "Already hit! Try again:" << std::endl;
  }
  return askPointCoords();
}

void PlayerInterface::informShotResult(size_t playerNum, ShotResult result) const {
  if (result == ShotResult::Hit) {
    std::cout << std::endl << "Hit!" << std::endl;
  } else if (result == ShotResult::Killed) {
    std::cout << std::endl << "Killed!" << std::endl;
  } else if (result == ShotResult::Missed) {
    std::cout << std::endl << "Missed!" << std::endl;
  } else {
    std::cout << std::endl << "Player" << playerNum <<
                 " won! Congratulations!" << std::endl;
  }
}
