#ifndef IDATAENTRYPROVIDER_H_
#define IDATAENTRYPROVIDER_H_

#include "DataEntry.h"

class IDataEntryProvider
{
public:
	virtual ~IDataEntryProvider() = 0;
	virtual DataEntry chooseDataEntry() const = 0;
};
inline IDataEntryProvider::~IDataEntryProvider() {}

#endif /* IDATAENTRYPROVIDER_H_ */
