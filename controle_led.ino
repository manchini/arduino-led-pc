int pinleds = 5;
int pinCooler = 6;
int modoOperacao = 1;
int potenciaLed = 255;
int potenciaCooler = 255;

int botao = 0;

void setup() {
  pinMode(pinleds, OUTPUT);
  pinMode(pinCooler, OUTPUT);
  
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);

  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    modoOperacao = Serial.parseInt();
    potenciaLed = 0;
   
  }
   botao = analogRead(0);
   Serial.println(botao);
   
  if(botao==1023){
    botao = analogRead(0);
  }
   if (botao == 740 || botao == 0) {
    potenciaLed = 0;
    modoOperacao++;
    if (modoOperacao > 4) {
      modoOperacao = 1;
    }
  }
  


  if (modoOperacao == 1) { 
    potenciaLed = 255;
    potenciaCooler = 255;
  } else if (modoOperacao == 2) { 
    potenciaLed = 0   ;
    potenciaCooler = 255;
  } else if (modoOperacao == 3) { 
    potenciaLed = 255   ;
    potenciaCooler = 00;
  } else if (modoOperacao == 4) { 
    potenciaLed = 0   ;
    potenciaCooler = 00;
  } 
  
 
  Serial.println(modoOperacao);
  analogWrite (pinleds, potenciaLed);
  analogWrite (pinCooler, potenciaCooler);
  delay(100);

}
