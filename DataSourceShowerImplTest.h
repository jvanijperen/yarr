#ifndef DATASOURCESHOWERIMPLTEST_H_
#define DATASOURCESHOWERIMPLTEST_H_

#include <cxxtest/TestSuite.h>

#include <sstream>
#include "DataSourceShowerImpl.h"

class DataSourceShowerImplTest : public CxxTest::TestSuite
{
protected:
	std::ostringstream outputStringStream;
	std::ostream &outStream = outputStringStream;
	DataSourceShowerImpl self;

public:
	DataSourceShowerImplTest()
	: self(outStream)
	{
	}

	void setUp()
	{
		outputStringStream.str("");
	}

public:
	void test_showLineWithEmptyLineEntry_showsNoOutput()
	{
		LineEntry emptyLineEntry;
		self.showLine(emptyLineEntry);
		TS_ASSERT_EQUALS(outputStringStream.str(), "\n");
	}

	void test_showLineWithFilledLineEntry_showsEntryContents()
	{
		LineEntry filledLineEntry = { "line" };
		self.showLine(filledLineEntry);
		TS_ASSERT_EQUALS(outputStringStream.str(), filledLineEntry.line + "\n");
	}
};

class DataSourceShowerImplTestWithNoSources : public CxxTest::TestSuite
{
protected:
	std::ostringstream outputStringStream;
	std::ostream &outStream = outputStringStream;
	DataSourceShowerImpl self;

public:
	DataSourceShowerImplTestWithNoSources()
	: self(outStream)
	{
	}

	void setUp()
	{
		outputStringStream.str("");
	}

public:
	void test_showChoices_withEmptySetOfDataSources_showsBaseText()
	{
		DataSourceCollection emptyDataSources;
		self.showChoices(emptyDataSources);

		TS_ASSERT_EQUALS(outputStringStream.str(), "(H) for help\n(X) to quit\n > ");
	}
};

#endif /* DATASOURCESHOWERIMPLTEST_H_ */
