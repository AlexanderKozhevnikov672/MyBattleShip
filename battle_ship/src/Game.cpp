#include "Game.hpp"

Game::Game() : moveTurn_(0) {}

size_t Game::getNextNum(size_t nowNum) const {
  return (nowNum + 1) % kPlayersCnt_;
}

void Game::switchTurn() {
  moveTurn_ = getNextNum(moveTurn_);
}

void Game::initPlayers() {
  for (size_t i = 0; i < kPlayersCnt_; ++i) {
    players_.push_back(Player(i, getNextNum(i)));
  }
}

void Game::play() {
  initPlayers();
  ShotResult result = ShotResult::Missed;
  while (result != ShotResult::Won) {
    result = players_[moveTurn_].makeShot();
    if (result == ShotResult::Missed) {
      switchTurn();
    }
  }
}
