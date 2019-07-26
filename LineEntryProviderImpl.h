#ifndef LINEENTRYPROVIDERIMPL_H_
#define LINEENTRYPROVIDERIMPL_H_

#include "DataSource.h"
#include "LineEntryProvider.h"
#include "NumberGenerator.h"

class LineEntryProviderImpl : public LineEntryProvider
{
public:
	LineEntryProviderImpl(DataSource &dataSource, NumberGenerator &numberGenerator);
	~LineEntryProviderImpl();
	virtual LineEntry chooseLineEntry() const;

private:
	DataSource &dataSource;
	NumberGenerator &numberGenerator;
};

#endif /* LINEENTRYPROVIDERIMPL_H_ */
