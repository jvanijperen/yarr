#ifndef LINEENTRYPROVIDERIMPLTEST_H_
#define LINEENTRYPROVIDERIMPLTEST_H_

#include "LineEntryProviderImpl.h"

#include <cxxtest/TestSuite.h>

class EmptyDataSourceFake : public DataSource
{
public:
	~EmptyDataSourceFake() {}
	const std::vector<LineEntry> &getAllDataEntries() const
	{
		static std::vector<LineEntry> emptyVector = { };
		return emptyVector;
	}
};

class NumberGeneratorFake : public NumberGenerator
{
public:
	~NumberGeneratorFake() {}
	int generate(int /*maxValue*/)
	{
		return 0;
	}
};


class DataEntryProviderTest : public CxxTest::TestSuite
{
public:
	void test_emptyDataSource_providesEmptyDataEntries()
	{
		EmptyDataSourceFake emptyDataSource;
		NumberGeneratorFake fakeNumberGenerator;
		LineEntryProviderImpl self(emptyDataSource, fakeNumberGenerator);

		LineEntry entry = self.chooseLineEntry();

		TS_ASSERT_EQUALS(entry.line, "");
	}
};

#endif /* LINEENTRYPROVIDERIMPLTEST_H_ */
