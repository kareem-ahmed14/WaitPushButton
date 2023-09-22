class wait {

private:
  byte button1_pin, button2_pin, led_pin;
  uint16_t delay = 2000;
  uint16_t t = 0;

public:
  void init();
  void waits();
  void waitms();
  void waits(uint16_t delay1);
  void waitms(uint16_t delay2);
  wait(byte button1, byte button2, byte led);
  wait(byte button1, byte button2, byte led, uint16_t deftime);
};
wait ::wait(byte button1, byte button2, byte led) {
  button1_pin = button1;
  button2_pin = button2;
  led_pin = led;
}

wait ::wait(byte button1, byte button2, byte led, uint16_t deftime) {
  button1_pin = button1;
  button2_pin = button2;
  led_pin = led;
  delay = deftime;
}


void wait ::init() {
  pinMode(button1_pin, INPUT);
  pinMode(button2_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void wait ::waits() {
  if (digitalRead(button1_pin)) {
    digitalWrite(led_pin, HIGH);
    t = millis();
  }
  if (digitalRead(button2_pin) == 1 || millis() - t >= delay) {
    digitalWrite(led_pin, LOW);
  }
}
void wait ::waitms() {
  if (digitalRead(button1_pin)) {
    t = millis();
    digitalWrite(led_pin, HIGH);
  }
  if (digitalRead(button2_pin) == 1 || millis() - t >= delay) {
    digitalWrite(led_pin, LOW);
  }
}

void wait ::waits(uint16_t delay1) {
  delay1 = delay1 * 1000;
  if (digitalRead(button1_pin) == 1) {
    digitalWrite(led_pin, HIGH);
    t = millis();
  }
  if (digitalRead(button2_pin) == 1 || millis() - t >= delay1) {
    digitalWrite(led_pin, LOW);
  }
}


void wait ::waitms(uint16_t delay2) {
  if (digitalRead(button1_pin) == 1) {
    digitalWrite(led_pin, HIGH);
    t = millis();
  }
  if (digitalRead(button2_pin) == 1 || millis() - t >= delay2) {
    digitalWrite(led_pin, LOW);
  }
}


wait my1(8, 9, 13);
void setup() {
  my1.init();
}

void loop() {
  my1.waitms(5000);
}
