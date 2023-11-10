# ECG Machine using NodeMCU and OLED

This project describes how to build an ECG machine using NodeMCU and OLED. The ECG machine can be used to monitor the electrical activity of the heart and display the ECG waveform on an OLED screen. The project uses an AD8232 ECG sensor and NodeMCU ESP8266 board to interface with the heart and OLED display.

## Hardware Requirements

- AD8232 ECG Sensor
- NodeMCU ESP8266 Board
- USB Connector
- Breadboard
- 0.96″ OLED Display with 128x64 resolution

## Software Requirements

- Arduino IDE

## Wiring

The AD8232 ECG sensor is connected to the NodeMCU ESP8266 board. The VCC pin of the AD8232 ECG sensor is connected to the 3.3V output of the NodeMCU board. The GND pin of the AD8232 ECG sensor is connected to the GND pin of the NodeMCU board. The OUTPUT pin of the AD8232 ECG sensor is connected to analog pin A0 of the NodeMCU board. The LO+ and LO- pins of the AD8232 ECG sensor are connected to digital pins D5 and D6 of the NodeMCU board, respectively. The OLED display is connected to the NodeMCU board using I2C protocol. The VCC pin of the OLED display is connected to the 3.3V output of the NodeMCU board. The GND pin of the OLED display is connected to the GND pin of the NodeMCU board. The SCL pin of the OLED display is connected to digital pin D1 of the NodeMCU board. The SDA pin of the OLED display is connected to digital pin D2 of the NodeMCU board.



## Usage

1. Connect the circuit according to the wiring diagram.
2. Open Arduino IDE and write the code.
3. Save the file with extension `.ino`.
4. Change the Ubidots token and save the code and upload.
5. Check the serial plotter.
6. Then go to the Ubidots to check the uploaded data.

## Conclusion

This project demonstrates how to build an ECG machine using NodeMCU and OLED. The ECG machine can be used to monitor the electrical activity of the heart and display the ECG waveform on an OLED screen. The project uses an AD8232 ECG sensor and NodeMCU ESP8266 board to interface with the heart and OLED display.
