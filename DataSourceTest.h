#ifndef DATASOURCETEST_H_
#define DATASOURCETEST_H_

#include <cxxtest/TestSuite.h>
#include <exception>
#include "DataSource.h"

class DataSourceUnderTest : public DataSource
{
public:
	DataSourceUnderTest(std::string name)
	: DataSource(name)
	{
	}

	const std::vector<LineEntry> &getAllLineEntries() const
	{
		throw new std::exception;
	}
};

class DataSourceTest : public CxxTest::TestSuite
{
public:
	void test_createNamedDataSource()
	{
		std::string name = "name";
		DataSourceUnderTest thisDataSource(name);

		TS_ASSERT_EQUALS(thisDataSource.getName(), name);
	}

};

#endif /* DATASOURCETEST_H_ */
