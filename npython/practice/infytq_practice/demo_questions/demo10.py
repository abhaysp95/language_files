#!/usr/bin/env python3

class InvalidSkillException(Exception):
    pass

class Educator:
    total_allocation = 101
    def __init__(self, skill):
        self.__skill = skill

    def validate_skill(self, skill_required):
        if (skill_required == self.__skill):
            Educator.total_allocation += 1
            return True
        else:
            raise InvalidSkillException

class ClassRoom:
    def __init__(self, educator):
        self.__educator = educator
        self.class_room_no = None

    def allocate_educator(self, skill_required, class_room_no):
        try:
            if (self.__educator.validate_skill(skill_required)):
                self.class_room_no = class_room_no
        except Exception:
            print("Something Wrong")
        except InvalidSkillException:
            Educator.total_allocation -= 1
            print("Invalid Skill")

edu = Educator("Java")
class_room1 = ClassRoom(edu)
class_room1.allocate_educator("Java", "L2-73")
class_room2 = ClassRoom(edu)
class_room1.allocate_educator("C++", "L1-75")
print(class_room1.class_room_no, class_room2.class_room_no)
print(Educator.total_allocation)
