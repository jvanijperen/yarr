#include "RandomNumberGenerator.h"
#include <stdexcept>
#include <chrono>


RandomNumberGenerator::RandomNumberGenerator()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	rngEngine = new std::default_random_engine(seed);
}

RandomNumberGenerator::RandomNumberGenerator(int seed)
{
	rngEngine = new std::default_random_engine(seed);
}

RandomNumberGenerator::~RandomNumberGenerator()
{
	delete rngEngine;
}

int RandomNumberGenerator::generate(int maxValue)
{
	if (maxValue <= 0)
		throw std::invalid_argument("invalid maxValue");
	std::uniform_int_distribution<int> distribution(0, maxValue - 1);
	return distribution(*rngEngine);
}

