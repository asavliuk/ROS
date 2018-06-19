/* this code is written by geobruce
for more info check my site http://xprobe.net
*/
#include <Servo.h> // include Servo library 

Servo horizontal; // horizontal servo
int servoh = 110; // stand horizontal servo

Servo vertical; // vertical servo 
int servov = 35; // stand vertical servo

// LDR pin connections
// name = analogpin;
//int ldrlt = 0; //LDR top left
//int ldrrt = 3; //LDR top rigt
//int ldrld = 1; //LDR down left
//int ldrrd = 2; //ldr down rigt

int ldrlt = 3; //LDR top left
int ldrrt = 0; //LDR top rigt
int ldrld = 2; //LDR down left
int ldrrd = 1; //ldr down rigt


void setup()
{
  Serial.begin(9600);
// servo connections
// name.attacht(pin);
  horizontal.attach(9); 
  vertical.attach(10);
}

void loop() 
{
  int lt = analogRead(ldrlt); // top left
  int rt = analogRead(ldrrt); // top right
  int ld = analogRead(ldrld); // down left
  int rd = analogRead(ldrrd); // down rigt
  
  Serial.print("\t | LT: ");  Serial.print(lt);
  Serial.print("\t | RT: ");  Serial.print(rt);
  Serial.print("\t | LD: ");  Serial.print(ld);
  Serial.print("\t | RD: ");  Serial.println(rd);
  

//  int dtime = analogRead(4)/20; // read potentiometers
  int tol = analogRead(5)/4;
  
  Serial.print("\t | tol: ");
  Serial.println(tol);
  
  int dtime = 500; // 2 sec
  int sunTime = 60000; // час наскільки треба зупинитися якщо група TOP == DOWN || RIGHT == LEFT
//  int tol = 10;

  int avt = (lt + rt) / 2; // average value top
  int avd = (ld + rd) / 2; // average value down
  int avl = (lt + ld) / 2; // average value left
  int avr = (rt + rd) / 2; // average value right
//
//  Serial.print("top: ");
//  Serial.print(avt);
//  Serial.print("\t | down: ");
//  Serial.print(avd);
//  Serial.print("\t \t | left: ");
//  Serial.print(avl);
//  Serial.print("\t \t | right: ");
//  Serial.println(avr); 
//  Serial.println("");

  int dvert = avt - avd; // check the diffirence of up and down
  int dhoriz = avl - avr;// check the diffirence og left and rigt

  Serial.print("\t | vertic: ");
  Serial.print(dvert);
  Serial.print("\t | horizont: ");
  Serial.println(dhoriz); 
  Serial.println("");

  if (-1*tol > dvert || dvert > tol) // check if the diffirence is in the tolerance else change vertical angle
  {
     if (avt > avd) // якщо група TOP більша за DOWN то піднимаэмо
      { 
            Serial.print("Up: " );  Serial.print(servov); Serial.print(" | ");
        servov = ++servov;
            Serial.println(servov); 
        if (servov < 10)
        {
            servov = 160;
        }
      }
      else if (avt < avd) // якщо група TOP більша за DOWN то піднимаэмо// якщо група TOP більша за DOWN то піднимаэмо
      {
            Serial.print("Down: " );  Serial.print(servov); Serial.print(" | ");
        servov = --servov;
            Serial.println(servov); 
        if (servov > 160)
        {
          servov = 25;
        }
      }
     vertical.write(servov);
  }
  
  if (-1*tol > dhoriz || dhoriz > tol) // check if the diffirence is in the tolerance else change horizontal angle
  {
    if (avl < avr) // якщо ліва сторона більша за праву то повернути серво в ліво
    {
            Serial.print("Right: " ); Serial.print(servov); Serial.print(" | ");
      servoh = ++servoh;
            Serial.println(servov); 
      if (servoh > 160)
      {
        servoh = 25;
      }
    }
    else if (avl > avr) // якщо ліва сторона меньша за праву то повернути серво в право
    {
            Serial.print("Left: " );  Serial.print(servov); Serial.print(" | ");
      servoh = --servoh;  
            Serial.println(servov); 
      if (servoh < 10)
      {
        servoh = 160;
      }
    }
    else if (avl == avr)
    {
    // nothing
    }
    horizontal.write(servoh);
  }
  else if (dvert == dhoriz)
   {
     Serial.println(" =============================================================\n \t Waiting  5 sec \n \t Сонечко знаходеться у точці що ви обрали!\n =============================================================\n");
     delay(sunTime);
   }
delay(dtime);
} 
