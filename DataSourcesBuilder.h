#ifndef DATASOURCESBUILDER_H_
#define DATASOURCESBUILDER_H_

#include <string>
#include <vector>
#include <filesystem>
#include "DataSource.h"

class DataSourcesBuilder
{
public:
	DataSourcesBuilder(std::string dataSourceDirectory);
	~DataSourcesBuilder();

	std::vector<DataSource *>& get() { return dataSourcesContainer; }

private:
	DataSource* createDataSource(const std::filesystem::directory_entry dirEntry) const;

private:
	std::vector<DataSource *> dataSourcesContainer;
};

#endif /* DATASOURCESBUILDER_H_ */
