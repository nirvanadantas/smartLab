
/*####################   RELE   ####################*/

int pinorele = 2;


void setup() {
  pinMode(pinorele, OUTPUT);
}

void loop() {
  digitalWrite(pinorele,  HIGH);
  delay(5000);
  
  digitalWrite(pinorele,  LOW);
  delay(5000);
  

}
