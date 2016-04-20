#include <math.h>

//Variaveis de controle 
#define N 16
int data[N] = {0};  
int i = 0;
boolean flag = false;

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  
  // read from port 1, send to port 0:
  if (Serial1.available()) {   
    int inByte = Serial1.read();
    
    if(inByte == 63)
      flag = true; 
    
    if (flag){
      data[i] = crazyConversion(inByte);
      i++;
    }
    
    //Just to see 
    //Serial.print(crazyConversion(inByte));
    //Serial.print(inByte);
    //Serial.print(" ");   
    if (inByte == 121){
      //Serial.println();
      i = 0;
      flag = false; 
      //view(data);
      Serial.println(getNumber(data));
    } 
  }
  
}

double getNumber(int v[])
{
   double force = 0; 
   force = v[7]*pow(10,7) + v[8]*pow(10,6) + v[9]*pow(10,5) + v[10]*pow(10,4) + v[11]*pow(10,3) + v[12]*pow(10,2) +  v[13]*pow(10,1) + v[14];
   force = force/(pow(10,v[6]));
   
   if(v[5]==1)
     force = -force;
     
   return force;  
}

void view(int v[])
{
  for (int i = 0; i < N -1; i++) {
    Serial.print(v[i]);
    Serial.print(" ");
  }
  Serial.println(v[N-1]);
}

int crazyConversion (int x)
{
  switch (x) {
    case 6:
      return 0;
      break;
    case 103:
      return 1;
      break;
    case 51:
      return 2;
      break;
    case 102:
      return 3;
      break;
    case 25:
      return 4;
      break;
    case 101:
      return 5;
      break;
    case 50:
      return 6;
      break;
    case 100:
      return 7;
      break;
    case 12:
      return 8;
      break;
    case 99:
      return 9;
      break;
    case 121:
      return 121;
      break;  
    case 63:
      return 63;
    break;
    default: 
      return 99;
  }
}
