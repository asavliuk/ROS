int IN3 = 4; // Input3 подключен к выводу 5 
int IN4 = 5;
int ENB =0;

int IN1 = 12; 
int IN2 = 14;
int ENA = 13;
int i;


void setup()
{
 Serial.begin(115200); // открываем соедениение с портом на скорости 115200
 
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);

 pinMode (ENA, OUTPUT); //устанавливает скорость мотора ENA
 pinMode (ENB, OUTPUT); //устанавливает скорость мотора ENB

 
}
void loop()
{
  if (Serial.available()){  
    char i = (char)Serial.read();   
//    i = Serial.read();
    
    if (i=='U'){
        Serial.println("Up");
        digitalWrite (IN3, HIGH);
        digitalWrite (IN4, LOW); 
        analogWrite(ENB,1000);
        delay(1000);
    }

    else if (i=='D'){
        Serial.println("Down");
        digitalWrite (IN3, LOW);
        digitalWrite (IN4, HIGH); 
        analogWrite(ENB,1000);
        delay(1000);
    }

  else if (i=='R'){
        Serial.println("Right");
        digitalWrite (IN1, LOW);
        digitalWrite (IN2, HIGH); 
        analogWrite(ENA,1000);
        delay(1000); 
    }

  else if (i=='L'){
        Serial.println("Right");
        digitalWrite (IN1, HIGH);
        digitalWrite (IN2, LOW); 
        analogWrite(ENA,1000);
        delay(1000); 
    }
  else {
        Serial.println("Error"); 
        analogWrite(ENB,0);
        analogWrite(ENA,0);
        delay(5000);
      }


}
      
  }

