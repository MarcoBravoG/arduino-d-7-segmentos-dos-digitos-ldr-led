
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 11;  // Analog output pin that the LED is attached to

int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value output to the PWM (analog out)

int valor=0;
const int pins[7] = { 2, 3, 4, 5, 6, 7, 8 }; 

//Declaramos los numeros para el ánodo común
const byte numbersDisplayAnode[10] = {0b1000000,     //0
                            0b1111001,          //1
                            0b0100100,          //2
                            0b0110000,          //3
                            0b0011001,          //4
                            0b0010010,          //5
                            0b0000010,          //6
                            0b1111000,          //7
                            0b0000000,          //8
                            0b0010000};         //9

const int nbrDigits = 2;
//                         digits 1   2
const int digitPins[nbrDigits] = {9,10};

void setup() {
  Serial.begin(9600);
    for(int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
    }

    for(int i = 0; i < nbrDigits; i++) {
    pinMode(digitPins[i], OUTPUT);
    }
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

// Rango 21
  if (sensorValue>926) {
    valor=20;
    }


// Rango 20
  if (sensorValue>901& sensorValue<925 ) {
    valor=19;
    }

// Rango 19
 if (sensorValue>851 & sensorValue<900 ) {
    valor=18;
    }

    // Rango 18
 if (sensorValue>726 & sensorValue<850 ) {
    valor=17;
    }

    // Rango 17
 if (sensorValue>801 & sensorValue<825 ) {
    valor=16;
    }

    
// Rango 16
 if (sensorValue>751 & sensorValue<800 ) {
    valor=15;
    }

// Rango 15
 if (sensorValue>701 & sensorValue<750 ) {
    valor=14;
    }

// Rango 14
 if (sensorValue>651 & sensorValue<700 ) {
    valor=13;
    }

// Rango 13
 if (sensorValue>601 & sensorValue<650 ) {
    valor=12;
    }
// Rango 12
 if (sensorValue>551 & sensorValue<600 ) {
    valor=11;
    }

// Rango 11
 if (sensorValue>501 & sensorValue<550 ) {
    valor=10;
    }

// Rango 10
 if (sensorValue>451 & sensorValue<500 ) {
    valor=9;
    }

// Rango 9
 if (sensorValue>401 & sensorValue<450 ) {
    valor=8;
    }

// Rango 8
 if (sensorValue>351 & sensorValue<400 ) {
    valor=7;
    }


// Rango 7
 if (sensorValue>301 & sensorValue<350 ) {
    valor=6;
    }

// Rango 6
 if (sensorValue>251 & sensorValue<300 ) {
    valor=5;
    }

// Rango 5
 if (sensorValue>201 & sensorValue<250 ) {
    valor=4;
    }

// Rango 4
 if (sensorValue>151 & sensorValue<200 ) {
    valor=3;
    }

// Rango 3
 if (sensorValue>101 & sensorValue<150 ) {
    valor=2;
    }

// Rango 2
 if (sensorValue>51 & sensorValue<100 ) {
    valor=1;
    }

// Rango 1
    if (sensorValue<50) {
    valor=0;
    }


    for(int i = 0; i <  100; i++ ){
    showNumber(valor);  
    //delay(1);
    }
    
}

void showNumber(int number) {
    if(number == 0) {
    showDigit(0, nbrDigits-1);
    } else {
    for(int digit = nbrDigits-1; digit >= 0; digit--) {
        if(number > 0) {
        showDigit(number % 10, digit);
        number = number / 10;
        }
    }
    }
}

void showDigit(int number, int digit) {
    digitalWrite(digitPins[digit], HIGH);
    byte numberBit = numbersDisplayAnode[number];
    for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
    }
    delay(8);
    digitalWrite(digitPins[digit], LOW);
}