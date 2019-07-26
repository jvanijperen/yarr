#ifndef NUMBERGENERATOR_H_
#define NUMBERGENERATOR_H_

class NumberGenerator
{
public:
	// Generate an integer value between [0, maxValue>. (I.e. excluding maxValue)
	virtual int generate(int maxValue) = 0;

	virtual ~NumberGenerator() = 0;
};
inline NumberGenerator::~NumberGenerator()
{ }

#endif /* NUMBERGENERATOR_H_ */
