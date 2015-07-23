char x;
char gps[40];
int valid=0;
int index=0;
void setup()
{
 Serial.begin(9600); 
  
}

void loop()
{
  if(Serial.available())
  {
    x=Serial.read();
    if(x=='$')   //start GPS header packet
    valid=1;
    else if(x=='G')
     valid++; 
     else if(x=='P')
     valid=3;
     else if(x=='A' && valid==5)
     {
       valid=6;
       Serial.println("correcet");
    }
     else{
     if(valid<6) 
     valid=0;}
     
     if(valid==6)
     {
       
      gps[index]=x;
      index++; 
     }
     
     if(valid==6&&index>10)
     {
        Serial.write(gps[4]);
        Serial.write(gps[5]);
        valid=0;
        index=0;
     }
     
//     Serial.print(valid);
//     if(valid==6)
//     {
//       Serial.println("correcet");
//     }
    
    
  }
  
  
  
}
