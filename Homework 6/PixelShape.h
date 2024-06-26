// Copyright 2024 Aarsh Patel
#ifndef PIXELSHAPE_H_
#define PIXELSHAPE_H_

#include <string>

namespace CSCE240_Program6 {

class PixelShape {
 private:
  std::string name_;
  char pixel_;

 public:
  // Constructor with default values
  explicit PixelShape(const std::string& name = "?", char pixel = '*');

  // Virtual destructor
  virtual ~PixelShape();

  // Setters
  void SetName(const std::string& new_name);
  void SetPixel(char new_pixel);

  // Getters
  std::string GetName() const;
  char GetPixel() const;

  // Print function
  virtual void Print(bool fill = true) const;

  // Pure virtual operator
  virtual PixelShape& operator*=(double factor) = 0;
};

}  // namespace CSCE240_Program6

#endif  // PIXELSHAPE_H_
