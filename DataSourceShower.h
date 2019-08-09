#ifndef DATASOURCESHOWER_H_
#define DATASOURCESHOWER_H_

#include "LineEntry.h"

class DataSourceShower {
public:
	virtual ~DataSourceShower();

	virtual void showLine(LineEntry &entry) = 0;
};

#endif /* DATASOURCESHOWER_H_ */
