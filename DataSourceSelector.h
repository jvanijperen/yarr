#ifndef DATASOURCESELECTOR_H_
#define DATASOURCESELECTOR_H_

enum DataSourceChoice
{
	InvalidChoice = -1,
	QuitChoice = -2,
	HelpChoice = -3,
};

class DataSourceSelector
{
public:
	virtual ~DataSourceSelector() {}

	virtual int getChoice() = 0;
};

#endif /* DATASOURCESELECTOR_H_ */
