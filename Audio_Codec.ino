#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

#define SD_ChipSelectPin 10  

TMRpcm audio;   

void setup() {
  
  audio.speakerPin = 4; 

  Serial.begin(115200);
  
  if (!SD.begin(SD_ChipSelectPin)) {  
    Serial.println("SD Fail");
    return;
  }else{
    Serial.println("SD OK"); 
  }
  audio.CSPin = SD_ChipSelectPin;
}


void loop() {
    if(Serial.available()){                          
      char c = Serial.read();
      Serial.println(c);
      switch(c){
        case 'r': audio.startRecording("test.wav",16000,A0); break;    
        case 'R': audio.startRecording("test.wav",16000,A0,1); break;  
        case 't': audio.startRecording("test.wav",16000,A0,2); break;  
        case 's': audio.stopRecording("test.wav"); break;                  
        case 'p': audio.play("test.wav"); break;                     
        case '=': audio.volume(1); break;          
        case '-': audio.volume(0); break;  
        case 'S': audio.stopPlayback(); break; 
      }
    }
}
