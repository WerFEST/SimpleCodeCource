#include "Pixel.h"

std::string Pixel::GetInfo()
{
    return "Pixel: R= " + std::to_string(r) + "\tG= " + std::to_string(g) + "\tB= " + std::to_string(g);
}
