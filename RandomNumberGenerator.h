#ifndef RANDOMNUMBERGENERATOR_H_
#define RANDOMNUMBERGENERATOR_H_

#include "INumberGenerator.h"
#include <random>

class RandomNumberGenerator : public INumberGenerator
{
public:
	RandomNumberGenerator();
	RandomNumberGenerator(int seed);

	virtual ~RandomNumberGenerator();

	int generate(int maxValue);

private:
	std::default_random_engine *rngEngine;
};

#endif /* RANDOMNUMBERGENERATOR_H_ */
