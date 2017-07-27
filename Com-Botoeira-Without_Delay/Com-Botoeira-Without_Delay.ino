#define luzVermelha 2
#define luzAmarela 3
#define luzVerde 4
#define botoeira 5

int tickDoRelogio = 0;
int tempoAmarelo = 2;
int tempoVermelho = 3;
int tempoReinicia = 5;


// Variables used for timing
unsigned long timet;
unsigned long tempoativo1inicio;
unsigned long tempoativo1final;
unsigned long tempototal1;
unsigned long previousTime;
boolean enterFunction = true;
boolean botoeiraPressionada = false;
//-----------------------


void setup() {
  // set the digital pin as output:
  pinMode(luzVermelha, OUTPUT);
  pinMode(luzAmarela, OUTPUT);
  pinMode(luzVerde, OUTPUT);
  pinMode(botoeira, INPUT);

  ligaVerde();
}

void loop() {

   timet = micros();
    if (botoeiraPressionada == false){
      botoeiraPressionada = digitalRead(botoeira);
    }
      
   
  if (enterFunction == true){
    previousTime= timet;
    // Write your first code below 
    //-----------------------
    if (botoeiraPressionada == true){
      tickDoRelogio = tickDoRelogio + 1; 
    }
    
    if (tickDoRelogio <= tempoAmarelo){
      ligaVerde();
    } else if ((tickDoRelogio >= tempoAmarelo) && (tickDoRelogio <= tempoVermelho) && (botoeiraPressionada == true)){
      ligaAmarelo();       
    } else if ((tickDoRelogio > tempoVermelho) && (tickDoRelogio < tempoReinicia) && (botoeiraPressionada == true)){
      ligaVermelho();
      botoeiraPressionada = false;
    } else{
      tickDoRelogio = 0;
    }
    
    //-----------------------
    // End of your first code
  }  
   

  // The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime < 999990){ // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */   
    enterFunction= false;
  } 
  else {
    enterFunction= true;
  }
}
int ligaVerde(){
  digitalWrite(luzVerde, HIGH);
  digitalWrite(luzAmarela, LOW);
  digitalWrite(luzVermelha, LOW);
}
int ligaAmarelo(){
  digitalWrite(luzVerde, LOW);
  digitalWrite(luzAmarela, HIGH);
  digitalWrite(luzVermelha, LOW);  
}
int ligaVermelho(){
  digitalWrite(luzVerde, LOW);
  digitalWrite(luzAmarela, LOW);
  digitalWrite(luzVermelha, HIGH);
}

