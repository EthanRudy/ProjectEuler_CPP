#pragma once

#include <chrono>

template <typename HRClock = std::chrono::high_resolution_clock>
class Timer {
public:
	Timer() : start_point(HRClock::now())
	{}

	template <typename Rep = typename HRClock::duration::rep, typename Units = HRClock::duration>
	Rep get_duration() const {
		return std::chrono::duration_cast<Units>(HRClock::now() - start_point).count();
	}


private:
	std::chrono::high_resolution_clock::time_point start_point;
};

using precise_timer = Timer<>;