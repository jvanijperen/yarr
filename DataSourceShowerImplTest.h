#ifndef DATASOURCESHOWERIMPLTEST_H_
#define DATASOURCESHOWERIMPLTEST_H_

#include <cxxtest/TestSuite.h>

#include "DataSourceShowerImpl.h"

class DataSourceShowerImplTest : public CxxTest::TestSuite
{
protected:
	DataSourceShowerImpl *self = nullptr;
public:
	void test_createDataSourceShowerImpl()
	{
		TS_ASSERT(true);
	}
};

#endif /* DATASOURCESHOWERIMPLTEST_H_ */
