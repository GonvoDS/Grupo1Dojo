// C++ code
//

#define A 12
#define B 13
#define C 2
#define D 3
#define E 4
#define F 11
#define G 10
#define SUMAR 7
#define MOSTRAR 8

int leds[] = {A, B, C, D, E, F, G};
int digitos[][7] = {{1,1,1,1,1,1,0}, //Numero 0 
					{0,1,1,0,0,0,0},  //Numero 1
					{1,1,0,1,1,0,1},  //Numero 2
					{1,1,1,1,0,0,1},  //Numero 3
					{0,1,1,0,0,1,1},  //Numero 4
					{1,0,1,1,0,1,1},  //Numero 5
					{1,0,1,1,1,1,1},  //Numero 6
					{1,1,1,0,0,0,0},  //Numero 7
					{1,1,1,1,1,1,1},  //Numero 8
					{1,1,1,1,0,1,1}}; //Numero 9
int numero = 0;

void mostrar_numero(int numero[]){
  for(int x=0; x < 7; x++) {
    if (numero[x] == 1) {
      digitalWrite(leds[x], HIGH);
    } else {
      digitalWrite(leds[x], LOW);
    }
  }
}

void setup(){
  //<> {}
  for(int i = 0; i <= 6; i++){
    pinMode(leds[i], OUTPUT);
  }
  pinMode(SUMAR, INPUT);
  pinMode(MOSTRAR, INPUT);
}

void loop(){
  	numero = contador();
  	mostrar(numero);
}

void mostrar(int digito){
  int presionar = digitalRead(MOSTRAR);
  bool entre = true;
  if(presionar == HIGH and entre){
    delay(200);
 	mostrar_numero(digitos[digito]);
    numero = 0;
    entre = false;
  }
}

int contador()
{
  int presionar = digitalRead(SUMAR);
  if(presionar == HIGH){
    delay(200);
    numero++;
  }
  return numero;
}
