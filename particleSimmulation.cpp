#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int TOTAL_PARTICLES = 1000;		//number of particles to run the simulation for
const int FORWARD = 1;
const int BACKWARD = 2;
const int DIR_SENTINEL = -1;			//represents the particle has not yet moved
const int OUTER_BOUND = 5;				//represents the outer layer of the lead shield
const int INNER_BOUND = 1;				//represents the inner layer of the lead shield
const int MAX_COLLISIONS = 10;
int main()
{
	int escapedParts = 0,
		direction, collisions, prevDirection, partPos;
	double rateEscaped;
	bool isPartActive, isInShield;

	srand(static_cast<int>(time(0)));											//seed rng

	for (int particle = 1; particle <= TOTAL_PARTICLES; particle++)				//loop for each particle
	{
		prevDirection = DIR_SENTINEL;											//reset previous Direction
		collisions = MAX_COLLISIONS;											//collission counter, counts to 0
		partPos = INNER_BOUND;													//the particle will disapate
		
		isPartActive = true;													//boolean test variables start activated
		isInShield = true;
		while (isPartActive && isInShield)
		{
			direction = rand() % 4 + 1;											//generate a direction 1 to 4
			if (direction != prevDirection && prevDirection != DIR_SENTINEL)	//test for change in direction
				collisions--;													
			switch (direction)													//move particle forward or backwards
			{
			case FORWARD: 
				partPos++;
				break;
			case BACKWARD: 
				partPos--;
				break;
			}//End Switch
			prevDirection = direction;											//update previous direction

			isPartActive = static_cast<bool>(collisions);						//single particle simmulation ends when particle disapates due to collisions OR
			isInShield = partPos >= INNER_BOUND && partPos <= OUTER_BOUND;		//when particle escapes or re-enters the reactor. THESE CONTROL THE WHILE LOOP
		}//End While
		if (partPos > OUTER_BOUND)												//test if the end condition was caused by an escaped particle
			escapedParts++;
	}//End For


	rateEscaped = static_cast<double>(escapedParts) / TOTAL_PARTICLES * 100;	//calculate escaped particles percentage
															
	cout << "          Total Particles: " << setw(5)							//display formatted results
		 << TOTAL_PARTICLES << endl;

	cout << "        Escaped Particles: " << setw(5) 
		 << escapedParts << endl;

	cout << "Rate of Escaped Particles: " << setw(5) 
		 << rateEscaped << " %" << endl;
	return 0;
}