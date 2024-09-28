cmake_minimum_required(VERSION 3.5.0)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(Lab_2 VERSION ${PROJECT_VESRION})
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(Lab_2 main.cpp )

set(TSV_FILE "ip_filter.tsv")
configure_file(${TSV_FILE} ${CMAKE_BINARY_DIR}/ip_filter.tsv COPYONLY)

set_target_properties(Lab_2 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(Lab_2
    PRIVATE "${CMAKE_BINARY_DIR}"
)

install(TARGETS Lab_2 RUNTIME DESTINATION bin)


if (${CMAKE_SYSTEM} MATCHES "Linux")
    set(CPACK_GENERATOR DEB)
else ()
    set(CPACK_GENERATOR ZIP)
endif()

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

include(CPack)

enable_testing()

set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

