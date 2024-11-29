#pragma once
#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <vector>
#include <string>
#include <stdexcept>

class Image
{
protected:
	size_t rows;
	size_t cols;
	std::vector<int> pixels;

public:
	Image(size_t rows, size_t cols);

	size_t getRows() const;
	size_t getCols() const;
	int &at(size_t i, size_t j);
	const int &at(size_t i, size_t j) const;

	virtual std::vector<int> getPixels() const;
	virtual bool load(const std::string &filePath) = 0;
	virtual void save(const std::string &filePath) const = 0;
};
#endif // IMAGE_HPP
