#ifndef DATAENTRYPROVIDERTEST_H_
#define DATAENTRYPROVIDERTEST_H_

#include <cxxtest/TestSuite.h>
#include "DataEntryProvider.h"

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
		DataEntryProvider self(emptyDataSource, fakeNumberGenerator);

		DataEntry entry = self.chooseDataEntry();

		TS_ASSERT_EQUALS(entry.line, "");
	}
};

#endif /* DATAENTRYPROVIDERTEST_H_ */
