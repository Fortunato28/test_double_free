#include <iostream>
#include <fstream>
#include <sstream>

#include <boost/program_options.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/config.hpp>

#include <gtest/gtest.h>

using namespace std;
namespace bpo=boost::program_options;

static constexpr auto dms_default = "9999999";

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

    bpo::options_description desc("Allowed options");
    desc.add_options()
        ("dms path", bpo::value<string>()->default_value(dms_default), "some shit");

    bpo::variables_map vm;
    bpo::store(bpo::parse_config_file<char>(filename.c_str(), desc), vm);
    bpo::notify(vm);

    string gotten_dms_path = vm["dms path"].as<string>();


    printf("HERE %s\n", gotten_dms_path.c_str());

    ASSERT_EQ(1, 1);
}
