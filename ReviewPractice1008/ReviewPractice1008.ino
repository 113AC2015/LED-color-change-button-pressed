const int buttonPin = 2;
const int RledPin = 3; 
const int GledPin = 4; 
const int BledPin = 5; 

// Button and debounce
int buttonState = HIGH;        
int lastButtonState = HIGH;    
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; 

bool reverseOrder = false; 
int colorIndex = 0; // 0 = red, 1 = green, 2 = blue, 3 = white

unsigned long previousMillis = 0;
const long interval = 1000; // change color every second

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Button connected to GND
  Serial.begin(9600);
}

void loop() {
  // --- Button handling with debounce ---
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) { // pressed
        reverseOrder = !reverseOrder;
        Serial.println(reverseOrder ? "Reversed Order" : "Normal Order");
      }
    }
  }

  lastButtonState = reading;

  // --- Change color every second ---
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (!reverseOrder) {
      colorIndex++;
      if (colorIndex > 3) colorIndex = 0;
    } else {
      colorIndex--;
      if (colorIndex < 0) colorIndex = 3;
    }

    showColor(colorIndex);
  }
}

void showColor(int index) {
  switch (index) {
    case 0: // Red
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, HIGH);
      Serial.println("RED");
      break;
    case 1: // Green
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, HIGH);
      Serial.println("GREEN");
      break;
    case 2: // Blue
      digitalWrite(RledPin, HIGH);
      digitalWrite(GledPin, HIGH);
      digitalWrite(BledPin, LOW);
      Serial.println("BLUE");
      break;
    case 3: // White
      digitalWrite(RledPin, LOW);
      digitalWrite(GledPin, LOW);
      digitalWrite(BledPin, LOW);
      Serial.println("WHITE");
      break;
  }
}







