const int LED1 =17;
const int LED2 =18;
const int RELAY1 =19;
const int RELAY2 =21;
const int pinInput =10;
int count = 0;

void setup() {
  Serial.begin(115200);
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (RELAY1, OUTPUT);
  pinMode (RELAY2, OUTPUT);
  pinMode (pinInput, OUTPUT);
}

void loop() {
  
   if(Serial.read() == 's'){
     digitalWrite (pinInput, HIGH);
     digitalWrite (LED1, HIGH);
     digitalWrite (LED2, LOW);
     digitalWrite (RELAY1, HIGH);
     digitalWrite (RELAY2, LOW);
     
   }
   if(Serial.read() == 'j'){
      count++;
     if(count > 5){
       digitalWrite (pinInput, HIGH);
       digitalWrite (LED1, LOW);
       digitalWrite (LED2, HIGH);
       digitalWrite (RELAY1, LOW);
       digitalWrite (RELAY2, HIGH);
       count = 0;
    }
   }
}
