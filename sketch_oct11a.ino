void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

double th(int v) {
  double t;
  t = log(((10240000.0 / v) - 10000.0));
  t = 1.0 / (0.001129148 + (0.000234125 * t) + (0.0000000876741 * t * t * t));
  t = t - 273.15; // 화씨를 섭씨로 바꾸어줌
  return t;
}

void loop() {
  int s;
  s = analogRead(A0);
  float f = th(s);
  if (f > 27.0) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  Serial.println(f);
  delay(500);
}
