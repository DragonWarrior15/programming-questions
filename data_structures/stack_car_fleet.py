class Solution:
    def fleet_count(cars: List[(int, int)]) -> int:
        # first car always counted as a fleet
        count = 1
        for i in range(2, len(cars)):
            # cars at two different positions
            if cars[i][0] != cars[i-1][0]:
                count += 1

        return count

    def carFleet(
        self, target: int, position: List[int], speed: List[int]
    ) -> int:
        """We first sort the data by position and calculate the delta of
        positions and speeds to find the two consecutive cars that will be
        the first to become a fleet. Once one iteration of this simulation is
        over, we update the positions of all the remaining cars and keep
        calling the function until all cars have crossed the target
        """
        cars = [(position[i], speed[i]) for i in range(len(position))]
        cars = sorted(cars, key=lambda x: x[0], reverse=False)

        # calculate delta position and delta speed
        delta_time = []
        min_time, min_position = float("inf"), -1
        for i in range(len(cars) - 1):
            if cars[i][0] == cars[i + 1][0]:
                # append +inf
                delta_time.append((i, float("inf")))
            elif cars[i][1] < cars[i + 1][1]:
                # car may not be able to catch up
                delta_time.append((i, float("inf")))
            else:
                # candidate for possible fleet formation
                delta_time.append(
                    (
                        i,
                        (cars[i][1] - cars[i + 1][1])
                        / (-cars[i][0] + cars[i + 1][0]),
                    )
                )

                if delta_time[-1] < min_time:
                    min_time = delta_time[-1]
                    min_position = cars[i][0]

        # check if minimum time is less than infinity
        if min_time == float("inf"):
            # nothing more to iterate, return the fleet count
            return self.fleet_count(cars)
        else:
            # possible to iterate further
            # first check if the destination is crossed in that time
