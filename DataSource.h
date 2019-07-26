#ifndef DATASOURCE_H_
#define DATASOURCE_H_

#include "DataEntry.h"
#include <vector>

class DataSource
{
public:
	virtual ~DataSource() = 0;
	virtual const std::vector<DataEntry> &getAllDataEntries() const = 0;
};
inline DataSource::~DataSource() {}

#endif /* DATASOURCE_H_ */
