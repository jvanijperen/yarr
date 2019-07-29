#include "PlainFileDataSource.h"

PlainFileDataSource::PlainFileDataSource(std::istream &in)
: _dataEntryList()
{
	static const int maxLineLength = 1024;
	while (in.good()) {
		LineEntry entry;
		char lineBuf[maxLineLength];
		in.getline(lineBuf, maxLineLength);
		entry.line = lineBuf;
		if (entry.line.size() > 0) {
			_dataEntryList.push_back(entry);
		}
	}
}

const std::vector<LineEntry> &PlainFileDataSource::getAllLineEntries() const {
	return _dataEntryList;
}
