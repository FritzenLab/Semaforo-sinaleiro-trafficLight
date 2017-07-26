#define luzVermelha 2
#define luzAmarela 3
#define luzVerde 4


void setup() {
  // set the digital pin as output:
  pinMode(luzVermelha, OUTPUT);
  pinMode(luzAmarela, OUTPUT);
  pinMode(luzVerde, OUTPUT);
}

void loop() {
  
  digitalWrite(luzVerde, HIGH);
  digitalWrite(luzAmarela, LOW);
  digitalWrite(luzVermelha, LOW);
  delay(3000);

  digitalWrite(luzVermelha, LOW);
  digitalWrite(luzAmarela, HIGH);
  digitalWrite(luzVerde, LOW);
  delay(1000);

  digitalWrite(luzVerde, LOW);
  digitalWrite(luzAmarela, LOW);
  digitalWrite(luzVermelha, HIGH);
  delay(5000);
  
}

