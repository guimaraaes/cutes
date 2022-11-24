/** Generated by YAKINDU Statechart Tools code generator. */

import com.yakindu.core.IStatemachine;
import com.yakindu.core.ITimed;
import com.yakindu.core.ITimerService;
import com.yakindu.core.rx.Observable;
import java.util.LinkedList;
import java.util.Queue;

public class Statechart implements IStatemachine, ITimed {
	public static class Light {
		private boolean oN;
		
		
		protected void raiseON() {
			oN = true;
			oNObservable.next(null);
		}
		
		private Observable<Void> oNObservable = new Observable<Void>();
		
		public Observable<Void> getON() {
			return oNObservable;
		}
		
		private boolean oFF;
		
		
		protected void raiseOFF() {
			oFF = true;
			oFFObservable.next(null);
		}
		
		private Observable<Void> oFFObservable = new Observable<Void>();
		
		public Observable<Void> getOFF() {
			return oFFObservable;
		}
		
	}
	
	public static class Pir {
		private Statechart parent;
		
		public Pir(Statechart parent) {
			this.parent = parent;
		}
		private boolean oN;
		
		
		public void raiseON() {
			parent.inEventQueue.add(() -> {
				oN = true;
			});
			parent.runCycle();
		}
		
		private boolean oFF;
		
		
		public void raiseOFF() {
			parent.inEventQueue.add(() -> {
				oFF = true;
			});
			parent.runCycle();
		}
		
	}
	
	protected Light light;
	
	protected Pir pir;
	
	public enum State {
		MAIN_REGION_STATELIGHTOFF,
		MAIN_REGION_STATELIGHTON,
		MAIN_REGION_DECISION,
		$NULLSTATE$
	};
	
	private final State[] stateVector = new State[1];
	
	private ITimerService timerService;
	
	private final boolean[] timeEvents = new boolean[2];
	
	private Queue<Runnable> inEventQueue = new LinkedList<Runnable>();
	private boolean isExecuting;
	
	protected boolean getIsExecuting() {
		return isExecuting;
	}
	
	protected void setIsExecuting(boolean value) {
		this.isExecuting = value;
	}
	public Statechart() {
		light = new Light();
		pir = new Pir(this);
		for (int i = 0; i < 1; i++) {
			stateVector[i] = State.$NULLSTATE$;
		}
		
		clearInEvents();
		
		
		isExecuting = false;
	}
	
	public void enter() {
		if (timerService == null) {
			throw new IllegalStateException("Timer service must be set.");
		}
		
		
		if (getIsExecuting()) {
			return;
		}
		isExecuting = true;
		
		enterSequence_main_region_default();
		isExecuting = false;
	}
	
	public void exit() {
		if (getIsExecuting()) {
			return;
		}
		isExecuting = true;
		
		exitSequence_main_region();
		isExecuting = false;
	}
	
	/**
	 * @see IStatemachine#isActive()
	 */
	public boolean isActive() {
		return stateVector[0] != State.$NULLSTATE$;
	}
	
	/** 
	* Always returns 'false' since this state machine can never become final.
	*
	* @see IStatemachine#isFinal()
	*/
	public boolean isFinal() {
		return false;
	}
	private void clearInEvents() {
		pir.oN = false;
		pir.oFF = false;
		timeEvents[0] = false;
		timeEvents[1] = false;
	}
	
	private void microStep() {
		switch (stateVector[0]) {
		case MAIN_REGION_STATELIGHTOFF:
			main_region_StateLightOff_react(-1l);
			break;
		case MAIN_REGION_STATELIGHTON:
			main_region_StateLightOn_react(-1l);
			break;
		case MAIN_REGION_DECISION:
			main_region_Decision_react(-1l);
			break;
		default:
			break;
		}
	}
	
	private void runCycle() {
		if (timerService == null) {
			throw new IllegalStateException("Timer service must be set.");
		}
		
		
		if (getIsExecuting()) {
			return;
		}
		isExecuting = true;
		
		nextEvent();
		do { 
			microStep();
			
			clearInEvents();
			
			nextEvent();
		} while ((((pir.oN || pir.oFF) || timeEvents[0]) || timeEvents[1]));
		
		isExecuting = false;
	}
	
	protected void nextEvent() {
		if(!inEventQueue.isEmpty()) {
			inEventQueue.poll().run();
			return;
		}
	}
	/**
	* Returns true if the given state is currently active otherwise false.
	*/
	public boolean isStateActive(State state) {
	
		switch (state) {
		case MAIN_REGION_STATELIGHTOFF:
			return stateVector[0] == State.MAIN_REGION_STATELIGHTOFF;
		case MAIN_REGION_STATELIGHTON:
			return stateVector[0] == State.MAIN_REGION_STATELIGHTON;
		case MAIN_REGION_DECISION:
			return stateVector[0] == State.MAIN_REGION_DECISION;
		default:
			return false;
		}
	}
	
	public void setTimerService(ITimerService timerService) {
		this.timerService = timerService;
	}
	
	public ITimerService getTimerService() {
		return timerService;
	}
	
