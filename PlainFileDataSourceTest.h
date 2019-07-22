#ifndef PLAINFILEDATASOURCETEST_H_
#define PLAINFILEDATASOURCETEST_H_

#include <cxxtest/TestSuite.h>
#include "PlainFileDataSource.h"
#include <sstream>

class PlainFileDataSourceTest : public CxxTest::TestSuite
{
public:
	void test_emptyFile_returnsEmptyList()
	{
		std::istringstream in("");
		PlainFileDataSource self(in);
		std::vector<DataEntry> dataEntryList = self.getAllDataEntries();
		TS_ASSERT_EQUALS(dataEntryList.size(), 0);
	}

	void test_onlyNewLinesFile_returnsEmptyList()
	{
		std::istringstream in("\n\n\n\n\n\n");
		PlainFileDataSource self(in);
		std::vector<DataEntry> dataEntryList = self.getAllDataEntries();
		TS_ASSERT_EQUALS(dataEntryList.size(), 0);
	}

	void test_singleLineFile_returnsListWithOneEntry()
	{
		std::string lineOne = "lineOne";
		std::istringstream in(lineOne);
		PlainFileDataSource self(in);

		std::vector<DataEntry> dataEntryList = self.getAllDataEntries();

		TS_ASSERT_EQUALS(dataEntryList.size(), 1);
		TS_ASSERT_EQUALS(dataEntryList.front().line, lineOne);
	}

	void test_multipleLineFiles_returnsThoseLines()
	{
		std::string lineOne = "lineOne";
		std::string lineTwo = "lineTwo";
		std::stringstream multiLineStream;
		multiLineStream << lineOne << "\n" << lineTwo;
		PlainFileDataSource self(multiLineStream);

		std::vector<DataEntry> dataEntryList = self.getAllDataEntries();

		TS_ASSERT_EQUALS(dataEntryList.size(), 2);
		TS_ASSERT_EQUALS(dataEntryList[0].line, lineOne);
		TS_ASSERT_EQUALS(dataEntryList[1].line, lineTwo);
	}

	void test_multipleNormalAndEmptyLines_returnOnlyNormalLines()
	{
		std::string lines =
				"lineOne\n"
				"\n"
				"lineTwo\n"
				"\n"
				"\n"
				"lineThree";
		std::stringstream multiLineStream(lines);
		PlainFileDataSource self(multiLineStream);

		std::vector<DataEntry> dataEntryList = self.getAllDataEntries();

		TS_ASSERT_EQUALS(dataEntryList.size(), 3);
		TS_ASSERT_EQUALS(dataEntryList[0].line, "lineOne");
		TS_ASSERT_EQUALS(dataEntryList[1].line, "lineTwo");
		TS_ASSERT_EQUALS(dataEntryList[2].line, "lineThree");
	}
};

#endif /* PLAINFILEDATASOURCETEST_H_ */
