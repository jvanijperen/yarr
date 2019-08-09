#ifndef USERINTERACTORTEST_H_
#define USERINTERACTORTEST_H_

#include "UserInteractor.h"

#include <cxxtest/TestSuite.h>

class UserInteractorTest : public CxxTest::TestSuite
{
protected:
	UserInteractor self;
public:
	void test_empty()
	{
		TS_ASSERT(true);
	}
};

#endif /* USERINTERACTORTEST_H_ */
