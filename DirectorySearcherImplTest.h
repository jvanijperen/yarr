#ifndef DIRECTORYSEARCHERIMPLTEST_H_
#define DIRECTORYSEARCHERIMPLTEST_H_

#include "DirectorySearcherImpl.h"

#include <cxxtest/TestSuite.h>
#include <filesystem>
#include <cstdio>

class DirectorySearcherImplTest : public CxxTest::TestSuite
{
protected:
	DirectorySearcherImpl self;
public:
	virtual ~DirectorySearcherImplTest() {}
};

class DirectorySearcherImplTestWithoutSetup : public DirectorySearcherImplTest
{
public:
	void test_emptyDirectoryPath_throwsException()
	{
		std::filesystem::path emptyDirPath;

		TS_ASSERT_THROWS(self.listAllDataSourceFiles(emptyDirPath),
				std::filesystem::filesystem_error &);
	}
};

class DirectorySearcherImplTestWithTemporaryFile : public DirectorySearcherImplTest
{
protected:
	std::filesystem::path filePath;
public:
	DirectorySearcherImplTestWithTemporaryFile()
	{
		filePath = std::filesystem::temp_directory_path() / "yarr_tst.txt";
		std::fclose(std::fopen(filePath.c_str(), "w"));
	}

	~DirectorySearcherImplTestWithTemporaryFile()
	{
		std::filesystem::remove(filePath);
	}

	static DirectorySearcherImplTestWithTemporaryFile* createSuite()
	{
		return new DirectorySearcherImplTestWithTemporaryFile();
	}
	static void destroySuite(DirectorySearcherImplTestWithTemporaryFile* suite)
	{
		delete suite;
	}

	void test_fileInsteadOfDirectory_throwsException()
	{
		TS_ASSERT_THROWS(self.listAllDataSourceFiles(filePath),
				std::filesystem::filesystem_error &);

	}
};

class DirectorySearcherImplTestWithTemporaryDirectory : public DirectorySearcherImplTest
{
protected:
	std::filesystem::path dirPath;
public:
	DirectorySearcherImplTestWithTemporaryDirectory()
	{
		dirPath = std::filesystem::temp_directory_path() / "yarr_tst_dir";
		std::filesystem::create_directory(dirPath);
	}

	~DirectorySearcherImplTestWithTemporaryDirectory()
	{
		std::filesystem::remove(dirPath);
	}

	static DirectorySearcherImplTestWithTemporaryDirectory* createSuite()
	{
		return new DirectorySearcherImplTestWithTemporaryDirectory();
	}
	static void destroySuite(DirectorySearcherImplTestWithTemporaryDirectory* suite)
	{
		delete suite;
	}

	void test_directoryWithNoFiles_returnsEmptyCollection()
	{
		auto dataSourceFiles = self.listAllDataSourceFiles(dirPath);

		TS_ASSERT_EQUALS(dataSourceFiles.size(), 0);
	}
};

class DirectorySearcherImplTestWithTemporaryDirectoryAndDataSourceFile : public DirectorySearcherImplTestWithTemporaryDirectory
{
protected:
	std::filesystem::path dataSourceFilePath;
public:
	DirectorySearcherImplTestWithTemporaryDirectoryAndDataSourceFile()
	{
		dataSourceFilePath = dirPath / "dataSource1.txt";
		std::fclose(std::fopen(dataSourceFilePath.c_str(), "w"));
	}

	~DirectorySearcherImplTestWithTemporaryDirectoryAndDataSourceFile()
	{
		std::filesystem::remove(dataSourceFilePath);
	}

	static DirectorySearcherImplTestWithTemporaryDirectoryAndDataSourceFile* createSuite()
	{
		return new DirectorySearcherImplTestWithTemporaryDirectoryAndDataSourceFile();
	}
	static void destroySuite(DirectorySearcherImplTestWithTemporaryDirectoryAndDataSourceFile* suite)
	{
		delete suite;
	}

	void test_directoryWithOneDataSource_returnsThatDataSource()
	{
		auto dataSourceFiles = self.listAllDataSourceFiles(dirPath);

		TS_ASSERT_EQUALS(dataSourceFiles.size(), 1);
		TS_ASSERT_EQUALS(dataSourceFiles.at(0).path(), dataSourceFilePath);
	}
};

#endif /* DIRECTORYSEARCHERIMPLTEST_H_ */
