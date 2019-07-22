/*
 * PlainFileDataSource.h
 *
 *  Created on: Jul 22, 2019
 *      Author: jvy
 */

#ifndef PLAINFILEDATASOURCE_H_
#define PLAINFILEDATASOURCE_H_

#include "IDataSource.h"
#include <istream>

class PlainFileDataSource : public IDataSource
{
public:
	PlainFileDataSource(std::istream &in);
	~PlainFileDataSource();
	virtual std::vector<DataEntry> getAllDataEntries() const;

private:
	std::vector<DataEntry> _dataEntryList;
};

#endif /* PLAINFILEDATASOURCE_H_ */
