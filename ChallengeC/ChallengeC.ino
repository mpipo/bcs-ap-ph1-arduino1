int switchState = 0;
int potPin = A5;
int val;
int lastSwitchState = 0;
bool isOn = false;

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
  switchState = digitalRead(2);
  Serial.println(isOn);
  if (switchState != lastSwitchState){
    if (switchState == HIGH) {
      Serial.println("High");
      isOn = !isOn;
    } else {
      Serial.println("Low");
    }
    for (int i = 5; i < 11; i++) {
      digitalWrite(i, LOW);
    }
    delay(50);
  }
  lastSwitchState = switchState;
  while (isOn == true) {
    for (int i = 5; i <= 7; i++) {
      digitalWrite(i, HIGH);
      delay(250);
      if (digitalRead(2) == HIGH) {
        isOn = false;
        break;
      }
    }
    for (int i = 7; i >= 5; i--) {
      digitalWrite(i, LOW);
      delay(250);
      if (digitalRead(2) == HIGH) {
        isOn = false;
        break;
      }
    }
  }
}
