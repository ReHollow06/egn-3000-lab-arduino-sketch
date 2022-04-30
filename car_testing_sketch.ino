 /*
******
Setup: L298 H-bridge driver 

******
*/

#define IN1 5
#define IN2 6
#define IN3 4
#define IN4 3
#define IRPin1 8
#define IRPin2 9

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);//LEFT motor
  pinMode(IN2, OUTPUT);//
  
  pinMode(IN3, OUTPUT);//RIGHT motor
  pinMode(IN4, OUTPUT);//   

  pinMode(IRPin1, INPUT);
  pinMode(IRPin2, INPUT);
  Serial.begin(9600);

  //digitalWrite(IN1, LOW); // Turn on the LEFT motor (FORWARD)
  //digitalWrite(IN2, HIGH);
  
  //digitalWrite(IN3, HIGH); // Turn on the RIGHT motor (FORWARD)
  //digitalWrite(IN4, LOW);

  
  //delay(2000);

  //digitalWrite(IN3, LOW);
  //digitalWrite(IN2, LOW); // Turn off the motor

  //delay(2000);

  //digitalWrite(IN1, HIGH); // Turn on the motor (CLOCKWISE/ BACKWARDS/ LEFT MOTOR)
  //digitalWrite(IN2, LOW);

  //delay(2000);

  //digitalWrite(IN1, LOW);
}

void loop() {
  //Serial.print("IR SENSOR IP ");
  //Serial.println(digitalRead(IRPin1));

  if (digitalRead(IRPin1) == 1 && digitalRead(IRPin2) == 1){
    digitalWrite(IN1, LOW); // Turn on the RIGHT motor (FORWARD)
    digitalWrite(IN2, HIGH);  
    digitalWrite(IN3, HIGH); // Turn on the LEFT motor (FORWARD)
    digitalWrite(IN4, LOW);  
  }

  else if (digitalRead(IRPin1) == 0 && digitalRead(IRPin2) == 1){
    digitalWrite(IN1, LOW); // Turn on the RIGHT motor (FORWARD)
    digitalWrite(IN2, HIGH);  
    digitalWrite(IN3, LOW); // Turn off the LEFT motor (FORWARD)
    digitalWrite(IN4, LOW);
  }
  else if (digitalRead(IRPin1) == 1 && digitalRead(IRPin2) == 0){
    digitalWrite(IN1, LOW); // Turn on the RIGHT motor (FORWARD)
    digitalWrite(IN2, LOW);  
    digitalWrite(IN3, HIGH); // Turn off the LEFT motor (FORWARD)
    digitalWrite(IN4, LOW);
  }
    
  
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW); 
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, LOW);
  }
}
