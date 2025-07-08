const int pinoTrig = 3;
const int pinoEcho = 4;
long duracao;
float distanciaCM;

int ledVerde = 10; //Porta 10 para o led

void setup() {
  Serial.begin(9600);
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(ledVerde, OUTPUT); 
  Serial.println("Iniciando leitura...");
}

void loop() {
  // Envia o pulso ultrassônico
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // Lê o tempo de resposta do eco
  duracao = pulseIn(pinoEcho, HIGH);

  // Converte para distância em centímetros
  distanciaCM = duracao * 0.034 / 2;

  // Exibe no monitor serial
  Serial.print("Distancia em cm: ");
  Serial.println(distanciaCM);
  
  if (distanciaCM <20){ // se a distância for menor que 20CM
	digitalWrite(ledVerde, HIGH);//ligamos o led
    delay(1000); // Aguarda 1 segundo
  }else{
    digitalWrite(ledVerde, LOW);// senão,desligamos o led
  }

  delay(1000); // Aguarda 1 segundo
}
