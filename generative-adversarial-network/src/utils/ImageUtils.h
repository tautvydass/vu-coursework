#pragma once
#include <armadillo>

#include <stb_image.h>
#include <stb_image_write.h>

#define COLOR_CHANNEL_COUNT	3
#define MAX_COLOR_VALUE		255
#define ASCII_ZERO			48

class ImageUtils
{
public:
	static arma::vec* getImageVector(const char* path, const size_t& imageWidth, const size_t& imageHeight)
	{
		int width, height, bpp;

		uint8_t* rgb_image = stbi_load(path, &width, &height, &bpp, COLOR_CHANNEL_COUNT);

		if (rgb_image == nullptr) throw "Failed to load image";
		if (imageWidth != width || imageHeight != imageHeight) throw "Invalid image format (dimensions)";

		size_t vectorLength = width * height * COLOR_CHANNEL_COUNT;

		arma::vec* imageVector = new arma::vec(vectorLength);

		// TODO: optimize this
		for (size_t i = 0; i < vectorLength; i++)
		{
			imageVector->at(i) = rgb_image[i] == ASCII_ZERO ? 0 : static_cast<double>(rgb_image[i]) / MAX_COLOR_VALUE;
		}

		stbi_image_free(rgb_image);

		return imageVector;
	}
};