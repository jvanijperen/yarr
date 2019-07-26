#include "DataEntryProviderImpl.h"

DataEntryProviderImpl::DataEntryProviderImpl(DataSource &dataSource, NumberGenerator &numberGenerator)
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
