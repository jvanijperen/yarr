#ifndef DATAENTRYPROVIDERIMPL_H_
#define DATAENTRYPROVIDERIMPL_H_

#include "DataEntryProvider.h"
#include "DataSource.h"
#include "INumberGenerator.h"

class DataEntryProviderImpl : public DataEntryProvider
{
public:
	DataEntryProviderImpl(DataSource &dataSource, INumberGenerator &numberGenerator);
	~DataEntryProviderImpl();
	virtual DataEntry chooseDataEntry() const;

private:
	DataSource &dataSource;
	INumberGenerator &numberGenerator;
};

#endif /* DATAENTRYPROVIDERIMPL_H_ */
