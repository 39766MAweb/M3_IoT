const int ldrPin = A0;
const int ledPin = 3;
const int led5 = 5;
const int led6 = 6;

int lowestValue = 1023;
int highestValue = 0;

bool isLowLight(int value) {
  if (value < 500) {
    return true;
  } else {
    return false;
  }
}

void controlLight(int value) {
  if (value >= 500 && value < 700) {
    digitalWrite(led5, HIGH);
  } else {
    digitalWrite(led5, LOW);
  }

  if (value >= 700) {
    digitalWrite(led6, HIGH);
  } else {
    digitalWrite(led6, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  if (ldrValue < lowestValue) {
    lowestValue = ldrValue;
  }

  if (ldrValue > highestValue) {
    highestValue = ldrValue;
  }

  if (isLowLight(ldrValue)) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  controlLight(ldrValue);

  Serial.print("{ ");
  Serial.print("\"current\": ");
  Serial.print(ldrValue);
  Serial.print(", \"lowest\": ");
  Serial.print(lowestValue);
  Serial.print(", \"highest\": ");
  Serial.print(highestValue);
  Serial.println(" }");

  delay(1000);
}
