#include <Servo.h> 
// создаём объект для управления сервоприводом
Servo myservoVertical;
Servo myservoHorizont;

int angleVertical = 90;
int angleHorizont = 90;

  const int buttonPinUp = 4;     // номер входа, подключенный к кнопке UP
  const int buttonPinDown = 16;     // номер входа, подключенный к кнопке Down
  const int buttonPinRight = 14;     // номер входа, подключенный к кнопке Right
  const int buttonPinLeft = 12;     // номер входа, подключенный к кнопке Left

  //переменные 
  int buttonUp = 0;     // номер входа, подключенный к кнопке UP
  int buttonDown = 0;     // номер входа, подключенный к кнопке Down
  
  int buttonRight = 0;     // номер входа, подключенный к кнопке Right
  int buttonLeft = 0;     // номер входа, подключенный к кнопке Left
  
void setup() 
{

  Serial.begin(9600);
  // подключаем сервопривод  к D1 (5)  и k D7 (13)
  myservoVertical.attach(5);
  myservoHorizont.attach(13);

  // инициализируем пин, подключенный к кнопке, как вход
  pinMode(buttonUp, INPUT);  
  pinMode(buttonDown, INPUT);
  pinMode(buttonRight, INPUT);  
  pinMode(buttonLeft, INPUT);
} 
 
void loop() 
{
  // считываем значения с входа кнопок
  buttonUp = digitalRead(buttonPinUp);
  buttonDown = digitalRead(buttonPinDown);
  buttonRight = digitalRead(buttonPinRight);
  buttonLeft = digitalRead(buttonPinLeft);

  // проверяем нажата ли кнопка
  // если нажата, то buttonUp||buttonDown будет HIGH:
  if (buttonUp == HIGH && angleVertical < 180 ) {       
    Serial.print("Up    Angle:  ");
    angleVertical = angleVertical + 1;
    myservoVertical.write(angleVertical );
    Serial.println(angleVertical );
    delay(100);
  }else if (buttonDown == HIGH && angleVertical > 15) {   
    // включаем светодиод  
    Serial.print("Down   Angle:  ");
    angleVertical = angleVertical - 1;
    myservoVertical.write(angleVertical );
    Serial.println(angleVertical);
    delay(100);
  }else if (buttonRight == HIGH  && angleHorizont < 175) {    
    Serial.print("Right   Angle:  ");
    angleHorizont = angleHorizont + 1;
    myservoHorizont.write(angleHorizont);
    Serial.println(angleHorizont);
    delay(100);
  }else if (buttonLeft == HIGH && angleHorizont > 0) {    
    Serial.print("Left    Angle:  ");
    angleHorizont = angleHorizont - 1;
    myservoHorizont.write(angleHorizont);
    Serial.println(angleHorizont);
    delay(100);
  }

  
  
} 
