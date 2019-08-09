#ifndef PLAINFILEDATASOURCE_H_
#define PLAINFILEDATASOURCE_H_

#include <istream>
#include "DataSource.h"

class PlainFileDataSource : public DataSource
{
public:
	PlainFileDataSource(std::istream &in);
	PlainFileDataSource(std::string name, std::istream &in);
	virtual const std::vector<LineEntry> &getAllLineEntries() const;

private:
	void populateLineEntries(std::istream &in);

private:
	std::vector<LineEntry> dataEntryList;
};

#endif /* PLAINFILEDATASOURCE_H_ */
