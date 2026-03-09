void setup() {
  A = random(999);
  B = random(999);
  C = random(999);
  D = random(999);

}

void loop() {
  
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  if (A > B || A < C) {
    digitalWrite(3, HIGH);
  }

  if (C > A && A < B) {
    digitalWrite(5, HIGH);
  }

  if (B > C && B > A && C < A) {
    digitalWrite(6, HIGH);
  }

  if (D > A && D > B && D > C) {
    for (int i = 0; i < 20; i++) {
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(100);

      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(100);
    }
  }

  delay(10000);
}

}
