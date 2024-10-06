#pragma once

#include "Cell.hpp"

class EmptyCell : public Cell {
 public:
  EmptyCell() = default;

  ~EmptyCell() = default;

  CellImagine getImagine() const override;

  ShotResult hitCell() override;
};
