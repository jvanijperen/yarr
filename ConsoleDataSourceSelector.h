#ifndef CONSOLEDATASOURCESELECTOR_H_
#define CONSOLEDATASOURCESELECTOR_H_

#include <istream>

#include "DataSourceSelector.h"

class ConsoleDataSourceSelector : public DataSourceSelector
{
public:
	ConsoleDataSourceSelector(std::istream &inStream);
	virtual ~ConsoleDataSourceSelector();

	int getChoice();

private:
	int parseChoice();
	int parseNumericChoice();
	int parseStringChoice();

private:
	std::istream &inStream;
};

#endif /* CONSOLEDATASOURCESELECTOR_H_ */
