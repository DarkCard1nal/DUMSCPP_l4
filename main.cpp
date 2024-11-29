#include "image.hpp"
#include "pgma_strategy.hpp"
#include "ppm_strategy.hpp"
#include <iostream>

int main()
{
	try
	{
		// Using PGMA Strategy
		auto pgmaStrategy = std::make_shared<PGMAStrategy>();
		Image image(0, 0, pgmaStrategy);

		if (image.load("feep.ascii.pgm"))
		{
			std::cout << "PGMA Image loaded successfully.\n";
			// Image change
			for (size_t i = 0; i < 24; i += 2)
			{
				image.at(0, i) = 255;
				image.at(6, i + 1) = 255;
			}
			std::cout << "Image changed successfully:\n";
			for (int value : image.getPixels())
			{
				std::cout << value << " ";
			}
			std::cout << std::endl;

			image.save("output_pgma.pgm");
			std::cout << "Image save to output_pgma.pgm successfully.\n";
		}
		// Switching to PPM Strategy
		auto ppmStrategy = std::make_shared<PPMStrategy>();
		image.setStrategy(ppmStrategy);

		if (image.load("feep.ppma"))
		{
			std::cout << "PPM Image loaded successfully.\n";
			for (int value : image.getPixels())
			{
				std::cout << value << " ";
			}
			std::cout << std::endl;
			image.save("output_ppm.ppm");
			std::cout << "Image save to output_ppm.ppm successfully.\n";
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << "\n";
	}

	return 0;
}