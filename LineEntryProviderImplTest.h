#ifndef LINEENTRYPROVIDERIMPLTEST_H_
#define LINEENTRYPROVIDERIMPLTEST_H_

#include "LineEntryProviderImpl.h"

#include <cxxtest/TestSuite.h>

class EmptyDataSourceFake : public DataSource
{
public:
	~EmptyDataSourceFake() {}
	const std::vector<LineEntry> &getAllLineEntries() const
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

class SingleDataSourceFake : public DataSource
{
public:
	~SingleDataSourceFake() {}
	const std::vector<LineEntry> &getAllLineEntries() const
	{
		const static std::vector<LineEntry> lineEntries = { {"non-empty"} };
		return lineEntries;
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

	void test_dataSource_providesDataEntry()
	{
		SingleDataSourceFake dataSource;
		NumberGeneratorFake fakeNumberGenerator;
		LineEntryProviderImpl self(dataSource, fakeNumberGenerator);

		LineEntry entry = self.chooseLineEntry();

		TS_ASSERT_EQUALS(entry.line, "non-empty");
	}
};

#endif /* LINEENTRYPROVIDERIMPLTEST_H_ */
