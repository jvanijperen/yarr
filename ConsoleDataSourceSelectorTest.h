#ifndef CONSOLEDATASOURCESELECTORTEST_H_
#define CONSOLEDATASOURCESELECTORTEST_H_

#include <cxxtest/TestSuite.h>

#include <sstream>
#include <limits>
#include "ConsoleDataSourceSelector.h"

CXXTEST_ENUM_TRAITS(DataSourceChoice,
					CXXTEST_ENUM_MEMBER(InvalidChoice)
					CXXTEST_ENUM_MEMBER(QuitChoice)
					CXXTEST_ENUM_MEMBER(HelpChoice));

class ConsoleDataSourceSelectorTest : public CxxTest::TestSuite
{
protected:
	std::istringstream inputStringStream;
	std::istream &inputStream = inputStringStream;
	ConsoleDataSourceSelector self;

public:
	ConsoleDataSourceSelectorTest()
	: self(inputStream)
	{
	}

	void setUp()
	{
		inputStringStream.str("");
		inputStringStream.clear();
	}

	void test_getChoice_eof_returnsQuitChoice() {
		inputStringStream.str("");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, QuitChoice);
	}

	void test_getChoice_onlyWhiteSpace_returnsQuitChoice() {
		inputStringStream.str("    \t\r\n\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, QuitChoice);
	}

	void test_getChoice_q_returnsQuitChoice() {
		inputStringStream.str("q\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, QuitChoice);
	}

	void test_getChoice_whiteSpacePlusQ_returnsQuitChoice() {
		inputStringStream.str("   \t\nq\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, QuitChoice);
	}

	void test_getChoice_quit_returnsInvalidChoice() {
		inputStringStream.str("quit\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, InvalidChoice);
	}

	void test_getChoice_h_returnsHelpChoice() {
		inputStringStream.str("h\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, HelpChoice);
	}

	void test_getChoice_invalidNumeric_returnsInvalidChoice() {
		inputStringStream.str("-1\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, InvalidChoice);
	}

	void test_getChoice_validNumericAboveNrDataSources_returnsInvalidChoice() {
		int nrDataSources = 0;
		self.setNumberDataSources(nrDataSources);
		inputStringStream.str("1\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, InvalidChoice);
	}

	void test_getChoice_validNumericEqualDataSources_returnsNumeric() {
		int nrDataSources = 1;
		self.setNumberDataSources(nrDataSources);
		inputStringStream.str("1\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, 1);
	}

	void test_getChoice_validNumericBelowDataSources_returnsNumeric() {
		int nrDataSources = 2;
		self.setNumberDataSources(nrDataSources);
		inputStringStream.str("1\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, 1);
	}

	void test_getChoice_validNumericAboveMaxInt_returnsInvalidChoice() {
		unsigned int nrDataSources = std::numeric_limits<unsigned int>::max();
		self.setNumberDataSources(nrDataSources);

		long overflowInt = std::numeric_limits<int>::max() + 1l;
		std::ostringstream overflowStringStream;
		overflowStringStream << overflowInt << "\n";
		inputStringStream.str(overflowStringStream.str());

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, InvalidChoice);
	}


	void test_getChoice_quitThenQ_returnsInvalidThenQuitChoice() {
		inputStringStream.str("quit\nq\n");

		int choice1 = self.getChoice();
		int choice2 = self.getChoice();

		TS_ASSERT_EQUALS(choice1, InvalidChoice);
		TS_ASSERT_EQUALS(choice2, QuitChoice);
	}

	void test_setGetNumberDataSources_zero() {
		unsigned int value = 0;
		self.setNumberDataSources(value);

		unsigned int dataSources = self.getNumberDataSources();

		TS_ASSERT_EQUALS(dataSources, value);
	}

	void test_setGetNumberDataSources_maxUint() {
		unsigned int value = std::numeric_limits<unsigned int>::max();
		self.setNumberDataSources(value);

		unsigned int dataSources = self.getNumberDataSources();

		TS_ASSERT_EQUALS(dataSources, value);
	}


};

#endif /* CONSOLEDATASOURCESELECTORTEST_H_ */
