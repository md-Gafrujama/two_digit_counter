# Arduino Two-Digit Counter

This project implements a two-digit counter using an Arduino Uno, two 7-segment displays, and 74HC595 shift registers. The counter increments every second, counting from `00` to `99`.

## Components
- **Arduino Uno**: The microcontroller that controls the display.
- **Two 7-segment Displays (Common Cathode)**: Used to display the counter digits.
- **Two 74HC595 Shift Registers**: Used to expand the number of output pins needed to drive the 7-segment displays.
- **Resistors (220 ohms)**: Current limiting resistors for each segment of the displays.
- **Breadboard and Connecting Wires**: To connect everything.

## Circuit Diagram

1. Connect each segment of the 7-segment displays to the outputs of the shift registers.
2. Connect the pins of the shift registers as follows:
   - **Pin 8 (ST_CP)** -> Arduino Pin `8`
   - **Pin 12 (SH_CP)** -> Arduino Pin `12`
   - **Pin 11 (DS)** -> Arduino Pin `11`
   - Connect all GNDs and VCCs accordingly.
3. Add resistors (220 ohm) in series with each segment of the displays to prevent burning out the LEDs.

## Code Description

The Arduino code uses two `74HC595` shift registers to control the two 7-segment displays. It makes use of the `shiftOut()` function to shift the binary data representing each digit to the registers.

- **digitPattern[]**: An array holding the bit patterns for displaying digits `0-9`.
- **displayNumber()**: This function takes the tens and units digits, shifts the bits corresponding to the correct patterns, and displays them on the 7-segment displays.
- The code counts from `00` to `99`, with a delay of 1 second between increments.

## Setup Instructions

1. **Assemble the Circuit**: Follow the circuit diagram and connect the shift registers, displays, and Arduino Uno accordingly.
2. **Upload Code**: Copy and paste the provided code into the Arduino IDE.
3. **Upload the Sketch**: Connect your Arduino Uno to the computer and upload the sketch.
4. **Power on**: After uploading, the counter will begin incrementing from `00` to `99`.

## How It Works

- The counter starts at `00` and increments by `1` every second.
- The **shift registers** control the segments of the displays. For each digit, a corresponding bit pattern is shifted into the register, which lights up the correct segments.
- The **latch pin** ensures the display is updated simultaneously after all data is shifted into the registers.

## Pin Configuration

- **latchPin**: Arduino Pin 8
- **clockPin**: Arduino Pin 12
- **dataPin**: Arduino Pin 11

### Example Wiring for a Single 7-segment Display (Connected to the Shift Register)

| Shift Register Pin | 7-Segment Segment |
| ------------------ | ----------------- |
| Q0                 | a                 |
| Q1                 | b                 |
| Q2                 | c                 |
| Q3                 | d                 |
| Q4                 | e                 |
| Q5                 | f                 |
| Q6                 | g                 |

## Enhancements
- Add push buttons to increment and reset the counter manually.
- Display a higher range of numbers by adding more digits.

## License


This project is open-source under the MIT License.
teps to run:
Set up the hardware as per the wiring diagram.
Paste the code in Arduino IDE.
Connect the Arduino Uno to your computer, select the right board and port, and upload the code.
The display will start counting from 00 to 99.
