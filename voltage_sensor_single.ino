int voltagePin1 = A0;
int voltagePin2 = A1;

float vout1 = 0.0;
float vout2 = 0.0;

float vin1 = 0.0;
float vin2 = 0.0;

int value1 = 0;
int value2 = 0;

float R1 = 29950.0; // The value of Resistor R1 from the Voltage Sensor Device
float R2 = 7480.0; // The value of Resistor R2 from the Voltage Sensor Device

void setup()
{
  pinMode(voltagePin1, INPUT);
  pinMode(voltagePin2, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //For Battery_1
  value1 = analogRead(voltagePin1);
  vout1 = (value1 * 5.0) / 1024.0;
  vin1 = vout1 / (R2 / (R1 + R2));

  //For Battery_2
  value2 = analogRead(voltagePin2);
  vout2 = (value2 * 5.0) / 1024.0;
  vin2 = vout2 / (R2 / (R1 + R2));

  //Serial.print("Battery_1 V= ");
  Serial.println(vin1);
  //Serial.print("Battery_2 V= ");
  //Serial.println(vin2);
  delay(1000);
}
