// Copyright 2024 Aarsh Patel
#ifndef PIXELSHAPE_H
#define PIXELSHAPE_H

#include <string>

namespace CSCE240_Program6 {

class PixelShape {
 private:
  std::string name;
  char pixel;

 public:
  // Constructor with default values
  PixelShape(const std::string& name = "?", char pixel = '*');

  // Virtual destructor
  virtual ~PixelShape();

  // Setters
  void SetName(const std::string& newName);
  void SetPixel(char newPixel);

  // Getters
  std::string GetName() const;
  char GetPixel() const;

  // Print function
  virtual void Print(bool fill = true) const;

  // Pure virtual operator
  virtual PixelShape& operator*=(double factor) = 0;
};

}  // namespace CSCE240_Program6

#endif  // PIXELSHAPE_H
