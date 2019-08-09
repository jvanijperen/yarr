#ifndef DATASOURCESHOWERIMPL_H_
#define DATASOURCESHOWERIMPL_H_

#include <iostream>
#include "DataSourceShower.h"

class DataSourceShowerImpl: public DataSourceShower {
public:
	DataSourceShowerImpl(std::ostream &outStream);
	virtual ~DataSourceShowerImpl();

	virtual void showLine(LineEntry &entry);

private:
	std::ostream &outStream;
};

#endif /* DATASOURCESHOWERIMPL_H_ */
