#include "SI/all.hpp"

using namespace si;

int main()
{
	length Paris_to_Berlin = meter(878080);
	time flight_time_needed = second(900);
	speed average_speed = Paris_to_Berlin / flight_time_needed;

	return 0;
}
