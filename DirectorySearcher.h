#ifndef DIRECTORYSEARCHER_H_
#define DIRECTORYSEARCHER_H_

#include <vector>
#include <filesystem>

class DirectorySearcher
{
public:
	virtual ~DirectorySearcher() {}
	virtual std::vector<std::filesystem::directory_entry> listAllDataSourceFiles(std::filesystem::path &directoryToSearch) = 0;
};

#endif /* DIRECTORYSEARCHER_H_ */
