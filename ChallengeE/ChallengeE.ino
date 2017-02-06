int switchState = 0;
int potPin = A5;
int val;
int lastSwitchState = 0;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

double convPercent(double input) {
  return input / 1024 * 100;
}
void loop() {
  Serial.println(switchState);
  switchState = digitalRead(2);
  if (switchState != lastSwitchState){
    while (switchState == HIGH) {
      digitalWrite(5, HIGH);
      digitalWrite(8, HIGH);
      delay(250);
      if (digitalRead(2) == HIGH) {
        break;
      }
      digitalWrite(5, LOW);
      digitalWrite(8, LOW);
      delay(250);
      if (digitalRead(2) == HIGH) {
        break;
      }
      digitalWrite(7, HIGH);
      digitalWrite(10, HIGH);
      delay(250);
      if (digitalRead(2) == HIGH) {
        break;
      }
      digitalWrite(7, LOW);
      digitalWrite(10, LOW);
      delay(250);
      if (digitalRead(2) == HIGH) {
        break;
      }
    }
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(50);
  }
  lastSwitchState = switchState;
}
