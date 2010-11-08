/// \file  TidBits_Cpp/tidbits/ctassert/test_ctassert.hpp
/// \brief Unit test code for CTAssert

/** \file  TidBits_Cpp/tidbits/ctassert/test_ctassert.hpp
 *  Header file needed to run the automated unit tests on the CTAssert tidbit
 *
 */



#ifndef Guard_4A0F60E4_5CA5_4d6a_9F3A_EFAA3F0DB6B4
#define Guard_4A0F60E4_5CA5_4d6a_9F3A_EFAA3F0DB6B4
#define test_ctassert_hpp

#include <tidbits/ctassert.hpp>
#include <tidbits/unit_testing.hpp>

namespace tidbits
{


class TestCTAssert : public UnitTesting
{
	public:
		explicit  TestCTAssert(){};
		virtual	~TestCTAssert(){};

		void run_test_case();
};


/// \brief Runs the tests for CTAssert

/**
 * This function tests for compile time assertion, so it does not compile unless the ONLY_RUNTIME_TESTS
 * is defined. The function does count its tests.
 *
 * It is inline in order to allow the definition of ONLY_RUNTIME_TESTS from a test app. If this was a CPP
 * file this definition should have been in a hpp file included or should be set globally at build time,
 * both of which are not ideal.
 *
 * This class does not have a cpp file.
 *
 */

void
TestCTAssert::run_test_case()
{
	message += "\nRunning TestCTAssert test case...\n\n";

	// disable warnings about unused variable. Reset to default has to come after function body
	// TODO check on other compilers than msvc

	#pragma warning( disable : 4189 )

		bool test = true;


	// Test sizeof (should compile)
	message += "   test bool is smaller than 256 bytes (COMPILE TIME)\n"					;

	TIDBITS_CTASSERT( sizeof( test ) < 256	, bool_cannot_be_bigger_than_265_bytes )	;
	assert_true		 ( true						, LOG												)	;



	// Test a literal (should compile)
   message += "   test the literal true (COMPILE TIME)\n"									;

	TIDBITS_CTASSERT( true						, literals_should_compile					)	;
	assert_true		 ( true						, LOG 											)	;



	// if leaving these tests in for now, as long as we don't create a makefile to test for compile time errors,
	// the tests can't compile. So only test if the define is set.

	#ifndef ONLY_RUNTIME_TESTS


		// Test false literal (should NOT compile in order to pass)
		message += "   test the literal false (COMPILE TIME)\n"				;

		TIDBITS_CTASSERT( false, evaluate_to_false_should_not_compile	)	;
		assert_true		 ( false, LOG 												)	;  //< if this line compiles the test has already failed.



		// Test a variable (should NOT compile in order to pass)
	   message += "   test a variable (COMPILE TIME)\n"						;

		TIDBITS_CTASSERT( test , not_compile_time_should_not_compile	)	;
		assert_true		 ( false, LOG 												)	; //< if this line compiles the test has already failed.


	#endif

}

// is disabled in TestCTAssert::run_test_case
#pragma warning( default : 4189 )


} 			// namespace tidbits
#endif 	// Guard_4A0F60E4_5CA5_4d6a_9F3A_EFAA3F0DB6B4
