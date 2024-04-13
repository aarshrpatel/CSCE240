// Copyright 2024 Aarsh Patel
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "PixelShape.h"

namespace CSCE240_Program6 {

class Rectangle : public PixelShape {
 private:
  int length;
  int width;

 public:
  // Constructor with default values
  Rectangle(int length = 2, int width = 1, char pixel = '*');

  // Virtual destructor
  virtual ~Rectangle();

  // Mutators and Accessors
  void SetLength(int newLength);
  void SetWidth(int newWidth);
  int GetLength() const;
  int GetWidth() const;

  // Pure virtual operator*=
  Rectangle& operator*=(double factor) override;
  
  // Print function
  void Print(bool fill = true) const override;
};

} // namespace CSCE240_Program6

#endif // RECTANGLE_H
