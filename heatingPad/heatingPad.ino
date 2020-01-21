int temperaturePin = 0;
int heatingPins[] = {9, 10};
int alertPin = 12;

const int SECOND_TO_MILLIS = 1000;
const int IDEAL_TEMP_IN_CELSIUS = 25;
const int MAX_TEMPERATURE_VOLTAGE_READ = 1024;
const double OFFSET = 0.5;
const int DEGREES = 100;

bool isHeatingOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(alertPin, OUTPUT);
  for (int i = 0; i < sizeof(heatingPins); i++) {
    pinMode(heatingPins[i], OUTPUT);
  }
}

void loop() {
  float temperature = getTemperature(temperaturePin);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  if (temperature >= IDEAL_TEMP_IN_CELSIUS) {
    turnHeatOff(heatingPins);
    alert(alertPin);
  } else if (!isHeatingOn) {
    turnHeatOn(heatingPins);
  }
  delay(1 * SECOND_TO_MILLIS);
}

float getTemperature(int pin) {
  double voltage = (double)analogRead(pin);
  Serial.print("Voltage ");
  Serial.println(voltage);
  double temp = voltage / MAX_TEMPERATURE_VOLTAGE_READ; //find percentage of input reading
  temp *= 5;                                            //multiply by 5V to get voltage
  temp -= OFFSET;                                       //Subtract the offset 
  return temp * DEGREES;                                //Convert to degrees 
}

void alert(int pin) {
 digitalWrite(pin, HIGH);
 delay(5 * SECOND_TO_MILLIS);
 digitalWrite(pin, LOW);
}

void turnHeatOn(int pins[]) {
  for (int i = 0; i < sizeof(heatingPins); i++) {
    digitalWrite(pins[i], HIGH);
  }
  Serial.print("Turning Heat on ");
  isHeatingOn = true;
  Serial.println(isHeatingOn);
}

void turnHeatOff(int pins[]) {
  for (int i = 0; i < sizeof(heatingPins); i++) {
    digitalWrite(pins[i], LOW);
  }
  Serial.print("Turning Heat off ");
  isHeatingOn = false;
  Serial.println(isHeatingOn);
}
