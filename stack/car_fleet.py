"""
https://leetcode.com/problems/car-fleet/description/

There are n cars at given miles away from the starting mile 0, traveling to
reach the mile target.
You are given two integer arrays position and speed, both of length n, where
position[i] is the starting mile of the ith car and speed[i] is the speed of
the ith car in miles per hour.
A car cannot pass another car, but it can catch up and then travel next to it
at the speed of the slower car.
A car fleet is a single car or a group of cars driving next to each other.
The speed of the car fleet is the minimum speed of any car in the fleet.
If a car catches up to a car fleet at the mile target, it will still be
considered as part of the car fleet.
Return the number of car fleets that will arrive at the destination.

Example 1:
Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting
each other at 12. The fleet forms at target.
The car starting at 0 (speed 1) does not catch up to any other car, so it
is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting
each other at 6. The fleet moves at speed 1 until it reaches target.

Example 2:
Input: target = 10, position = [3], speed = [3]
Output: 1
Explanation:
There is only one car, hence there is only one fleet.

Example 3:
Input: target = 100, position = [0,2,4], speed = [4,2,1]
Output: 1
Explanation:
The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting
each other at 4. The car starting at 4 (speed 1) travels to 5.
Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one
fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches
target.

Constraints:
n == position.length == speed.length
1 <= n <= 10^5
0 < target <= 10^6
0 <= position[i] < target
All the values of position are unique.
0 < speed[i] <= 10^6
"""


class Solution:
    def carFleet(
        self, target: int, position: list[int], speed: list[int]
    ) -> int:
        # Suppose there are just two cars, they will form a fleet if the slower
        # car is ahead of the faster car, and if the difference in time to
        # reach target is such that its lesser for the slower car than the
        # faster one, they will meet and become a fleet, else not
        # in case of more cars, we just need to check if there exists at least
        # one care in the front, that our current car can bump into, if yes
        # they will eventually form a fleet, irrespective of whatever cars
        # are in between

        # build an array of time it takes to reach target, we will start
        # with the longest time, and try to merge cars into that to build
        # fleets
        time = [
            ((target - position[i]) / speed[i], position[i])
            for i in range(len(position))
        ]

        # form an array for joint sorting by time and position, a slower car
        # sorting is in descending order of time and descending order of
        # position
        time = sorted(time, key=lambda x: (-x[0], -x[1]))

        # maintain a stack, add elements to build fleets
        fleets = [time[0]]
        idx = 1

        while idx < len(time):
            # if this faster car is ahead, it cannot be merged, hence we need
            # to add this as well to form a new fleet
            if time[idx][1] > fleets[-1][1]:
                fleets.append(time[idx])

            # when the time is same, they will form a fleet, hence we can
            # keep the stack as is, and just move to the next car
            idx += 1

        return len(fleets)
