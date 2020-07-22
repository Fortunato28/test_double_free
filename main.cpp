#include "config_controller.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <gtest/gtest.h>

using namespace std;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, double_free)
{
    string filename = "test.txt";
    ofstream out_file(filename);
    out_file << "dms path = 8888888";
    out_file.flush();

    config_controller config_ctrl(filename);

    ASSERT_EQ(1, 1);
}
