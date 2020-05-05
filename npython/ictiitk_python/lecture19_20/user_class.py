#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-29
Description: User Class storing and getting details of user
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-29
"""

from datetime import datetime


# user class <<<
class User:
    '''Specifying information about user'''
    def __init__(self, user_name, home_dir, login_time, logout_itme):
        '''creating method for various information on user'''
        self.hostname = "server"
        self.name = user_name
        self.home_folder = home_dir
        self.login = login_time
        self.logout = logout_itme
        self.attempt_nums = 0

    def describe_user(self):
        '''Giving details of user'''
        print(f"User's name is {(self.name).title()}.")
        if self.home_folder != 'no':
            print(f"User's home folder exist at /home/{self.name}")
        print("Login time of user is ", self.login)
        print("Logout time of user is ", self.logout)

    def greet_user(self):
        '''Greeting user according to the system time'''
        current_hour = datetime.today().time().hour
        if 0 <= current_hour <= 12:
            print("Hello, ", self.name, " Very Good Moring")
        elif 12 < current_hour <= 4:
            print("Hello, ", self.name, " Good Afternoon")
        else:
            print("Hello ", self.name, " Good Evening")

    def login_attempts(self):
        '''Increment login attempts by one'''
        self.attempt_nums += 1

    def reset_login_attempts(self):
        '''Reset the login attempts'''
        self.attempt_nums = 0
# >>>


class Admin_User(User):
    '''Admin class inheriting User class'''
    def __init__(self, user_name, home_dir, login_time, logout_itme,
                 get_privilege):
        super().__init__(user_name, home_dir, login_time, logout_itme)
        self.get_privilege = Priviliges(get_privilege)


class Priviliges():
    def __init__(self, privilege):
        self.privilege = privilege

    def show_privileges(self):
        print(f"User has privilage to {self.privilege}")


# main class <<<
def main():
    '''Entering in main class'''
    first_user = User('abhay', 'yes', '12.00', '16.00')
    second_user = User('thor', 'no', '2:00', '5:00')
    third_user = Admin_User('Captain', 'yes',
                            '12:00', '4:00', 'can command other users')

    first_user.greet_user()
    first_user.describe_user()

    print("Number of attempts: ", first_user.attempt_nums)
    first_user.login_attempts()
    print("Number of attempts: ", first_user.attempt_nums)
    first_user.login_attempts()
    print("Number of attempts: ", first_user.attempt_nums)
    first_user.login_attempts()
    print("Number of attempts: ", first_user.attempt_nums)
    print("Resetting login attempts", end='\n')
    first_user.reset_login_attempts()
    print("Number of attempts: ", first_user.attempt_nums)

    print()

    second_user.greet_user()
    second_user.describe_user()

    print("Number of attempts: ", second_user.attempt_nums)
    second_user.login_attempts()
    print("Number of attempts: ", second_user.attempt_nums)
    second_user.login_attempts()
    print("Number of attempts: ", second_user.attempt_nums)
    second_user.login_attempts()
    print("Number of attempts: ", second_user.attempt_nums)
    print("Resetting login attempts", end='\n')
    second_user.reset_login_attempts()
    print("Number of attempts: ", second_user.attempt_nums)

    third_user.greet_user()
    third_user.describe_user()

    print("Number of attempts: ", third_user.attempt_nums)
    third_user.login_attempts()
    print("Number of attempts: ", third_user.attempt_nums)
    third_user.login_attempts()
    print("Number of attempts: ", third_user.attempt_nums)
    third_user.login_attempts()
    print("Number of attempts: ", third_user.attempt_nums)
    print("Resetting login attempts", end='\n')
    third_user.reset_login_attempts()
    print("Number of attempts: ", third_user.attempt_nums)
    print(third_user.get_privilege.show_privileges())
# >>>


if __name__ == "__main__":
    main()
