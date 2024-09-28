#define BOOST_TEST_MODULE test_version

#include "fun.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    std::string l = "1.0.1.0";
    std::string r = "2.0.1.0";
    std::string r1 = "1.0.2.0";
    BOOST_CHECK(compare(l, r));
    BOOST_CHECK(compare(r, l));
    BOOST_CHECK(compare(l, r1));
}

BOOST_AUTO_TEST_SUITE_END()