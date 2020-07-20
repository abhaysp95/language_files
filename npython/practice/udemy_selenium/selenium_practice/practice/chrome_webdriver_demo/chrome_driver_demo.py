#!/usr/bin/env python3

'''
small program to test chromedriver
'''

from os import path
from time import sleep
from selenium import webdriver


class ChromeDriverTest():
    '''class to test chromedriver'''

    home = path.expanduser('~')
    driver_path = "/Documents/npython/drivers/chromedriver"

    def __init__(self):
        print("Initializing ChromeDriver test")

    def test_chrome(self):
        '''test method'''
        # Initialization of chrome browser command
        # put drivers in executable_path(like /usr/loca/bin) if not want
        # to give executable_path everytime
        driver = webdriver.Chrome(
            executable_path=self.home + self.driver_path
        )
        # get url
        driver.get("http://letskodeit.com")

        # if you want you browser opened(you can use as funtion instead of
        # object) or
        sleep(30)  # will keep open for 30 secs


def main():
    '''main function'''
    ctest = ChromeDriverTest()
    # as soon as python destroys the object, chrome/chromium will also quit
    ctest.test_chrome()


if __name__ == "__main__":
    main()
