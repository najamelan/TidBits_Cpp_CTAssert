/// \file  ctassert/ctassert.hpp
/// \brief Provides compile time assertions

/** \file  ctassert/ctassert.hpp
 * Code comes from Modern C++ Design: Generic Programming and Design Patterns Applied by Andrei Alexandrescu
 * http://erdani.com/book/main.html
 */

#ifndef Guard_6D79EDD5_F357_4efe_84AD_85776F2DBB2A
#define Guard_6D79EDD5_F357_4efe_84AD_85776F2DBB2A
#define ctassert_hpp

namespace tidbits
{

template< bool >
struct STATIC_ASSERTION_FAILURE
{
   STATIC_ASSERTION_FAILURE(...);
};

template<>
struct STATIC_ASSERTION_FAILURE< false > { };


/// Use this macro to assert at compile time

/**
 * \hideinitializer
 *
 * \param expr An expression that can evaluate to a bool at compile time
 * \param msg  An errormessage, must only contain alphanumeric characters or underscore
 *
 * Example on msvc 2010 with TIDBITS_CTASSERT( false, illegal_conversion_from_bitflag_to_bool ) and next using a variable based expr.
 *
 * If <b>expr evaluates to false</b>: <i>error C2440: '<function-style-cast>' :
 *  cannot convert from 'main::ERROR_illegal_conversion_from_bitflag_to_bool' to 'STATIC_ASSERTION_FAILURE<false>'</i>
 *
 * If <b>expr cannot be evaluated at compile time</b>: <i>error C2975: 'unnamed-parameter' :
 * invalid template argument for 'STATIC_ASSERTION_FAILURE', expected compile-time constant expression</i>
 *
 * Most other compilers will give informative error messages like above.
 *
 */

#define TIDBITS_CTASSERT(expr, msg) \
{\
	class ERROR_##msg {}; \
	(void)sizeof(( STATIC_ASSERTION_FAILURE< (expr) != 0>((ERROR_##msg()))));\
}

} 			// namespace tidbits
#endif 	// Guard_6D79EDD5_F357_4efe_84AD_85776F2DBB2A
