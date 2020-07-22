#pragma once

#include <boost/program_options.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/config.hpp>

namespace bpo=boost::program_options;

static constexpr auto dms_default = "9999999";

class config_controller
{
public:
    config_controller(const std::string config_path)
    {

        bpo::options_description desc("Allowed options");
        desc.add_options()
            ("dms path", bpo::value<std::string>()->default_value(dms_default), "some shit");

        bpo::variables_map vm;
        bpo::store(bpo::parse_config_file<char>(config_path.c_str(), desc), vm);
        bpo::notify(vm);

        std::string gotten_dms_path = vm["dms path"].as<std::string>();

        printf("HERE %s\n", gotten_dms_path.c_str());
    }

};

