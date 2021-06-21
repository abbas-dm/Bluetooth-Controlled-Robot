/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Bluetooth Controlled Robot~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*
* Designed an Andriod App which connects with the bluetooth present on the robot.
* The controlls for thr robot will be send from the App from control buttons. 
*/

  /*For Left Motor*/
#define lm1 3
#define lm2 4
  /*For Right Motor*/
#define rm1 6
#define rm2 7

void setup() {
  // put your setup code here, to run once:
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  
  Serial.begin(9600);
  Serial.flush();
}

void control_function(char val){
  if(val == 'F'){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
  }
  else if(val == 'R'){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, HIGH);
  }
  else if(val == 'B'){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, HIGH);    
  }
  else if(val == 'L'){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);    
  }
  if(val == 'S'){
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2, HIGH);
      digitalWrite(rm1, HIGH);
      digitalWrite(rm2, HIGH);    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  char val;
  if(Serial.available()>0){
    val = Serial.read();
    Serial.println(val);
    control_function(val);
  }
  while(!Serial.available()){
    control_function(val);
    if(Serial.available()>0){
      return;
    }
  }
  delay(1000);
}
