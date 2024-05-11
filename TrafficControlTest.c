#include <stdio.h>
#include <stdint.h>

/*all the states of FSM*/
typedef enum {
    ALLRED_1,
    ROAD1_GREEN,
    ROAD1_YELLOW,
    ALLRED_2,
    ROAD2_GREEN,
    ROAD2_YELLOW,
    ALLRED_3,
    ROAD3_GREEN,
    ROAD3_YELLOW,
    ALLRED_4,
    ROAD4_GREEN,
    ROAD4_YELLOW
} States;

/*
Each road is denoted by a signal variable i.e signal 1 for road 1, signal 2 for road 2 etc. Each bit denotes state of light in a signal. 
bit0 --> Red    bit1 --> Yellow     bit2 --> Green 
If bit is 0, the color of light is Off, is bit is 1 the color of light is On
*/
uint8_t signal1 = 0b001, signal2 = 0b001, signal3 = 0b001, signal4 = 0b001;
States currentState = ALLRED_1;
States nextState;

void current_state_fsm(void);
void next_state_fsm(void);
void delay_fnc(States state);


int main()
{
    
    int i = 0;
    
    while(i!=15){
        
    current_state_fsm();
    next_state_fsm();
    delay_fnc(currentState);
    
    printf("R1-%b\tR2-%b\tR3-%b\tR4-%b\n", signal1, signal2, signal3, signal4);
    
    currentState = nextState;
    i++;
    }

    return 0;
}

/*
FSM function for Current State
*/
void current_state_fsm(void){
    switch (currentState){
        case ALLRED_1:
            signal4 = 0b001;
            break;
        case ROAD1_GREEN: 
            signal1 = 0b100;
            break;
        case ROAD1_YELLOW: 
            signal1 = 0b010;
            break;
        case ALLRED_2:
            signal1 = 0b001;
            break;
        case ROAD2_GREEN: 
            signal2 = 0b100;
            break;
        case ROAD2_YELLOW: 
            signal2 = 0b010;
            break;
        case ALLRED_3:
            signal2 = 0b001;
            break;
        case ROAD3_GREEN: 
            signal3 = 0b100;
            break;
        case ROAD3_YELLOW: 
            signal3 = 0b010;
            break;
        case ALLRED_4:
            signal3 = 0b001;
            break;
        case ROAD4_GREEN: 
            signal4 = 0b100;
            break;
        case ROAD4_YELLOW: 
            signal4 = 0b010;
            break;
        default:
            signal1 = 0b001;
            signal2 = 0b001;
            signal3 = 0b001;
            signal4 = 0b001;
            break;
    }
}


/*
FSM function for next state
*/
void next_state_fsm(void){
    
    nextState = currentState + 1;
    
    if(nextState == 12)
        nextState = 0;
}

/*
add delay function or timer function in below case. 
*/
void delay_fnc(States state){
     
     if(state == ALLRED_1 || state == ALLRED_2 || state == ALLRED_3 || state == ALLRED_4);
        /* delay function for 1 second */
    else if(state == ROAD1_GREEN || state == ROAD2_GREEN || state == ROAD3_GREEN || state == ROAD4_GREEN);
        /* delay function for 5 seconds */
    else if(state == ROAD1_YELLOW || state == ROAD2_YELLOW || state == ROAD3_YELLOW || state == ROAD4_YELLOW);
        /* delay function for 2 seconds*/
}
