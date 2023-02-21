# Wrapper to simplify test
function(project_add_test test_name test_source test_dependencies)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} ${test_dependencies} gmock gtest_main gtest pthread)
    add_test(${test_name} ${test_name})
endfunction()
