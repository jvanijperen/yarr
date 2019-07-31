#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "DirectorySearcherImpl.h"
#include "RandomNumberGenerator.h"
#include "PlainFileDataSource.h"
#include "LineEntryProviderImpl.h"

class DataSources
{
public:
	DataSources(std::string dataSourceDirectory);
	~DataSources();

	std::vector<DataSource *>& get() { return dataSourcesContainer; }

private:
	DataSource* createDataSource(const std::filesystem::directory_entry dirEntry) const;

private:
	std::vector<DataSource *> dataSourcesContainer;
};

DataSources::DataSources(std::string dataSourceDirectory)
{
	DirectorySearcherImpl dirSearcher;

	std::vector<std::filesystem::directory_entry> dataSourceFiles = dirSearcher.listAllDataSourceFiles(dataSourceDirectory);
	for (auto dataSourceFile: dataSourceFiles) {
		dataSourcesContainer.push_back(createDataSource(dataSourceFile));
	}
}

DataSources::~DataSources()
{
	for (auto dataSource: dataSourcesContainer) {
		delete dataSource;
	}
}

DataSource* DataSources::createDataSource(std::filesystem::directory_entry dirEntry) const
{
	std::ifstream inputStream(dirEntry.path());

	return new PlainFileDataSource(inputStream);
}


int main(int /*argc*/, char **/*argv*/) {
	DataSources dataSources(".");
	if (dataSources.get().size() == 0) {
		std::cout << "No data sources found in current directory. (Data sources end with .txt)" << std::endl;
	} else {
		RandomNumberGenerator rng;
		for (auto dataSource: dataSources.get()) {
			LineEntryProviderImpl lineEntryProvider(*dataSource, rng);
			std::cout << lineEntryProvider.chooseLineEntry().line << std::endl;
		}
	}
	return 0;
}

