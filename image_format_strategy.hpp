#pragma once
#ifndef IMAGE_FORMAT_STRATEGY_HPP
#define IMAGE_FORMAT_STRATEGY_HPP
#include <string>
#include <vector>

class ImageFormatStrategy
{
public:
	virtual ~ImageFormatStrategy() = default;

	virtual bool load(const std::string &filePath, size_t &rows, size_t &cols, std::vector<int> &pixels) const = 0;
	virtual void save(const std::string &filePath, size_t rows, size_t cols, const std::vector<int> &pixels) const = 0;
};
#endif // IMAGE_FORMAT_STRATEGY_HPP
