#!/usr/bin/env python3

'''
demonstrating implicit wait type
'''

from selenium import webdriver
from selenium.webdriver.common.by import By


class TestImplicit():
    '''test the implicit wait method'''

    def __init__(self, url):
        self.url = url
        print("Initializing operation")
        self.driver = webdriver.Firefox()
        print("Getting the first url provided")
        self.driver.get(self.url)
        # implicitly_wait automatic does polling
        self.driver.implicitly_wait(5)

    def get_to_login(self):
        '''go to login page'''
        login_link = self.driver.find_element(
            By.XPATH, "//a[@class='login']"
        )
        login_link.click()

    def login_password(self):
        '''enter text for login and password'''
        username = self.driver.find_element(
            By.XPATH, "//input[@id='email']"
        )
        username.send_keys("test-login")
        password = self.driver.find_element(
            By.XPATH, "//input[@id='passwd']"
        )
        password.send_keys("test-password")


def main():
    '''main function'''
    # try with another site, this site requires captcha
    url = "http://automationpractice.com/index.php"
    timp = TestImplicit(url)
    timp.get_to_login()
    timp.login_password()


if __name__ == "__main__":
    main()
