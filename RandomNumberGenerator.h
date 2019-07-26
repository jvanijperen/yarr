#ifndef RANDOMNUMBERGENERATOR_H_
#define RANDOMNUMBERGENERATOR_H_

#include <random>
#include "NumberGenerator.h"

class RandomNumberGenerator : public NumberGenerator
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
