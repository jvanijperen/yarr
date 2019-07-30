#include "DirectorySearcherImpl.h"

DirectorySearcherImpl::DirectorySearcherImpl() {
}

DirectorySearcherImpl::~DirectorySearcherImpl() {
}

std::vector<std::filesystem::directory_entry> DirectorySearcherImpl::listAllDataSourceFiles(std::filesystem::path &directoryToSearch)
{
	dataSources.clear();
	for(auto curDirectoryEntry: std::filesystem::directory_iterator(directoryToSearch))
		if (isValidDataSource(curDirectoryEntry))
			dataSources.push_back(curDirectoryEntry);

	return dataSources;
}

bool DirectorySearcherImpl::isValidDataSource(const std::filesystem::directory_entry &dirEntry) {
	return (dirEntry.is_regular_file() && dirEntry.path().extension().string() == ".txt");
}
