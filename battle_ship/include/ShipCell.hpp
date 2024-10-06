#pragma once

#include "Cell.hpp"

class ShipCell : public Cell {
 public:
  ShipCell() = default;

  ~ShipCell() = default;

  CellImagine getImagine() const override;

  ShotResult hitCell() override;
};
