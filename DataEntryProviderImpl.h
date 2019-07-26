#ifndef DATAENTRYPROVIDERIMPL_H_
#define DATAENTRYPROVIDERIMPL_H_

#include "DataEntryProvider.h"
#include "IDataSource.h"
#include "INumberGenerator.h"

class DataEntryProviderImpl : public DataEntryProvider
{
public:
	DataEntryProviderImpl(IDataSource &dataSource, INumberGenerator &numberGenerator);
	~DataEntryProviderImpl();
	virtual DataEntry chooseDataEntry() const;

private:
	IDataSource &dataSource;
	INumberGenerator &numberGenerator;
};

#endif /* DATAENTRYPROVIDERIMPL_H_ */
