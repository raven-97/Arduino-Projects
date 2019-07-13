//This is code for Line follower using 6 channel sensor array.
//The code is self explanatory with proper commenting showing pins and functionality



#define Kp 20 // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
#define Kd 5 // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd) 
#define MaxSpeed 100// max speed of the robot
#define BaseSpeed 65 // this is the speed at which the motors should spin when the robot is perfectly on the line

int prevpos;
bool flag=false;

#define speedturn 120

#define rightMotor1 5
#define rightMotor2 4
#define rightMotorPWM 8
#define leftMotor1 6
#define leftMotor2 7
#define leftMotorPWM 9 

int error,motorSpeed,pos,preverr,rspeed,lspeed,correction; 

int sense[]={A0,A1,A2,A3,A4,A5};
int sread[6];
int lastError = 0;

void setup() {
  // put your setup code here, to run once:
for(int i=0;i<6;i++)
pinMode(sense[i],INPUT);

  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
 


  


Serial.begin(9600);


}



void loop() {
 for(int i=0;i<6;i++)    
    {
      sread[i]=digitalRead(sense[i]);
      //Serial.print(sread[i]);
    }
    
 

    pos=32*sread[0]+16*sread[1]+8*sread[2]+4*sread[3]+2*sread[4]+1*sread[5];

    


   


if(pos==60||pos==62)//r turn 
{
  

  analogWrite(leftMotor1,speedturn);
  digitalWrite(leftMotor2,LOW);

 digitalWrite(rightMotor1,LOW);
 analogWrite(rightMotor2,speedturn);


}


if(pos==31||pos==15)//l turn {

{
analogWrite(leftMotor2,speedturn);
digitalWrite(leftMotor1,LOW);

 digitalWrite(rightMotor2,LOW);
 analogWrite(rightMotor1,speedturn);

 

}






if(pos==12 || pos==14 ||pos==28)
error=0;
if(pos==6)
error=1; // left charivu
if(pos==52 || pos==60 )
error=-1; // right charivu
if(pos==3 || pos==2)
error=2; // left charivu
if(pos==48)
error=-2; // left charivu
if(pos==32)
error=-3; // right charivu

if(pos==1)
error=3; // right charivu




correction = Kp*error +Kd*(error-preverr);
preverr=error;

rspeed=constrain(BaseSpeed-correction,0,MaxSpeed);
lspeed=constrain(BaseSpeed+correction,0,MaxSpeed);






  Serial.println();
  Serial.println(pos);


analogWrite(leftMotor1,lspeed);
  digitalWrite(leftMotor2,LOW);

 analogWrite(rightMotor1,rspeed);
  digitalWrite(rightMotor2,LOW);

  
}
