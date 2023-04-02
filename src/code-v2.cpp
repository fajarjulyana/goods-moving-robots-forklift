/*
kode lengkap untuk robot pemindah barang dari titik A ke titik B dan sebaliknya dengan menggunakan Arduino, motor DC, dan servo forklift, serta sensor warna untuk mendeteksi barang yang diangkut.

*/

#include <Servo.h>

#include <TCS3200.h>

// definisikan pin untuk motor DC

#define MOTOR_A_EN 10

#define MOTOR_A_IN1 9

#define MOTOR_A_IN2 8

#define MOTOR_B_EN 5

#define MOTOR_B_IN1 7

#define MOTOR_B_IN2 6

// definisikan pin untuk servo forklift

#define FORKLIFT_PIN 3

// definisikan pin untuk output sensor warna

#define S0 2

#define S1 3

#define S2 4

#define S3 5

#define OUT 6

// definisikan variabel

int speed = 200; // kecepatan motor DC

int red_threshold = 100; // threshold warna merah untuk deteksi barang

int green_threshold = 100; // threshold warna hijau untuk deteksi barang

int blue_threshold = 100; // threshold warna biru untuk deteksi barang

// buat objek motor DC

class Motor {

  private:

    int enable_pin;

    int in1_pin;

    int in2_pin;

    

  public:

    Motor(int en, int in1, int in2) {

      enable_pin = en;

      in1_pin = in1;

      in2_pin = in2;

      

      pinMode(enable_pin, OUTPUT);

      pinMode(in1_pin, OUTPUT);

      pinMode(in2_pin, OUTPUT);

    }

    

    void forward() {

      digitalWrite(in1_pin, HIGH);

      digitalWrite(in2_pin, LOW);

      analogWrite(enable_pin, speed);

    }

    

    void reverse() {

      digitalWrite(in1_pin, LOW);

      digitalWrite(in2_pin, HIGH);

      analogWrite(enable_pin, speed);

    }

    

    void stop() {

      digitalWrite(in1_pin, LOW);

      digitalWrite(in2_pin, LOW);

      analogWrite(enable_pin, 0);

    }

};

Motor motor_A(MOTOR_A_EN, MOTOR_A_IN1, MOTOR_A_IN2);

Motor motor_B(MOTOR_B_EN, MOTOR_B_IN1, MOTOR_B_IN2);

// buat objek servo forklift

Servo forklift;

// buat objek sensor warna

TCS3200 tcs3200(S0, S1, S2, S3, OUT);

void setup() {

  // set pin untuk motor DC dan servo forklift ke kondisi awal

  motor_A.stop();

  motor_B.stop();

  forklift.attach(FORKLIFT_PIN);

  forklift.write(0);

  

  // set frekuensi pengambilan data sensor warna

  tcs3200.setFrequency(TCS3200::FREQUENCY_2KHZ);

  

  // mulai serial communication

  Serial.begin(9600);

}

void loop() {

  // baca data dari sensor warna

  int red = tcs3200.readRed();

  int green = tcs3200.readGreen();

  int blue = tcs3200.readBlue();

  // tampilkan data ke serial monitor

  Serial.print("Red: ");

  Serial.print(red);

  Serial.print(" Green: ");

  Serial.print(green);

  Serial.print(" Blue: ");

  Serial.println(blue);

  // cek apakah ada barang yang diangkut

  if (red > red_threshold && green > green_threshold && blue > blue_threshold

