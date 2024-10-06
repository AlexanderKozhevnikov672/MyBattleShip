#pragma once

#include "Player.hpp"

class Game {
 public:
  Game();

  ~Game() = default;

  void play();

 private:
  static const size_t kPlayersCnt_ = 2;
  size_t moveTurn_;
  std::vector<Player> players_;

  size_t getNextNum(size_t nowNum) const;

  void switchTurn();

  void initPlayers();
};
