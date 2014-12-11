
/*####################   RELE   ####################*/

int pinorele = 2;
char c;

void setup() {
  pinMode(pinorele, OUTPUT);
  Serial.begin(9600);
  digitalWrite(pinorele, LOW);
}

void loop() {
  while(Serial.available() > 0){
    c = Serial.read();
    if (c=='1')  digitalWrite(pinorele,  HIGH);
  
    if(c=='0')  digitalWrite(pinorele,  LOW);
    Serial.println(c);
  }
  

}
