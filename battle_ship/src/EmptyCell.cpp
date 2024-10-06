#include "EmptyCell.hpp"

CellImagine EmptyCell::getImagine() const {
  if (isClosed_) {
    return CellImagine::Closed;
  }
  return CellImagine::HitEmpty;
}

ShotResult EmptyCell::hitCell() {
  if (!isClosed_) {
    return ShotResult::AlreadyHit;
  }
  isClosed_ = false;
  return ShotResult::Missed;
}
