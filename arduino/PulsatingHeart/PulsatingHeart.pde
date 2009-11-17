
int ledPin       = 11;           
int time         = 5;             // define delay element  
int pulsewidth   = 0;            // define pulsewidth (0-255)  
int pulseRange   = 255;

int max          = 255;
int min          = 60; //0;
int inDelay      = 200; //400;
int outDelay     = 200; //230;
int shortDelay   = 0; //0;
int longDelay    = 600;

void setup() {  
  // None required for analogWrite!  
}  

void loop() {  
  pulse();
  delay(shortDelay);
  pulse();
  delay(longDelay);
}  
void pulse()
{
  // slowly fade the LEDs to full brightness  
  for (pulsewidth=min; pulsewidth <= max; pulsewidth++){  
    analogWrite(ledPin, pulsewidth); 
    delay(outDelay/pulseRange);
  }  
  // slowly dim the LEDs  
  for (pulsewidth=max; pulsewidth >= min; pulsewidth--){  
    analogWrite(ledPin, pulsewidth); 
    delay(inDelay/max);  
  }
}

