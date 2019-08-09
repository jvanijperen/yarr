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
