#include <VarSpeedServo.h> // 2nd Version of Today's Code

VarSpeedServo base; 
VarSpeedServo claw;
VarSpeedServo arm;
VarSpeedServo should;

int i = 0;
int choice;
int part;

void setup() {

  Serial.begin(9600);
  Serial.println("Starting");

  base.attach(5);
  claw.attach(9); 
  arm.attach(10); 
  should.attach(11);
   
  base.write(90,22,true);              
  claw.write(170,22,true);     
  arm.write(90,22,true);
  should.write(90,22,true);         

}


void loop() {

  Serial.println("Choose");
  Serial.println("1 - Pick and Place");
  Serial.println("2 - Manual Mode");
  Serial.println("3 - Home Position"  );
 
  while(Serial.available()==0){
           
  }
  
  choice = Serial.parseInt();
  Serial.println(choice);
  Serial.println();

  if( choice == 1){
    Serial.println("Automatic Pick and Place Mode");
    base.write(175,22,true); // Initial Position         
    claw.write(122,22,true);     
    arm.write(170,22,true);
    should.write(160,22,true);
    delay(100);
    
    claw.write(160,10,true);//Closing the Claw
    delay(1000);
    
    should.write(100,22,true);//Final Position
    base.write(0,22,true);
    arm.write(170,22,true);
    should.write(165,22,true);
    claw.write(122,22,true);
    should.write(100,22,true);         
    delay(10);
    base.write(90,22,true);              
    claw.write(160,22,true);     
    arm.write(90,22,true);
    should.write(95,22,true);               
 
    }
    else if(choice == 2){
      Serial.println("Manual Mode");
      Serial.println("Select");
      Serial.println("0 - Base");
      Serial.println("1 - Shoulder");
      Serial.println("2 - Arm");
      Serial.println("3 - Claw");
      Serial.println("4 to Exit to Home");
      Serial.println();
      
      while(Serial.available()==0){}
      part = Serial.parseInt();
      Serial.println(part);
      delay(1000);
      
      
    while(part<=4){
      
      
      if(part == 0){
        Serial.println("Input the Base Value");
        
        while(Serial.available() == 0){}
        int base_val = Serial.parseInt();
        Serial.println(base_val);
        base.write(base_val,22,true);
        delay(200);
        break;
      }
      else if(part == 1){
        Serial.println("Input the Shoulder Value");
       
        while(Serial.available() == 0){}
        int shoulder_val = Serial.parseInt();
        Serial.println(shoulder_val);
        should.write(shoulder_val,22,true);
        delay(200);
        break;
       }
      else if(part == 2){
        Serial.println("Input the Arm Value");
        
        while(Serial.available() == 0){}
        int arm_val = Serial.parseInt();
        Serial.println(arm_val);
        arm.write(arm_val,22,true);
        delay(200);
        break;
      }
      else if(part == 3){
        Serial.println("Input the Claw Value");
        
        while(Serial.available() == 0){}
        int claw_val = Serial.parseInt();
        Serial.println(claw_val);
        claw.write(claw_val,22,true);
        delay(200);
        break;
      }
      else if(part==4){
        Serial.println("Going Back to Home Position");
        Serial.println();
        base.write(90,22,true);              
        claw.write(170,22,true);     
        arm.write(90,22,true);
        should.write(90,22,true);         

        break;
      }
    }} 
   
  else  {
    
    base.write(90,22,true);              
    claw.write(160,22,true);     
    arm.write(90,22,true);
    should.write(95,22,true);
    Serial.println("At Home Position");
    Serial.println();
    }
     
  }
