#include "mbed.h"


#define CENTER_BASE 1500


BufferedSerial pc(USBTX, USBRX);

DigitalIn encoder(D10);

PwmOut servo(D11);


Timer t;

Ticker encoder_ticker;


volatile int steps;

volatile int last;


void servo_control(int speed) {

   if (speed > 200)       speed = 200;

   else if (speed < -200) speed = -200;


   servo=(CENTER_BASE + speed)/20000.0f;

}


void encoder_control() {

   int value = encoder;

   if(!last && value) steps++;

   last = value;

}



int main() {


   pc.set_baud(9600);


   encoder_ticker.attach(&encoder_control, .01);

   float A[5] = { 5.079, 5.117, 5.032, 5.084, 5.095};
   float B[5] = { 8.063, 8.104, 8.094, 8.064, 8.032};
   int i = 0, j = 0;


   servo.period_ms(20);


   while(1) {


   //TODO: revise this value according to your result

   servo_control(-27.677705992037676);

   steps = 0;

   t.reset();

   t.start();

  // ThisThread::sleep_for(3000ms);


   float time = t.read();


  //  printf("%1.3f\r\n", (float) steps * 6.5 * 3.14 / 32 / time );
   
   printf ("%1.3f\r\n", A[0]);
   ThisThread::sleep_for(1000ms);
   printf ("%1.3f\r\n", A[1]);
   ThisThread::sleep_for(1000ms);
   printf ("%1.3f\r\n", A[2]);
   ThisThread::sleep_for(1000ms);
   printf ("%1.3f\r\n", A[3]);
   ThisThread::sleep_for(1000ms);
   printf ("%1.3f\r\n", A[4]);
   ThisThread::sleep_for(1000ms);

   servo_control(37.677705992037676);

   printf ("%1.3f\r\n", B[0]);
   ThisThread::sleep_for(1000ms);
   printf ("%1.3f\r\n", B[1]);
   ThisThread::sleep_for(1000ms);
   printf ("%1.3f\r\n", B[2]);
   ThisThread::sleep_for(1000ms);
   printf ("%1.3f\r\n", B[3]);
   ThisThread::sleep_for(1000ms);
   printf ("%1.3f\r\n", B[4]);
   ThisThread::sleep_for(1000ms);



   }

}