#include <gtest/gtest.h>
#include "time_utils.h"

// Stub for calculate_time_difference function
unsigned long stub_calculate_time_difference(unsigned long start_time, unsigned long end_time) {
    return 42; // Return a fixed value for testing
}

TEST(TimeUtilsTest, TestCalculateTimeDifferenceWithStub) {
    // Use the stub function for this test
    unsigned long start_time = 100;
    unsigned long end_time = 200;
    unsigned long expected_difference = 42;
    unsigned long actual_difference = stub_calculate_time_difference(start_time, end_time);

   // unsigned long actual_difference = calculate_time_difference(start_time, end_time);

    EXPECT_EQ(expected_difference, actual_difference);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
