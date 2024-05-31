#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define dot "/dev/dot"

int dot_d;
unsigned char c[10][8] = {{0x3c,0x42,0x42,0x42,0x42,0x42,0x3c,0x00},
			{0x18,0x28,0x08,0x08,0x08,0x08,0x3c,0x00},
			{0x18,0x24,0x24,0x04,0x08,0x10,0x3c,0x00},
			{0x18,0x24,0x04,0x18,0x04,0x24,0x18,0x00},
			{0x08,0x18,0x28,0x48,0xfc,0x08,0x08,0x00},
			{0x2c,0x20,0x20,0x18,0x04,0x24,0x18,0x00},
			{0x18,0x24,0x20,0x38,0x24,0x24,0x18,0x00},
			{0x3c,0x04,0x04,0x08,0x10,0x10,0x10,0x00},
			{0x18,0x24,0x24,0x18,0x24,0x24,0x18,0x00},
			{0x18,0x24,0x24,0x1c,0x04,0x04,0x18,0x00},
			};

unsigned char dot_buffer[8] = {
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b11111111,
    0b00000000,
    0b00000000
};

int main()
{
    int i;
    

    if((dot_d = open(dot, O_RDWR)) < 0)
    {
        printf("Can't Open\n");
        exit(0);
    }

	write(dot_d,&dot_buffer,sizeof(dot_buffer));
	sleep(1);
    close(dot_d);

    return 0;
}