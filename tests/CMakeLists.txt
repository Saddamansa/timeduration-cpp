add_executable(timeduration_tests timeduration.cpp)

if(TARGET GTest::GTest)
    # System-installed GTest
    target_link_libraries(timeduration_tests
            PRIVATE
            timeduration::timeduration
            GTest::GTest
            GTest::Main
    )
else()
    # Downloaded GTest
    target_link_libraries(timeduration_tests
            PRIVATE
            timeduration::timeduration
            gtest
            gtest_main
    )
endif()

set_target_properties(timeduration_tests PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

include(GoogleTest)
gtest_discover_tests(timeduration_tests)
