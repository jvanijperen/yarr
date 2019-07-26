#ifndef PLAINFILEDATASOURCE_H_
#define PLAINFILEDATASOURCE_H_

#include <istream>
#include "DataSource.h"

class PlainFileDataSource : public DataSource
{
public:
	PlainFileDataSource(std::istream &in);
	~PlainFileDataSource();
	virtual const std::vector<DataEntry> &getAllDataEntries() const;

private:
	std::vector<DataEntry> _dataEntryList;
};

#endif /* PLAINFILEDATASOURCE_H_ */
