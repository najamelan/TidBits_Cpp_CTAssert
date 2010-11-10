/// \file  TidBits_Cpp/tidbits/ctassert/test_ctassert.hpp
/// \brief Unit test code for CTAssert

/** \file  TidBits_Cpp/tidbits/ctassert/test_ctassert.hpp
 *  Header file needed to run the automated unit tests on the CTAssert tidbit
 *
 */



#ifndef Guard_4A0F60E4_5CA5_4d6a_9F3A_EFAA3F0DB6B4
#define Guard_4A0F60E4_5CA5_4d6a_9F3A_EFAA3F0DB6B4
#define test_ctassert_hpp

#include <tidbits/ctassert.h>
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

// test at namespace scope
// will not be accounted for in the test results, but helps you to check manually.
namespace test
{


	TIDBITS_CTASSERT( 1<2 );
	TIDBITS_CTASSERT( 123 );

	#ifndef ONLY_RUNTIME_TESTS
		TIDBITS_CTASSERT( 3<2 );
		TIDBITS_CTASSERT( 0   );
	#endif

	//tidbits::CompileTimeError<((1 < 2) != 0)> Error_msg;
	//const size_t i = sizeof( Error_msg );

}

	//TIDBITS_CTASSERT( sizeof( bool ) < 256	, bool_cannot_be_bigger_than_265_bytes )	;
	//assert_true		 ( true						, LOG												)	;
//}


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
	#ifdef _MSC_VER
		#pragma warning( disable : 4189 )
	#endif

	bool test = true;


	// Test sizeof (should compile)
	message += "   test bool is smaller than 256 bytes (COMPILE TIME)\n"		;

	TIDBITS_CTASSERT( sizeof( test ) < 256	 			)								;
	assert_true		 ( true						, LOG		)								;



	// Test a literal (should compile)
   message += "   test the literal true (COMPILE TIME)\n"						;

	TIDBITS_CTASSERT( true									)								;
	assert_true		 ( true						, LOG 	)								;



	// if leaving these tests in for now, as long as we don't create a makefile to test for compile time errors,
	// the tests can't compile. So only test if the define is set.

	#ifndef ONLY_RUNTIME_TESTS


		// Test false literal (should NOT compile in order to pass)
		message += "   test the literal false (COMPILE TIME)\n"	;

		TIDBITS_CTASSERT( false	)											;
		assert_true		 ( false	)											;  //< if this line is executed the test has already failed.


		// Test a variable (should NOT compile in order to pass)
	   message += "   test a variable (COMPILE TIME)\n"			;

		TIDBITS_CTASSERT( test 	)											;
		assert_true		 ( false )											; //< if this line is executed the test has already failed.


	#endif

}

// is disabled in TestCTAssert::run_test_case
#ifdef _MSC_VER
#pragma warning( default : 4189 )
#endif


} 			// namespace tidbits
#endif 	// Guard_4A0F60E4_5CA5_4d6a_9F3A_EFAA3F0DB6B4
