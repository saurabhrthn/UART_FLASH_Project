#include "uart.h"
#include "timer.h"
#include "main.h"

#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT disabled)

static void init_config(void);


void main(void)
{
    unsigned int eeprom_address = EEPROM_ADDRESS_START, last_written_address = EEPROM_ADDRESS_START;
    
    init_config();

    char received_char;
    unsigned long start_ticks, end_ticks, elapsed_ticks;
    unsigned int bytes_received = 0;

    puts("UART Initialized. Send 256-bytes data\n");

    // Start timer for the reception phase
    reset_timer();
    start_ticks = get_timer_ticks();

    // Reception loop
    while (1) 
    {
        received_char = getchar(); // Receive a byte from UART

        if (eeprom_address <= EEPROM_MAX_SIZE)
        {
            eeprom_write(eeprom_address, received_char); // Write byte to EEPROM
            eeprom_address++;
            bytes_received++;
        }
        else
        {
            puts("\nEEPROM Full! Cannot store more data.\n");
            break;
        }

        // Check for end of data transfer
        if (received_char == '\n' || received_char == '\r') // Newline indicates end of transmission
        {
            end_ticks = get_timer_ticks(); // Stop the timer
            elapsed_ticks = end_ticks - start_ticks;

            puts("\nData written to EEPROM successfully.\n");

            // Display reception speed
            show_transmission_speed(bytes_received, start_ticks, end_ticks);

            last_written_address = eeprom_address; // Save the last written address
            break;
        }
    }

    // Transmission phase
    puts("Transmitting data from EEPROM to PC:\n");

    // Start timer for transmission
    reset_timer();
    start_ticks = get_timer_ticks();
    unsigned int bytes_transmitted = 0;

    for (unsigned int read_address = EEPROM_ADDRESS_START; read_address < last_written_address; read_address++)
    {
        char data = eeprom_read(read_address); // Read byte from EEPROM
        putchar(data);                         // Send byte to PC
        bytes_transmitted++;
    }

    end_ticks = get_timer_ticks(); // Stop the timer

    // Display transmission speed
    show_transmission_speed(bytes_transmitted, start_ticks, end_ticks);

    puts("\nTransmission completed.\n");

    return;
}


static void init_config(void) 
{
    
    init_uart(2400);
    init_timer();  //to initialize Timer 2
    
    /* Peripheral Interrupt Enable Bit (For Timer2) */
    PEIE = 1;
    
    /* Enable all the Global Interrupts */
    GIE = 1;
}
