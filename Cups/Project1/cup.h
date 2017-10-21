#ifndef CUP_H
#define CUP_H

class cup {
	public:
		cup(int = 0);
		int getVolume() { return current_volume; }
		int getCapacity() { return capacity; }
		void empty() { current_volume = 0; }//empties the cup
		void fill() { current_volume = capacity; }//fills the cup
		void pour(cup&);
		//int current_volume;//current amount of water currently in the cup
	private:
		int capacity;//capacity of the cup
		int current_volume;//current amount of water currently in the cup
};

#endif