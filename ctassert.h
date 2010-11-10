/// \file  ctassert/ctassert.hpp
/// \brief Provides compile time assertions

/** \file  ctassert/ctassert.hpp
 *  This version is inspired on code by abhinaba which can be found with his explanations here:
 *  http://blogs.msdn.com/b/abhinaba/archive/2008/10/27/c-c-compile-time-asserts.aspx?CommentPosted=true#commentmessage
 *
 * */

#ifndef Guard_6D79EDD5_F357_4efe_84AD_85776F2DBB2A
#define Guard_6D79EDD5_F357_4efe_84AD_85776F2DBB2A
#define ctassert_hpp


//

#ifdef __cplusplus

	// prevents type already exists errors
   // disabled because original used __LINE__ which is not supported by msvc2010 with /ZI which is default.
	// if it becomes necessary, enable again with __COUNTER__ where exist, and __LINE__ elsewhere.

	#define JOIN( X, Y ) JOIN2(X,Y)
	#define JOIN2( X, Y ) X##Y

	#ifdef __COUNTER__

		#define UNIQUE __COUNTER__

	#else

		#define UNIQUE __LINE__

	#endif


	namespace tidbits
	{
		 template < int > struct COMPILE_TIME_ASSERT_FAILURE												 ;
		 template <		 > struct COMPILE_TIME_ASSERT_FAILURE< true > {/* enum { value = 1 }; */};
	}


	/// Use this macro to assert at compile time

	/**
	 * \hideinitializer
	 *
	 * \param expr An expression that can evaluate to a bool at compile time
	 *
	 * On most compilers this gives an error message that at least mentions COMPILE_TIME_ASSERT_FAILURE as
	 * well as the line number and filename of where the error happens.
	 *
	 * Another version exists in the Loki library that allows to add an error message, but does not work
	 * at namespace scope. I reckon that even with an error message one will have to look at the actual
	 * code location that caused the assert to fail, so the namespace scope seems more valuable here.
	 *
	 */


	#define TIDBITS_CTASSERT( expr ) \
		 typedef tidbits::COMPILE_TIME_ASSERT_FAILURE< sizeof( tidbits::COMPILE_TIME_ASSERT_FAILURE< (expr) != 0 > ) > JOIN( COMPILE_TIME_ASSERT, UNIQUE )


#else // __cplusplus
	// TODO test C version

	#define TIDBITS_CTASSERT(x) extern int __dummy[(int) (x) != 0 ]

#endif // __cplusplus


#endif // Guard_6D79EDD5_F357_4efe_84AD_85776F2DBB2A



