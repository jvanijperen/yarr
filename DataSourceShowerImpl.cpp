#include "DataSourceShowerImpl.h"

DataSourceShowerImpl::DataSourceShowerImpl(std::ostream &outStream)
: outStream(outStream)
{
}

DataSourceShowerImpl::~DataSourceShowerImpl()
{
}

void DataSourceShowerImpl::showLine(LineEntry &entry) {
	outStream << entry.line << std::endl;
}

void DataSourceShowerImpl::printBaseText() {
	outStream << "(H) for help" << std::endl;
	outStream << "(X) to quit" << std::endl;
}

void DataSourceShowerImpl::printPrompt() {
	outStream << " > ";
	outStream.flush();
}

void DataSourceShowerImpl::showChoices(std::vector<DataSource*> &/*sources*/) {
	printBaseText();
	printPrompt();
}
