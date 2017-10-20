#include "cup.h"

cup::cup(int n) {
	capacity = n;
	current_volume = 0;
}

void cup::pour(cup &B){
	if (B.getVolume() == B.capacity) {//if the cup that's being poured into is full
		return;
	}
	else {
		int difference = current_volume - B.getVolume();
		B.current_volume += difference;
		current_volume -= difference;
	}
}
