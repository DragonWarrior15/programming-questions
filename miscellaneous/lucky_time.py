"""
Given an input time in 24 hour hh:mm:ss format,
find the earliest time in the same format such that all the
digits in that time are distinct
"""
from sys import stdin

T = int(stdin.readline().strip())
data = stdin.readlines()


def increment_time(time, hour=0, minute=0, seconds=0):
    curr_hour = int(time[:2])
    curr_minute = int(time[3:5])
    curr_seconds = int(time[6:])

    if curr_seconds + seconds >= 60:
        minute += 1
    curr_seconds = (curr_seconds + seconds) % 60

    if curr_minute + minute >= 60:
        hour += 1
    curr_minute = (curr_minute + minute) % 60

    curr_hour = (curr_hour + hour) % 24

    # convert to strings
    curr_hour = str(curr_hour) if curr_hour > 9 else "0" + str(curr_hour)
    curr_minute = str(curr_minute) if curr_minute > 9 else "0" + str(curr_minute)
    curr_seconds = str(curr_seconds) if curr_seconds > 9 else "0" + str(curr_seconds)

    return curr_hour + ":" + curr_minute + ":" + curr_seconds


def check_lucky_time(time):
    time_list = [0] * 10
    for i in range(len(time)):
        if time[i] == ":":
            pass
        else:
            time_list[int(time[i])] += 1
    if max(time_list) == 1 and sum(time_list) == 6:
        return True
    return False


for time in data:
    curr_time = time
    while 1:
        new_time = increment_time(curr_time, seconds=1)
        # print(curr_time, new_time, check_lucky_time(new_time))
        if check_lucky_time(new_time):
            print(new_time)
            break
        else:
            curr_time = new_time
