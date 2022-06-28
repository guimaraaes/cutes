/*
 * Timer Service for SCTUnit
 */

#ifndef SC_TIMER_SERVICE_H_
#define SC_TIMER_SERVICE_H_

#include <list>

#include "sc_types.h"
#include "sc_statemachine.h"
#include "sc_timer.h"

class TimedSctUnitRunner : public sc::timer::TimerServiceInterface {
	public:
		TimedSctUnitRunner(sc::StatemachineInterface * statemachine, bool event_driven, sc_integer cycle_period);
		virtual ~TimedSctUnitRunner(){};
		void proceed_time(sc_integer time_ms);
		void proceed_cycles(sc_integer cycles);
		virtual void setTimer(sc::timer::TimedInterface* statemachine, sc_eventid event, sc_integer time_ms, sc_boolean isPeriodic);
		virtual void unsetTimer(sc::timer::TimedInterface* statemachine, sc_eventid event);
		virtual void cancel();
	private:
		class SctTimer;
		sc::StatemachineInterface * statemachine;
		
		bool event_driven;
		sc_integer cycle_period;
		sc_integer current_time_ms;

		std::list<SctTimer> timer_queue;
		void insert_timer(SctTimer timer);
};

class TimedSctUnitRunner::SctTimer {
	friend class TimedSctUnitRunner;
	public:
		SctTimer(sc::timer::TimedInterface * tsi, sc_integer time_ms, bool periodic, sc_eventid evid, sc_integer priority, sc_boolean is_runcycle);
		~SctTimer(){}
		
		sc_integer compare(SctTimer * other);
		
	private:
		sc::timer::TimedInterface * tsi;
		sc_integer rel_time_ms;
		sc_integer abs_time_ms;
		sc_boolean periodic;
		sc_eventid pt_evid;
		sc_integer priority;
		sc_boolean is_runcycle;
};

#endif /* SC_TIMER_SERVICE_H_ */

