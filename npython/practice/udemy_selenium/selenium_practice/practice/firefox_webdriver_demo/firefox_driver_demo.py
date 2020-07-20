#!/usr/bin/env python3

'''
a demo to show selenium work with geckodriver
'''

from os import path
from selenium import webdriver


class RunFTest():
    '''basic test of geckodriver with Firefox'''
    home = path.expanduser("~")
    driver_path = "/Documents/npython/drivers/geckodriver"

    def __init__(self):
        self.driver = None
        print("Initiating geckodriver test")

    def testpath(self):
        '''test self'''
        print(self.home + self.driver_path)

    def testmethod(self):
        '''test method for geckodriver'''
        # instantiate FF Browser Control
        self.driver = webdriver.Firefox(
            executable_path=self.home + self.driver_path
        )
        # get the provided URL
        self.driver.get("http://www.letskodeit.com")

    def close_ff(self):
        '''close the browser'''
        # you can also use close() if there's only one browser window running
        self.driver.quit()  # close the browser


def main():
    '''main function'''
    fftest = RunFTest()
    # fftest.testpath()
    fftest.testmethod()  # geckodriver doesn't closes the Firefox, when
    # object is destroyed by python(task if finished)
    fftest.close_ff()


if __name__ == "__main__":
    main()
