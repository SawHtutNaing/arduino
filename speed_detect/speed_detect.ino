
// Declaration of trigger and echo pins

int trigPin = 5;

int echoPin = 6;

 

// declaration of variables going to be used for the program

int distance1 = 0;

int distance2 = 0;

int measured_speed = 0;

long duration = 0;

int distance = 0;
const int MAX_DISTANCE = 30 ;
 

void setup()

{

    // Setting trigger pin as OUTPUT

    pinMode(trigPin, OUTPUT);

 

    // Setting echoPin as INPUT

    pinMode(echoPin, INPUT);

 

    // Starts the serial communication at baud rate 9600

    Serial.begin(9600); 

}

 

void loop()

{

    // Measuring distance 1

    distance1 = ultrasonicRead(); // calls ultrasoninicRead()

    delay(1000);                  // gives delay of 1 second

    distance2 = ultrasonicRead(); // calls ultrasoninicRead() function below

 

    // Formula to calculate speed from distance1 and distance2

    // We are dividing it by 1, since the time interval between the two distance measurement is 1000 ms or 1 second

    if (distance1 <= MAX_DISTANCE && distance2 <= MAX_DISTANCE) {
      measured_speed = abs(distance2 - distance1) / 1.0;

 

    // Displaying the speed value on the serial monitor

    Serial.print("Speed in cm/s :");

    Serial.println(measured_speed);

    }
    
}

 

// Function declaration to measure the distance based on the working principle of ultrasonic sensor

 

float ultrasonicRead()

{

    // Sets the trigPin on HIGH state for 10 micro seconds

    digitalWrite(trigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

 

    // Waits for the amount of time echoPin remains high and records the duration of the same

    duration = pulseIn(echoPin, HIGH);

    // Calculates the distance based on the speed of sound in ambient air 

    // and divide it by two since the sound traveled twice - once to the object and then back

    distance = duration * 0.034 / 2;

 

    // returning measured distance

    return distance;

}
