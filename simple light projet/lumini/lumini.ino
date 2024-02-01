int led=12;
int buton=7;
int state;
void setup() {
pinMode(led, OUTPUT);
pinMode(buton, INPUT);
}
void loop() {
  state=digitalRead(buton);
  if(state){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
}
