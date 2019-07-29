cmake_minimum_required (VERSION 2.6)

project (yarr)
set(CMAKE_CXX_STANDARD 17)

add_library(yarr_objects OBJECT 
    RandomNumberGenerator.cpp 
    PlainFileDataSource.cpp
    LineEntryProviderImpl.cpp)
target_compile_options(yarr_objects PUBLIC -Wall -Wpedantic -Wextra)

add_executable(yarr main.cpp)
target_link_libraries(yarr yarr_objects) # as needed

find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(${CXXTEST_INCLUDE_DIR})
    enable_testing()

    CXXTEST_ADD_TEST(unittest_yarr CxxTestRunner.cpp
                     ${CMAKE_CURRENT_SOURCE_DIR}/RandomNumberGeneratorTest.h
                     ${CMAKE_CURRENT_SOURCE_DIR}/PlainFileDataSourceTest.h
                     ${CMAKE_CURRENT_SOURCE_DIR}/LineEntryProviderImplTest.h)
    target_link_libraries(unittest_yarr yarr_objects) # as needed
endif()
