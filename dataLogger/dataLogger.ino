/////////////////////////////////////////////////////////////////
//              Data Logger de 6 señales     v1.00             //
/////////////////////////////////////////////////////////////////
#include <SD.h>
#include <SPI.h>

int CS_PIN = 10;

File file;

// El pin digital 2 tiene un pulsador conectado. Dale un nombre:
int pushButton = 2;

void setup()
{

  // Serial.begin(9600);
  // Serial.begin(115200);

  Serial.begin(2000000); // pude leer hasta 600 datos por segundo (18 segundos a 10700 líneas de 1 columna)
                         // pude leer hasta 116 datos por segundo (22 segundos a 2563 líneas de 6 columnas) (con conversión a flotante)
                         // pude leer hasta 483 datos por segundo (20 segundos a 9644 líneas de 6 columnas) (sin conversión a flotante)
  pinMode(pushButton, INPUT);


  initializeSD();
  createFile("test2.txt");
  writeToFile("Comienza Lectura");

  int buttonState;
  int sensorValue1, sensorValue2, sensorValue3, sensorValue4, sensorValue5, sensorValue6;
  float conv1, conv2, conv3, conv4, conv5, conv6;

  do
  {
    // lee el estado del pulsador:
    buttonState = digitalRead(pushButton);
    Serial.println(buttonState);
    sensorValue1 = analogRead(A0);
    sensorValue2 = analogRead(A1);
    sensorValue3 = analogRead(A2);
    sensorValue4 = analogRead(A3);
    sensorValue5 = analogRead(A4);
    sensorValue6 = analogRead(A5);


    writeToFileValue(sensorValue1);
    file.print("\t");
    writeToFileValue(sensorValue2);
    file.print("\t");
    writeToFileValue(sensorValue3);
    file.print("\t");
    writeToFileValue(sensorValue4);
    file.print("\t");
    writeToFileValue(sensorValue5);
    file.print("\t");
    writeToFileValue(sensorValue6);

    writeToFileString(".");
    // closeFile();
  } while (buttonState == 1);

  closeFile(); // necesario para el guardado final
  Serial.println("FIN DEL PROGRAMA");
  
}

void loop()
{
}


void initializeSD()
{
  Serial.println("Inicializando la tarjeta SD...");
  pinMode(CS_PIN, OUTPUT);

  if (SD.begin())
  {
    Serial.println("La tarjeta SD está lista para usar.");
  }
  else
  {
    Serial.println("Error al inicializar la tarjeta SD");
    return;
  }
}

int createFile(char filename[])
{
  file = SD.open(filename, FILE_WRITE);

  if (file)
  {
    Serial.println("Archivo creado exitosamente.");
    return 1;
  }
  else
  {
    Serial.println("Error al crear el archivo.");
    return 0;
  }
}

// funciOn de textos
int writeToFile(char text[])
{
  if (file)
  {
    file.println(text);
    Serial.println("Escribiendo en el archivo: ");
    Serial.println(text);
    return 1;
  }
  else
  {
    Serial.println("No se pudo escribir en el archivo");
    return 0;
  }
}


int writeToFileValue(int value)
{
  if (file)
  {
 
    file.print(value);
   
    return 1;
  }
  else
  {
    // Serial.println("No se pudo escribir en el archivo");
    return 0;
  }
}

int writeToFileString(char text[])
{
  if (file)
  {
    file.println(text);
    Serial.println("Escribiendo en el archivo: ");
    Serial.println(text);
    return 1;
  }
  else
  {
    Serial.println("No se pudo escribir en el archivo");
    return 0;
  }
}

void closeFile()
{
  if (file)
  {
    file.close();
    Serial.println("Archivo cerrado");
  }
}




