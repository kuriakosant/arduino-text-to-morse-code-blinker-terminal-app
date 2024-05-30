# Arduino Morse Code Converter

## Overview

This project is an Arduino-based application that converts text input from a user into Morse code and blinks the corresponding Morse code using the built-in LED on an Arduino Uno. The program allows users to input a message, which is then displayed as a series of LED blinks following the Morse code rules. After the message is blinked, the user can choose to replay the message or input a new one. The application runs continuously until the user decides to exit.

## Features

-   **Text-to-Morse Conversion**: Converts user input into Morse code.
-   **LED Blinking**: Blinks the Morse code using the Arduino's built-in LED.
-   **Interactive Terminal**: Allows the user to input a message, replay it, or enter a new one.
-   **Continuous Operation**: The program loops until the user decides to exit.

## Technologies Used

-   **Arduino Uno**: Microcontroller used to run the program and control the LED.
-   **C++**: Programming language used to write the Arduino sketch.
-   **Visual Studio Code**: Code editor used for development, with the Arduino extension for easy integration.
-   **Git & GitHub**: Version control system used to manage the project and share it on GitHub.

## How It Works

1.  The program prompts the user to input a message via the Serial Monitor.
2.  The message is converted to Morse code, with dots and dashes represented by short and long LED blinks.
3.  After the message is displayed, the user can choose to replay the message or input a new one.
4.  The program continues to run until the user opts to exit.

## Getting Started

### Requirements

-   Arduino Uno
-   Arduino IDE or Visual Studio Code with the Arduino extension
-   USB cable to connect Arduino to your computer

### Installation

1.  Clone the repository from GitHub.
 
    `git clone https://github.com/kuriakosant/arduino-text-to-morse-code-blinker-terminal-app` 
    
2.  Open the project in Visual Studio Code or the Arduino IDE.
3.  Upload the `morse_code.ino` file to your Arduino Uno.

### Usage

1.  Open the Serial Monitor in the Arduino IDE or Visual Studio Code.
2.  Follow the prompts to input your message and control the application.

## License

This project is open-source and available under the MIT License.

