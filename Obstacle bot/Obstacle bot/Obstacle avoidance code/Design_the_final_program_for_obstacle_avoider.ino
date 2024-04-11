void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // Begins the serial communication with baudrate 9600
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(A0,INPUT);
pinMode(A1,INPUT);

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
  
int Right = analogRead(A0);//read the analog value of pin a0
int Left = analogRead(A1);// read the analog value of pin a1
Serial.print("Value of Right Sensor is :" + String(Right));
Serial.print("\t"); //gives a tab space
Serial.println("Value of Left Sensor is :" + String(Left));
delay(1000);

//if(Right >700 && Left >700){
//  moveRobot("Stop");
//  delay(1000);
//  moveRobot("Backward");
//  delay(1000);
//  moveRobot("Left");
//  delay(2000);
//}
//if(Right < 700 && Left < 700){
//     moveRobot("Forward");
//}
//if(Right < 600 && Left > 600){
//  moveRobot("Stop");
//  delay(1000);
//  moveRobot("Backward");
//  delay(1000);
//  moveRobot("Right");
//  delay(2000);
//}
//if(Right > 600 && Left < 600){
//  moveRobot("Stop");
//  delay(1000);
//  moveRobot("Backward");
//  delay(1000);
//  moveRobot("Left");
//  delay(2000);
//}
} 
