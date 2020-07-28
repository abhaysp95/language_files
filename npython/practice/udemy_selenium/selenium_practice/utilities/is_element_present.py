#!/usr/bin/env python3

'''
check if element/s present or not using handy_wrapper
'''

from selenium import webdriver
from handy_wrapper import HandyWrappers


class ElementPresenceCheck():
    '''check for element presence'''

    def __init__(self, url):
        self.url = url
        print("Initializing operation")
        self.driver = webdriver.Firefox()
        self.hw_driver = HandyWrappers(self.driver)
        print("Getting the page")
        self.driver.get(self.url)
        self.driver.implicitly_wait(10)

    def test_presence(self):
        '''method to test the presence of element'''
        result1 = self.hw_driver.iselementpresent("name")
        print(str(result1))

        result2 = self.hw_driver.elementpresencecheck(
            # this type of xpath build is dynamic xpath, just like the strings
            "//input[@type='{0}']".format('abcdef'), 'xpath'
            # intentionally provided wrong
        )
        print(str(result2))


def main():
    '''main function'''
    url = "https://letskodeit.teachable.com/pages/practice"
    ele_presence = ElementPresenceCheck(url)
    ele_presence.test_presence()


if __name__ == "__main__":
    main()
