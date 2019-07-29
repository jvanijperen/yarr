#include "DirectorySearcherImpl.h"

DirectorySearcherImpl::DirectorySearcherImpl() {
}

DirectorySearcherImpl::~DirectorySearcherImpl() {
}

std::vector<std::filesystem::directory_entry> DirectorySearcherImpl::listAllDataSourceFiles(std::filesystem::directory_entry &directoryToSearch) const {
	throw std::filesystem::filesystem_error(
			"Empty path",
			directoryToSearch.path(),
			std::error_code()
	);
}
