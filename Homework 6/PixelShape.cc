// Copyright 2024 Aarsh Patel
#include "PixelShape.h"
#include <iostream>

namespace CSCE240_Program6 {

PixelShape::PixelShape(const std::string& name, char pixel) : name(name), pixel(pixel) {}

PixelShape::~PixelShape() {}

void PixelShape::SetName(const std::string& newName) {
    if (!newName.empty()) {
        name = newName;
    }
}

void PixelShape::SetPixel(char newPixel) {
    if (newPixel >= 33 && newPixel <= 126) {
        pixel = newPixel;
    }
}

std::string PixelShape::GetName() const {
    return name;
}

char PixelShape::GetPixel() const {
    return pixel;
}

void PixelShape::Print(bool fill) const {
    std::cout << name << std::endl;
}

} // namespace CSCE240_Program6
