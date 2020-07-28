#!/usr/bin/env python3

'''
checking out the handy wrapper script
'''

from time import sleep
from sys import exit
from selenium import webdriver
from selenium.webdriver.common.by import By
from handy_wrapper import HandyWrappers


class UsingWrappers():
    '''class to test out demo wrapper'''

    def __init__(self, url):
        self.url = url
        print("Initializing operation")
        self.driver = webdriver.Firefox()
        self.hw_driver = HandyWrappers(self.driver)
        print("getting the page")
        self.driver.get(self.url)

    def test_with_read_clear(self):
        '''test with send_text and clear'''
        textfield = self.hw_driver.get_element('name')
        try:
            textfield.send_keys("Hello, this is bot")
        except AttributeError:
            print("Element not found, exiting")
            exit()

        # clear the alert button
        try:
            textfield2 = self.hw_driver.get_element(
                "//input[@type='text']", 'xpath'
            )
            textfield2.click()
        except AttributeError:
            print("Element not found, exiting")
            exit()
        sleep(3)

        textfield2.clear()  # clear the textfield


def main():
    '''main function'''
    url = "https://letskodeit.teachable.com/pages/practice"
    wrap = UsingWrappers(url)
    wrap.test_with_read_clear()


if __name__ == "__main__":
    main()
