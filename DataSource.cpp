#include "DataSource.h"

DataSource::DataSource(std::string name)
: name(name)
{
}

std::string DataSource::getName() const {
	return name;
}
