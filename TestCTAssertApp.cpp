/// CTAssert has compile time checks. To test it code should not compile.
/// however to allow automatic testing, if this define is set it will compile and omit
/// the tests that shouldn't compile.

#define ONLY_RUNTIME_TESTS

// local includes
#include <tidbits/ctassert/test_ctassert.hpp>

// system includes
#include <iostream>

using namespace tidbits;

int main()
{
   std::cout << "TidBits Library. CTAssert Test Application." << std::endl;

   TestCTAssert test;

   test.print_results();

   std::cin.get();

	return 0;
}
