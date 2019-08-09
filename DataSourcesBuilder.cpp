#include "DataSourcesBuilder.h"

#include "DirectorySearcherImpl.h"
#include "PlainFileDataSource.h"
#include <fstream>

DataSourcesBuilder::DataSourcesBuilder(std::string dataSourceDirectory)
{
	DirectorySearcherImpl dirSearcher;

	std::vector<std::filesystem::directory_entry> dataSourceFiles = dirSearcher.listAllDataSourceFiles(dataSourceDirectory);
	for (auto dataSourceFile: dataSourceFiles) {
		dataSourcesContainer.push_back(createDataSource(dataSourceFile));
	}
}

DataSourcesBuilder::~DataSourcesBuilder()
{
	for (auto dataSource: dataSourcesContainer) {
		delete dataSource;
	}
}

DataSource* DataSourcesBuilder::createDataSource(std::filesystem::directory_entry dirEntry) const
{
	std::ifstream inputStream(dirEntry.path());

	return new PlainFileDataSource(dirEntry.path(), inputStream);
}

