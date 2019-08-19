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

void DataSourceShowerImpl::showChoices(std::vector<DataSource*> &sources) {
	printSources(sources);
	printBaseText();
	printPrompt();
}

void DataSourceShowerImpl::printSources(std::vector<DataSource*> &sources) {
	for (unsigned int i = 0; i < sources.size(); ++i) {
		const DataSource *curSource = sources.at(i);
		outStream << "(" << i + 1 << ") for "
				<< getPrintableNameForDataSource(curSource)
				<< std::endl;
	}
}

std::string DataSourceShowerImpl::getPrintableNameForDataSource(const DataSource *dataSource) {
	std::string name = dataSource->getName();
	if (name == "")
		return "<unknown>";
	else
		return name;
}

void DataSourceShowerImpl::printBaseText() {
	outStream << "(H) for help" << std::endl;
	outStream << "(X) to quit" << std::endl;
}

void DataSourceShowerImpl::printPrompt() {
	outStream << " > ";
	outStream.flush();
}
