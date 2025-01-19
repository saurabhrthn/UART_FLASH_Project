#include <xc.h> // include processor files - each processor file is guarded.  

#define EEPROM_ADDRESS_START        0
#define EEPROM_MAX_SIZE             256  
#define UART_FRAME_BITS             10 // 1 start bit, 8 data bits, 1 stop bit

void itoa(unsigned long num, char *str);
void show_transmission_speed(unsigned int byte_count, unsigned long start_ticks, unsigned long end_ticks);
