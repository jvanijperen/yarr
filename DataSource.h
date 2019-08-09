#ifndef DATASOURCE_H_
#define DATASOURCE_H_

#include <vector>
#include <string>
#include "LineEntry.h"

class DataSource
{
public:
	DataSource(std::string name);
	virtual ~DataSource() {}
	virtual const std::vector<LineEntry> &getAllLineEntries() const = 0;

	std::string getName() const;

private:
	std::string name;
};

#endif /* DATASOURCE_H_ */
