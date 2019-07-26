#ifndef LINEENTRYPROVIDER_H_
#define LINEENTRYPROVIDER_H_

#include "LineEntry.h"

class LineEntryProvider
{
public:
	virtual ~LineEntryProvider() = 0;
	virtual LineEntry chooseLineEntry() const = 0;
};
inline LineEntryProvider::~LineEntryProvider() {}

#endif /* LINEENTRYPROVIDER_H_ */
