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

	DataSourceCollection& get() { return dataSourcesContainer; }

private:
	DataSource* createDataSource(const std::filesystem::directory_entry dirEntry) const;

private:
	DataSourceCollection dataSourcesContainer;
};

#endif /* DATASOURCESBUILDER_H_ */
