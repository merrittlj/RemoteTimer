/*  StateMachine.h
 *  Author: Lucas Merritt/dynamic.void
 *  Date: 12/8/22
 *  Header file for finite state machine functions and variables  */


/*
 * Finite State Machine State
 *
 * displayEnabled: Display on(1) or off(0)
 * waitMs: Time to wait(seconds) before switching states
 * nextState: The next state's index to go to after previous state is done,
 * and if the timer is running or not(1st state: running 2nd state: not running)
 */
struct displayState {
    int displayEnabled : 1;
    int waitMs;
    int nextState[2];
};
typedef const struct displayState sType;

/*
 * Finite State Machine
 * Uses displayState's
 *
 * S1: Idle state - Display turned off, after finished displaying timer waiting for time
 * S2 & S4: Blink on - Display on, part of blink cycle
 * S3 & S5: Blink off - Display off, part of blink cycle
 * S6: Time running - Counting down, once reaching 0 return to blink cycle, then return to idle
 */
sType FSM[6] = {
    {0, 0, {1, 0}},
    {1, 1000, {2, 2}},
    {0, 1000, {3, 3}},
    {1, 1000, {4, 4}},
    {0, 1000, {5, 0}}
    {1, 0, {5, 1}}
}

/*
 * Update the display's state
 *
 * currentState: the current state of the display
 * timerRunning: if the timer is currently running or not
 */
void DisplayStateUpdate(int *currentState, int timerRunning);
