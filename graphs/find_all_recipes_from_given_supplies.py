"""
https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/

You have information about n different recipes. You are given a string array
recipes and a 2D string array ingredients. The ith recipe has the name
recipes[i], and you can create it if you have all the needed ingredients from
ingredients[i]. A recipe can also be an ingredient for other recipes, i.e.,
ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that
you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the
answer in any order.

Note that two recipes may contain each other in their ingredients.

Example 1:
Input: recipes = ["bread"], ingredients = [["yeast","flour"]],
supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".

Example 2:
Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],
["bread","meat"]], supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create
the ingredient "bread".

Example 3:

Input: recipes = ["bread","sandwich","burger"], ingredients =
[["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]],
supplies = ["yeast","flour","meat"]
Output: ["bread","sandwich","burger"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".
We can create "sandwich" since we have the ingredient "meat" and can create
the ingredient "bread".
We can create "burger" since we have the ingredient "meat" and can create the
ingredients "bread" and "sandwich".

Constraints:
n == recipes.length == ingredients.length
1 <= n <= 100
1 <= ingredients[i].length, supplies.length <= 100
1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase
English letters.
All the values of recipes and supplies combined are unique.
Each ingredients[i] does not contain any duplicate values.
"""


class Solution:
    def findAllRecipes(
        self,
        recipes: list[str],
        ingredients: list[list[str]],
        supplies: list[str],
    ) -> list[str]:
        from dataclasses import dataclass, field

        # create a set of supplies, a given recipe can be made if
        # its ingredients are a subset of supplies
        # the above approach works if none of the recipes are used for other
        # recipes, to actually solve this problem we need to create a graph
        # and then evaluate if every recipe and its dependencies are possible
        # to prepare in our case
        @dataclass
        class Node:
            is_valid: bool | None = None
            depends_on: list[str] = field(default_factory=list)

        # first add all supplies to the graph, every key of the graph is a node
        graph: dict[str, Node] = {}

        for supply in supplies:
            graph[supply] = Node(is_valid=True, depends_on=[])

        # no add recipes to this one by one
        for idx in range(len(recipes)):
            if recipes[idx] not in graph:
                graph[recipes[idx]] = Node(
                    is_valid=None, depends_on=ingredients[idx]
                )

        # maintain a visited list to prevent cycles
        visited = set()

        # now work through all the recipes, and traverse the graph where needed
        def check_is_valid(node: str) -> bool:
            if node not in graph:
                visited.add(node)
                return False
            elif graph[node].is_valid is not None:
                # no need to traverse further
                visited.add(node)
                return graph[node].is_valid
            else:
                # we will encounter cycles when working through the None cases
                # only
                if node in visited:
                    return False

                # normal execution
                visited.add(node)
                # first get the is valid for all children, and then return
                # the value for the current thing
                current = True
                for child in graph[node].depends_on:
                    current = current and check_is_valid(child)

                # also set the obtained value before returning it
                graph[node].is_valid = current
                return current

        # return the list of valid recipes
        return [x for x in recipes if check_is_valid(x)]
