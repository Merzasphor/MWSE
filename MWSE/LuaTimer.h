#pragma once

#include <list>
#include <unordered_set>

#include "sol.hpp"

namespace mwse {
	namespace lua {
		struct Timer;

		namespace TimerState {
			enum TimerState {
				Active,
				Paused,
				Expired
			};
		}

		struct TimerComparer {
			bool operator() (const std::shared_ptr<Timer>& first, double second);
			bool operator() (const std::shared_ptr<Timer>& first, const std::shared_ptr<Timer>& second);
		};

		class TimeKeeper {
		public:
			TimeKeeper();
			TimeKeeper(double initialClock);
			
			void setClock(double clock);
			void incrementClock(double delta);
			double getClock();

			std::shared_ptr<Timer> createTimer(double duration, sol::protected_function callback, unsigned int iterations = 1);
			bool pauseTimer(std::shared_ptr<Timer> timer);
			bool resumeTimer(std::shared_ptr<Timer> timer);
			bool resetTimer(std::shared_ptr<Timer> timer);
			bool cancelTimer(std::shared_ptr<Timer> timer);
			void repositionTimer(std::shared_ptr<Timer> timer);
			void clearTimers();

		private:
			void update();

			std::vector<std::shared_ptr<Timer>>::iterator insertActiveTimer(std::shared_ptr<Timer> timer);

			double m_Clock;

			std::vector<std::shared_ptr<Timer>> m_ActiveTimers;
			std::unordered_set<std::shared_ptr<Timer>> m_PausedTimers;

			TimerComparer comparer;
		};

		struct Timer {
			// A handle back to the associated controller.
			TimeKeeper * controller;

			// The current state of the timer.
			TimerState::TimerState state;

			// How long the timer lasts.
			double duration;

			// Either the completion state, or the time left when it was paused.
			double timing;

			// The number of iterations it has left, or -1 if it runs forever.
			int iterations;

			// Callback for timer completion.
			sol::protected_function callback;
		};

		void bindLuaTimer();
	}
}
