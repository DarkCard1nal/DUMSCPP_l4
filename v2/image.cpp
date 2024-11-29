#include "image.hpp"

Image::Image(size_t rows, size_t cols)
	: rows(rows), cols(cols), pixels(rows *cols, 0)
{
}

size_t Image::getRows() const { return rows; }
size_t Image::getCols() const { return cols; }

int &Image::at(size_t i, size_t j)
{
	if (i >= rows || j >= cols) throw std::out_of_range("Index out of bounds");
	return pixels[i * cols + j];
}

const int &Image::at(size_t i, size_t j) const
{
	if (i >= rows || j >= cols) throw std::out_of_range("Index out of bounds");
	return pixels[i * cols + j];
}

std::vector<int> Image::getPixels() const
{
	return std::vector<int>(pixels);
}