	public void raiseTimeEvent(int eventID) {
		inEventQueue.add(() -> {
			timeEvents[eventID] = true;
		});
		runCycle();
	}
	
	public Light light() {
		return light;
	}
	
	public Pir pir() {
		return pir;
	}
	
	
	/* Entry action for state 'StateLightOff'. */
	private void entryAction_main_region_StateLightOff() {
		timerService.setTimer(this, 0, (1l * 1000l), false);
		
		light.raiseOFF();
	}
	
	/* Entry action for state 'StateLightOn'. */
	private void entryAction_main_region_StateLightOn() {
		timerService.setTimer(this, 1, (1l * 1000l), false);
		
		light.raiseON();
	}
	
	/* Exit action for state 'StateLightOff'. */
	private void exitAction_main_region_StateLightOff() {
		timerService.unsetTimer(this, 0);
	}
	
	/* Exit action for state 'StateLightOn'. */
	private void exitAction_main_region_StateLightOn() {
		timerService.unsetTimer(this, 1);
	}
	
	/* 'default' enter sequence for state StateLightOff */
	private void enterSequence_main_region_StateLightOff_default() {
		entryAction_main_region_StateLightOff();
		stateVector[0] = State.MAIN_REGION_STATELIGHTOFF;
	}
	
	/* 'default' enter sequence for state StateLightOn */
	private void enterSequence_main_region_StateLightOn_default() {
		entryAction_main_region_StateLightOn();
		stateVector[0] = State.MAIN_REGION_STATELIGHTON;
	}
	
	/* 'default' enter sequence for state Decision */
	private void enterSequence_main_region_Decision_default() {
		stateVector[0] = State.MAIN_REGION_DECISION;
	}
	
	/* 'default' enter sequence for region main_region */
	private void enterSequence_main_region_default() {
		react_main_region__entry_Default();
	}
	
	/* Default exit sequence for state StateLightOff */
	private void exitSequence_main_region_StateLightOff() {
		stateVector[0] = State.$NULLSTATE$;
		
		exitAction_main_region_StateLightOff();
	}
	
	/* Default exit sequence for state StateLightOn */
	private void exitSequence_main_region_StateLightOn() {
		stateVector[0] = State.$NULLSTATE$;
		
		exitAction_main_region_StateLightOn();
	}
	
	/* Default exit sequence for state Decision */
	private void exitSequence_main_region_Decision() {
		stateVector[0] = State.$NULLSTATE$;
	}
	
	/* Default exit sequence for region main_region */
	private void exitSequence_main_region() {
		switch (stateVector[0]) {
		case MAIN_REGION_STATELIGHTOFF:
			exitSequence_main_region_StateLightOff();
			break;
		case MAIN_REGION_STATELIGHTON:
			exitSequence_main_region_StateLightOn();
			break;
		case MAIN_REGION_DECISION:
			exitSequence_main_region_Decision();
			break;
		default:
			break;
		}
	}
	
	/* Default react sequence for initial entry  */
	private void react_main_region__entry_Default() {
		enterSequence_main_region_Decision_default();
	}
	
	private long react(long transitioned_before) {
		return transitioned_before;
	}
	
	private long main_region_StateLightOff_react(long transitioned_before) {
		long transitioned_after = transitioned_before;
		
		if (transitioned_after<0l) {
			if (timeEvents[0]) {
				exitSequence_main_region_StateLightOff();
				timeEvents[0] = false;
				enterSequence_main_region_Decision_default();
				react(0l);
				
				transitioned_after = 0l;
			}
		}
		/* If no transition was taken then execute local reactions */
		if (transitioned_after==transitioned_before) {
			transitioned_after = react(transitioned_before);
		}
		return transitioned_after;
	}
	
	private long main_region_StateLightOn_react(long transitioned_before) {
		long transitioned_after = transitioned_before;
		
		if (transitioned_after<0l) {
			if (timeEvents[1]) {
				exitSequence_main_region_StateLightOn();
				timeEvents[1] = false;
				enterSequence_main_region_Decision_default();
				react(0l);
				
				transitioned_after = 0l;
			}
		}
		/* If no transition was taken then execute local reactions */
		if (transitioned_after==transitioned_before) {
			transitioned_after = react(transitioned_before);
		}
		return transitioned_after;
	}
	
	private long main_region_Decision_react(long transitioned_before) {
		long transitioned_after = transitioned_before;
		
		if (transitioned_after<0l) {
			if (pir.oN) {
				exitSequence_main_region_Decision();
				enterSequence_main_region_StateLightOn_default();
				react(0l);
				
				transitioned_after = 0l;
			} else {
				if (pir.oFF) {
					exitSequence_main_region_Decision();
					enterSequence_main_region_StateLightOff_default();
					react(0l);
					
					transitioned_after = 0l;
				}
			}
		}
		/* If no transition was taken then execute local reactions */
		if (transitioned_after==transitioned_before) {
			transitioned_after = react(transitioned_before);
		}
		return transitioned_after;
	}
	
	/* Can be used by the client code to trigger a run to completion step without raising an event. */
	public void triggerWithoutEvent() {
		runCycle();
	}
}
