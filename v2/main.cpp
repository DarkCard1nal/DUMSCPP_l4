#include "pgma_image.hpp"
#include "ppm_image.hpp"
#include <iostream>
#include <memory>

int main()
{
	try
	{
		std::unique_ptr<Image> image1 = std::make_unique<PGMAImage>(0, 0);
		if (image1->load("feep.ascii.pgm"))
		{
			std::cout << "PGMA Image loaded successfully.\n";
			for (size_t i = 0; i < 24; i += 2)
			{
				image1->at(0, i) = 255;
				image1->at(6, i + 1) = 255;
			}
			std::cout << "Image changed successfully:\n";
			for (int value : image1->getPixels())
			{
				std::cout << value << " ";
			}
			std::cout << std::endl;
			image1->save("output_pgma.pgm");
			std::cout << "PGMA Image saved successfully.\n";
		}

		std::unique_ptr<Image> image2 = std::make_unique<PPMImage>(0, 0);
		if (image2->load("feep.ppma"))
		{
			std::cout << "PPM Image loaded successfully.\n";
			for (int value : image2->getPixels())
			{
				std::cout << value << " ";
			}
			std::cout << std::endl;
			image2->save("output_ppm.ppm");
			std::cout << "PPM Image saved successfully.\n";
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}

	return 0;
}