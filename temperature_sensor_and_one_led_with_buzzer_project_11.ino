const int ledPin = 5;

const int Ultrasonic = 7;

const int buzzerPin = 4;

const int ldrPin = A0;

const int smoke_detectorPin = A1;
void setup () {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);

pinMode(buzzerPin, OUTPUT);

pinMode(smoke_detectorPin,INPUT);
  
pinMode(ldrPin, INPUT);

}

void loop() {

int ldrStatus = analogRead(ldrPin);
  
int sensor_read = analogRead(smoke_detectorPin);
  
  Serial.print("Smoke Density: ");
  Serial.println(sensor_read);
  

if (ldrStatus >= 400){

tone(buzzerPin,500, 100);

digitalWrite(ledPin, HIGH);

delay(100);

noTone(buzzerPin);

digitalWrite(ledPin, LOW);

delay(100);

Serial.println("----------- ALARM ACTIVATED -----------");

}

else {

noTone(buzzerPin);

digitalWrite(ledPin, LOW);

Serial.println("ALARM DEACTIVATED");

}

}




