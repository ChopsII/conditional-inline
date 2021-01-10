cmake_minimum_required(VERSION 3.19)

project(conditional-inline)

set(CMAKE_VERBOSE_MAKEFILE ON)


include(cmaked-ez/cmaked-ez.cmake)

include(cmaked-ez/cmaked-ez-conan.cmake)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION FALSE)
add_compile_options(/GL-)

ez_auto_configure_modules()


target_link_libraries(lib_test_project conditional-inline)
target_compile_features(lib_test_project PUBLIC cxx_std_17)

target_link_libraries(lib_inlined lib_test_project)
target_compile_definitions(lib_inlined PRIVATE CONDITIONAL_INLINE_ON)
set_target_properties(lib_inlined PROPERTIES INTERPROCEDURAL_OPTIMIZATION FALSE)

target_link_libraries(lib_not_inlined lib_test_project)
set_target_properties(lib_not_inlined PROPERTIES INTERPROCEDURAL_OPTIMIZATION FALSE)

target_link_libraries(test_lib_inlined
    lib_inlined
    CONAN_PKG::catch2
)
set_target_properties(test_lib_inlined PROPERTIES INTERPROCEDURAL_OPTIMIZATION FALSE)

target_link_libraries(test_lib_not_inlined 
    lib_not_inlined
    CONAN_PKG::catch2
)
set_target_properties(test_lib_not_inlined PROPERTIES INTERPROCEDURAL_OPTIMIZATION FALSE)
