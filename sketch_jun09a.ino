#include <Servo.h>    // 声明调用Servo.h库
Servo myservo;        // 创建一个舵机对象
int pos = 0;          // 变量pos用来存储舵机位置
const int buttonPin = 2;     

const int ledPin =  7;      

int buttonState = 0;         

void setup() {

  pinMode(ledPin, OUTPUT);
  myservo.attach(9);
  pinMode(buttonPin, INPUT);

}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {

    digitalWrite(ledPin, HIGH);
    for(pos = 0; pos < 180; pos += 1){    // 舵机从0°转到180°，每次增加1°          
      myservo.write(pos);           // 给舵机写入角度   
      delay(15);                    // 延时15ms让舵机转到指定位置
   }
    for(pos = 180; pos>=1; pos-=1) {    // 舵机从180°转回到0°，每次减小1°                               
       myservo.write(pos);        // 写角度到舵机     
       delay(1);                 // 延时15ms让舵机转到指定位置
    } 
    

  }

  else {

    digitalWrite(ledPin, LOW);

  }

}
