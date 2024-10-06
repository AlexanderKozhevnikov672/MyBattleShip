#pragma once

#include "Field.hpp"
#include "PlayerInterface.hpp"

class Player {
 public:
  Player(size_t playerNum, size_t opponentNum);

  Player() = default;

  ~Player() = default;

  ShotResult makeShot();

 private:
  static const size_t kFieldSize_ = 10;
  static const size_t kMaxShipLength_ = 4;
  static const size_t kShipsCnt_ = 10;
  const std::vector<size_t> kShipsFixedLengthNeed_ = {0, 4, 3, 2, 1};
  size_t playerNum_;
  size_t shipsLeft_;
  Field opponentField_;
};
