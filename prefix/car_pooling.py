"""
https://leetcode.com/problems/car-pooling/

There is a car with capacity empty seats. The vehicle only drives east (i.e.,
it cannot turn around and drive west).
You are given the integer capacity and an array trips where
trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has
numPassengersi passengers and the locations to pick them up and drop them
off are fromi and toi respectively. The locations are given as the number of
kilometers due east from the car's initial location.
Passengers are dropped off before new passengers are picked up at the same
location. At every point along the route, the total number of passengers in
the car must not exceed capacity.
Return true if it is possible to pick up and drop off all passengers for all
the given trips, or false otherwise.

Example 1:
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Explanation:
At kilometer 1, 2 passengers are picked up, so the car holds 2.
At kilometer 3, 3 more are picked up, so the car holds 5.
Since 5 > capacity = 4, the trips cannot all be completed.

Example 2:
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
Explanation:
At kilometer 1, the car holds 2 passengers.
At kilometer 3, the car holds 5 passengers.
At kilometer 5, the first 2 are dropped off, so the car holds 3.
At kilometer 7, the last 3 are dropped off, so the car holds 0.
The maximum occupancy is 5, which never exceeds capacity = 5.

Constraints:
1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 10^5
"""


class Solution:
    def carPooling(self, trips: list[list[int]], capacity: int) -> bool:
        # we build an array that holds the delta of passengers at every
        # specific mark part of trips
        # for example, for trips = [[2,1,5]]
        # we will build a map {1: +2, 5: -2}
        # then we just iterate over this and see if the capacity
        # is exceeded anywhere
        checkpoints = [0] * 1001
        for trip in trips:
            num_passengers, from_, to_ = trip
            checkpoints[from_] += num_passengers
            checkpoints[to_] -= num_passengers

        # iterate and validate capacity
        curr_passengers = 0
        for num_passangers in checkpoints:
            curr_passengers += num_passangers
            if curr_passengers > capacity:
                return False

        return True
