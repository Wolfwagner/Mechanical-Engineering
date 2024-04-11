

// defines pins
#define stepPin 4
#define dirPin 5 
 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  digitalWrite(dirPin,HIGH); 
  
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(700);  
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(700); 
  }
  delay(1000); // One second delay
  
  digitalWrite(dirPin,LOW); 

  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}
