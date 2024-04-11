void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // Begins the serial communication with baudrate 9600
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT); // sets analog pin a0 and a1 as Input pins


}
/*  a function is a way for programmeers to reuse code
 *   syntax: returntype functionName(arguments){
 *   //function body;
 *   return returntype;
 *   }
 */

void moveRobot(String motion){

  if (motion == "Forward")
  {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    Serial.println("Forward");
  }
   if (motion == "Backward")
   {
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    Serial.println("Backward");
   }
   if (motion == "Left")
   {
     digitalWrite(10,HIGH);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,HIGH);
     Serial.println("Left");
   }
   if (motion == "Right")
   {
     digitalWrite(10,LOW);
     digitalWrite(11,HIGH);
     digitalWrite(12,HIGH);
     digitalWrite(13,LOW);
     Serial.println("Right");  
   }
   if (motion == "Stop")
   {
     digitalWrite(10,LOW);
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,LOW);
     Serial.println("Stop");  
   }
}

void loop() {
  // put your main code here, to run repeatedly:
  
int Right = analogRead(A0); // Reads the analog value a0 and stores it in "Right" 
int Left = analogRead(A1); // Reads the analog value a1 and stores it in "Left"  
Serial.println("Value of Right sensor is" + String(Right));
Serial.print("\t"); //give a tab space
Serial.println("Value of Left sensor is" + String(Left));
delay(1000);

if ((Right > 600) && (Left > 600)){  // both sensors detect white surface
  moveRobot("Forward");
  
 }
if ((Right < 600) && (Left < 600)){ // both sensors detect black surface
  moveRobot("Stop");
  
}
if ((Right < 600) && (Left > 600)){ //  Right sensor detects ,to turn right
  moveRobot("Right");
  
 }
if ((Right > 600) && (Left < 600)){ // left sensor detects.to turn left
  moveRobot("Left");
  
 }
if ((Right < 600) && (Left < 600)){ // sensor stop
  
  moveRobot("Stop");
  
 } 
}
