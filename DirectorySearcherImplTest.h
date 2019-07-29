#ifndef DIRECTORYSEARCHERIMPLTEST_H_
#define DIRECTORYSEARCHERIMPLTEST_H_

#include "DirectorySearcherImpl.h"

#include <cxxtest/TestSuite.h>
#include <filesystem>


class DirectorySearcherImplTest : public CxxTest::TestSuite
{
public:
	void test_emptyDirectoryEntry_throwsException()
	{
		std::filesystem::directory_entry emptyDirEntry;
		DirectorySearcherImpl self;

		TS_ASSERT_THROWS(self.listAllDataSourceFiles(emptyDirEntry),
				std::filesystem::filesystem_error &);
	}
};

#endif /* DIRECTORYSEARCHERIMPLTEST_H_ */
