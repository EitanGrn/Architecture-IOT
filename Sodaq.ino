#define debugSerial SerialUSB
#define loraSerial  Serial1 
#define PIN_RECEPTION 2

void setup() {
  debugSerial.begin(57600);
  while (!debugSerial);
  
  loraSerial.begin(57600);

  pinMode(PIN_RECEPTION, INPUT);

  pinMode(11, OUTPUT); digitalWrite(11, HIGH); 
  pinMode(17, OUTPUT); digitalWrite(17, HIGH);
  delay(1000);

  debugSerial.println("--- INITIALISATION LORA P2P ---");
  
  loraSerial.println("sys reset");
  delay(500);
  loraSerial.println("radio set mod lora");
  loraSerial.println("radio set freq 868100000");
  loraSerial.println("radio set pwr 14");
  loraSerial.println("mac pause"); 

  debugSerial.println("PRET : EN ATTENTE DU CHOC ELECTRIQUE SUR D2...");
}

void loop() {
  int etatFil = digitalRead(PIN_RECEPTION);

  if (etatFil == HIGH) {
    debugSerial.println(">>> 3.3V RECU SUR D2 ! ALERTE MINE !");
    debugSerial.println("ENVOI LORA EN COURS...");
    
    loraSerial.println("radio tx 424F4F4D");
    
    delay(500);
    while(loraSerial.available()) {
      debugSerial.print("RADIO : ");
      debugSerial.println(loraSerial.readStringUntil('\n'));
    }

    delay(3000); 
  }
}
