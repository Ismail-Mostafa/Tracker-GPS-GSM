char x;
char gsm;
char gps[50];
int valid=0;
int index=0;
int pc=3;  //power control to power on GSM
int ri=2;  //Ring indicator pin
void setup()
{
 Serial.begin(9600); //PC
 Serial1.begin(9600); //GPS
 Serial2.begin(9600); //GSM
    
    
pinMode(ri,INPUT); 
delay(500);
pinMode(pc,OUTPUT);

digitalWrite(pc,HIGH);
delay(2000);
pinMode(pc,INPUT);
delay(2000);




  
}

void loop()
{
  
  if(Serial.available())
  {
    gsm=Serial.read();
    if(gsm=='r')
    Serial2.println("atd01147712152;");
    
    Serial.println("done");
    delay(500);
}
  
  if(Serial1.available())
  {
    x=Serial1.read();
    if(x=='$')   //start GPS header packet
    valid=1;
    else if(x=='G')
     valid++; 
     else if(x=='P')
     valid=3;
     else if(x=='A' && valid==5)
     {
       valid=6;
    }
     else{
     if(valid<6) 
     valid=0;}
     
     if(valid==6)
     {
       
      gps[index]=x;
      index++; 
     }
     
     if(valid==6&&index>40)
     {
       //13 to 23 lat
       //25 to 36 lon
       Serial.print(" LAT= ");
       for(int j=13;j<24;j++){
       Serial.write(gps[j]);
       
       }
        Serial.println();

        Serial.print(" LONG= ");
       for(int j=25;j<37;j++)
        Serial.write(gps[j]);
        Serial.println();
        
     
        valid=0;
        index=0;
     }
 
  }
  while(digitalRead(ri)==LOW)
  {
       Serial.println("Ring");
       while(digitalRead(ri)==LOW);
       Serial2.println("at+cmgf=1");
       delay(200);
       Serial2.println("at+cmgs=\"01004771389d\"");
       delay(200);
       Serial2.print(" LAT= ");
       for(int j=13;j<24;j++)
       Serial2.write(gps[j]);
       Serial2.println();
       Serial2.print(" LONG= ");
       for(int j=25;j<37;j++)
       Serial2.write(gps[j]);
       Serial2.println();
       Serial2.write(26);  //CTRL+Z
       Serial2.write(26);
       delay(1000);
   
  }
  
  
  
}
