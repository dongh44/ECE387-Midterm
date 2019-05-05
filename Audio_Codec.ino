#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

#define SD_ChipSelectPin 10

TMRpcm audio;   

void setup() {
  
  audio.speakerPin = A0; 

  Serial.begin(9600);
  
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
        case 'r': audio.startRecording("MAX9814.wav",16000,A0); break;    //Start recording at a sampling rate of 16 kHz
        case 's': audio.stopRecording("MAX9814.wav"); break;                  //Stop recording
      }
    }
}
