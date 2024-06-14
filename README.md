# Smart-Fuel-Measurement-System
Employing Arduino technology, this device is designed to monitor the fuel dispensing process by checking the dispensed amount with the display on the machine. In case of any discrepancies, a buzzer is activated at the petrol station alerting the staff. The device employs IoT capabilities to transmit the petrol station's location to headquarters.

## System Components
### 1. Arduino
The Arduino Uno is an open-source microcontroller board based on the Microchip ATmega328P microcontroller. It was developed by Arduino.cc and initially released in 2010.
* #### Here are some key features and specifications:
  - **Digital and Analog I/O Pins:**
    The board is equipped with 14 digital input/output pins (of which 6 can be used as PWM outputs), and 6 analog input/output pins12.
  - **Memory and Storage:**
    It has 2 KB SRAM, 32 KB Flash, and 1 KB EEPROM.
  - **Programming and Communication:**
    The board is programmable with the Arduino IDE (Integrated Development Environment), via a type B USB cable1. It communicates using the original STK500 protocol.
  - **Power Supply:**
    It can be powered by a USB cable or a barrel connector that accepts voltages between 7 and 20 volts.
  - **Microcontroller:**
    It has the same microcontroller as the Arduino Nano board.
  - **Headers:**
    It has the same headers as the Arduino Leonardo board.
  - **USB-to-Serial Converter:**
    Unlike preceding boards that use a FTDI USB-to-UART serial chip, it uses the Atmega16U2 (Atmega8U2 up to version R2) programmed as a USB-to-serial converter.
### 2. GSM MODULE
A GSM module is a compact electronic device that facilitates communication between devices and the GSM (Global System for Mobile Communications) network. It integrates a GSM modem, power supply circuitry, and communication interfaces (such as RS-232 or USB). These modules are used in various applications, including SMS services, MMS services, and more. GSM modules can be external modems or embedded within equipment. They rely on SIM cards for network communication. Unlike mobile phones, which have embedded processors, GSM modules serve as dedicated communication components. They play a crucial role in enabling wireless communication across the globe.
* #### Wire the GPS to your Arduino board as follows:
  - VCC to 5V in Arduino
  - TX to digital pin 6
  - RX to digital pin 7
  - GND to ground pin
* #### Features of GSM Module: 
  - Improved spectrum efficiency 
  -	International roaming 
  - Compatibility with integrated services digital network (ISDN) 
  - Support for new services.
  -	SIM phonebook management
  -	Fixed dialing number (FDN)
  -	Real time clock with alarm management
  -	High-quality speech
  -	Uses encryption to make phone calls more secure
  -	Short message service (SMS)
### 3. LCD Display
LCDs (Liquid Crystal Displays) are versatile and commonly used for displaying information. The most commonly used type is compatible with the Hitachi HD44780 driver, which can be controlled via a 16-pin interface1. These displays usually operate in either 4-bit or 8-bit mode, with the 4-bit mode being sufficient for most tasks and requiring fewer I/O pins from the Arduino. Here’s a step-by-step guide:
* #### Wire the LCD screen to your Arduino board as follows:
  - LCD RS pin to digital pin 1.
  - LCD Enable pin to digital pin 11
  - LCD D4-D7 pins to digital pins 5, 4, 3, and 2
  - LCD R/W pin to GND
  - LCD VSS pin to GND
* #### Characteristics of LCD display
  - Character LCD 16x4
  - 5x8 dots includes cursor
  - Built-in controller (ST7066 or Equivalent)
  - +5V power supply (Also available for +3V)
  - WG16032D3 optional for +3V power supply
  - 1/16 duty cycle
### 4. Flow Sensor
A flow sensor definition is a sensor that is used to measure a fluid like liquid or gas. These sensors mainly use both electrical and mechanical subsystems to gauge changes within the physical attributes of fluid & measure its flow.So measuring these mainly depends on the physical attributes of fluid. A flow sensor is an electronic device that measures the changes in liquids flow rate & gasses in tubes & pipes. The flow sensor working principle is based on Bernoulli’s principle. This principle states that the drop of pressure across the meter is simply proportional to the square of the rate of flow.
* **Mass FLow Sensor** is used in the project.
  A mass flow sensor measures the flow rate of fluid or the amount of fluid or gas flowing throughout a pipe by simply determining the mass for each unit of time. These sensors are extensively used in automobiles, wherever they are utilized to measure the air inflowing the air intake system of an inside combustion engine.
### 5. Buzzer
A buzzer is an audio signaling device that converts an audio signal into sound. The primary function of a buzzer is to produce sound for alerts or notifications in devices like timers, alarm systems, and computers. Buzzers typically operate on a voltage range from 3V to 24V DC, with a sound pressure level around 85dBA and an operating temperature range from -20°C to +60°C. When the power source is turned on, the oscillator that generates the audio signal will start to send current through the solenoid coil, creating a magnetic field. Under the influence of the magnet and solenoid coil, the vibration diaphragm will occasionally vibrate and produce sound. Its frequency range is between 2 kHz and 4 kHz.
### 6. Wi-fi Module
A Wi-Fi module is a self-contained SoC (System on Chip) that provides wireless communication capabilities to devices. It typically includes a Wi-Fi chip and an application host processor. The Wi-Fi subsystem comprises an 802.11 radio physical layer (PHY), baseband, media access control (MAC), and sometimes a crypto engine for secure internet connections. The application host processor usually has internal or external flash, ROM, and RAM1. Wi-Fi modules are integral to IoT (Internet of Things) designs because they offer native IP addressability, which is essential for devices to connect and exchange data over the internet without needing a separate gateway. This makes Wi-Fi a standout choice for IoT applications due to its ubiquity, scalability in terms of data rates, and power optimization

### 7. DC Motor
DC motors are used to convert electrical energy into mechanical energy and we can use these for example in our power tools, toy cars and cooling fans. DC motor has such basic components, as a stator (stationary part of the element producing magnetic field) and a rotor part that rotates carrying winding or coil. When a DC voltage is connected to the coil, current flows through it and generates an electromagnetic field. When the magnetic field of this rotor interacts with that produced by the stator, a torque is induced which causes this piece to start spinning. DC motors are used where the speed of the motor needs to be controlled externally. The speed of DC motors can be controlled by changing the current of the armature winding.
