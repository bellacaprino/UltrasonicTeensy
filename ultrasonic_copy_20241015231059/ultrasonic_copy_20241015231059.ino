
const int trigPin = 9;
const int echoPin = 10;
const int potPin = A0;
float duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(15, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);    
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  if(digitalRead(15) == HIGH) {
    Serial.print("Button: ");
    Serial.println ("0");
    } else {
      Serial.print("Button: ");
      Serial.println("1");
      delay(50);
      }

  int potValue = analogRead(potPin);

  Serial.print("Pot: ");
  Serial.println(potValue);

}
