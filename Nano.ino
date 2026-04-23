#include <Arduino_BMI270_BMM150.h>
#include <Arduino_APDS9960.h>

#define PIN_ROUGE 22
#define PIN_ALERTE 2

void setup() {
  Serial.begin(9600);
  
  IMU.begin();
  APDS.begin();

  pinMode(PIN_ROUGE, OUTPUT);
  digitalWrite(PIN_ROUGE, HIGH); 
  
  pinMode(PIN_ALERTE, OUTPUT);
  digitalWrite(PIN_ALERTE, LOW);

  Serial.println("--- MINE PRETE (SIGNAL ELECTRIQUE) ---");
}

void loop() {
  if (APDS.colorAvailable()) {
    int r, g, b, clair;
    APDS.readColor(r, g, b, clair);
    
    if (clair > 100) {
      declencherExplosion();
    }
  }

  if (IMU.magneticFieldAvailable()) {
    float mx, my, mz;
    IMU.readMagneticField(mx, my, mz);
    float magnitude = sqrt(mx*mx + my*my + mz*mz);

    if (magnitude > 200.0) {
      declencherExplosion();
    }
  }
  delay(200); 
}

void declencherExplosion() {
  Serial.println("!!! EXPLOSION !!!");
  
  digitalWrite(PIN_ALERTE, HIGH); 

  digitalWrite(PIN_ROUGE, LOW);
  delay(2000);
  digitalWrite(PIN_ROUGE, HIGH);

  digitalWrite(PIN_ALERTE, LOW); 
}
