#define trigPin 11
#define echoPin 10
#define trigPin2 8
#define echoPin2 7

int sensorPin = 0; //analog pin 0

#define buzzer 5
#define LED 4
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);                                                                                                                                                                                                                                                                                                                                                                                                                                          
  
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  The program to function according to the switch

 

// The program to make the buzzer work
 
//===========================================  ULTRASONIC SENSOR 1 ====================================================================  
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 
  Serial.print(distance);
  Serial.println(" cm U1");
  delay(10);

//============================================ ULTRASONIC SENSOR 2 =====================================================================

long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
 
  Serial.print(distance2);
  Serial.println(" cm U2");
  delay(10);




//================================================= INFRARED SENSOR ======================================================
  int val = analogRead(sensorPin);
  //Serial.println(val);


    
  if (val <100 || distance <50 || distance2 < 50) // checking the distance 
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED, HIGH);
  }else
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(LED, LOW);
  }

  
}
