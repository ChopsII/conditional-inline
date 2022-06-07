cmake_minimum_required(VERSION 3.19)

project(conditional-inline)

set(CMAKE_VERBOSE_MAKEFILE ON)


include(cmaked-ez/cmaked-ez.cmake)

include(cmaked-ez/cmaked-ez-conan.cmake)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION FALSE)
add_compile_options(/GL- )
add_link_options(/LTCG:OFF)

ez_auto_configure_modules()


target_link_libraries(lib_test_project conditional-inline)
target_compile_features(lib_test_project PUBLIC cxx_std_20)

target_link_libraries(lib_inlined_a lib_test_project)
target_compile_definitions(lib_inlined_a PRIVATE CONDITIONAL_INLINE_ON)
set_target_properties(lib_inlined_a PROPERTIES INTERPROCEDURAL_OPTIMIZATION FALSE)

target_link_libraries(lib_inlined_b lib_test_project)
target_compile_definitions(lib_inlined_b PRIVATE CONDITIONAL_INLINE_ON)
set_target_properties(lib_inlined_b PROPERTIES INTERPROCEDURAL_OPTIMIZATION FALSE)

target_link_libraries(lib_not_inlined lib_test_project)
set_target_properties(lib_not_inlined PROPERTIES INTERPROCEDURAL_OPTIMIZATION FALSE)

target_link_libraries(test_lib_inlined
    lib_inlined_a
    lib_inlined_b
    CONAN_PKG::catch2
)
set_target_properties(test_lib_inlined PROPERTIES INTERPROCEDURAL_OPTIMIZATION FALSE)

target_link_libraries(test_lib_not_inlined 
    lib_not_inlined
    CONAN_PKG::catch2
)
set_target_properties(test_lib_not_inlined PROPERTIES INTERPROCEDURAL_OPTIMIZATION FALSE)

#### Catch setup ####

# Make "include(Catch) available when using catch2 from conan"
include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
list(APPEND CMAKE_MODULE_PATH "${CONAN_LIB_DIRS_CATCH2}/cmake/Catch2")

include(CTest)
include(Catch)

catch_discover_tests(test_lib_inlined)
catch_discover_tests(test_lib_not_inlined)
