#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
}
int ms=1500;
   unsigned long c=0;
   double angle=0;
   unsigned long start, finished, elapsed;

void loop() {
  // put your main code here, to run repeatedly:
  
   //Read QPD voltages
  float sensorValue[] = {0 , 0, 0, 0};
  float voltage[]={0 , 0, 0, 0};
  sensorValue[0] = analogRead(A1);
  sensorValue[1] = analogRead(A2);
  sensorValue[2] = analogRead(A3);
  sensorValue[3] = analogRead(A4);
  for(int i = 0 ; i<4 ; i++){
    voltage[i] = sensorValue[i] * (5.0/1023.0);
    
    Serial.print(i+1);
    Serial.print(" == ");
    Serial.print(voltage[i]);
    Serial.print("\n");  
    
  } 
   double x= 100*(((voltage[2]+voltage[3])-(voltage[1]+voltage[4]))/(voltage[1]+voltage[2]+voltage[3]+voltage[4]));
   double y = 100*(((voltage[1]+voltage[2])-(voltage[3]+voltage[4]))/(voltage[1]+voltage[2]+voltage[3]+voltage[4]));
   double z = sqrt((x*x)+(y*y)) ;
   int AirAngle = 0;

   //Look up table
    // For positive AirAngle values
    
    if(y>33){
    
    if (z>48.6 && z<49.4){
     AirAngle=90 ;  }
     if (z>49.4 && z<50.2){
     AirAngle=89 ;  }
     if (z>50.2 && z<50.7){
     AirAngle=88 ;  }
     if (z>50.7 && z<51){
     AirAngle=87 ;  }
     if (z>51 && z<51.6){
     AirAngle=86 ;  }
     if (z>51.6 && z<52.1){
     AirAngle=85 ;  }
     if (z>52.1 && z<52.5){
     AirAngle=84 ;  }
     if (z>52.5 && z<53.15){
     AirAngle=83 ;  }
     if (z>53.15 && z<53.75){
     AirAngle=82 ;  }
     if (z>53.75 && z<54.3){
     AirAngle=81 ;  }
     if (z>54.3 && z<55){
     AirAngle=80 ;  }
     if (z>55 && z<55.6){
     AirAngle=79 ;  }
     if (z>55.6 && z<56.1){
     AirAngle=78 ;  }
     if (z>56.1 && z<56.7){
     AirAngle=77 ;  }
     if (z>56.7 && z<57.5){
     AirAngle=76 ;  }
     if (z>57.5 && z<58.4){
     AirAngle=75 ;  }
     if (z>58.4  && z<59){
     AirAngle=74 ;  }
     if (z>59 && z<59.9){
     AirAngle=73 ;  }
     if (z>59.9 && z<60.9){
     AirAngle=72 ;  }
     if (z>60.9 && z<62){
     AirAngle=71 ;  }
     if (z>62 && z<63.2){
     AirAngle=70 ;  }
     if (z>63.2 && z<64.5){
     AirAngle=69 ;  }
     if (z>64.5 && z<66){
     AirAngle=68 ;  }
     if (z>66 && z<68){
     AirAngle=67 ;  }
     if (z>68 && z<70.8){
     AirAngle=66 ;  }
     if (z>70.8 && z<73){
     AirAngle=65 ;  }
     if (z>73 && z<77){
     AirAngle=64 ;  }
     if (z>77 && z<83.5){
     AirAngle=63 ;  }
     if (z>83.5 && z<90){
     AirAngle=62 ;  }
     if (z>90 && z<95){
     AirAngle=61 ;  }
     if (z>95 && z<98.2){
     AirAngle=60 ;  }
     if (z>98.2 && z<99){
     AirAngle=59 ;  }
     
     
     }

 // For negative AirAngle values
     if (y<33) {
     
      if (z>48.4 && z<49){
     AirAngle=-85 ;  }
      if (z>49 && z<49.6){
     AirAngle=-81 ;  }
      if (z>49.6 && z<50.25){
     AirAngle=-80 ;  }
      if (z>50.25 && z<50.8){
     AirAngle=-79 ;  }
      if (z>50.8 && z<51.7){
     AirAngle=-78 ;  }
      if (z>51.7 && z<52.7){
     AirAngle=-77 ;  }
      if (z>52.7 && z<53.25){
     AirAngle=-76 ;  }
      if (z>53.25 && z<54){
     AirAngle=-75 ;  }
      if (z>54 && z<55.6){
     AirAngle=-74 ;  }
      if (z>55.6 && z<57.5){
     AirAngle=-73 ;  }
      if (z>57.5 && z<60){
     AirAngle=-72 ;  }
      if (z>60 && z<63){
     AirAngle=-71 ;  }
      if (z>63 && z<67.7){
     AirAngle=-70 ;  }
      if (z>67.7 && z<71){
     AirAngle=-69 ;  }
      if (z>71 && z<78){
     AirAngle=-68 ;  }
      if (z>78 && z<85){
     AirAngle=-67 ;  }
      if (z>85 && z<98){
     AirAngle=-66 ;  }
      if (z>98 && z<114){
     AirAngle=-65 ;  }
      if (z>114 && z<126){
     AirAngle=-64 ;  }
      if (z>126 && z<130.8){
     AirAngle=-63 ;  }
     if (z>130.8 && z<131){
     AirAngle=-62 ;  }
     
     }
    Serial.print("X axis=");
    Serial.println(x);
    Serial.print("Y axis=");
    Serial.println(y);
    Serial.print("Sqrt=");
    Serial.println(z);
    Serial.print("Air angle=");
    Serial.println(AirAngle);
    Serial.println(" ");
      
     String airAngleStr ;
     if(AirAngle>0){
      airAngleStr = "+" + (String) AirAngle;
      }else {
        airAngleStr = "-" + (String) abs(AirAngle);
        }
        
        //When a light detected
        if (voltage[0]>0.2 || voltage[1]>0.2 || voltage[2]>0.2 || voltage[3]>0.2 ){
          start=millis(); //The time that light detected
           lcd.setCursor(0, 0);
            lcd.print("Light detected! ");
            lcd.setCursor(0, 1);
            lcd.print(airAngleStr);
            lcd.setCursor(4, 1);
            lcd.print("             ");
           }
        //When there is no light detected  
        if (voltage[0]<0.2 && voltage[1]<0.2 && voltage[2]<0.2 && voltage[3]<0.2  ) {
          finished=millis(); //The time value that lighth off
           elapsed=finished-start; //Modulation speed (The time of the light on and off)
           if(elapsed>2000) {
          lcd.setCursor(0, 0);
          lcd.print("    No light    ");
          lcd.setCursor(0, 1);
          lcd.print("    detected    ");
          }
         
          }    
  
}

