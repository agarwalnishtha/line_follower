/*
  Line follower
  In sensor, the led is "ON" on black line but out volt is 0
*/
int l1,l2,r1,r2,c1,c2;


void left(void);
void sharpLeft(void);
void right(void);
void sharpRight(void);
void straight(void);
void stopp(void);
void trace_back(void);



void setup() {
    pinMode(3, INPUT); //assuming this as left most
    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(10, OUTPUT); //motorL1
    pinMode(11, OUTPUT); //motorL2
    pinMode(12, OUTPUT); //motorR1
    pinMode(13, OUTPUT); //motorR2
}

void loop() {
  l1 = digitalRead(3);
  l2 = digitalRead(4);
  c1 = digitalRead(5);
  c2 = digitalRead(6);
  r1 = digitalRead(7);
  r2 = digitalRead(8);
  
  if((!(c1 || c2)) && (!(r1 || r2 || l1 || l2))) // both c1 and c2 must be 0
  {
    straight();
  }
  // RIGHT
  else if((!(r1 || r2)) && (!(c1 || c2 || l1 || l2)))
  {
    right();
  }
  else if((!(r1 || c2)) && (!(c1 || r2 || l1 || l2)))
  {
    right();
  }
  else if((!(r1 || r2 || c2)) && (!(c1 || r2 || l1 || l2)))
  {
    sharpRight();
  }
  else if((!(r1 || r2 || c1 || c2)) && (!(c1 || r2 || l1 || l2)))
  {
    sharpRight();
  }
  // LEFT
  else if((!(l1 || l2)) && (!(r1 || r2 || c1 || c2)))
  {
    left();
  }
  else if((!(c1 || l2)) && (!(r1 || r2 || l1 || c2)))
  {
    left();
  }
  else if((!(l1 || l2 || c1)) && (!(r1 || r2 || c1 || c2)))
  {
    sharpLeft();
  }
  else if((!(l1 || l2 || c1 || c2)) && (!(r1 || r2 || c1 || c2)))
  {
    sharpLeft();
  }
  // STOP when all on
  else if(!(l1 || l2 || c1 || c2 || r1 || r2))
  {
      stopp();
  }
  else //some random pattern due to callibration error, go back
  {
      trace_back();
  }
}

void left(void)
{
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
}
void sharpLeft(void)
{
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);  
}
void right(void)
{
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW); 
}
void sharpRight(void)
{
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
}
void straight(void)
{
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
}
void stopp(void)
{
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
void trace_back(void)
{
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
}