# Music_with_ligth_arduino
Arduino: componiamo note musicali usando la luce

Siamo pronti a fare rumore. Utilizzando una board Arduino, una fotoresistenza e un piezo potrai realizzare il tuo theremin comandato dalla luce.

Il theremin è uno strumento musicale che produce suoni in base ai movimenti delle mani del musicista. Il theremin rileva la posizione delle mani del musicista in relazione a due antenne leggendo le variazioni di capacità sulle antenne, che sono collegate a un circuito analogico che crea il suono. Un’antenna controlla la frequenza del suono e l’altra controlla il volume.

Con Arduino è possibile emulare questi suoni utilizzando la funzione tone().

Quali sono le differenze tra analogWrite() e tone() che permette a un trasduttore come uno speaker o un piezo di vibrare a velocità diverse?

La funzione tone() opera in modo molto simile al PWM in analogWrite(), ma con una differenza significativa.

In analogWrite() la frequenza è fissa; cambia il ciclo di lavoro degli impulsi in un dato periodo di tempo. Con tone() invii ancora impulsi, ma cambiando la loro frequenza. tone() manda sempre impulsi a un ciclo di lavoro del 50%.

Vediamo questa immagine per capire la differenza:

![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2021/07/1-1.png?resize=300%2C257&ssl=1)

Nel primo caso si può notare come sia basso il segnale nella maggior parte del tempo, ma la frequenza è la stessa di PWM 200.

Nel secondo caso possiamo notare come sia alta la tensione nella maggior parte del tempo ma la frequenza è la stessa di PWM 50.

Nel terzo caso il ciclo di lavoro è al 50% ma cambia la frequenza rispetto al quarto caso.

Nel quarto caso abbiamo lo stesso ciclo di lavoro del terzo caso ma abbiamo una frequenza doppia.

In questo progetto effettueremo una calibrazione. Perchè?

La funzione tone() ti offre la possibilità di generare frequenze diverse tramite uno speaker. Usando i sensori in un partitore di tensione, probabilmente non sarà possibile ottenere l’intera gamma di valori tra 0 e 1023. Calibrando i sensori, è possibile mappare gli ingressi a un intervallo adatto.

Componenti da utilizzare:

* 1x board Arduino Uno
* 1x buzzer passivo
* 1x fotoresistenza
* 1x resistenza da 10 kilo ohm
* vari jumper

Muovendo le mani sul sensore, cambia la quantità di luce che cade sulla fotoresistenza. Il cambiamento di tensione sul piedino analogico determina la frequenza delle note.

![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2021/10/circuito.png?resize=768%2C363&ssl=1)

Diagramma di collegamento:

![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2021/07/circuito-2.png?w=587&ssl=1)

# [CODICE](https://github.com/SimoneMoreWare/Music_with_ligth_arduino/blob/main/musicligth.ino)

Nella programmazione funzionale una map è una funzione che applica una data funzione ad una lista di elementi e restituisce una lista di risultati.

Ora sei pronto a copiare e caricare il codice sulla board Arduino.

![alt text](https://i0.wp.com/www.moreware.org/wp/wp-content/uploads/2021/07/d8655f08-cc8f-4e2e-a3d1-37debc107618-min.png?resize=768%2C511&ssl=1)

Conclusione

Quando accendi Arduino, c’è una finestra di 5 secondi per calibrare il sensore. Per farlo, muovi la mano su e giù sopra la fotoresistenza modificando la quantità di luce che la raggiunge.

Dopo 5 secondi la calibrazione è completa. Dovresti quindi sentire dei rumori provenienti dallo speaker.

Al variare della quantità di luce che cade sui sensori dovrebbe variare la frequenza prodotto dal piezo.
