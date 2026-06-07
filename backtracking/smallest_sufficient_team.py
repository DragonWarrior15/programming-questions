# https://leetcode.com/problems/smallest-sufficient-team/

"""
In a project, you have a list of required skills req_skills, and a list of
people. The ith person people[i] contains a list of skills that the person has.
Consider a sufficient team: a set of people such that for every required skill
in req_skills, there is at least one person in the team who has that skill. We
can represent these teams by the index of each person.

For example, team = [0, 1, 3] represents the people with skills people[0],
people[1], and people[3]. Return any sufficient team of the smallest possible
size, represented by the index of each person. You may return the answer in any
order.

It is guaranteed an answer exists.

Example 1:
Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],
["nodejs","reactjs"]]
Output: [0,2]
Example 2:

Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"],
people = [["algorithms","math","java"],["algorithms","math","reactjs"],
["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]

Constraints:

1 <= req_skills.length <= 16
1 <= req_skills[i].length <= 16
req_skills[i] consists of lowercase English letters.
All the strings of req_skills are unique.
1 <= people.length <= 60
0 <= people[i].length <= 16
1 <= people[i][j].length <= 16
people[i][j] consists of lowercase English letters.
All the strings of people[i] are unique.
Every skill in people[i] is a skill in req_skills.
It is guaranteed a sufficient team exists.
"""


class Solution:
    def smallestSufficientTeam(
        self, req_skills: List[str], people: List[List[str]]
    ) -> List[int]:
        # lets use sets to represent the data here
        # we start with an empty set, and keep adding people till our
        # starting set equals the full set of req skills
        # we can immediately discard people who do not have any intersection
        # with our required skills set
        # then we can greedily add people, prioritizing ones with maximum
        # intersection with our required skills set

        req_skills_set = set(req_skills)
        found_skills_indicator = [0] * len(req_skills)
        skill_to_idx_map = {k: idx for idx, k in enumerate(req_skills)}

        for idx in range(len(people)):
            people[idx] = (idx, set(people[idx]))

        # basic filter
        people = [
            people[idx]
            for idx in range(len(people))
            if people[idx][1].intersection(req_skills)
        ]

        # sort using our logic
        people = sorted(
            people, reverse=True, key=lambda x: len(x[1].intersection(req_skills))
        )

        selected_people_indicator = [0] * len(people)

        # backtrack and build
        possible_teams = []
        size_best_possible_team = float("inf")

        def build_team(selected_people_indicator, found_skills_indicator):
            nonlocal size_best_possible_team, possible_teams
            # base case, all missing skills found
            if (
                all(found_skills_indicator)
                and sum(selected_people_indicator) < size_best_possible_team
            ):
                possible_teams.append(list(selected_people_indicator))
                size_best_possible_team = sum(selected_people_indicator)
                return

            # pruning
            if sum(selected_people_indicator) > size_best_possible_team:
                # no need to explore further
                return

            # carry on, get the next missing people, and iterate over people
            # who have that skill
            for skill_idx in range(len(found_skills_indicator)):
                if found_skills_indicator[skill_idx] == 0:
                    break

            # DO NOT take an intersection with needed_skills as this will lead
            # to irrelevant matches.. since we are trying to find just the
            # next missing skill at this iteration.. to put into perspective
            # consider we are missing A and B, person 1 has A and person 2 has
            # B.. direct intersection with needed skills will filter both
            # person 1 and 2.. whereas this iteration should just focus
            # on person 1.. otherwise will create duplicate branches
            needed_skills = set(
                [
                    req_skills[idx]
                    for idx in range(len(req_skills))
                    if found_skills_indicator[idx] == 0
                ]
            )

            eligible_people = [
                idx
                for idx in range(len(selected_people_indicator))
                if selected_people_indicator[idx] == 0
                and req_skills[skill_idx] in people[idx][1]
            ]

            if not eligible_people:
                return

            # greedy sorting
            eligible_people = sorted(
                eligible_people,
                reverse=True,
                key=lambda idx: len(people[idx][1].intersection(needed_skills)),
            )

            for eligible in eligible_people:
                # mark as available and recurse
                selected_people_indicator[eligible] = 1
                # update found skills
                for skill in people[eligible][1]:
                    if skill in skill_to_idx_map:
                        found_skills_indicator[skill_to_idx_map[skill]] += 1

                # recurse
                build_team(selected_people_indicator, found_skills_indicator)

                # undo changes
                for skill in people[eligible][1]:
                    found_skills_indicator[skill_to_idx_map[skill]] -= 1

                selected_people_indicator[eligible] -= 1

        build_team(selected_people_indicator, found_skills_indicator)

        for team in possible_teams:
            if sum(team) == size_best_possible_team:
                return [people[idx][0] for idx in range(len(team)) if team[idx] == 1]
