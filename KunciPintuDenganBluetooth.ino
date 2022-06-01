#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int indikatorledMerah = 6;  // Indikator LED di pin 6
int indikatorledHijau = 7; // Relay doorlock di pin 7
String readString;
const int servokunci = 9;
const int servopintu= 10;
Servo servokun;
Servo servopint;

void setup() {
  Serial.begin(9600);// Sesuaikan dengan Baudrate bluetooth anda
  servopint.attach(servopintu);
  servokun.attach(servokunci);
  lcd.begin(16,2);
  pinMode(indikatorledHijau, OUTPUT); // Set Relay sebagai output
  pinMode(indikatorledMerah, OUTPUT);  // Set Indikator sebagai output
  servokun.write(40);
  servopint.write(15);
  delay (2000);
  servokun.write(90); 
  digitalWrite(indikatorledMerah, HIGH); // Aktifkan Indikator Terkunci
  lcd.setCursor(1,0);
  lcd.print("Pintu Terkunci");
  lcd.setCursor(0,1);
  lcd.print("MASUKAN PASSWORD");
  
}

void loop() {
  while (Serial.available()) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() >0) {
    Serial.println(readString);
    if (readString == "2131") // Jika hasil Keypad benar
    {
      servokun.write(40);
      lcd.clear();
      delay(100);
      lcd.setCursor(1,0);
      lcd.print("AKSES DITERIMA");
      lcd.setCursor(1,1);
      lcd.print("loading");
      delay (200);
      lcd.setCursor(8,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(9,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(10,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(11,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(12,1);
      lcd.print(".");
      delay (300);
      lcd.setCursor(13,1);
      lcd.print(".");
      delay (500);
      lcd.setCursor(14,1);
      lcd.print(".");
      delay (1000);
     
      
      servopint.write(170);
      lcd.clear();
      delay(100);
      lcd.setCursor(0,0);
      lcd.print("Untuk mengunci!");
      lcd.setCursor(0,1);
      lcd.print("TEKAN ANGKA 1");
      digitalWrite(indikatorledHijau, HIGH); // Aktifkan relay selama 15 detik
      digitalWrite(indikatorledMerah, LOW);   // Aktifkan indikator Terbuka  
      readString="";
      
    }
    else if (readString  == "1")     {
      servopint.write (15);
      lcd.clear();
      delay (100);
      lcd.setCursor(1,0);
      lcd.print("AKSES DITERIMA");
     lcd.setCursor(1,1);
      lcd.print("loading");
      delay (200);
      lcd.setCursor(8,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(9,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(10,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(11,1);
      lcd.print(".");
      delay (200);
      lcd.setCursor(12,1);
      lcd.print(".");
      delay (300);
      lcd.setCursor(13,1);
      lcd.print(".");
      delay (500);
      lcd.setCursor(14,1);
      lcd.print(".");
      delay (1000);
     
     
      servokun.write(90);
      lcd.setCursor(15,1);
      lcd.print(".");
      lcd.setCursor(1,0);
      lcd.print("Pintu Terkunci");
      lcd.setCursor(0,1);
      lcd.print("MASUKKAN PASWORD");
      digitalWrite(indikatorledHijau, LOW); // Aktifkan relay selama 15 detik
      digitalWrite(indikatorledMerah, HIGH);   // Aktifkan indikator Terbuka
      readString="";
     }
     else {
       lcd.clear();
      delay (100);
      lcd.setCursor(1,0);
      lcd.print("AKSES DITOLAK");
      lcd.setCursor(0,1);
      lcd.print("MASUKKAN PASWORD");
     readString="";
     }
       
  }
  }
  


   
