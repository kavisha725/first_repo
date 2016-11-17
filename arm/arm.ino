
 #include <Servo.h>
#define grabber_release 120
#define grabber_grab 160
#define grabber_back 50
#define  arm_up 150
#define arm_half 100
#define arm_down  80
Servo arm, grabber;
int pos = 0;
void setup()
{
  arm.attach(26);
    grabber.attach(27);
    arm.write(arm_up);
    grabber.write(grabber_grab);

    pick_darth_vadar();
    delay(1000);
    drop_darth_vadar();
    delay(1000);
    pick_clone_block();
    delay(1000);
    drop_clone_block();
}

void loop()
{
 
}


 void pick_clone_block(){
   // Serial2.println("  ");
     //   Serial2.println("Picking Clone Block");
//        travelDirection2 = findTurnDirection(currentPosition,destination);
//        turnTo(travelDirection2);
//        //move_fwORbw_cm(0, 10);
      //  Serial2.println("Turned");
        //Serial2.println("moving forward");
//        knobLeft.write(0);
//         newFowLeft = knobLeft.read();                   
//        FowDist = (newFowLeft/2248.66)*(8*pi);
//        while (FowDist < 8){
//          lineFollow();
//          newFowLeft = knobLeft.read();                   
//          FowDist = (newFowLeft/2248.66)*(8*pi);
//          //Serial2.println(FowDist);
//          }
//          md.setBrakes(400,400);
//        knobLeft.write(0);
       // Serial2.println("done moving forward");
        delay(1000);
        grabber.write(grabber_release);
        delay(500);
        //arm.write(arm_down);
        arm_up_to_down(0);
        delay(500);
        //grabber.write(grabber_grab);
        grab();
        delay(500);
        //arm.write(arm_up);
        arm_down_to_up(0);
        delay(1000);
      //  move_fwORbw_cm(1, 8);
       // Serial2.println("Picked Clone Block");
        //Serial2.println("  ");
    }
void drop_clone_block(){
    //Serial2.println("  ");
      //  Serial2.println("Dropping Clone Block");
//        turnTo(1);
//        //move_fwORbw_cm(0, 6);
//        delay(1000);
        //arm.write(arm_down);
        arm_up_to_down(0);
        delay(500);
        //grabber.write(grabber_release);
        releas();
        delay(500);
        //grabber.write(grabber_grab);
        arm.write(arm_up);
        delay(500);
        //move_fwORbw_cm(1, 6);
        //Serial2.println("Dropped Clone Block");
        //Serial2.println("  ");
    }

void pick_darth_vadar(){
  //Serial2.println("  ");
    //     Serial2.println("Picking Darth Vadar");
//        travelDirection2 = findTurnDirection(37,36);
//        turnTo(travelDirection2);
        grabber.write(grabber_release);
        delay(500);
        //move_fwORbw_cm(0, 6);

//        knobLeft.write(0);
//         newFowLeft = knobLeft.read();                   
//        FowDist = (newFowLeft/2248.66)*(8*pi);
//        while (FowDist < 6){
//          lineFollow();
//          newFowLeft = knobLeft.read();                   
//          FowDist = (newFowLeft/2248.66)*(8*pi);
//          }
//          md.setBrakes(400,400);
//        knobLeft.write(0);
//        
        delay(500);
        grabber.write(grabber_release);
        arm.write(arm_half);
        delay(500);
       // grabber.write(grabber_grab);
       grab();
        delay(500);
        //arm.write(arm_up);
        arm_down_to_up(1);
        delay(500);
      //  move_fwORbw_cm(1, 6);
        delay(1000);
      //  Serial2.println("Picked Darth Vadar");
        //Serial2.println("  ");
  }
void drop_darth_vadar(){
  //Serial2.println("  ");
    //   Serial2.println("Dropping Darth Vadar");
//       travelDirection2 = findTurnDirection(currentPosition,destination);
//        turnTo(travelDirection2);
//        delay(500);
//        //move_fwORbw_cm(0, 6);
//
//        knobLeft.write(0);
//         newFowLeft = knobLeft.read();                   
//        FowDist = (newFowLeft/2248.66)*(8*pi);
//        while (FowDist < 6){
//          lineFollow();
//          newFowLeft = knobLeft.read();                   
//          FowDist = (newFowLeft/2248.66)*(8*pi);
//          }
//          md.setBrakes(400,400);
//        knobLeft.write(0);
//        
        delay(500);
        
        //arm.write(arm_half);
        arm_up_to_down(1);
        delay(500);
        //grabber.write(grabber_release);
        releas();
        delay(500);
        arm.write(arm_up);
        delay(500);
       // move_fwORbw_cm(1, 10);
        delay(1000);
      //  Serial2.println("Dropped Darth Vadar");
        //Serial2.println("  ");
  }



void grab() {

  for (pos = grabber_release; pos <= grabber_grab; pos += 1)
  {
    grabber.write(pos);
    delay(20);
  }
}

void releas() {

  for (pos = grabber_grab; pos >= grabber_release; pos -= 1)
  {
    grabber.write(pos);
    delay(20);
  }
}

void arm_up_to_down(int depth) {        //depth = 0:full down, else half
  if (depth == 1){
  for (pos = arm_up; pos >= arm_half; pos -= 1){
    arm.write(pos);
    delay(20);
  }
  }
  else if (depth == 0){
    for (pos = arm_up; pos >= arm_down; pos -= 1){
    arm.write(pos);
    delay(20);
    }
    }
}

void arm_down_to_up(int depth) {        //depth = 0:full down, else half
  if (depth == 1){
  for (pos = arm_half; pos <= arm_up; pos += 1){
    arm.write(pos);
    delay(20);
  }
  }
  else if (depth == 0){
    for (pos = arm_down; pos <= arm_up; pos += 1){
    arm.write(pos);
    delay(20);
    }
    }
}


