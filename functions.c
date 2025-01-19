#include "main.h"
#include "uart.h"

void itoa(unsigned long num, char *str)
{
    int i = 0;
    if (num == 0)
    {
        str[i++] = '0';
    }
    else
    {
        char temp[16];
        while (num > 0)
        {
            temp[i++] = (num % 10) + '0';
            num /= 10;
        }
        for (int j = 0; j < i; j++)
        {
            str[j] = temp[i - j - 1];
        }
    }
    str[i] = '\0';
}

//Function to show transmission speed
void show_transmission_speed(unsigned int byte_count, unsigned long start_ticks, unsigned long end_ticks)
{
    unsigned long elapsed_ticks = end_ticks - start_ticks; // Elapsed time in ms
    if (elapsed_ticks == 0)
    {
        puts("Speed: N/A\n");
        return;
    }

    // Calculate speed in bits per second
    unsigned long bits_transferred = byte_count * UART_FRAME_BITS;
    unsigned long speed = (bits_transferred * 1000) / elapsed_ticks; // bps

    // Convert speed to string
    char speed_str[16];
    itoa(speed, speed_str);

    // Send the speed via UART
    puts("Speed: ");
    puts(speed_str);
    puts(" bips\n");
}
