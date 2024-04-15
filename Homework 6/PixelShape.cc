// Copyright 2024 Aarsh Patel
#include "PixelShape.h"
#include <iostream>

namespace CSCE240_Program6 {

PixelShape::PixelShape(const std::string& name, char pixel) :
  name_((name.length() < 1 || name == "") ? "?" : name),
  pixel_(pixel) {
  if (pixel < 33 || pixel > 126) {
    this->pixel_ = '*';
  }
}

PixelShape::~PixelShape() {}

void PixelShape::SetName(const std::string& new_name) {
  if (!new_name.empty()) {
    name_ = new_name;
  }
}

void PixelShape::SetPixel(char new_pixel) {
  if (new_pixel >= 33 && new_pixel <= 126) {
    pixel_ = new_pixel;
  }
}

std::string PixelShape::GetName() const {
  return name_;
}

char PixelShape::GetPixel() const {
  return pixel_;
}

void PixelShape::Print(bool fill) const {
  std::cout << name_ << std::endl;
}

}  // namespace CSCE240_Program6
