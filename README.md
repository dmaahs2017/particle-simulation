# particle-simulation
C++ program that simulates the number of particles that escape a reactor's lead shielding.


Problem Description:

A circular slab of uniform thickness (5 units) (cross-section of the slab is illustrated below) is to be used to shield a nuclear reactor. A radioactive particle entering the shield follows a random path by moving forward, backward, left, or right with equal likelihood, in jumps of one unit (You may assume the radioactive particle begins in the shield( position one) ). 

A change in the direction of the particle is interpreted as a collision with a Lead atom in the shield. After 10 collisions the particle’s energy has dissipated and will not escape the shield. 

If the particle moves forward 6 positions (without exceeding 10 collisions), it has escaped the shielding.  If the particle returns to the reactor, it is has not escaped the shield.

Write a program to simulate 1000 particles entering the shield and determine what percentage of the particles escape the shielding. Note: The simulation for each particle will end when any of the events described above has occurred. 

Note: The slab encompasses the entire core of the reactor so it is possible that a simulation might never end.

Problem Analysis:
  Output:	% of escaped particles
  Input: 	N/a
  Process: 
    simmulate each particle bouncing withing the lead shielding. Moving either up, down, left or right.
      simmulation per particle ends when it collides over 10 times, it escapes the shield, or it returns to the reactor
      count if the particle escaped
    Calculate rate of escaped particles
