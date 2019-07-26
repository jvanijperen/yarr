#ifndef LINEENTRYPROVIDER_H_
#define LINEENTRYPROVIDER_H_

#include "LineEntry.h"

class LineEntryProvider
{
public:
	virtual ~LineEntryProvider() {};
	virtual LineEntry chooseLineEntry() const = 0;
};

#endif /* LINEENTRYPROVIDER_H_ */
