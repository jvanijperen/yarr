#ifndef DATASOURCE_H_
#define DATASOURCE_H_

#include <vector>
#include "LineEntry.h"

class DataSource
{
public:
	virtual ~DataSource() = 0;
	virtual const std::vector<LineEntry> &getAllDataEntries() const = 0;
};
inline DataSource::~DataSource() {}

#endif /* DATASOURCE_H_ */
