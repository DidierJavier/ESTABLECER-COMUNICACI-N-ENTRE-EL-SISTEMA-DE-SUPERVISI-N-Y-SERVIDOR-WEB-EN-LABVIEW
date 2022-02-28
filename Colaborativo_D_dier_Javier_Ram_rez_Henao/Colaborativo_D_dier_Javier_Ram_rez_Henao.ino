//Programa que escribe correctamentamente el estado de la marcha 3 mediante LED en pin 13, la parada en el pin 12, por medio de labview y lee el Nivel en el PIN análogo A5
//Dídier Javier Ramírez Henao - Estudiante de Ingeniería de Telecomunicaciones.
//UNAD - Curso LabVIEW
//24/11/2021
#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial
int MarchaPIN = 13;           //Se asigna el PIN 13 a la marcha del sistema
int ParadaPIN = 12;           //Se asigna el PIN 12 a la parada del sistema
int NivelPIN = 5;             //Se asigna el PIN 5 al nivel del silo
int NivelValor;               //Se define una variable entera para guardar el valor del nivel del silo

void setup() {
  Serial.begin(9600);         //Se indica la velocidad de la comunicación serial
  pinMode(MarchaPIN, OUTPUT); //El PIN asignado a la marcha del sistema se define como salida
  pinMode(ParadaPIN, OUTPUT);//El PIN asignado a la parada se define como salida
}
void loop() {
  if(Serial.available())       //Condición para validar si hay algún dato en el puerto serial que indique cambio de estado de la marcha o de la parada (desde LabVIEW).
  {
    int Datos = Serial.read(); //Los datos de marcha o parada que llegan desde LabVIEW por comunicación serial se guardan en la variable Datos
    if (Datos == '0')                //Si el dato que llega es un cero
    {
      digitalWrite(MarchaPIN, LOW);  //El pin de marcha se pone en bajo y no activa el led
    }
    if (Datos == '1')                //Si el dato que llega es un uno
    {
      digitalWrite(MarchaPIN, HIGH); //El pin de marcha se pone en alto y el led se enciende
    }
    if (Datos == '2')                //Si el dato que llega es el 2
    {
      digitalWrite(ParadaPIN, LOW);  //Es porque el botón de parada no está presionado y por lo tanto no se enciende el led de parada
    }
    if (Datos == '3')                //Si el dato que llega es un 3
    {
      digitalWrite(ParadaPIN, HIGH); //El pin de parada se pone en alto y se enciende el led
    }   
  
  }
  
  NivelValor = analogRead(NivelPIN);                          //Se lee el valor del nivel en la entrada análoga A5 y se guarda este valor en la variable NivelValor
  Serial.print((int)NivelValor); Serial.println(" Nivel");    //Se envía el valor del nivel por el puerto serial para ser mostrado en LabVIEW.
    
    delay(50);
}
