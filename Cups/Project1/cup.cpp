#include "cup.h"

cup::cup(int n) {
	capacity = n;
	current_volume = 0;
}

void cup::pour(cup &B){
	if (B.getVolume() == B.getCapacity()) {//if the cup that's being poured into is full
		return;
	}
	else {
		for (unsigned int i = B.getVolume(); i < B.getCapacity() && current_volume > 0; i++) {
			current_volume--;
			B.current_volume++;
		}
	}
}
