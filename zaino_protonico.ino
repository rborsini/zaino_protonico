
#define KEEP_ALIVE 2
#define GREEN_LED 3
#define YELLOW_LED 5
#define RED_LED 9
#define LASER 10

#define BUTTON 12
#define TRIMMER A0
  
int buttonState = 0;
int currentButtonState = 0;

unsigned long startMillis = 0;

long interval_1 = 100;
long interval_2 = 1100;
long interval_3 = 2100;
long interval_4 = 3100;
int power = 150;
int value = 0;

void setup() {  
  pinMode(KEEP_ALIVE, OUTPUT);     
  pinMode(GREEN_LED, OUTPUT);     
  pinMode(YELLOW_LED, OUTPUT);     
  pinMode(RED_LED, OUTPUT);     
  pinMode(LASER, OUTPUT);     

  pinMode(BUTTON, INPUT);    
  Serial.begin(9600);
}  
  
void loop() {  

  unsigned long currentMillis = millis();
  unsigned long delta = currentMillis - startMillis;

  currentButtonState = digitalRead(BUTTON);

  // Serial.print("button: ");
  // Serial.println(currentButtonState);

  digitalWrite(KEEP_ALIVE, HIGH);

  if(currentButtonState != buttonState) {
    buttonState = currentButtonState;
    startMillis = millis();
  } 

  power = analogRead(TRIMMER) / 4;

  // Serial.print("power: ");
  // Serial.println(power);

  // Interval 1 -> LED VERDE
  if(delta >= interval_1 && buttonState == 1){   
    analogWrite(GREEN_LED, power);
    Serial.print("GREEN:");
    Serial.println(power);
  } else {
    digitalWrite(GREEN_LED, LOW);
  }

  // Interval 2 -> LED GIALLO
  if(delta >= interval_2 && buttonState == 1){   
    analogWrite(YELLOW_LED, power);
    Serial.print("YELLOW:");
    Serial.println(power);
  } else {
    digitalWrite(YELLOW_LED, LOW);
  }  

  // Interval 3 -> LED ROSSO
  if(delta >= interval_3 && buttonState == 1){   
    analogWrite(RED_LED, power);
    Serial.print("RED:");
    Serial.println(power);    
  } else {
    digitalWrite(RED_LED, LOW);
  }  

  // Interval 4 -> LASER
  if(delta >= interval_4 && buttonState == 1){   
    analogWrite(LASER, power);
  } else {
    digitalWrite(LASER, LOW);    
  }      

}  