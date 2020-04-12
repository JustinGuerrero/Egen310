//Cats Conundrum Microcontroller Code


//**Overview of the Program**//
//The following is arudino code that is constantly listening for a number to be sent to it from the control app.
//Depeing the the number recieved, it will send power to the four servos in order for the car to move.
//Each wheel has its own speed and will vary depeding on the current setting.


//import the servo library
#include <Servo.h>

//variable that represents the latest number received from the control app
int x;

int rfSpeed; //Speed variable for front right servo
int rrSpeed; //Speed variable for back right servo
int lfSpeed; //Speed variable for front left servo
int lrSpeed; //Speed variable for back left servo

int setting; //variable that keeps track of current setting number


//Servo names for each of the 4 servos
Servo servoOne; //Back Motor -- Pin 13 on microcontroller
Servo servoTwo; //Front Motor -- Pin 12 on microcontroller
Servo servoThree; //Front Motor -- Pin 10 on microcontroller
Servo servoFour; //Back Motor -- Pin 11 on microcontroller

void setup() {
  Serial.begin(9600); //Open up serial port 

  //set servo speeds to default speed (full power setting)
  rfSpeed = 1650;
  rrSpeed = 1650;
  lfSpeed = 1350;
  lrSpeed = 1350;

  //set default speed setting to full power mode
  setting = 1;
}

void loop() { //function that will run forever 


  if (Serial.available() > 0) { //as long as a serial port is available, keep reading in messages from control app
    x = Serial.read();

    if (x == '1') { //If a '1' is recieved from the control app, then we will tell servos to move forward
      Serial.println("Moving servo forward");

      //connect the servos
      servoOne.attach(13); 
      servoTwo.attach(12); 
      servoThree.attach(10); 
      servoFour.attach(11); 

      //send power to the servos to move forward
      servoOne.writeMicroseconds(rrSpeed);
      servoTwo.writeMicroseconds(lrSpeed);
      servoThree.writeMicroseconds(lfSpeed);
      servoFour.writeMicroseconds(rfSpeed);


    }
    else if (x == '3') { //If a '3' is recieved from the control app, then we will tell servos to turn to the right
      Serial.println("Turning Right");

      //connect the servos
      servoOne.attach(13);
      servoTwo.attach(12);
      servoThree.attach(10);
      servoFour.attach(11);

      //send power to the servos to turn to the right
      servoOne.writeMicroseconds(rfSpeed);
      servoTwo.writeMicroseconds(rfSpeed);
      servoThree.writeMicroseconds(rfSpeed);
      servoFour.writeMicroseconds(rfSpeed);
    }

    else if (x == '4') { //If a '4' is recieved from the control app, then we will tell servos to turn to the left
      Serial.println("Turning Left");

      //connect the servos
      servoOne.attach(13);
      servoTwo.attach(12);
      servoThree.attach(10);
      servoFour.attach(11);

      //send power to the servos to turn to the left
      servoOne.writeMicroseconds(lfSpeed);
      servoTwo.writeMicroseconds(lfSpeed);
      servoThree.writeMicroseconds(lfSpeed);
      servoFour.writeMicroseconds(lfSpeed);
    }

    else if (x == '0') { //if a '0' is recieved from the control app, then we will tell the servos to move the car backwards
      Serial.println("Moving Servo Backward");

      //connect the servos
      servoOne.attach(13);
      servoTwo.attach(12);
      servoThree.attach(10);
      servoFour.attach(11);

      //send power to the servos to turn move car backwards
      servoOne.writeMicroseconds(lrSpeed);
      servoTwo.writeMicroseconds(rrSpeed);
      servoThree.writeMicroseconds(rfSpeed);
      servoFour.writeMicroseconds(lfSpeed);

    }

    else if (x == '2') { //if a '2' is recieved from the control app, then we will cut all power to the servos to make the car stop moving
      Serial.println("Not Moving");

      //disconnect all the servos
      servoTwo.detach();
      servoOne.detach();
      servoThree.detach();
      servoFour.detach();
    }
    
    else if (x == '5') { //if a '5' is recieved from the control app, then we will change the speed variables for the servos

      //the modulus (%) operator was used to cycle through the different speed settings
    
      //full speed  setting
      if (setting % 3 == 0) {
        //change each servo's speed
        lrSpeed = 1350;
        lfSpeed = 1350;
        rrSpeed = 1650;
        rfSpeed = 1650;
      }
      
      //slower speed  setting
      else if (setting % 3 == 1) {
        //change each servo's speed
        lrSpeed = 1430;
        lfSpeed = 1430;
        rrSpeed = 1570;
        rfSpeed = 1570;
      }

      //hill climber setting
      else if (setting % 3 == 2) {
        //change each servo's speed 
        lrSpeed = 1430;
        lfSpeed = 1350;
        rrSpeed = 1570;
        rfSpeed = 1650;
      }

      setting ++; //increase the setting variable to update which setting we are currently on

      if (setting == 201) { //if the setting integer gets too high, reset it back to 0 to prevent integer overflow
        setting = 0;
      }
    }
  }
}
