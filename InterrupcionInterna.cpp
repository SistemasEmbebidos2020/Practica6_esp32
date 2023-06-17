int LEDs[] = {18,5,4,2,15,19,21};    // Pines del display anodo comun

// Estado de pines para formar los numeros del display
int cero[] = {0,0,0,0,0,0,1}; 
int uno[] = {1,0,0,1,1,1,1};   
int dos[] = {0,0,1,0,0,1,0}; 
int tres[] = {0,0,0,0,1,1,0}; 
int cuatro[] = {1,0,0,1,1,0,0}; 
int cinco[] = {0,1,0,0,1,0,0}; 
int seis[] = {0,1,0,0,0,0,0}; 
int siete[] = {0,0,0,1,1,1,1};
int ocho[] = {0,0,0,0,0,0,0}; 
int nueve[] = {0,0,0,0,1,0,0}; 

int demora=3000;

#define TIMER_INTERVAL_MS 3000 // Intervalo de tiempo para la interrupcion
#define TIMER_DIVIDER 80  // Divisor para una frecuencia de 1 MHz
#define LED_PIN 14  //Define el led de la interupcion
#define LED_VERDE 12 // Define el led del programa principal
hw_timer_t *timer = NULL; // Define el tiempo del temporizador
//sincroniza el bucle principal y la ISR cuando se modifique una variable compartida
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED; 

volatile bool ledState = false; 
volatile bool estado = false;

// Se define la funcion de la interrupcion 
void IRAM_ATTR timerInterrupt() {
  portENTER_CRITICAL_ISR(&timerMux); //Declara el inicio de la interrupcion 
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);
  portEXIT_CRITICAL_ISR(&timerMux); // Declara que la interrupcion termino 
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_VERDE,OUTPUT);
  for (int i = 0; i<7; i++) pinMode(LEDs[i], OUTPUT); 

  timer = timerBegin(1, TIMER_DIVIDER, true); // Inicializa el timer 
  timerAttachInterrupt(timer, &timerInterrupt, true); // Declara la interrupcion
  // Define el tiempo en que se activa la interrupcion
  timerAlarmWrite(timer, TIMER_INTERVAL_MS * 1000, true); 
  timerAlarmEnable(timer); // Habilita la alarma del timer 
}

void loop() {
     delay(demora);
    estado = !estado;
    digitalWrite(LED_VERDE, estado);
    for (int i = 0; i<7; i++) digitalWrite(LEDs[i], uno[i]);
    delay(demora);
    estado = !estado;
    digitalWrite(LED_VERDE, estado);
    for (int i = 0; i<7; i++) digitalWrite(LEDs[i], dos[i]);
    delay(demora);
    estado = !estado;
    digitalWrite(LED_VERDE, estado);
    for (int i = 0; i<7; i++) digitalWrite(LEDs[i], tres[i]);
    delay(demora);
    estado = !estado;
    digitalWrite(LED_VERDE, estado);
    for (int i = 0; i<7; i++) digitalWrite(LEDs[i], cuatro[i]);
    delay(demora);
    estado = !estado;
    digitalWrite(LED_VERDE, estado);
    for (int i = 0; i<7; i++) digitalWrite(LEDs[i], cinco[i]);
    delay(demora);
    estado = !estado;
    digitalWrite(LED_VERDE, estado);
    for (int i = 0; i<7; i++) digitalWrite(LEDs[i], seis[i]);
    delay(demora);
    estado = !estado;
    digitalWrite(LED_VERDE, estado);
    for (int i = 0; i<7; i++) digitalWrite(LEDs[i], siete[i]);
    delay(demora);
    estado = !estado;
    digitalWrite(LED_VERDE, estado);
    for (int i = 0; i<7; i++) digitalWrite(LEDs[i], ocho[i]);
    delay(demora);
    estado = !estado;
    digitalWrite(LED_VERDE, estado);
    for (int i = 0; i<7; i++) digitalWrite(LEDs[i], nueve[i]);
}
