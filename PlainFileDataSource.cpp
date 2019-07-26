#include "PlainFileDataSource.h"

PlainFileDataSource::PlainFileDataSource(std::istream &in)
: _dataEntryList()
{
	while (in.good()) {
		DataEntry entry;
		char lineBuf[1024];
		in.getline(lineBuf, 1024);
		entry.line = lineBuf;
		if (entry.line.size() > 0) {
			_dataEntryList.push_back(entry);
		}
	}
}

PlainFileDataSource::~PlainFileDataSource() {
}

const std::vector<DataEntry> &PlainFileDataSource::getAllDataEntries() const {
	return _dataEntryList;
}