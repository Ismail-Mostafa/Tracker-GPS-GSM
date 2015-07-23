char x;
char gps[50];
int valid=0;
int index=0;
float latit;
float longit;
float y;
void setup()
{
 Serial.begin(9600); 
  Serial1.begin(9600); 
  
}

void loop()
{
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
       //Serial.println("correcet");
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
        
//        latit=(gps[13]-48)*1000;
//        latit=((gps[14]-48)*100)+latit;
//        latit=((gps[15]-48)*10)+latit;
//        latit=((gps[16]-48))+latit;
//        latit=((gps[18]-48)*0.1)+latit;
//        latit=((gps[19]-48)*0.01)+latit;
//        latit=((gps[20]-48)*0.001)+latit;
//        latit=((gps[21]-48)*0.0001)+latit;

//        Serial.println(latit);
        Serial.print(" LONG= ");
       for(int j=25;j<37;j++)
        Serial.write(gps[j]);
        Serial.println();
        
     
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
