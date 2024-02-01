int senzor=0;
int led=7;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(senzor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lumina=analogRead(senzor);
  if(lumina<100){
    digitalWrite(led,HIGH);
  }
  else{
      digitalWrite(led,LOW);
  }
  delay(10);
}
