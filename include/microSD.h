#include "SdFat.h"
#include <SPI.h>

#define SD_CSPin  10

SdFat SD;
SdFile recording_file;

File myFile;

#define FILE_NAME "HM_"
#define error(msg) SD.errorHalt(F(msg))

const uint8_t   NAME_SIZE = sizeof(FILE_NAME) - 1;
char    filename[] = FILE_NAME "00.txt";

void sd_init(){
  if (!SD.begin(SD_CSPin, SD_SCK_MHZ(50)))  SD.initErrorHalt();

  // if(NAME_SIZE > 6)  error("BASE_NAME too long");

  // while (SD.exists(filename)) {
  //   if(filename[NAME_SIZE + 1] != '9') filename[NAME_SIZE + 1]++;
  //   else if(filename[NAME_SIZE] != '9') {
  //     filename[NAME_SIZE + 1] = '0';
  //     filename[NAME_SIZE]++;
  //   } else  error("Can't create file name");
  // }
  // if (!recording_file.open(filename, O_WRONLY | O_CREAT | O_EXCL)) {
  //   error("file.open");
  // }
}

void sd_read(){  
  myFile = SD.open("HM_01.txt");
  if (myFile) {
    Serial.println("test.txt:");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } 

}

void sd_write(uint16_t input_write){
  // file = sd.open(filename, FILE_WRITE);
  if (recording_file) recording_file.println(input_write);
}

void sd_stop(){  
    recording_file.close(); 
}

void sd_test(){
  if (recording_file) {
    Serial.println("SD CARD WRITING");
    recording_file.println("sd card connected");
    recording_file.close();
    // recording_file.println(analogRead(0));
  }
  else {
    Serial.println("done");
  }
}



//https://www.e-tinkers.com/2021/05/the-simplest-button-debounce-solution/