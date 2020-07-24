#!/usr/bin/env python3

'''
basic clicking and writing stuff
'''

from time import sleep
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys


class ClickAndSendKeys():
    '''basic click and write stuff'''

    def __init__(self, url):
        self.url = url
        self.email = None
        self.passkey = None
        self.email_field = None
        self.pass_field = None
        self.driver = webdriver.Firefox()
        print("Initializing process")
        self.driver.implicitly_wait(10)
        # cause all the elements in page not load at the same time

    def get_email_password(self):
        '''get the email and password from demo site'''
        print("Getting URL")
        self.driver.get(self.url)
        print("Getting Element")
        elements = self.driver.find_elements_by_xpath(
            "//div[@class='row']")[6]  # find more about subscripting with
        # webdriver
        self.email, self.passkey = elements.text.split('\n')
        print("Email Split")
        self.email = self.email.split(' ')[1]
        print("Password Split")
        self.passkey = self.passkey.split(' ')[1]
        print("Got Email: ", self.email)
        print("Got Password: ", self.passkey)

    def goto_login_page(self):
        '''press the login and goto login page'''
        self.driver.get(self.url)
        loginlink = self.driver.find_element(
            By.XPATH, "//a[@href='//www.phptravels.net']")
# By.XPATH, "//a[contains(text(), 'http://www.phptravels.net')]")
# By.XPATH, "//div[@id='navbar']//a[@href='/sign_in']")
# loginlink.send_keys("Hello" + Keys.RETURN)  # to write and press enter
        loginlink.click()
        print("Login link clicked")
# worked till here

    def get_to_login(self):
        '''click the login'''
        login_button = self.driver.find_element(
            By.XPATH, "//div[contains(@class, 'dropdown')]//a[text()='Login']")
        print("Login button clicked")
        login_button.click()

    def write_email_password(self):
        '''write email and password in there respective fields'''
        self.email_field = self.driver.find_element(
            By.XPATH, "//div[@class='form-group']//input[@type='email']")
        self.email_field.send_keys(self.email)
        print("Email Entered")
        self.pass_field = self.driver.find_element(
            By.XPATH, "//div[@class='form-group']//input[@type='password']")
        self.pass_field.send_keys(self.passkey)
        print("Password Entered")

    # work still left, will complete when I'll learn about handling
    # multiple tabs and windows


def main():
    '''main function'''
    url = "https://phptravels.com/demo/"
    csproc = ClickAndSendKeys(url)
    csproc.get_email_password()
    csproc.goto_login_page()
    csproc.get_to_login()
    csproc.write_email_password()


if __name__ == "__main__":
    main()

# def write_email_password(self):
# '''write to email and password field'''
# self.driver.implicitly_wait(30)
# print("Current URL is: " + self.driver.current_url)
# self.email_field = self.driver.find_element(
# By.ID, "user_email")
# self.email_field.send_keys("thisisemail@valid.in")
# self.pass_field = self.driver.find_element(
# By.ID, "user_password")
# print("Current URL is: " + self.driver.current_url)
# self.pass_field.send_keys("ThisIsAValidPassword")

# def clear_and_send_again(self):
# '''clear the fields and write again'''
# sleep(3)  # give a bit wait
# if not hasattr(ClickAndSendKeys, self.email_field):
# raise AttributeError("Attribute self.email_field not found")
# if not hasattr(ClickAndSendKeys, self.pass_field):
# raise AttributeError("Attribute self.pass_field not found")
# print("Clearing the fields")
# self.email_field.clear()
# sleep(1)  # enjoy the process
# self.pass_field.clear()
# sleep(1)
# print("Writing email and password again")
# write again
# self.write_email_password()
