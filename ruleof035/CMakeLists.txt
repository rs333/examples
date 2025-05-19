add_executable( slicing slicing.cpp )

add_executable( test_ruleof0 test_ruleof0.cpp )
add_executable( test_ruleof5slice test_ruleof5slice.cpp )

target_link_libraries( test_ruleof0 
    GTest::gtest_main
)
target_link_libraries( test_ruleof5slice 
    GTest::gtest_main
)

gtest_discover_tests( test_ruleof0 )
gtest_discover_tests( test_ruleof5slice )