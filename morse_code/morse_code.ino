// Morse code dictionary
const int dotDuration = 200;    // duration of a dot
const int dashDuration = dotDuration * 3;  // duration of a dash
const int symbolPause = dotDuration;   // pause between dots and dashes in a character
const int letterPause = dotDuration * 3;  // pause between letters
const int wordPause = dotDuration * 7;   // pause between words

char message[100];  // to hold the user message

// Morse code mappings
char morse[][5] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
  "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void blinkMorse(char *message);
void blinkDot();
void blinkDash();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while (true) {
    Serial.println("Please input your message:");
    while (Serial.available() == 0) {}  // Wait for user input
    int i = 0;
    while (Serial.available() > 0) {
      char c = Serial.read();
      if (c == '\n' || c == '\r') break;
      message[i++] = c;
    }
    message[i] = '\0';  // Null-terminate the string
    
    Serial.println("Your message is being blinked currently:");
    blinkMorse(message);
    
    while (true) {
      Serial.println("Do you want to replay the message? y/n");
      while (Serial.available() == 0) {}  // Wait for user input
      char replay = Serial.read();
      if (replay == 'y' || replay == 'Y') {
        blinkMorse(message);
      } else if (replay == 'n' || replay == 'N') {
        break;
      }
    }

    while (true) {
      Serial.println("Do you want to exit? y/n");
      while (Serial.available() == 0) {}  // Wait for user input
      char exitProgram = Serial.read();
      if (exitProgram == 'y' || exitProgram == 'Y') {
        return;  // Exit the loop, and program stops
      } else if (exitProgram == 'n' || exitProgram == 'N') {
        break;
      }
    }
  }
}

void blinkMorse(char *message) {
  for (int i = 0; message[i] != '\0'; i++) {
    if (message[i] == ' ') {
      delay(wordPause);
    } else {
      char c = toupper(message[i]);
      if (c >= 'A' && c <= 'Z') {
        char *morseCode = morse[c - 'A'];
        for (int j = 0; morseCode[j] != '\0'; j++) {
          if (morseCode[j] == '.') {
            blinkDot();
          } else if (morseCode[j] == '-') {
            blinkDash();
          }
          delay(symbolPause);
        }
        delay(letterPause - symbolPause);  // Adjust for extra symbolPause
      }
    }
  }
}

void blinkDot() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dotDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(dotDuration);
}

void blinkDash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dashDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(dotDuration);
}
