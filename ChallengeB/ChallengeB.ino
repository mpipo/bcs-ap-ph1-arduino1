int switchState = 0;
int potPin = A5;
int val;
int lastSwitchState = 0;
bool isOn = false;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

double convPercent(double input) {
  return input / 1024 * 100;
}
void loop() {
  switchState = digitalRead(2);
  Serial.println(isOn);
  if (switchState != lastSwitchState){
    if (switchState == HIGH) {
      Serial.println("High");
      isOn = !isOn;
    } else {
      Serial.println("Low");
    }
    digitalWrite(12, LOW);
    delay(50);
  }
  lastSwitchState = switchState;
  while (isOn == true) {
    delay(1000);
    for (int i = 0; i < 5; i++) {
      digitalWrite(12, HIGH);
      if (digitalRead(2) == HIGH) {
        isOn = false;
        break;
      }
      delay(200);
      digitalWrite(12, LOW);
      if (digitalRead(2) == HIGH) {
        isOn = false;
        break;
      }
      delay(200);
    }
    for (int i = 0; i < 70; i++) {
      delay(100);
      if (digitalRead(2) == HIGH) {
        isOn = false;
        break;
      }
    }
  }
}
