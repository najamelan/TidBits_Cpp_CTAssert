#include <tidbits/CTAssert.hpp>

int main()
{
	bool test = true;

	// should compile
	TIDBITS_CTASSERT( sizeof(test) < 256	, bool_cannot_be_bigger_than_265_bytes 	);

	// should compile
	TIDBITS_CTASSERT( true						, literals_should_compile						);

	// should NOT compile
	TIDBITS_CTASSERT( false						, evaluate_to_false_should_not_compile		);

	// should NOT compile
	TIDBITS_CTASSERT( test						, not_compile_time_should_not_compile		);

	return 0;
}
