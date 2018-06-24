'''
Valentina is looking for a new game to play with her friends. She asks her mom Marcia for an idea. 
After a moment Marcia described to girls the following simple game.

Girls are divided into n teams, indexed 1 through n. Each girl chooses a lowercase letter, 
one of 'a' - 'z'. Of course, some girls can choose the same letter. Then, Marcia, as a judge, 
shows a string s, consisting of lowercase letters. For each letter in s, each girl with the same letter gets one point.

We define the score of a team as the total number of points of its members.

Your task is to find the winning team, determined according to the following rules:

The winning team is the one with the largest score.
In case of a tie between two or more teams, the one with the fewest members wins.
If there is still a tie between two or more teams then the one with the lowest index wins.
Given all the information about the game, find the index of the winning team.

Input format
The first line of the input contains one integer T denoting the number of test cases.

The first line of each test case description contains an integer n and a string s denoting 
the number of teams and a string showed by Marcia.

The i-th of the next n lines contains one non-empty string containing letters chosen 
by girls in the i-th team. The length of a string is equal to the number of members in a team.

All strings in the input consist of lowercase letters only.

Output format
For each test case, output a single line containing the 1-based index of the winning team.

Constraints
Subtasks
Extra constraints   Points  Which tests
40  1-4
no extra constraints    60  5-10
SAMPLE INPUT 
3
2 qwopwasp
wdw
abco
5 eeeessaa
valentina
esta
jugando
con
marcia
5 ahi
valentina
esta
jugando
con
susamigas
SAMPLE OUTPUT 
1
2
1
Explanation
In the first sample test case, there are 2 teams. The string showed by Marcia is qwopwasp. 
There are two letters 'w' in s, so two points are given to every girl who has chosen a letter 'w'.

Team 1 has three members. Two of them has chosen a letter 'w', and the other one has chosen a letter 'd'. 
The two girls get two points each, but the other girl has zero points because a letter 'd' doesn't occur in s at all. The score of team 1 is 4.

Team 2 has four members. A girl who has chosen a letter 'a' gets one point, and so does a girl who has chosen a letter 'o'. The score of team 2 is 2.

So, in the first sample test case there is no tie and team 1 clearly wins.
'''

from sys import stdin
T = int(stdin.readline().strip())
data = stdin.readlines()
index = 0
N_start = True
teams_start = False
while(1):
    if(N_start):
        N, marcia_string = data[index].split(' ')
        N = int(N.strip())
        marcia_string = marcia_string.strip()
        index += 1
        teams_start = True
        N_start = False
        team_scores = []

        marcia_list = [0]*26
        for char in marcia_string:
            marcia_list[ord(char) - 97] += 1

    if(teams_start):
        team_string = data[index].strip()
        score = 0
        for char in team_string:
            score += marcia_list[ord(char) - 97]
        team_scores.append([len(team_scores), score, len(team_string)])
        index += 1
        if(len(team_scores) == N):
            teams_start = False
            N_start = False
        continue

    team_scores = sorted(team_scores, key = lambda x: x[1], reverse = True)
    max_score = team_scores[0][1]
    team_scores = filter(lambda x: x[1] == max_score, team_scores)
    team_scores = sorted(team_scores, key = lambda x: x[2], reverse = False)
    min_memb = team_scores[0][2]
    team_scores = filter(lambda x: x[2] == min_memb, team_scores)
    team_scores = sorted(team_scores, key = lambda x: x[0], reverse = False)

    print(team_scores[0][0] + 1)

    N_start = True
    teams_start = False

    if(index == len(data)):
        break
