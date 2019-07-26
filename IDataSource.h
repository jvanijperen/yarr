#ifndef IDATASOURCE_H_
#define IDATASOURCE_H_

#include "DataEntry.h"
#include <vector>

class IDataSource
{
public:
	virtual ~IDataSource() = 0;
	virtual const std::vector<DataEntry> &getAllDataEntries() const = 0;
};
inline IDataSource::~IDataSource() {}

#endif /* IDATASOURCE_H_ */
