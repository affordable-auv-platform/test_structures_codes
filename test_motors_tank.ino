#include <Servo.h>
#define VEL_INI 180
#define ACELERACAO 180

Servo myservo;
int velocidade;

void arm(){
  setSpeed(VEL_INI);
  delay(3000);}

void setSpeed(int speed){
  myservo.write(speed); 
}

void setup()
{ Serial.begin(9600);
  myservo.attach(10); 
  velocidade = 180;
  arm();  }

void loop() {  
  char comando;
   if(Serial.available( )> 0){
     char c = Serial.read();
     Serial.println(c);
     comando = c;
  }
  
   switch (comando){
      case 'q':  //  Aumenta a rotação
        velocidade = velocidade + ACELERACAO;
        Serial.println(velocidade);
        setSpeed(velocidade);
        delay(1000); 
      break;
    
      case 'w':  //  Diminui a rotação
        velocidade = velocidade - ACELERACAO;
        Serial.println(velocidade);
        setSpeed(velocidade);
        delay(1000);
      break;
      
      case 'e':  // Desliga o motor
        velocidade = VEL_INI+ACELERACAO;
        setSpeed(velocidade);
      break; 
	  
      case 'r': // Aumenta a rotação até o max
	aumentar();
      break; 
   }
}

void aumentar(){     
  int speed;
  for(speed = 0; speed <= 100; speed += 5) {
        setSpeed(speed);
        delay(1000);
  }
}

