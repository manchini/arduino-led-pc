int leds = 5;
int modo = 1;
int power = 255;
int up = 1;
int a = 0;

void setup() {
  pinMode(leds, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);

  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    modo = Serial.parseInt();
    power = 0;
    up = 1;
  }
   a = analogRead(7);
   Serial.println(a);
  if(a==1023){
    a = analogRead(0);
  }
  
  if (a == 740 || a == 0) {
    power = 0;
    up = 1;
    modo++;
    if (modo > 8) {
      modo = 1;
    }
  }

  if (modo == 1) { // sempre ligado
    power = 255;
  } else if (modo == 2) { // desligado
    power = 0   ;
  } else if (modo == 3) { // moda loca
      power = random(255);
  } else if (modo == 4) { // delay maciota
    if (up == 1) {
      power = power + 255/126;
    } else {
      power = power - 255/126;
    }
  }
  else if (modo == 5) { // delay maciota
    if (up == 1) {
      power = power +  255/85;
    } else {
      power = power - 255/85;
    }
  } else if (modo == 6) { // delay maciota
    if (up == 1) {
      power = power +  255/62;
    } else {
      power = power - 255/62;
    }
  } else if (modo == 7) { // delay maciota
    if (up == 1) {
      power = power +  255/51;
    } else {
      power = power - 255/51;
    }
  }else if (modo == 8) { // delay maciota
    if (up == 1) {
      power = power +  100;
    } else {
      power = power - 100;
    }
  }

  if (power > 254) {
    up = 0;
    power= 255;
  } else if (power < 1) {
    up = 1;
    power = 0;
  }
  Serial.print(modo);
  Serial.print(";");
  Serial.print(up);
  Serial.print(";");
  Serial.println(power);
  analogWrite (leds, power);
  delay(100);

}
