void num(int n, int k);

int anode[7];
int cathode[2] = { 12, 13 };
int read_pin = 10;
int state_flg = 0;
const int distance = 1;
int seconds, milli_seconds;

void stop(int seconds, int milli_seconds);

void setup() {

  for (int a = 0; a < 7; a++) {
    anode[a] = a + 2;
    pinMode(anode[a], OUTPUT);
  }
  pinMode(cathode[0], OUTPUT);
  pinMode(cathode[1], OUTPUT);

  pinMode(read_pin, INPUT);
}

void loop() {

  num(0, 0);
  delay(1);
  num(0, 1);
  delay(1);

  if ((button() == true) && (state_flg == 0)) {
    state_flg = 1;

    for (int a = 0; a < 10; a++) {
      for (int b = 0; b < 10; b++) {
        for (int c = 0; c < 100 / (distance * 2); c++) {
          num(a, 0);
          delay(distance);
          num(b, 1);
          delay(distance);
        }
        seconds = a;
        milli_seconds = b;

        if ((button() == true) && (state_flg == 1)) {
          stop(seconds, milli_seconds);

        }
      }
    }
    state_flg = 0;
  }
  /*if((digitalRead(10) == LOW) && (flg == 0)){
    int time = millis() / 100;
    num((time / 10) % 10, 0);
    delay(1);
    num(time % 10, 1);
    delay(1);
    flg = 1;
  }else if(dogotalWrite(10) == LOW) && (flg == 1){
    
  }*/
}
void num(int n, int k) {
  switch (n) {

    case 0:
      digitalWrite(anode[0], HIGH);
      digitalWrite(anode[1], HIGH);
      digitalWrite(anode[2], HIGH);
      digitalWrite(anode[3], HIGH);
      digitalWrite(anode[4], HIGH);
      digitalWrite(anode[5], HIGH);
      digitalWrite(anode[6], LOW);
      break;

    case 1:
      digitalWrite(anode[0], LOW);
      digitalWrite(anode[1], HIGH);
      digitalWrite(anode[2], HIGH);
      digitalWrite(anode[3], LOW);
      digitalWrite(anode[4], LOW);
      digitalWrite(anode[5], LOW);
      digitalWrite(anode[6], LOW);
      break;

    case 2:
      digitalWrite(anode[0], HIGH);
      digitalWrite(anode[1], HIGH);
      digitalWrite(anode[2], LOW);
      digitalWrite(anode[3], HIGH);
      digitalWrite(anode[4], HIGH);
      digitalWrite(anode[5], LOW);
      digitalWrite(anode[6], HIGH);
      break;

    case 3:
      digitalWrite(anode[0], HIGH);
      digitalWrite(anode[1], HIGH);
      digitalWrite(anode[2], HIGH);
      digitalWrite(anode[3], HIGH);
      digitalWrite(anode[4], LOW);
      digitalWrite(anode[5], LOW);
      digitalWrite(anode[6], HIGH);
      break;

    case 4:
      digitalWrite(anode[0], LOW);
      digitalWrite(anode[1], HIGH);
      digitalWrite(anode[2], HIGH);
      digitalWrite(anode[3], LOW);
      digitalWrite(anode[4], LOW);
      digitalWrite(anode[5], HIGH);
      digitalWrite(anode[6], HIGH);
      break;

    case 5:
      digitalWrite(anode[0], HIGH);
      digitalWrite(anode[1], LOW);
      digitalWrite(anode[2], HIGH);
      digitalWrite(anode[3], HIGH);
      digitalWrite(anode[4], LOW);
      digitalWrite(anode[5], HIGH);
      digitalWrite(anode[6], HIGH);
      break;

    case 6:
      digitalWrite(anode[0], HIGH);
      digitalWrite(anode[1], LOW);
      digitalWrite(anode[2], HIGH);
      digitalWrite(anode[3], HIGH);
      digitalWrite(anode[4], HIGH);
      digitalWrite(anode[5], HIGH);
      digitalWrite(anode[6], HIGH);
      break;

    case 7:
      digitalWrite(anode[0], HIGH);
      digitalWrite(anode[1], HIGH);
      digitalWrite(anode[2], HIGH);
      digitalWrite(anode[3], LOW);
      digitalWrite(anode[4], LOW);
      digitalWrite(anode[5], HIGH);
      digitalWrite(anode[6], LOW);
      break;

    case 8:
      digitalWrite(anode[0], HIGH);
      digitalWrite(anode[1], HIGH);
      digitalWrite(anode[2], HIGH);
      digitalWrite(anode[3], HIGH);
      digitalWrite(anode[4], HIGH);
      digitalWrite(anode[5], HIGH);
      digitalWrite(anode[6], HIGH);
      break;

    case 9:
      digitalWrite(anode[0], HIGH);
      digitalWrite(anode[1], HIGH);
      digitalWrite(anode[2], HIGH);
      digitalWrite(anode[3], HIGH);
      digitalWrite(anode[4], LOW);
      digitalWrite(anode[5], HIGH);
      digitalWrite(anode[6], HIGH);
      break;
  }
  switch (k) {
    case 0:
      digitalWrite(cathode[0], LOW);
      digitalWrite(cathode[1], HIGH);
      break;

    case 1:
      digitalWrite(cathode[0], HIGH);
      digitalWrite(cathode[1], LOW);
  }
}
void stop(int time_a, int time_b) {
  state_flg = 0;
  while (true) {
    num(time_a, 0);
    delay(1);
    num(time_b, 1);
    delay(1);
    if ((button() == true) && (state_flg == 0)) {
      state_flg = 1;
      break;
    }
  }
}

int prev = HIGH;
bool button(void) {
  int now = digitalRead(read_pin);
  if ((prev == LOW) && (now == HIGH)) {
    prev = now;
    return true;
  }
  prev = now;
  return false;
}