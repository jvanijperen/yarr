#ifndef DATASOURCESHOWERIMPLTEST_H_
#define DATASOURCESHOWERIMPLTEST_H_

#include <cxxtest/TestSuite.h>

#include <sstream>
#include "DataSourceShowerImpl.h"
#include "DataSource.h"

class UnspecifiedDataSource : public DataSource
{
public:
	UnspecifiedDataSource() : DataSource("") {}

	const std::vector<LineEntry> &getAllLineEntries() const
	{
		throw new std::exception();
	}
};

class NamedDataSource : public DataSource
{
public:
	NamedDataSource(std::string name) : DataSource(name) {}

	const std::vector<LineEntry> &getAllLineEntries() const
	{
		throw new std::exception();
	}
};


class DataSourceShowerImplTest : public CxxTest::TestSuite
{
protected:
	std::ostringstream outputStringStream;
	std::ostream &outStream = outputStringStream;
	DataSourceShowerImpl self;

	std::string baseText = "(H) for help\n(X) to quit\n > ";

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

	void test_showChoices_withEmptySetOfDataSources_showsBaseText()
	{
		DataSourceCollection emptyDataSources;
		self.showChoices(emptyDataSources);

		TS_ASSERT_EQUALS(outputStringStream.str(), baseText);
	}

	void test_showChoices_withSingleUnspecifiedDataSource_showsUnknownAndBaseText()
	{
		DataSourceCollection dataSources;
		UnspecifiedDataSource unspecifiedDataSource;
		dataSources.push_back(&unspecifiedDataSource);

		self.showChoices(dataSources);

		TS_ASSERT_EQUALS(outputStringStream.str(), "(1) for <unknown>\n" + baseText);
	}

	void test_showChoices_withSingleNamedDataSource_showsNamedChoiceAndBaseText()
	{
		std::string dataSourceName = "dataSourceName";
		DataSourceCollection dataSources;
		NamedDataSource namedDataSource(dataSourceName);
		dataSources.push_back(&namedDataSource);

		self.showChoices(dataSources);

		TS_ASSERT_EQUALS(outputStringStream.str(), "(1) for dataSourceName\n" + baseText);
	}

	void test_showChoices_withTwoNamedDataSources_showsNamedChoicesAndBaseText()
	{
		std::string dataSourceName1 = "dataSourceName1";
		std::string dataSourceName2 = "dataSourceName2";
		NamedDataSource namedDataSources[] = { { dataSourceName1 }, { dataSourceName2 } };
		DataSourceCollection dataSources;
		dataSources.push_back(&namedDataSources[0]);
		dataSources.push_back(&namedDataSources[1]);

		self.showChoices(dataSources);

		TS_ASSERT_EQUALS(outputStringStream.str(),
				"(1) for dataSourceName1\n(2) for dataSourceName2\n" + baseText);
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
};



#endif /* DATASOURCESHOWERIMPLTEST_H_ */
