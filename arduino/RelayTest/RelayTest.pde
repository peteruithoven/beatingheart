int relayPin = 12;
void setup()
{
  //digitalWrite(motorPin,HIGH);
  pinMode(relayPin,OUTPUT);
}
void loop()
{
  digitalWrite(relayPin,LOW);
  delay(1500); 
  digitalWrite(relayPin,HIGH);
  delay(200); 
}
