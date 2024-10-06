#include "Player.hpp"

Player::Player(size_t playerNum, size_t opponentNum) :
       playerNum_(playerNum + 1), shipsLeft_(kShipsCnt_),
       opponentField_(PlayerInterface().askFieldDescription(opponentNum + 1, kShipsCnt_,
                      kMaxShipLength_, kShipsFixedLengthNeed_, kFieldSize_)) {
}

ShotResult Player::makeShot() {
  bool isFirstAttempt = true;
  Point shotCoords = PlayerInterface().askShotCoords(isFirstAttempt, playerNum_,
                                                     opponentField_.getImagine());
  ShotResult result = opponentField_.hitCell(shotCoords.row, shotCoords.column);
  while (result == ShotResult::AlreadyHit) {
    shotCoords = PlayerInterface().askShotCoords(!isFirstAttempt, playerNum_,
                                                 opponentField_.getImagine());
    result = opponentField_.hitCell(shotCoords.row, shotCoords.column);
  }
  if (result == ShotResult::Killed && --shipsLeft_ == 0) {
    result = ShotResult::Won;
  }
  PlayerInterface().informShotResult(playerNum_, result);
  return result;
}
