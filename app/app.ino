/*
 * Rotina para definir o solo com o MH Sensor Series
 * Equipe TechAgro 
 * 22-10-2017
*/

//Carrega a biblioteca SoftwareSerial
//#include <SoftwareSerial.h>
   
//Define os pinos para a serial  (RX, TX)
//SoftwareSerial MinhaSerial(3,2);

#define analogico A0
#define led_vermelho 12
#define led_amarelo 11
#define led_verde 10
 
int valor_analogico;
int seco, umidade;

void setup()
{
  pinMode(analogico, INPUT);        //entrada
  pinMode(led_vermelho, OUTPUT);    //saida
  pinMode(led_amarelo, OUTPUT);     //saida
  pinMode(led_verde, OUTPUT);       //saida
  Serial.begin(9600);
}
 
void loop()
{
  //Le o valor analogico do pino A0
  valor_analogico = analogRead(analogico);
  leitura();
  
  //Solo umido, acende o led verde
  if (valor_analogico > 0 && valor_analogico < 450)
  {
    apagaleds();
    digitalWrite(led_verde, HIGH);
  }
 
  //Solo com umidade moderada, acende led amarelo
  if (valor_analogico > 451 && valor_analogico < 949)
  {
     apagaleds();
    digitalWrite(led_amarelo, HIGH);
  }
 
  //Solo seco, acende led vermelho
  if (valor_analogico > 950 && valor_analogico < 1020)
  {
    apagaleds();
    digitalWrite(led_vermelho, HIGH);
  }
  delay(1000);
}

void apagaleds()
{
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_verde, LOW);
}

void leitura(){
  //Mostra o valor da porta analogica no serial monitor
  Serial.println(" "); Serial.print("Valor: ");
  Serial.print(valor_analogico);
  seco = (valor_analogico * 100) / 1000;
  if (valor_analogico >= 950) 
   { 
     seco = 100;
   } 
  if (valor_analogico < 350 )
   {  umidade = 100;
      seco = 0; }
  else { umidade = 100 - seco;
    }
  Serial.println(" "); Serial.print("Seco: ");
  Serial.print(seco);  Serial.print(" %");
  Serial.println(" "); Serial.print("umidade: ");
  Serial.print(umidade); Serial.print(" %");
  Serial.println(" ");
  delay(1000);
}
