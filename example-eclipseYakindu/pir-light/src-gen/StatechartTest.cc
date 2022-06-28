/** Generated by YAKINDU Statechart Tools code generator. */
#include <string>
#include "gtest/gtest.h"
#include "Statechart.h"
#include "sc_runner_timed.h"
#include "sc_types.h"

#define SC_UNUSED(P) (void)P

namespace  {

Statechart* statechart;



//! The timers are managed by a timer service. */
static TimedSctUnitRunner * runner;

class StatechartTest : public ::testing::Test{
	protected:
	virtual void SetUp() {
		statechart = new Statechart();
		runner = new TimedSctUnitRunner(
			statechart,
			true,
			200
		);
		statechart->setTimerService(runner);
	}
	virtual void TearDown() {
		delete statechart;
		delete runner;
	}
};


TEST_F(StatechartTest, test_LightOff_PirOff_LightOff) {
	
	statechart->enter();
	
	EXPECT_TRUE(statechart->light
	()->isRaisedOFF());
	
	statechart->pir
	()->raiseOFF();
	
	EXPECT_TRUE(statechart->light
	()->isRaisedOFF());
	
	
}
TEST_F(StatechartTest, test_PirOn_LightOn_5s_PirOn_LightOn) {
	
	statechart->enter();
	
	statechart->pir
	()->raiseON();
	
	EXPECT_TRUE(statechart->light
	()->isRaisedON());
	
	runner->proceed_time(5*1000);
	
	statechart->pir
	()->raiseOFF();
	
	EXPECT_TRUE(statechart->light
	()->isRaisedOFF());
	
	
}

}

