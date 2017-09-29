import ddf.minim.*;
import processing.serial.*;

Minim minim;
AudioPlayer player1;
AudioPlayer player2;

Serial myPort;
int SerialData;

void setup(){
  size(500,500);
  printArray(Serial.list());
  myPort=new Serial(this, Serial.list()[1],9600);
  
  minim = new Minim(this);
  
  player1 = minim.loadFile("1.mp3");
  player2 = minim.loadFile("3.mp3");
}

void draw(){
  while(myPort.available()>0){
    SerialData=myPort.read();
    int myByte = myPort.read();
    println(SerialData);
    if(SerialData ==49){
        player2.pause();  
        player1.play();
        player1.loop(2);
        println("playing1");
    }else if(SerialData==50){
        player1.pause(); 
        player2.play();
        player2.loop(2);
        println("playing2");
    }
  }
}

    
    //println(myByte);