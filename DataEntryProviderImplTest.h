#ifndef DATAENTRYPROVIDERIMPLTEST_H_
#define DATAENTRYPROVIDERIMPLTEST_H_

#include "DataEntryProviderImpl.h"

#include <cxxtest/TestSuite.h>

class EmptyDataSourceFake : public IDataSource
{
public:
	~EmptyDataSourceFake() {}
	const std::vector<DataEntry> &getAllDataEntries() const
	{
		static std::vector<DataEntry> emptyVector = { };
		return emptyVector;
	}
};

class NumberGeneratorFake : public INumberGenerator
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
		DataEntryProviderImpl self(emptyDataSource, fakeNumberGenerator);

		DataEntry entry = self.chooseDataEntry();

		TS_ASSERT_EQUALS(entry.line, "");
	}
};

#endif /* DATAENTRYPROVIDERIMPLTEST_H_ */
