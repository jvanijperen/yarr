#ifndef PLAINFILEDATASOURCE_H_
#define PLAINFILEDATASOURCE_H_

#include "IDataSource.h"
#include <istream>

class PlainFileDataSource : public IDataSource
{
public:
	PlainFileDataSource(std::istream &in);
	~PlainFileDataSource();
	virtual const std::vector<DataEntry> &getAllDataEntries() const;

private:
	std::vector<DataEntry> _dataEntryList;
};

#endif /* PLAINFILEDATASOURCE_H_ */
