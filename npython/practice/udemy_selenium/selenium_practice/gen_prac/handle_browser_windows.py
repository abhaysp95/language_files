#!/usr/bin/env python3

'''
handle tabs and windows(old)
'''

from time import sleep
from selenium import webdriver

class TestTabWindows():


    def __init__(self, url):
        self.url = url
        self.driver = webdriver.Chrome()
        print("Testing tabs and windows functionality")

    def open(self):
        '''open the browser'''
        # implicit time to 30 seconds
        self.driver.implicitlyWait(30)
        # navigate to url
        self.driver.get(self.url)

        # get the Session id of the Parent
        parentGUID = self.driver.current_window_handle

        # click the button to open new window
        self.driver.find_element_by_id("two-window").click()
        sleep(8000);

        # get the ALL the session id of the browsers
        allGUID = self.driver.window_handles

        # print the title of the epage
        print("Page title before Switching: " + self.driver.getTitle())
        print("Total Windows: " + allGUID.size())

        # iterate the values in set
        for guid in allGUID:
            if guid != parentGUID:
                # switch to the guid
                self.driver.switch_to_window(guid)
                # break the loop
                break

        # search on google page
        self.driver.find_element_by_name("q").send_keys("success")
        # print the title after switching
        print("Page title after Switching to google: " + self.driver.getTitle())
        sleep(8000)
        # close the browser
        self.driver.close()  # closes the window
        # switch back to parent
        self.driver.switch_to_window(parentGUID)
        # print the title
        print("Page title after switching back to Parent: " + self.driver.getTitle())


if __name__ == "__main__":
    URL = "https://chercher.tech/python/windows-selenium-python"
    testing = TestTabWindows(URL)
    testing.open()
