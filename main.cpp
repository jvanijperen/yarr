#include <iostream>

#include "DirectorySearcherImpl.h"
#include "RandomNumberGenerator.h"
#include "PlainFileDataSource.h"
#include "LineEntryProviderImpl.h"
#include "DataSourcesBuilder.h"

int main(int /*argc*/, char **/*argv*/) {
	DataSourcesBuilder dataSources(".");
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

