
// light properties
int lightPin     = 11;   
int min          = 60; //0;
int max          = 255;
int pulsewidth   = min;            // define pulsewidth (0-255)  
int pulseRange   = max-min;
int inDelay      = 750; //200; //400;
int outDelay     = 750; //200; //230;
int shortDelay   = 0;

// relay properties
int relayPin     = 12;  
unsigned long switchedRelayTime = 0;
unsigned long relaySwitchTime = 200;
boolean switchingRelay = false;

// switch properties
int switchPin    = 2;

void setup() 
{  
  pinMode(lightPin,OUTPUT);
  pinMode(relayPin,OUTPUT);
  pinMode(switchPin,INPUT);

  digitalWrite(switchPin,HIGH);  
  analogWrite(lightPin, pulsewidth); 
  Serial.begin(9600);
}  

void loop() 
{
  if((Serial.available() > 0 && Serial.read() == 'b') || 
    digitalRead(switchPin) == LOW)
  {
    beat();
  }
}  
void beat()
{
  Serial.println("beat");
  switchOnRelay();
  pulseLight();
  delay(shortDelay);
  switchOnRelay();
  pulseLight();
}
void switchOnRelay()
{
  Serial.println("switchOnRelay");
  digitalWrite(relayPin,HIGH);
  switchedRelayTime = millis();
  Serial.print("switchedRelayTime: ");
  Serial.println(switchedRelayTime);
  switchingRelay = true;
}
void pulseLight()
{
  printTime();
  Serial.println("pulseLight");
  // slowly fade the LEDs to full brightness  
  for (pulsewidth=min; pulsewidth <= max; pulsewidth++){  
    analogWrite(lightPin, pulsewidth); 
    switchOffRelay();
    delay(outDelay/pulseRange);
  }  
  printTime();
  switchOffRelay();
  // slowly dim the LEDs  
  for (pulsewidth=max; pulsewidth >= min; pulsewidth--)
  {  
    analogWrite(lightPin, pulsewidth); 
    switchOffRelay();
    delay(inDelay/max); 
  }
  printTime();
}
void switchOffRelay()
{
 
  if(millis() > switchedRelayTime+relaySwitchTime && switchingRelay)
    {
      Serial.println("switchOffRelay really");
      digitalWrite(relayPin,LOW);
      switchingRelay = false;
    }
}
void printTime()
{
  Serial.print(millis());
  Serial.print(" : ");
  Serial.println((switchedRelayTime+relaySwitchTime));
  
}
