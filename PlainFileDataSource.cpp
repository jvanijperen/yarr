#include "PlainFileDataSource.h"

PlainFileDataSource::PlainFileDataSource(std::istream &in)
: dataEntryList()
{
	populateLineEntries(in);
}

void PlainFileDataSource::populateLineEntries(std::istream &in) {
	static const int maxLineLength = 1024;
	char lineBuf[maxLineLength];
	while (in.good()) {
		in.getline(lineBuf, maxLineLength);
		LineEntry entry = { lineBuf };
		if (entry.line.size() > 0) {
			dataEntryList.push_back(entry);
		}
	}
}

const std::vector<LineEntry> &PlainFileDataSource::getAllLineEntries() const {
	return dataEntryList;
}
