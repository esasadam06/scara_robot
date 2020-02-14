#include<Servo.h>
//#include<SD.h>
#define button 8
Servo sag; 
Servo sol; 
Servo kalem;
static int k_durum=0;
static int sol_aci;
static int sag_aci;
//File dosya;
int i=0;
int j=0;
int k=0;
int sol_dizi[]={39,40,42,43,44,46,47,48,50,51,52,54,55,57,58,59,61,62,63,65,66,68,69,70,72,73,75,76,77,79,80,81,81,81,82,82,83,83,84,84,85,86,86,87,88,89,90,90,91,93,94,92,91,89,88,87,85,84,83,81,80,79,77,76,75,74,73,71,70,69,68,67,66,65,64,63,62,61,60,59,58,56,55,54,53,52,51,50,49,48,47,47,46,45,44,43,42,41,41,40,39};
int sag_dizi[]={108,110,111,112,114,115,117,118,119,121,122,123,125,126,128,129,130,132,133,134,136,137,138,140,141,142,144,145,146,147,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,130,129,128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,107,106,105,104,103,101,101,99,97,96,95,96,97,98,99,100,100,101,102,103,103,104,104,105,106,106,107,107,107,108,108};
char gecici[3];
void setup() {
  delay(2000);
   pinMode(button,INPUT);
   sol.attach(5);
   sag.attach(6);
   kalem.attach(7);
   Serial.begin(9600);
   sag.write(108);
   sol.write(39);
   delay(2000);
   /*while(!Serial){
    ;
   }
   Serial.print("SD Card Başlatılıyor.");
   pinMode(10,INPUT);
   if(!SD.begin(4)){
    Serial.println("SD kartı kontrol et");
    return;
   }
   Serial.println("SD Kart Algılandı.");
   dosya = SD.open("kare.txt",FILE_READ);
   if(dosya){
    Serial.println("Dosya açıldı.");
    while(i<dosya.size()){
      char temp;
      bool flag=0;
      dosya.seek(i);
      temp=dosya.peek();
      if(temp>47||temp<58){
        if(flag==0){
          sol_dizi[j]=temp;
          j++;
        }else{
          sag_dizi[k]=temp;
          k++;
        }
      }else{
        if(flag==0){
          flag=1;
        }else{
          flag=0;
        }
      }
      
      i++;
    }
   }
   else{
    Serial.println("Dosya açılamadı.";
   }*/
}
void loop() {
  if(digitalRead(button)==1){
  delay(100);
  sag.write(sag_dizi[0]);
  sol.write(sol_dizi[0]);
  delay(5000);
  b_noktasi(sol_dizi[0],sag_dizi[0]);
  delay(5000);
  
    yaz(sol_dizi,sag_dizi);
    k_kaldir();
  delay(3000);
  }
}

void b_noktasi(int x,int y){
  k_kaldir();
  sol.write(x);
  sag.write(y);
  sol_aci=x;
  sag_aci=y;
  delay(100);
  k_indir();
}
void k_kaldir(){
  kalem.write(0);
}
void k_indir(){
  kalem.write(90);
}
void yaz(int x[], int y[]){
  for(int k=0;k<101;k++){
  while(x[k]!=sol_aci || y[k]!=sag_aci){
    if(sag_aci>y[k]){
      sag_aci--;
      sag.write(sag_aci);
      //delay(200);
    }if(sag_aci<y[k]){
      sag_aci++;
      sag.write(sag_aci);
      //delay(200);
    }
    if(sol_aci>x[k]){
      sol_aci--;
      sol.write(sol_aci);
      //delay(200);
    }if(sol_aci<x[k]){
      sol_aci++;
      sol.write(sol_aci);
      //delay(200);
    }
    //Serial.println(sol_aci);
    delay(100);
  }
  }
}
