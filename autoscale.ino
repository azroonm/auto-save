#define SENSOR_PIN 34
#define RELAY_PIN 25
#define GREEN_LED 26
#define RED_LED 27

float zeroCurrent = 2048;
float threshold = 0.6;  // fixed current limit

void setup() {
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);
}

void loop() {

  int sensorValue = analogRead(SENSOR_PIN);

  float current = abs(sensorValue - zeroCurrent) * 0.00049;

  Serial.print("Current: ");
  Serial.println(current);

  if(current > threshold) {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }
  else {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }

  delay(300);
}