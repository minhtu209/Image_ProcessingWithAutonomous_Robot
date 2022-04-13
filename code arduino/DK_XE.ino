#define enA 9
#define enB 10
#define IN1 7 //L298N
#define IN2 6
#define IN3 5
#define IN4 4
String command;

void setup(){
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  
}
void motorControlNoSpeed (byte in1,byte in2, byte direct)
{

switch (direct) 
  {
    case 0:// Dc ko quay
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      break;
    case 1:// Quay chieu 1
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      break;    
    case 2:// Quay  chiều 2
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      break;
    //default: 
  }
}
void robotMover (byte inR1, byte inR2, byte inL1, byte inL2, byte action)
{
  switch (action)
  {
    case 0:// dừng
    
      motorControlNoSpeed(inR1, inR2, 0);
      motorControlNoSpeed(inL1, inL2, 0);
      break;
    case 1: // đi lên 
    
      analogWrite(enA,70);
      analogWrite(enB,74);
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 1);
      
      break;
    case 2:// đi lùi
      analogWrite(enA,60);
      analogWrite(enB,64);
      
      motorControlNoSpeed(inR1, inR2, 2);
      motorControlNoSpeed(inL1, inL2, 2);
      break;
    case 3:// lệch trái 1
    
      analogWrite(enA,75);
      analogWrite(enB,0);
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 1);
      break;
    case 4:// lệch trái 2
      analogWrite(enA,60);
      analogWrite(enB,64);
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 1);
      break;
    case 5:// lệch phải 1
      analogWrite(enA,0);
      analogWrite(enB,80);
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 1);
      break;
    case 6://lệch phải 2
      analogWrite(enA,63);
      analogWrite(enB,73);
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 1);
      break;
    case 7:// quay phải
      analogWrite(enA,60);
      analogWrite(enB,0);
      motorControlNoSpeed(inR1, inR2, 1);
      motorControlNoSpeed(inL1, inL2, 2);
      break;
    case 8: //quay trái
      analogWrite(enA,0);
      analogWrite(enB,60);
      motorControlNoSpeed(inR1, inR2, 2);
      motorControlNoSpeed(inL1, inL2, 1);
      break;  
    default:
      action = 0;
      
  }
}
void loop(){
  

  if(Serial.available() > 0) {

    //goi ham string command
    Serial.setTimeout(30);// xet thoi gian nhan bien
     command = Serial.readString();
    Serial.println(command[0]);
     switch(command[0]){ 
     case 'p':// xe dung
     robotMover(IN1,IN2,IN3,IN4,0);
     break;
        
     case 'b'://lùi
     robotMover(IN1,IN2,IN3,IN4,2);
     //Serial.println("xe di lui");
     delay(200);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(10);
     break;
     case 'g':// lên
     robotMover(IN1,IN2,IN3,IN4,1);
     //Serial.println("xe di thang");
     delay(120);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(50);
     break;
     case '1'://đi lệch trái 1
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(100);
     //robotMover(IN1,IN2,IN3,IN4,0);
     //delay(30);
     robotMover(IN1,IN2,IN3,IN4,3);
     delay(30);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     case '2'://đi lệch trái 2
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(80);
     //robotMover(IN1,IN2,IN3,IN4,0);
    // delay(30);
     robotMover(IN1,IN2,IN3,IN4,3);
     delay(35);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     case '3'://đi lệch trái 3
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(60);
     //robotMover(IN1,IN2,IN3,IN4,0);
     //delay(30);
     robotMover(IN1,IN2,IN3,IN4,3);
     delay(40);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     case '4'://đi lệch trái 4
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(50);
     //robotMover(IN1,IN2,IN3,IN4,0);
     //delay(30);
     robotMover(IN1,IN2,IN3,IN4,3);
     delay(45);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     case '5':// đi lệch trái 5
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(40);
     //robotMover(IN1,IN2,IN3,IN4,0);
     //delay(30);
     robotMover(IN1,IN2,IN3,IN4,3);
     delay(50);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     case '6'://đi lệch phải 1
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(100);
     //robotMover(IN1,IN2,IN3,IN4,0);
     //delay(30);
     robotMover(IN1,IN2,IN3,IN4,5);
     delay(30);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     case '7'://đi lệch phải 2
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(80);
     //robotMover(IN1,IN2,IN3,IN4,0);
     //delay(30);
     robotMover(IN1,IN2,IN3,IN4,5);
     delay(35);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     case '8'://đi lệch phải 3
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(60);
     //robotMover(IN1,IN2,IN3,IN4,0);
     //delay(30);
     robotMover(IN1,IN2,IN3,IN4,5);
     delay(40);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     case '9'://đi lệch phải 4
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(50);
     //robotMover(IN1,IN2,IN3,IN4,0);
     //delay(30);
     robotMover(IN1,IN2,IN3,IN4,5);
     delay(45);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     case '10':// đi lệch phải 5
     //robotMover(IN1,IN2,IN3,IN4,1);
     //delay(40);
     //robotMover(IN1,IN2,IN3,IN4,0);
     //delay(30);
     robotMover(IN1,IN2,IN3,IN4,5);
     delay(50);
     robotMover(IN1,IN2,IN3,IN4,0);
     delay(100);
     break;
     
     }
  }
}

    
    
