#ifndef DATAENTRYPROVIDERIMPL_H_
#define DATAENTRYPROVIDERIMPL_H_

#include "DataEntryProvider.h"
#include "DataSource.h"
#include "NumberGenerator.h"

class DataEntryProviderImpl : public DataEntryProvider
{
public:
	DataEntryProviderImpl(DataSource &dataSource, NumberGenerator &numberGenerator);
	~DataEntryProviderImpl();
	virtual DataEntry chooseDataEntry() const;

private:
	DataSource &dataSource;
	NumberGenerator &numberGenerator;
};

#endif /* DATAENTRYPROVIDERIMPL_H_ */
