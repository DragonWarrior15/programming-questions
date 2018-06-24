'''
Big P has become a Physical Education teacher at Hack International School.

Today, the students of class XII have been very undisciplined and he decides to punish them all.

He makes all of the N student (numbered 1 to N ) to stand in a line and asks them to sit down on their knees.

Students know that Big P is a very cruel and sadistic person and students start to sit down themselves when they see a friend sit down.

However, there are always some students who do not follow the trend. Now when Big P sees that happen ,
he slaps that student and makes him sit down. The same process as above is followed and is stopped 
when any - one student in the line refuses to sit down by himself.

Given the students that Big P slaps to make them sit down , you need to tell the total no. of students who sat down in that line.

Note: It is not necessary that if A is friend of B then B is also friend of A.

Input Format :
First Line Contains an integer T denoting no of test cases. 
Each test case begins with a line containing three integers  where N is the number of students in the line. 
Next F lines have two integers A and B denoting the friendship between the students A and B. 
Next S lines have one integer X denoting the student that was slapped by Big P .

Output Format:
For each test case, output a line containing one integer, the total number of students that sit down in that line.


SAMPLE INPUT 
1
3 2 1
1 2
2 3
2
SAMPLE OUTPUT 
2
'''

from sys import stdin
import queue as queue

T = int(stdin.readline().strip())
N, F, S = list(map(int, stdin.readline().strip().split(' ')))
data = stdin.readlines()

edge_dict = {}
for edge in data[:F]:
    curr_edge = list(map(int, edge.split(' ')))
    # a student can be friends with multiple people
    try:
        edge_dict[curr_edge[1]].append(curr_edge[0])
    except KeyError:
        edge_dict[curr_edge[1]] = [curr_edge[0]]
        

slap_list = []
for i in range(F, F + S):
    slap_list.append(int(data[i].strip()))

visited_set = set()
for student in slap_list:
    if(student in visited_set):
        pass
    else:
        student_queue = queue.Queue()
        student_queue.put(student)
        while(not student_queue.empty()):
            # take the first student and start processing
            # keep adding friends to a queue for processing later
            next_student = student_queue.get()
            print(next_student)
            if(next_student in edge_dict):
                for friend in edge_dict[next_student]:
                    if(friend not in visited_set):
                        visited_set = visited_set | set([friend])
                        student_queue.put(friend)

print(len(visited_set))
