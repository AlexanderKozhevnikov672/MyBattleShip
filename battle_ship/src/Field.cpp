#include "Field.hpp"

Field::Field(const std::vector<Ship>& ships) : ships_(ships),
      shipNums_(kSize_, std::vector<size_t>(kSize_, 0)),
      cellPtrs_(kSize_, std::vector<std::shared_ptr<Cell>>(kSize_)) {
  for (size_t shipNum = 1; shipNum < ships_.size(); ++shipNum) {
    for (Point shipPoint : ships_[shipNum].getBodyPoints()) {
      shipNums_[shipPoint.row][shipPoint.column] = shipNum;
    }
  }
  for (size_t row = 0; row < kSize_; ++row) {
    for (size_t column = 0; column < kSize_; ++column) {
      if (shipNums_[row][column] == 0) {
        cellPtrs_[row][column] = std::shared_ptr<Cell>(new EmptyCell());
      } else {
        cellPtrs_[row][column] = std::shared_ptr<Cell>(new ShipCell());
      }
    }
  }
}

ShotResult Field::hitCell(size_t row, size_t column) {
  ShotResult result = cellPtrs_[row][column]->hitCell();
  if (result == ShotResult::Hit) {
    result = ships_[shipNums_[row][column]].hitShip();
    if (result == ShotResult::Killed) {
      for (const Point& neibPoint : ships_[shipNums_[row][column]].getNeibPoints(kSize_)) {
        cellPtrs_[neibPoint.row][neibPoint.column]->hitCell();
      }
    }
  }
  return result;
}

std::vector<std::vector<CellImagine>> Field::getImagine() const {
  std::vector<std::vector<CellImagine>> result(kSize_, std::vector<CellImagine>(kSize_));
  for (size_t row = 0; row < kSize_; ++row) {
    for (size_t column = 0; column < kSize_; ++column) {
      result[row][column] = cellPtrs_[row][column]->getImagine();
    }
  }
  return result;
}
