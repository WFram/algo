set(URL https://github.com/google/googletest)
set(VERSION aee0f9d9b5b87796ee8a0ab26b7587ec30e8858e)
set(gtest_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/3rd_party/src/gtest_external/googletest/include)
set(gtest_LIBS ${CMAKE_CURRENT_BINARY_DIR}/3rd_party/src/gtest_external-build/lib/libgtest${CMAKE_STATIC_LIBRARY_SUFFIX})

ExternalProject_Add(gtest_external
        GIT_REPOSITORY ${URL}
        GIT_TAG ${VERSION}
        CMAKE_ARGS
        -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
        -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
        -DCMAKE_BUILD_TYPE=Release
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        PREFIX 3rd_party
        EXCLUDE_FROM_ALL 1
        )

add_library(gtest INTERFACE IMPORTED)
add_dependencies(gtest gtest_external)
file(MAKE_DIRECTORY ${gtest_INCLUDE_DIR})
target_include_directories(gtest INTERFACE ${gtest_INCLUDE_DIR})
target_link_libraries(gtest INTERFACE ${gtest_LIBS})