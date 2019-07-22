#ifndef RANDOMNUMBERGENERATORTEST_H_
#define RANDOMNUMBERGENERATORTEST_H_

#include <cxxtest/TestSuite.h>
#include <limits>
#include "RandomNumberGenerator.h"

class RandomNumberGeneratorTest : public CxxTest::TestSuite
{
private:
	INumberGenerator *rng;
public:
	RandomNumberGeneratorTest()
	{
		rng = new RandomNumberGenerator();
	}

	~RandomNumberGeneratorTest()
	{
		delete rng;
	}

public:
	void test_generateWithMaxNegativeNumber(void)
	{
		TS_ASSERT_THROWS(rng->generate(-1), std::invalid_argument &);
	}

	void test_generateWithMaxZero(void)
	{
		TS_ASSERT_THROWS(rng->generate(0), std::invalid_argument &);
	}

	void test_generateWithMaxOne(void)
	{
		TS_ASSERT_EQUALS(rng->generate(1), 0);
	}

	void test_generateWithMaxInt(void)
	{
		int value = rng->generate(std::numeric_limits<int>::max());
		TS_ASSERT(value >= 0 && value < std::numeric_limits<int>::max());
	}

	void test_twoGeneratesReturnsDifferentNumberWithMaxInt(void)
	{
		int value1 = rng->generate(std::numeric_limits<int>::max());
		int value2 = rng->generate(std::numeric_limits<int>::max());

		TS_ASSERT_DIFFERS(value1, value2);
	}

};

#endif /* RANDOMNUMBERGENERATORTEST_H_ */
