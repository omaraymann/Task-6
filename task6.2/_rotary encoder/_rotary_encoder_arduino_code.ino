//rotary encoder pins
#define ENCODER_CLK_A 2
#define ENCODER_DT_B 3
//initializing counter variable for pulses
long long pulse_counter = 0;

void setup() {

  Serial.begin(9600);
  //set encoder pins as inputs with internal pull up resistors
  pinMode(ENCODER_CLK_A, INPUT_PULLUP);
  pinMode(ENCODER_DT_B,INPUT_PULLUP);
  //attach interupts to encoder pins at any rise or fall
  attachInterrupt(digitalPinToInterrupt(ENCODER_CLK_A),ISR_ENCODER_PIN_A,CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_DT_B),ISR_ENCODER_PIN_B,CHANGE);
}

void loop() {
  //
}

void ISR_ENCODER_PIN_A() {
  if(digitalRead(ENCODER_CLK_A) != digitalRead(ENCODER_DT_B)) //moving clockwise
    pulse_counter++;
  else //moving counter clockwise
    pulse_counter--;
}

void ISR_ENCODER_PIN_B() {
  if(digitalRead(ENCODER_CLK_A) == digitalRead(ENCODER_DT_B)) //moving clockwise
    pulse_counter++;
  else //moving counter clockwise
    pulse_counter--;
}