#ifndef DIRECTORYSEARCHERIMPL_H_
#define DIRECTORYSEARCHERIMPL_H_

#include "DirectorySearcher.h"

class DirectorySearcherImpl: public DirectorySearcher {
public:
	DirectorySearcherImpl();
	virtual ~DirectorySearcherImpl();
	std::vector<std::filesystem::directory_entry> listAllDataSourceFiles(std::filesystem::path &directoryToSearch) const;
};

#endif /* DIRECTORYSEARCHERIMPL_H_ */
