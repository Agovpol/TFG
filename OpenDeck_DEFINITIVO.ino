// Librerías usadas
#include "Keyboard.h"
#include <SoftwareSerial.h>
#include <Nextion.h>

// Pines asignados a la pantalla
SoftwareSerial HMISerial(10, 11);

// Definimos las teclas F13-F20
#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15
#define BUTTON_KEY4 KEY_F16
#define BUTTON_KEY5 KEY_F17
#define BUTTON_KEY6 KEY_F18
#define BUTTON_KEY7 KEY_F19
#define BUTTON_KEY8 KEY_F20
#define BUTTON_KEY9 KEY_F21
#define BUTTON_KEY10 KEY_F22
#define BUTTON_KEY11 KEY_F23
#define BUTTON_KEY12 KEY_F24

// Declaración Botones táctiles
NexDSButton bt0 = NexDSButton(0, 13, "bt0");
NexDSButton bt1 = NexDSButton(0, 14, "bt1");
NexDSButton bt2 = NexDSButton(0, 15, "bt2");
NexDSButton bt3 = NexDSButton(0, 16, "bt3");
NexDSButton bt4 = NexDSButton(0, 17, "bt4");
NexDSButton bt5 = NexDSButton(0, 18, "bt5");
NexDSButton bt6 = NexDSButton(0, 19, "bt6");
NexButton b7 = NexButton(0, 20, "b7");
NexButton b8 = NexButton(0, 21, "b8");
NexButton b9 = NexButton(0, 22, "b9");
NexButton b10 = NexButton(0, 23, "b10");
NexDSButton bt11 = NexDSButton(0, 24, "bt11");

// Eventos Touch
NexTouch *nex_listen_list[] =
{
  &bt0, &bt1, &bt2, &bt3, &bt4, &bt5, &bt6, &bt11,
  &b7, &b8, &b9, &b10,
  NULL
};

void bt0_pulsar(void *ptr);
void bt1_pulsar(void *ptr);
void bt2_pulsar(void *ptr);
void bt3_pulsar(void *ptr);
void bt4_pulsar(void *ptr);
void bt5_pulsar(void *ptr);
void bt6_pulsar(void *ptr);
void b7_pulsar(void *ptr);
void b8_pulsar(void *ptr);
void b9_pulsar(void *ptr);
void b10_pulsar(void *ptr);
void bt11_pulsar(void *ptr);

// Se ejecutará siempre que se conecte el Arduino
void setup() {

  Keyboard.begin();
  Serial.begin(9600);
  bt0.attachPop(bt0_pulsar, &bt0);
  bt1.attachPop(bt1_pulsar, &bt1);
  bt2.attachPop(bt2_pulsar, &bt2);
  bt3.attachPop(bt3_pulsar, &bt3);
  bt4.attachPop(bt4_pulsar, &bt4);
  bt5.attachPop(bt5_pulsar, &bt5);
  bt6.attachPop(bt6_pulsar, &bt6);
  b7.attachPop(b7_pulsar);
  b8.attachPop(b8_pulsar);
  b9.attachPop(b9_pulsar);
  b10.attachPop(b10_pulsar);
  bt11.attachPop(bt11_pulsar, &bt11);
  HMISerial.begin(9600);
 
}

// Estará constantemente ejecutándose y escuchando posibles interacciones
void loop() {
  nexLoop(nex_listen_list);
  delay(5);
}

// Código de botón con doble estado
void bt0_pulsar(void *ptr) {
  uint32_t EstadoBoton;
  bt0.getValue(&EstadoBoton);

  if(EstadoBoton) {
    //Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY1);
    delay(500);
    //Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY1);
  } else {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY1);
    delay(500);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY1);    
  }
}

// Código de botón con doble estado
void bt1_pulsar(void *ptr) {
  uint32_t EstadoBoton;
  bt1.getValue(&EstadoBoton);

  if(EstadoBoton) {
    //Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY2);
    delay(500);
    //Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY2);
  } else {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY2);
    delay(500);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY2);    
  }
}

// Código de botón con doble estado
void bt2_pulsar(void *ptr) {
  uint32_t EstadoBoton;
  bt2.getValue(&EstadoBoton);

  if(EstadoBoton) {
    //Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY3);
    delay(500);
    //Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY3);
  } else {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY3);
    delay(500);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY3);    
  }
}

// Código de botón con doble estado
void bt3_pulsar(void *ptr) {
  uint32_t EstadoBoton;
  bt3.getValue(&EstadoBoton);

  if(EstadoBoton) {
    //Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY4);
    delay(500);
    //Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY4);
  } else {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY4);
    delay(500);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY4);    
  }
}

// Código de botón con estado único
void bt4_pulsar(void *ptr) {
    Keyboard.press(BUTTON_KEY5);
    delay(500);
    Keyboard.release(BUTTON_KEY5);
}

// Código de botón con estado único
void bt5_pulsar(void *ptr) {
    Keyboard.press(BUTTON_KEY6);
    delay(500);
    Keyboard.release(BUTTON_KEY6);
}

// Código de botón con doble estado
void bt6_pulsar(void *ptr) {
  uint32_t EstadoBoton;
  bt6.getValue(&EstadoBoton);

  if(EstadoBoton) {
    //Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY7);
    delay(500);
    //Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY7);
  } else {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY7);
    delay(500);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY7);    
  }
}


// Código de botón con estado único
void b7_pulsar(void *ptr) {
    Keyboard.press(BUTTON_KEY8);
    delay(500);
    Keyboard.release(BUTTON_KEY8);
}

// Código de botón con estado único
void b8_pulsar(void *ptr) {
    Keyboard.press(BUTTON_KEY9);
    delay(500);
    Keyboard.release(BUTTON_KEY9);
}

// Código de botón con estado único
void b9_pulsar(void *ptr) {
    Keyboard.press(BUTTON_KEY10);
    delay(500);
    Keyboard.release(BUTTON_KEY10);
}

// Código de botón con estado único
void b10_pulsar(void *ptr) {
    Keyboard.press(BUTTON_KEY11);
    delay(500);
    Keyboard.release(BUTTON_KEY11);
}

// Código de botón con doble estado
void bt11_pulsar(void *ptr) {
  uint32_t EstadoBoton;
  bt11.getValue(&EstadoBoton);

  if(EstadoBoton) {
    //Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY12);
    delay(500);
    //Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY12);
  } else {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(BUTTON_KEY12);
    delay(500);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(BUTTON_KEY12);    
  }
}
