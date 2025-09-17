int sensorPin1 = 12;
int sensorPin2 = A2;
int sensorPin3 = 4;
int sensorPin4 = A0;
int sensorPin5 = A1;
int sensorPin6 = A5;
int sensorPin7 = A3;
int sensorPin8 = A4;

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int sensorValue6 = 0;
int sensorValue7 = 0;
int sensorValue8 = 0;


const int enA = 5;
const int in1 = 7;
const int in2 = 8;

const int enB = 6;
const int in3 = 9;
const int in4 = 10;

void setup() {

   Serial.begin(9600);
   
   pinMode(sensorPin1, INPUT);
   pinMode(sensorPin2, INPUT);
   pinMode(sensorPin3, INPUT);
   pinMode(sensorPin4, INPUT);
   pinMode(sensorPin5, INPUT);
   pinMode(sensorPin6, INPUT);
   pinMode(sensorPin7, INPUT);
   pinMode(sensorPin8, INPUT);
  

   pinMode(enA, OUTPUT);
   pinMode(enB, OUTPUT);
   pinMode(in1, OUTPUT);
   pinMode(in2, OUTPUT);
   pinMode(in3, OUTPUT);
   pinMode(in4, OUTPUT);


}

void loop() {
    ReadSensor();
      if((sensorValue4 == 1 || sensorValue5 == 1) && (sensorValue1 == 0 && sensorValue2 == 0 && sensorValue3 == 0 && sensorValue6 == 0 && sensorValue7 == 0 && sensorValue8 == 0)) {
        Forward();
      }
    else if(sensorValue7 == 1  || sensorValue6 == 1){
          Left();
      }
    else if(sensorValue2 == 1 || sensorValue3 == 1){
          Right(); 
          delay(250);  
      }
    else if(sensorValue8 == 1){
          left();
      }
    else if(sensorValue1 == 1){
          right();
          delay(150);
      }
    else{
      delay(250);
        Stop();
      }   
  
}

void Forward(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    analogWrite(enA, 91);
    analogWrite(enB, 91); 
  
}

void Left(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enB, 101);
  analogWrite(enA, 0);
}

void Right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 109);
  analogWrite(enB, 0);
}

void left(){
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(enB, 190);
      analogWrite(enA, -50);
}

void right(){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 170);
      analogWrite(enB, -50);
}

void ReadSensor(){
      sensorValue1 = digitalRead(sensorPin1);
      sensorValue2 = digitalRead(sensorPin2);
      sensorValue3 = digitalRead(sensorPin3);
      sensorValue4 = digitalRead(sensorPin4);
      sensorValue5 = digitalRead(sensorPin5);
      sensorValue6 = digitalRead(sensorPin6);
      sensorValue7 = digitalRead(sensorPin7);
      sensorValue8 = digitalRead(sensorPin8);
}

void Stop(){
  analogWrite(enA,0);
  analogWrite(enB,0);
}



