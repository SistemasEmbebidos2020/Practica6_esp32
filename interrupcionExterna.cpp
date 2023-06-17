// Declaracion de pines
int luz_verde = 14;
int luz_amarilla=27;
int luz_roja=26;
int pulsador=12;


void IRAM_ATTR isr(){     //Funcion de la interrupcion
  digitalWrite(luz_verde,HIGH);
  digitalWrite(luz_amarilla,HIGH);
  digitalWrite(luz_roja,HIGH);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(luz_verde,OUTPUT);
  pinMode(luz_amarilla,OUTPUT);
  pinMode(luz_roja,OUTPUT);
  pinMode(pulsador,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pulsador),isr,FALLING); // Se define la interrupcion
}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(pulsador));
  digitalWrite(luz_roja,HIGH);
  digitalWrite(luz_amarilla,LOW);
  digitalWrite(luz_verde,LOW);
  delay(1000);

  digitalWrite(luz_roja,LOW);
  digitalWrite(luz_amarilla,HIGH);
  digitalWrite(luz_verde,LOW);
  delay(1000);
  digitalWrite(luz_roja,LOW);
  digitalWrite(luz_amarilla,LOW);
  digitalWrite(luz_verde,HIGH);
  delay(1000);
 
}
