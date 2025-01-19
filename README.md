# UART_FLASH_Project
README: UART Data Transmission with EEPROM Storage

Controller Used:    PIC16f877a
Simulator : PICSimLab
Serial Terminal : Cutecom

Assignment Overview
This assignment involved implementing a UART-based communication system to handle data transfer between a PC and an MCU, with real-time storage into the EEPROM memory. The focus was on effectively managing 256 bytes of EEPROM memory and providing real-time data transmission speed feedback during both reception and transmission. The project aimed to demonstrate efficient resource utilization under memory constraints while maintaining accurate performance monitoring.

What I Implemented

UART Communication:
Configured UART for 2400 baud rate, using:
8 data bits, 1 stop bit, and no parity.
Enabled byte-by-byte communication for both data reception and transmission.

Data Reception and Storage:
Developed a mechanism to receive data from the PC in real-time and write each byte to EEPROM sequentially.
Implemented logic to detect the end of data transmission when a newline (\n) or carriage return (\r) was received.
Added error handling to stop data storage if the 256-byte EEPROM limit was reached.

Data Transmission:
After receiving data, I implemented functionality to read it back from EEPROM and send it back to the PC via UART.
This ensured the integrity of data stored in EEPROM.

Real-Time Speed Monitoring:
Incorporated logic to calculate and display the live transmission speed in bits per second (bps) during both reception and transmission phases.
Speed was displayed dynamically after each byte, providing real-time feedback.

EEPROM Management:
Utilized EEPROM addresses starting from 0x00 to store incoming data sequentially.
Ensured no data was written beyond the 256-byte memory limit.
Stored the last written address for efficient data retrieval during transmission.

Timer Integration:
Used a hardware timer to measure elapsed time in milliseconds, ensuring precise speed calculation for each byte.
The timer was reset at the start of both reception and transmission phases.

Challenges I Encountered
EEPROM Memory Constraint:

Challenge: Limited to 256 bytes of memory, requiring careful handling to avoid overflow.
Solution: Implemented checks to stop data storage when the limit was reached, along with an error message:

Challenge: Accurately measuring live data speeds without relying on the baud rate.
Solution: Integrated a timer to dynamically calculate elapsed time and bits transferred for precise speed computation.

Challenge: Displaying speeds during ongoing operations without adding significant overhead.
Solution: Optimized speed calculation functions to run efficiently after every byte.

Challenge: Synchronizing data reception, storage, and retrieval seamlessly within a single program.
Solution: Maintained separate phases for reception and transmission, with clear entry and exit points.
