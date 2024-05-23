Overview:
The Smart Attendance System is designed to streamline and secure the process of marking attendance for students. The system combines the use of RFID technology and ultrasonic sensors to ensure that only students who are present in the classroom receive attendance. This project can be run using the Arduino IDE and involves both hardware and software components.

Components:

Arduino Uno: The microcontroller that acts as the brain of the system.
RFID Reader and Cards: Used for students to punch in their attendance at the door.
Ultrasonic Sensor: Detects the presence of students within the classroom.
Servo Motor: Controls the door mechanism to allow entry.
Buzzer: Provides audio feedback upon successful card punch.
LED Indicators: Visual indicators for successful/unsuccessful attendance recording.
Breadboard and Jumper Wires: For prototyping and connecting components.
System Setup:

RFID Punch Station: Located outside the classroom door where students punch their RFID cards.
Door Mechanism: Controlled by a servo motor that opens the door after a valid RFID card punch.
Ultrasonic Sensor: Installed inside the classroom to detect if a student actually enters the room.
Working Principle:

RFID Punching:

The student approaches the RFID reader at the door and punches their RFID card.
The RFID reader reads the unique ID from the card and sends it to the Arduino.
The Arduino checks the ID against a predefined list of valid student IDs.
If the ID is valid, the servo motor opens the door, allowing the student to enter.
A buzzer sounds and an LED lights up to indicate successful card reading.
Presence Detection:

Once the student enters the classroom, the ultrasonic sensor detects their presence.
The Arduino records the student’s attendance only if the ultrasonic sensor confirms their entry into the classroom.
If a student punches their card but does not enter the classroom (detected by the ultrasonic sensor), their attendance is not recorded.
Code Explanation:
The Arduino code consists of multiple functions to handle the RFID reading, servo motor control, ultrasonic sensor reading, and logic for marking attendance. Below is a brief explanation of the main sections of the code:

Setup Function: Initializes the RFID reader, servo motor, ultrasonic sensor, buzzer, and LED pins.
Loop Function: Continuously checks for RFID card punches and processes them.
RFID Reading: Reads the RFID card and validates it.
Door Control: Opens the door using the servo motor if the RFID card is valid.
Presence Detection: Uses the ultrasonic sensor to confirm the student’s presence inside the classroom.
Attendance Marking: Records attendance based on successful RFID card punch and presence detection.

Instructions to Run the Code:

Install the Arduino IDE from the official website.
Connect the Arduino Uno to your computer via USB.
Upload the provided Arduino code to the Arduino Uno.
Set up the hardware components as per the schematic provided in the project documentation.
Power up the Arduino and test the system by punching an RFID card and ensuring the ultrasonic sensor detects entry.
By following these steps, you can successfully deploy and run the Smart Attendance System for your classroom.

![WhatsApp Image 2024-05-03 at 18 51 50_ef3a69e4](https://github.com/sachin9587/smart_attendance_system/assets/143164961/1f86ebe9-7b0e-4400-a6b4-304c930a9f3b)
![WhatsApp Image 2024-05-03 at 18 51 50_b2252e18](https://github.com/sachin9587/smart_attendance_system/assets/143164961/933a6ccc-7349-4bb0-a04d-e0a98a0368db)


https://github.com/sachin9587/smart_attendance_system/assets/143164961/92a1e5b4-a929-4ce3-b769-c99cb9370aed

