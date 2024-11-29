#pragma once
#ifndef IMAGE_HPP
#define IMAGE_HPP
#include "image_format_strategy.hpp"
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

class Image
{
private:
	size_t rows;
	size_t cols;
	std::vector<int> pixels;
	std::shared_ptr<ImageFormatStrategy> strategy;

public:
	Image(size_t rows, size_t cols, std::shared_ptr<ImageFormatStrategy> strategy);

	size_t getRows() const;
	size_t getCols() const;
	int &at(size_t i, size_t j);
	const int &at(size_t i, size_t j) const;
	std::vector<int> getPixels();
	void setStrategy(std::shared_ptr<ImageFormatStrategy> newStrategy);
	bool load(const std::string &filePath);
	void save(const std::string &filePath) const;
};
#endif // IMAGE_HPP
