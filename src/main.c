#include <stdio.h>
#include <time.h>
#include "walkingdriver/driver.h"

bool a_fini = false;

void terminer()
{
	a_fini = true;
}

void pause()
{
	while (!a_fini) sleep(0.05);
	a_fini = false;
}


int main (int argc, char* args[])
{
	switch (initAX12(115200))
	{
		case 1:
		printf("can not open AX12 serial port");
		break;
		
		case 2:
		printf("Can not create mutex");
		break;
		
		case 0:
		break;
	};
	
	
	uint8_t id_motor_racine = 146;
	uint8_t id_motor_avant = 130;
	
	AX12move(id_motor_racine, 0, terminer);
	pause();
	AX12move(id_motor_avant, 0, terminer);
	pause();
	
	
	printf("Hello world");
	return 0;
}