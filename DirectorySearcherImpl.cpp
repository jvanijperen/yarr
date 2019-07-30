#include "DirectorySearcherImpl.h"

DirectorySearcherImpl::DirectorySearcherImpl() {
}

DirectorySearcherImpl::~DirectorySearcherImpl() {
}

std::vector<std::filesystem::directory_entry> DirectorySearcherImpl::listAllDataSourceFiles(std::filesystem::path &directoryToSearch)
{
	dataSources.clear();
	for(auto curDirectoryEntry: std::filesystem::directory_iterator(directoryToSearch))
		dataSources.push_back(curDirectoryEntry);

	return dataSources;
}
