#include "ConsoleDataSourceSelector.h"

ConsoleDataSourceSelector::ConsoleDataSourceSelector(std::istream &inStream)
: inStream(inStream)
{
}

ConsoleDataSourceSelector::~ConsoleDataSourceSelector()
{
}

int ConsoleDataSourceSelector::getChoice() {
	inStream >> std::ws;
	if (inStream.eof())
		return QuitChoice;
	return parseChoice();
}

int ConsoleDataSourceSelector::parseChoice() {
	int peekChar = inStream.peek();

	if (std::isdigit(peekChar))
		return parseNumericChoice();
	return parseStringChoice();
}

int ConsoleDataSourceSelector::parseNumericChoice() {
	int numericChoice;
	inStream >> numericChoice;
	return numericChoice;
}

int ConsoleDataSourceSelector::parseStringChoice() {
	std::string choiceString;
	inStream >> choiceString;
	if (choiceString == "q")
		return QuitChoice;
	if (choiceString == "h")
		return HelpChoice;
	return InvalidChoice;
}
