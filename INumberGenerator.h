#ifndef INUMBERGENERATOR_H_
#define INUMBERGENERATOR_H_

class INumberGenerator
{
public:
	// Generate an integer value between [0, maxValue>. (I.e. excluding maxValue)
	virtual int generate(int maxValue) = 0;

	virtual ~INumberGenerator() = 0;
};
inline INumberGenerator::~INumberGenerator()
{ }

#endif /* INUMBERGENERATOR_H_ */
