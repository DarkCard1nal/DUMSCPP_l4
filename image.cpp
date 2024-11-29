#include "image.hpp"

Image::Image(size_t rows, size_t cols, std::shared_ptr<ImageFormatStrategy> strategy)
	: rows(rows), cols(cols), pixels(rows *cols, 0), strategy(std::move(strategy))
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

std::vector<int> Image::getPixels()
{
	return std::vector<int>(pixels);
}

void Image::setStrategy(std::shared_ptr<ImageFormatStrategy> newStrategy)
{
	strategy = std::move(newStrategy);
}

bool Image::load(const std::string &filePath)
{
	return strategy->load(filePath, rows, cols, pixels);
}

void Image::save(const std::string &filePath) const
{
	strategy->save(filePath, rows, cols, pixels);
}