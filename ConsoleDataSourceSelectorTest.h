#ifndef CONSOLEDATASOURCESELECTORTEST_H_
#define CONSOLEDATASOURCESELECTORTEST_H_

#include <cxxtest/TestSuite.h>

#include <sstream>
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

	void test_getChoice_validNumeric_returnsNumeric() {
		inputStringStream.str("1\n");

		int choice = self.getChoice();

		TS_ASSERT_EQUALS(choice, 1);
	}

};

#endif /* CONSOLEDATASOURCESELECTORTEST_H_ */
