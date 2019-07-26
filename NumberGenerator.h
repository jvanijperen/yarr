#ifndef NUMBERGENERATOR_H_
#define NUMBERGENERATOR_H_

class NumberGenerator
{
public:
	virtual ~NumberGenerator() {}
	// Generate an integer value between [0, maxValue>. (I.e. excluding maxValue)
	virtual int generate(int maxValue) = 0;
};

#endif /* NUMBERGENERATOR_H_ */
