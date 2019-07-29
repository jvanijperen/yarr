#include "LineEntryProviderImpl.h"

LineEntryProviderImpl::LineEntryProviderImpl(DataSource &dataSource, NumberGenerator &numberGenerator)
: dataSource(dataSource)
, numberGenerator(numberGenerator)
{
}

LineEntry LineEntryProviderImpl::chooseLineEntry() const {
	auto &allEntries = dataSource.getAllLineEntries();
	if (allEntries.size() == 0) {
		LineEntry dataEntry;
		return dataEntry;
	} else {
		return allEntries.at(numberGenerator.generate(allEntries.size()));
	}
}
