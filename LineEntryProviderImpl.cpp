#include "LineEntryProviderImpl.h"

LineEntryProviderImpl::LineEntryProviderImpl(DataSource &dataSource, NumberGenerator &numberGenerator)
: dataSource(dataSource)
, numberGenerator(numberGenerator)
{
}

LineEntry LineEntryProviderImpl::chooseLineEntry() const {
	LineEntry dataEntry;

	return dataEntry;
}
