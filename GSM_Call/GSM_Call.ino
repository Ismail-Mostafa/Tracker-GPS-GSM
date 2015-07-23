

void setup()
{
 pinMode(12,INPUT); 
 pinMode(11,INPUT);
 pinMode(10,INPUT);
 Serial.begin(9600); 
}


void loop()
{
  
  if(digitalRead(12)==LOW)
  {
    Serial.println("atd01147712152;");
    delay(1000);
  }
   if(digitalRead(11)==LOW)
  {
    Serial.println("ath");
    delay(1000);
  } 
  if(digitalRead(10)==LOW)
    {
    Serial.println("at+cmgf=1");
    delay(200);
   Serial.println("at+cmgs=\"01147712152\"");
    delay(200);
    Serial.println("engzzz b2aa Tracker GSM");
    Serial.write(26);
    delay(1000);
    
    }

  
}
