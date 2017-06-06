#include "spinlocks.h"

int main(void) {

}


void spinlock(int volatile *Destination, int Exchange, int Comperand)
{
	while (*Destination != Comperand)
		;
	*Destination = Exchange;
}
