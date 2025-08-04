int micInput = A0;         // Microphone sensor input
int indicatorLED = 13;     // LED indicator pin
int outputRelay = 3;       // Relay control pin
bool toggleState = false;  // Tracks ON/OFF status

void setup() {
  pinMode(micInput, INPUT);
  pinMode(indicatorLED, OUTPUT);
  pinMode(outputRelay, OUTPUT);
  Serial.begin(9600);

  digitalWrite(outputRelay, HIGH);  // Start with relay OFF
}

void loop() {
  int micSignal = digitalRead(micInput);
  Serial.println(micSignal);

  if (micSignal == HIGH) {
    toggleState = !toggleState;  // Flip the state

    digitalWrite(indicatorLED, toggleState ? HIGH : LOW);
    digitalWrite(outputRelay, toggleState ? LOW : HIGH);

    delay(250);  // Debounce delay to prevent multiple triggers
  }
}
