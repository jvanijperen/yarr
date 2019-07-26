#ifndef DATAENTRYPROVIDER_H_
#define DATAENTRYPROVIDER_H_

#include "DataEntry.h"

class DataEntryProvider
{
public:
	virtual ~DataEntryProvider() = 0;
	virtual DataEntry chooseDataEntry() const = 0;
};
inline DataEntryProvider::~DataEntryProvider() {}

#endif /* DATAENTRYPROVIDER_H_ */
