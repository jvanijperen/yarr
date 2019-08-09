#ifndef DATASOURCESHOWERIMPL_H_
#define DATASOURCESHOWERIMPL_H_

#include <iostream>
#include "DataSourceShower.h"

class DataSourceShowerImpl: public DataSourceShower {
public:
	DataSourceShowerImpl(std::ostream &outStream);
	virtual ~DataSourceShowerImpl();

	virtual void showLine(LineEntry &entry);
	virtual void showChoices(DataSourceCollection &sources);

private:
	std::ostream &outStream;

	void printBaseText();
	void printPrompt();
};

#endif /* DATASOURCESHOWERIMPL_H_ */
