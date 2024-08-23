// Declarando portas
#define sensorDireita 4 // Porta do Infravermelho do lado direito
#define sensorEsquerda 12 // Porta do Infravermelho do lado esquerdo

#define pinMotorD1 5 // Pino IN3 (Motor da direita)
#define pinMotorD2 6 // Pino IN4 (Motor da direita)
#define pinMotorE1 10 // Pino IN1 (Motor da esquerda)
#define pinMotorE2 11 // Pino IN2 (Motor da esquerda)

#define velocidade 90 // Velocidade do motor

// Declarando funções
void IrParaFrente();
void IrParaDireita();
void IrParaEsquerda();
void Frear();

void setup() {
  // Declarando os sensores como INPUT
  pinMode(sensorDireita, INPUT);
  pinMode(sensorEsquerda, INPUT);

  // Declarando os motores como OUTPUT
  pinMode(pinMotorD1, OUTPUT);
  pinMode(pinMotorD2, OUTPUT);
  pinMode(pinMotorE1, OUTPUT);
  pinMode(pinMotorE2, OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  bool estadoDireita = digitalRead(sensorDireita); // Variavel que armazena os valores do sensor da direita
  bool estadoEsquerda = digitalRead(sensorEsquerda); // Variavel que armazena os valores do sensor da esquerda

  Serial.print("Direita: ");
  Serial.println(estadoDireita);
  Serial.print("Esquerda: ");
  Serial.println(estadoEsquerda);
  delay(1000);

  // Se ambos os sensores estiverem no branco, o carro vai para frente
  if(estadoDireita && estadoEsquerda) {
    IrParaFrente();
  }

  // Se ambos os sensores estiverem no preto, o carro vai frear
  if(!estadoDireita && !estadoEsquerda) {
    Frear();
  }

  // Se somente o sensor da esquerda estiver no branco, o carro vai para direita
  if(!estadoDireita && estadoEsquerda) {
    IrParaDireita();
  }

  // Se somente o sensor da direita estiver no branco, o carro vai para esquerda
  if(estadoDireita && !estadoEsquerda) {
    IrParaEsquerda();
  }
}

void IrParaFrente() {
  analogWrite(pinMotorD1, 0);
  analogWrite(pinMotorD2, velocidade);
  analogWrite(pinMotorE1, 0);
  analogWrite(pinMotorE2, velocidade);
}

void IrParaDireita() {
  analogWrite(pinMotorD1, 0);
  analogWrite(pinMotorD2, velocidade);
  analogWrite(pinMotorE1, velocidade);
  analogWrite(pinMotorE2, 0);
}

void IrParaEsquerda() {
  analogWrite(pinMotorD1, 0);
  analogWrite(pinMotorD2, velocidade);
  analogWrite(pinMotorE1, velocidade);
  analogWrite(pinMotorE2, 0);
}

void Frear() {
  analogWrite(pinMotorD1, 0);
  analogWrite(pinMotorD2, 0);
  analogWrite(pinMotorE1, 0);
  analogWrite(pinMotorE2, 0);
}
