#pragma once

#include "ShotResult.hpp"
#include "CellImagine.hpp"

class Cell {
 public:
  Cell();

  virtual ~Cell() = default;

  virtual CellImagine getImagine() const = 0;

  virtual ShotResult hitCell() = 0;

 protected:
  bool isClosed_;
};
