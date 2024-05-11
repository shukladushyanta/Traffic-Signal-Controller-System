
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


uint8_t signal1 = 0b001, signal2 = 0b001, signal3 = 0b001, signal4 = 0b001;
States currentState = ALLRED_1;
States nextState;


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


void next_state_fsm(void){
    
    nextState = currentState + 1;
    
    if(nextState == 12)
        nextState = 0;
}

void delay_fnc(States state){
     
     if(state == ALLRED_1 || state == ALLRED_2 || state == ALLRED_3 || state == ALLRED_4)
        delay(1000);
    else if(state == ROAD1_GREEN || state == ROAD2_GREEN || state == ROAD3_GREEN || state == ROAD4_GREEN)
        delay(5000);
    else if(state == ROAD1_YELLOW || state == ROAD2_YELLOW || state == ROAD3_YELLOW || state == ROAD4_YELLOW)
        delay(2000);
}

void setup() {
  // put your setup code here, to run once:

  for(int i=2; i<14xc;i++)
  pinMode(i,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  current_state_fsm();
    next_state_fsm();
    output_fnc();
    delay_fnc(currentState);
    currentState = nextState;

}

void output_fnc()
{
  digitalWrite(2,(signal1 & 0b001));
  digitalWrite(3,(signal1 & 0b010));
  digitalWrite(4,(signal1 & 0b100));

  digitalWrite(5,(signal2 & 0b001));
  digitalWrite(6,(signal2 & 0b010));
  digitalWrite(7,(signal2 & 0b100));

  digitalWrite(8,(signal3 & 0b001));
  digitalWrite(9,(signal3 & 0b010));
  digitalWrite(10,(signal3 & 0b100));

  digitalWrite(11,(signal4 & 0b001));
  digitalWrite(12,(signal4 & 0b010));
  digitalWrite(13,(signal4 & 0b100));
}
