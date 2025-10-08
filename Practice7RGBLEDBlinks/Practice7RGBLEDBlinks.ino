const int buttonPin = 2;
const int RledPin = 3; 
const int GledPin = 4; 
const int BledPin = 5; 

int buttonState = 0; 
int ledState = LOW;
int ledcolor = 0;
bool ButtonPressed = false; 
String currentcolor = "led";
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // You can read the button here and update ledcolor if you want
  buttonState = digitalRead(buttonPin);
  Serial.print("Current Color: ");
  Serial.println(currentcolor);
  if (buttonState == HIGH && !ButtonPressed) {
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
  }
  if (buttonState == LOW && ButtonPressed) {
      ButtonPressed = false;
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    //save the last time you blinked the LED
    previousMillis = currentMillis;
  if (ledState == LOW) {
    ledState = HIGH; 
  } else {
    ledState = LOW; 
    }  
  }

  // RGB LED control
  if (ledcolor == 0) {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  } else if (ledcolor == 1) {
    // RED
    currentcolor="RED";
      if(ledState == LOW) {
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  } else if (ledcolor == 2) {
    // GREEN
    currentcolor="GREEN";
      if(ledState == LOW) {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  } else if (ledcolor == 3) {
    // BLUE
    currentcolor="BLUE";
      if(ledState == LOW) {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  } else if (ledcolor == 4) {
    // YELLOW
    currentcolor="YELLOW";
      if (ledState == LOW) {
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  } else if (ledcolor == 5) {
    // PURPLE
    currentcolor="Purple";
      if (ledState == LOW) {
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  } else if (ledcolor == 6) {
    // CYAN
    currentcolor="Cyan";
      if (ledState == LOW) {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  } else if (ledcolor == 7) {
    currentcolor="WHITE";
      if (ledState == LOW) {
    // WHITE
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }
  }
  else if(ledcolor == 8){
    ledcolor = 0;
  }
}

