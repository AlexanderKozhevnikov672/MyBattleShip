#pragma once

#include "FormatParser.hpp"

class PlayerInterface {
 public:
  Point askPointCoords() const;

  Ship askShipCoords(const size_t kMaxShipLength) const;

  Field askFieldDescription(size_t playerNum, const size_t kShipsCnt,
                            const size_t kMaxShipLength,
                            const std::vector<size_t> kShipsFixedLengthNeed,
                            const size_t kMaxCoord) const;

  void showField(const std::vector<std::vector<CellImagine>>& fieldImagine) const;

  Point askShotCoords(bool isFirstAttempt, size_t playerNum,
                      const std::vector<std::vector<CellImagine>>& fieldImagine) const;

  void informShotResult(size_t playerNum, ShotResult result) const;
 
 private:
  static const char kClosedCell = '.';
  static const char kHitShipCell = '#';
  static const char kHitEmptyCell = '*';
};
