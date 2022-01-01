#define M5STACK_MPU6886
#include <M5Stack.h>

#include "uart_frame.h"
//#define M5STACK_MPU6886
int m=0;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

typedef struct _JpegFrame_t {
  uint8_t *buf;
  uint32_t size;
} JpegFrame_t;


static QueueHandle_t jpeg_fream_queue = NULL;

void frame_recv_callback(int cmd, const uint8_t*buf, int len) {
  JpegFrame_t frame;
  frame.buf = (uint8_t *)malloc(sizeof(uint8_t) * len);
  memcpy(frame.buf, buf, len);
  frame.size = len;
  
  if (xQueueSend(jpeg_fream_queue, &frame, 0) != pdTRUE) {
    free(frame.buf);
  }
}

// the setup routine runs once when M5Stack starts up
void setup(){

  
  pinMode(22,INPUT);
 // k=digitalRead(22);
  M5.begin();


 M5.Power.begin();

    M5.IMU.Init();

    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setTextColor(GREEN, BLACK);
    M5.Lcd.setTextSize(2);
  
  // Initialize the M5Stack object
  M5.begin(true, false, false, false);
  Serial.begin(1500000);
  uart_frame_init(36, 26, 1500000);
  jpeg_fream_queue = xQueueCreate(2, sizeof(JpegFrame_t));
}

// the loop routine runs over and over again forever

void loop() {
 M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
 //M5.Lcd.setCursor(0, 20);
   // M5.Lcd.printf("%6.2f  %6.2f  %6.2f      ", gyroX, gyroY, gyroZ);
    //M5.Lcd.setCursor(220, 42);
   // M5.Lcd.print(" o/s");
    //Serial.printf(" %5.2f   %5.2f   %5.2f   ", gyroX, gyroY, gyroZ);
    //Serial.printf("\n");
//delay(10);


  
int n=digitalRead(22);
  //if(digitalRead(22)==1)
 
  
  JpegFrame_t frame;
  int time_last = 0;
  time_last = millis();
  xQueueReceive(jpeg_fream_queue, &frame, portMAX_DELAY);
 
  if(n==0||gyroX>100||gyroY>100||gyroZ>100){
    delay(10);
if(m==0){
  m=1;
   M5.Lcd.drawJpg(frame.buf, frame.size, 0, 0);
    delay(20);
  }
   else if(m==1) {
    m=0;
   //  M5.Lcd.drawJpg(frame.buf, frame.size, 0, 0);
     delay(20);
    }
 // M5.Lcd.drawJpg(frame.buf, frame.size, 0, 0);
  }
  Serial.printf("--%ld--size--%d--\r\n", millis() - time_last, frame.size);
  free(frame.buf);





  
}
