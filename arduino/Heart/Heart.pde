
int lightPin     = 11;           
int motorPin     = 12;  
int ledPin       = 13;
int switchPin    = 0;

boolean beating   = false;

int time         = 5;             // define delay element  


int max          = 255;
int min          = 60; //0;
int inDelay      = 750; //200; //400;
int outDelay     = 750; //200; //230;
int shortDelay   = 0; //0;
int longDelay    = 600;

int pulsewidth   = min;            // define pulsewidth (0-255)  
int pulseRange   = 255;

int startedMotorTime = 0;
boolean startedMotor = false;
int relaySwitchTime = 200;

void setup() 
{  
  pinMode(lightPin,OUTPUT);
  pinMode(motorPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(switchPin,INPUT);
  
  digitalWrite(switchPin,HIGH);
  
  analogWrite(lightPin, pulsewidth); 
  
  Serial.begin(9600);
}  

void loop() 
{
  if(Serial.available() > 0 && Serial.read() == 'b')
  {
    beat();
  }
  if(digitalRead(switchPin) == LOW && !beating)
  {
    beat(); 
  }
}  
void beat()
{
  Serial.println("beat");
  beating = true;
  pulseShape();
  pulseLight();
  delay(shortDelay);
  pulseShape();
  pulseLight();
  beating = false;
}
void pulseShape()
{
  digitalWrite(motorPin,HIGH);
  digitalWrite(ledPin,HIGH);
  startedMotorTime = millis();
}
void pulseLight()
{
  // slowly fade the LEDs to full brightness  
  for (pulsewidth=min; pulsewidth <= max; pulsewidth++){  
    analogWrite(lightPin, pulsewidth); 
    
    if(millis() > startedMotorTime+relaySwitchTime)
    {
      digitalWrite(motorPin,LOW);
      digitalWrite(ledPin,LOW); 
    }
    
    delay(outDelay/pulseRange);
  }  
  
  
  
  // slowly dim the LEDs  
  for (pulsewidth=max; pulsewidth >= min; pulsewidth--){  
    analogWrite(lightPin, pulsewidth); 
    delay(inDelay/max);  
  }
}
