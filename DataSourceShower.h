#ifndef DATASOURCESHOWER_H_
#define DATASOURCESHOWER_H_

#include "LineEntry.h"
#include "DataSource.h"

class DataSourceShower {
public:
	virtual ~DataSourceShower();

	virtual void showLine(LineEntry &entry) = 0;
	virtual void showChoices(DataSourceCollection &sources) = 0;
};

#endif /* DATASOURCESHOWER_H_ */
