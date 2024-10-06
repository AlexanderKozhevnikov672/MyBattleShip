#pragma once

#include <memory>
#include "EmptyCell.hpp"
#include "ShipCell.hpp"
#include "Ship.hpp"

class Field {
 public:
  Field(const std::vector<Ship>& ships);

  Field() = default;

  ~Field() = default;

  ShotResult hitCell(size_t row, size_t column);

  std::vector<std::vector<CellImagine>> getImagine() const;

 private:
  static const size_t kSize_ = 10;
  std::vector<Ship> ships_;
  std::vector<std::vector<size_t>> shipNums_;
  std::vector<std::vector<std::shared_ptr<Cell>>> cellPtrs_;
};
