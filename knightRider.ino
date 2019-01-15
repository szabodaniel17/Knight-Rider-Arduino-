int pinArr[] = {2, 3, 4, 5, 6, 7, 8, 9}; //the LED pin array
int t = 50; // represents the delay in ms
int index = 0;
int brightness = 0; // initial brightness of the LED(off)
int fadeAmount = 5; //increasing factor for the brightness
int off = 0;
int val = 0;
void setup()
{
  Serial.begin(9600);
  for (index = 0; index < 7; index++)
  {
    pinMode(pinArr[index], OUTPUT);
  }
  pinMode(A0, INPUT); // analog value read from the potentiometer
}

void loop()
{

  val = analogRead(A0);
  Serial.print(val);
  Serial.print("\n");
  if (val < 300) // First animation(Knight Rider)
  {
    for (index = 0 ; index < 7; index++)
    {
      analogWrite(pinArr[index], 255);
      delay(t);
      analogWrite(pinArr[index + 1], 255);
      delay(t);
      analogWrite(pinArr[index], 0);
      delay(t);
    }
    for (index = 7 ; index > 0; index--)
    {
      analogWrite(pinArr[index], 255);
      delay(t);
      analogWrite(pinArr[index - 1], 255);
      delay(t);
      analogWrite(pinArr[index], 0);
      delay(t);
    }
  }
  if (val > 300 && val < 500) // Second animation(PWM)
  {
    for (index = 0 ; index < 7; index++)
    {
      for (fadeAmount = 5; fadeAmount < 200; fadeAmount += 5)
      {
        analogWrite(pinArr[index], brightness);
        analogWrite(pinArr[index + 1], brightness);
        brightness = brightness + fadeAmount;
        delay(t * 2);
      }
      analogWrite(pinArr[index], off);

    }
  }
    if(val>500) // Third animation
    {
      ascend();
      descend();
      allOnOff();
      animation1();
      allOnOff();
      animation2();
      allOnOff();
    }
  

}

void ascend()
{
  for(int i = 0 ; i < 7; i++)
  {
    digitalWrite(pinArr[i],HIGH);
    delay(100);
    digitalWrite(pinArr[i],LOW);
  }
}

void descend(){
   for(int i = 7 ; i > 0; i--)
  {
    digitalWrite(pinArr[i],HIGH);
    delay(100);
    digitalWrite(pinArr[i],LOW);
  }
}

void allOff()
{
  for(int i = 7 ; i > 0; i--)
  {
    digitalWrite(pinArr[i],LOW);
  }
}

void allOnOff()
{
  for(int i = 0 ; i < 7; i++)
  {
    digitalWrite(pinArr[i],HIGH);
    
  }
  delay(200);
  for(int i = 0 ; i < 7; i++)
  {
    digitalWrite(pinArr[i],LOW);
  }
}

void animation1()
{
  for(int i = 0; i < 7; i++)
  {
    digitalWrite(pinArr[i],HIGH);
    for(int j = i+1; j < 7; j++)
    {
      digitalWrite(pinArr[j],HIGH);
      delay(t*2);
      digitalWrite(pinArr[j],LOW);
    }
    digitalWrite(pinArr[i],LOW);
  }
}

void animation2()
{
  for(int i = 0; i < 7; i++)
  {
    for(int j = i+1; j < 7; j++)
    {
      digitalWrite(pinArr[j],HIGH);
      delay(t*2); 
    }
    delay(100);
    allOff();
  }
}
