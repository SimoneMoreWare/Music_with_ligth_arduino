/*
Crea una variabile per memorizzare il valore letto dalla fotoresistenza
con analogRead(). Poi, crea variabili per i valori alto e basso. Imposta
il valore iniziale nella variabile sensoreLow a 1023 e il valore di 
sensorHigh a 0. Quando esegui il programma per la prima volta, confronta 
questi numeri alla lettura del sensore per trovare i reali valori massimi
e minimi
*/

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
 
/*
Crea una costante chiamata ledPin. Userai questo LED come indicatore del 
fatto che il sensore ha finito la calibrazione. 
*/

const int ledPin = 13;
 
void setup()
{
 /*
  imposto ledPin come output e accendo il led
 */

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
 
  /*
   Nei passi successivi occorre calibrare i valori minimi e massimi del 
   sensore. Usa un'istruzione while() per eseguire un ciclo per 5 secondi.
   Il ciclo while si esegue fino a che si verifica una certa condizione. In
   questo caso usa la funzione millis() per misurare il tempo. millis()
   riporta da quanti millesimi di secondo Arduino è accesso.
  */
 
  while (millis() < 5000)
  {
    /*
     Nel ciclo leggi il valore del sensore. Se il valore è minore di sensorLow, 
     aggiorna questa variabile. Se è più grande di SensorHigh aggiornalo.
    */
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh)
    {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow)
    {
      sensorLow = sensorValue;
    }
  }
  
  /*
   Quando sono passati 5 secondi il ciclo while non eseguirà nessuna istruzione. 
   Spegni il led collegato al pin 13. Usa i valori maggiore e minore del sensore 
   appena registrato per calcolare la frequenza nella parte principale del codice.
  */

  digitalWrite(ledPin, LOW);
}
 
/*
Nel loop(), leggi il valore su A0 e assegnalo in sensorValue
*/

void loop()
{
  sensorValue = analogRead(A0);
  
  /*
   Crea una variabile di nome pitch. Il valore di pitch viene calcolato a partire 
   sensorValue. Utilizza sensorLow e sensorHigh come i limiti per i valori in
   entrata. Come valori iniziali d'usicta prova 50 e 4000. Questi numeri impostano
   l'intervallo di frequenze che genererà arduino
  */

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  
  /* 
  Chiama la funzione tone() per riprodurre un suono. Ci vogliono tre argomenti: 
  quale piedino far suonare
  quale frequenza generare
  per quanto tempo suonare la nota
  */

  tone(8, pitch, 20);
  delay(20);
  
  
}
