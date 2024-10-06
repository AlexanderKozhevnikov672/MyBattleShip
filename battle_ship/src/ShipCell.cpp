#include "ShipCell.hpp"

CellImagine ShipCell::getImagine() const {
  if (isClosed_) {
    return CellImagine::Closed;
  }
  return CellImagine::HitShip;
}

ShotResult ShipCell::hitCell() {
  if (!isClosed_) {
    return ShotResult::AlreadyHit;
  }
  isClosed_ = false;
  return ShotResult::Hit;
}
