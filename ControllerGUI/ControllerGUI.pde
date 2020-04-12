import controlP5.*; //import ControlP5 library
import processing.serial.*;

Serial port;

ControlP5 cp5; //create ControlP5 object
Boolean Pressed = false;

void setup(){ //Same as setup in arduino
  
  size(800, 800);                          //Window size, (width, height)
  port = new Serial(this, "COM4", 9600);   //Change this to our port
  
  cp5 = new ControlP5(this);
  
  
  
  
  cp5.addButton("Back")  //The button
    .setPosition(305, 405)  //x and y coordinates of button
    .setSize(120, 70)      //(width, height)
  ;     
    cp5.addButton("Forward")  //The button
    .setPosition(305, 205)  //x and y coordinates of button
    .setSize(120, 70)      //(width, height)
  ;     
  cp5.addButton("Left")  //The button
    .setPosition(155, 305)  //x and y coordinates of button
    .setSize(120, 70)      //(width, height)
  ;     
  cp5.addButton("Right")  //The button
    .setPosition(455, 305)  //x and y coordinates of button
    .setSize(120, 70)      //(width, height)
  ;     
  cp5.addButton("Stop")   // the button stop
    .setPosition(455, 505)  // x and y coordinates of button
    .setSize(120,70)
    ;
  cp5.addButton("TURBO BOOST")   // the button stop
    .setPosition(160, 512)  // x and y coordinates of button
    .setSize(200,100)
    ;
    


}






void draw(){  //Same as loop in arduino

  background(10, 0 , 150); //Background colour of window (r, g, b) or (0 to 255)
    
}
void keyPressed(){ //function that is executed when key is pressed
  if(keyCode == UP){
    println("pressed up arrow");
    fill(255, 204, 0);
    rect(300,200,130,80); //highlights the up button
    port.write(13);
  }
  
    else if(keyCode == DOWN){
      println("pressed down arrow");
      fill(255, 204, 0);
      rect(300,400,130,80); //highlights the up button
      port.write(11);
  }
    else if(keyCode == LEFT){
      println("pressed left arrow");
      fill(255, 204, 0);
      rect(150,300,130,80); //highlights the up button
      port.write(12);
  }
    else if(keyCode == RIGHT){
      println("pressed right arrow");
      fill(255, 204, 0);
      rect(450,300,130,80); //highlights the up button
      port.write(10);
  }
    else if(keyCode == 'S'){
      println("pressed STOP");
      fill(255, 204, 0);
      rect(450,500,130,80); //highlights the up button
      //port.write('11');
  }
    else if(keyCode == 'F'){
      println("pressed speed");
      fill(255, 204, 0);
      rect(150,500,220,130); //highlights the up button
      //port.write('11');
  }
}
void keyReleased(){
 if(keyCode == UP){
    println("pressed up arrow");
    fill(255, 204, 0);
    rect(300,200,130,80); //highlights the up button
    port.write('5');
  }
  
    else if(keyCode == DOWN){
      println("pressed down arrow");
      fill(255, 204, 0);
      rect(300,400,130,80); //highlights the up button
      port.write('4');
  }
    else if(keyCode == LEFT){
      println("pressed left arrow");
      fill(255, 204, 0);
      rect(150,300,130,80); //highlights the up button
      port.write('6');
  }
    else if(keyCode == RIGHT){
      println("pressed right arrow");
      fill(255, 204, 0);
      rect(450,300,130,80); //highlights the up button
      port.write('8');
  }
    else if(keyCode == 'S'){
      println("pressed STOP");
      fill(255, 204, 0);
      rect(450,500,130,80); //highlights the up button
     // port.write('10');
  }
    else if(keyCode == 'F'){
      println("pressed speed");
      fill(255, 204, 0);
      rect(150,500,220,130); //highlights the up button
    //  port.write('12');
  }
}
void Button(){
  
  port.write('t');
  
}
