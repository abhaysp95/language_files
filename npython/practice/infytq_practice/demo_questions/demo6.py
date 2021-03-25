#!/usr/bin/env python3

class Team:
    def __init__(self, name=None):
        self.name = name  #  added for checking(not in question)
        self.no_of_players = 1
        self.coach = None

cricket_team = Team("C")  # line 1
football_team = Team("F")
hockey_team = football_team
football_team = cricket_team
football_team = Team("H")
cricket_team=hockey_team  # line 2

# how many reference variable(s) refer to the object created in line1 at the end of line2

print(cricket_team.name)
print(football_team.name)
print(hockey_team.name)

# ans. 0

# no, C in output
