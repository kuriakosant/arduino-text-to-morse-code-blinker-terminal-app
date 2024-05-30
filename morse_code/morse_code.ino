// Morse code dictionary
const int dotDuration = 500;    // duration of a dot
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
  Serial.println("Welcome to kuriakos.ant arduino-text-to-morse-code-blinker-terminal-app");
  Serial.println("Please input a message for your Arduino to blink in Morse code:");
}

void loop() {
  // Wait for the user to input a message
  if (Serial.available() > 0) {
    int i = 0;
    while (true) {
      while (Serial.available() > 0) {
        char c = Serial.read();
        if (c == '\n' || c == '\r') {
          message[i] = '\0';  // Null-terminate the string
          Serial.print("Your message is \"");
          Serial.print(message);
          Serial.println("\" and is being blinked currently:");
          blinkMorse(message);
          Serial.println("Message has been blinked successfully.");
          break;  // Exit the loop to process the message
        } else {
          if (i < sizeof(message) - 1) {
            message[i++] = c;  // Add the character to the message
          }
        }
      }
      if (message[i] == '\0') {
        break;  // Exit the loop if the message has been processed
      }
    }

    // Prompt the user for another message or to exit
    Serial.println("Do you want to blink another? y/n");
    while (true) {
      while (Serial.available() == 0) {
        // Wait for user input
      }
      char response = Serial.read();
      if (response == 'y' || response == 'Y') {
        Serial.println("Please input a new message for your Arduino to blink in Morse code:");
        break;  // Break to input a new message
      } else if (response == 'n' || response == 'N') {
        Serial.println("Exiting the program. Goodbye!");
        while (true) {}  // Stop the loop and exit the program
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
  delay(symbolPause);
}

void blinkDash() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(dashDuration);
  digitalWrite(LED_BUILTIN, LOW);
  delay(symbolPause);
}
