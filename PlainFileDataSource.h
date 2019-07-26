#ifndef PLAINFILEDATASOURCE_H_
#define PLAINFILEDATASOURCE_H_

#include <istream>
#include "DataSource.h"

class PlainFileDataSource : public DataSource
{
public:
	PlainFileDataSource(std::istream &in);
	virtual const std::vector<LineEntry> &getAllLineEntries() const;

private:
	std::vector<LineEntry> _dataEntryList;
};

#endif /* PLAINFILEDATASOURCE_H_ */
