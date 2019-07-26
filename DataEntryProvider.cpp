#include "DataEntryProvider.h"

DataEntryProvider::DataEntryProvider(IDataSource &dataSource, INumberGenerator &numberGenerator)
: dataSource(dataSource)
, numberGenerator(numberGenerator)
{
}

DataEntryProvider::~DataEntryProvider() {
}

DataEntry DataEntryProvider::chooseDataEntry() const {
	DataEntry dataEntry;

	return dataEntry;
}
