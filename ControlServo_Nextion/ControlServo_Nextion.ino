#include <Servo.h>

Servo myservo;

int i = 0;
int valor[7];
int pos = 90;
int velocidad = 50;
int pausa;
bool Verificado = LOW;
bool over = LOW;

void setup() {
  Serial1.begin(9600); //configuracion del puerto serial
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {

  if (Serial1.available()) {
    valor[i] = Serial1.read();
    i++;
    if (i == 7) {
      i = 0;
      Serial1.flush();
      if ((valor[0] == 0x65) && (valor[6] == 0xFF)) {
        Serial.print(valor[1], HEX);
        Serial.print(valor[2], HEX);
        Serial.println(valor[3], HEX);
        Verificado = HIGH;
      }
      else {
        i = 0;
        Serial1.flush();
        Serial.println("ERROR");
        Serial.print(valor[1], HEX);
        Serial.print(valor[2], HEX);
        Serial.println(valor[3], HEX);
        for (int j = 0; j < 7; j += 1 ) valor[j] = 0;
      }
    }
  }
  control_sweep();
  control_velocidad();
}

void control_velocidad() {
  
  pausa = map(velocidad, 0, 100, 30, 0);

  // Ajusta valor por defecto
  if ((valor[1] == 0x00) && (valor[2] == 0x02) && (Verificado == HIGH)) {
    Verificado = LOW;
    over = LOW;
    velocidad = 50;
    Serial.println("Default");
    Serial.print("Velocidad = ");
    Serial.println(velocidad);
    Serial.print("Over = ");
    Serial.println(over);
  }

  // Incrementa velocidad
  else if ((valor[1] == 0x02) && (valor[2] == 0x02) && (Verificado == HIGH) && (over == LOW)) {
    Verificado = LOW;
    velocidad += 10;
    Serial.print("Velocidad = ");
    Serial.println(velocidad);
    if (velocidad == 100) {
      over = HIGH;
      Serial.print("Velocidad = ");
      Serial.println(velocidad);
      Serial.print("Over = ");
      Serial.println(over);
    }
    else {
      over = LOW;
    }
  }
  else if ((valor[1] == 0x02) && (valor[2] == 0x01) && (Verificado == HIGH) && (velocidad == 100) && (over == HIGH)) {
    over = LOW;
    Verificado == LOW;
  }

  // Disminuye velocidad
  else if ((valor[1] == 0x02) && (valor[2] == 0x01) && (Verificado == HIGH) && (over == LOW)) {
    Verificado = LOW;
    velocidad -= 10;
    Serial.print("Velocidad = ");
    Serial.println(velocidad);
    if (velocidad == 0) {
      over = HIGH;
      Serial.print("Velocidad = ");
      Serial.println(velocidad);
      Serial.print("Over = ");
      Serial.println(over);
    }
    else {
      over = LOW;
    }
  }
  else if ((valor[1] == 0x02) && (valor[2] == 0x02) && (Verificado == HIGH) && (velocidad == 0)) {
    over = LOW;
    Verificado == LOW;
  }
}

void control_sweep() {
  if ((valor[1] == 0x01) && (valor[2] == 0x02) && (Verificado == HIGH)) {
    Verificado = LOW;
    if (pos == 180) {
      return;
    }
    else if (pos == 90) {
      for (pos = 90; pos < 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(pausa);                       // waits 15ms for the servo to reach the position
      }
    }
    else {
      for (pos = 15; pos < 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(pausa);                       // waits 15ms for the servo to reach the position
      }
    }
  }
  else if ((valor[1] == 0x01) && (valor[2] == 0x01) && (Verificado == HIGH)) {
    Verificado = LOW;
    if (pos == 15) {
      return;
    }
    else if (pos == 90) {
      for (pos = 90; pos > 15; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(pausa);                       // waits 15ms for the servo to reach the position
      }
    }
    else {
      for (pos = 180; pos > 15; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(pausa);                       // waits 15ms for the servo to reach the position
      }
    }
  }
}
