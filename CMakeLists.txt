cmake_minimum_required(VERSION 3.5.0)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(Lab_2 VERSION ${PROJECT_VESRION})
find_package(Boost COMPONENTS unit_test_framework REQUIRED)



add_executable(Lab_2 main.cpp )
add_library(fun fun.cpp)
add_executable(tests tests.cpp)

set(TSV_FILE "ip_filter.tsv")
configure_file(${TSV_FILE} ${CMAKE_BINARY_DIR}/ip_filter.tsv COPYONLY)

set_target_properties(Lab_2 fun PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(fun
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties(tests PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(Lab_2 PRIVATE
    fun
)
target_link_libraries(tests
    ${Boost_LIBRARIES}
    fun
)

if (MSVC)
    target_compile_options(Lab_2 PRIVATE
        /W4
    )
    target_compile_options(fun PRIVATE
        /W4
    )
    target_compile_options(tests PRIVATE
        /W4
    )
else ()
    target_compile_options(Lab_2 PRIVATE
        -Wall -Wextra -Werror
    )
    target_compile_options(fun PRIVATE
        -Wall -Wextra -Werror
    )
    target_compile_options(tests PRIVATE
        
    )
endif()

install(TARGETS Lab_2 RUNTIME DESTINATION bin)


if (${CMAKE_SYSTEM} MATCHES "Linux")
    set(CPACK_GENERATOR DEB)
else ()
    set(CPACK_GENERATOR ZIP)
endif()

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)


include(CPack)

enable_testing()

add_test(tests tests)

set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

