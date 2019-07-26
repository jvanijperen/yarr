#ifndef DATAENTRYPROVIDER_H_
#define DATAENTRYPROVIDER_H_

#include "IDataEntryProvider.h"
#include "IDataSource.h"
#include "INumberGenerator.h"

class DataEntryProvider : public IDataEntryProvider
{
public:
	DataEntryProvider(IDataSource &dataSource, INumberGenerator &numberGenerator);
	~DataEntryProvider();
	virtual DataEntry chooseDataEntry() const;

private:
	IDataSource &dataSource;
	INumberGenerator &numberGenerator;
};

#endif /* DATAENTRYPROVIDER_H_ */
