#include "DataEntryProviderImpl.h"

DataEntryProviderImpl::DataEntryProviderImpl(IDataSource &dataSource, INumberGenerator &numberGenerator)
: dataSource(dataSource)
, numberGenerator(numberGenerator)
{
}

DataEntryProviderImpl::~DataEntryProviderImpl() {
}

DataEntry DataEntryProviderImpl::chooseDataEntry() const {
	DataEntry dataEntry;

	return dataEntry;
}
