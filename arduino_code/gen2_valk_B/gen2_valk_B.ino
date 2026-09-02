const int POE = 15;
const int RELAY1 = 10;
int nilai = 0;

void setup() {
  pinMode (POE, INPUT);
  pinMode (RELAY1, OUTPUT);

}

void loop() {
  nilai = digitalRead(POE);

  if (nilai == LOW){
    digitalWrite(RELAY1, HIGH);
  }
  else{
    digitalWrite(RELAY1, LOW);
  }

}
