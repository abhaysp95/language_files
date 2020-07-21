#!/usr/bin/env python3

'''
methods and elements for browser interactions
'''

from time import sleep
from selenium import webdriver


class BrowserInteraction():
    '''class for different browser interactions'''

    def __init__(self, url, sec_url):
        self.url = url
        self.sec_url = sec_url
        print("Initialziing test")

    def test(self):
        '''test method'''
        driver = webdriver.Firefox()

        # Window maximize
        driver.maximize_window()
        sleep(10)

        # open the url
        driver.get(self.url)

        # Get Title
        title = driver.title
        print("Title of page is: " + title)

        # Get current URL
        cur_url = driver.current_url
        print("Current URL is: " + cur_url)

        # Browser Refresh
        print("Refreshing Browser 1st time")
        driver.refresh()

        # Browser Refresh Again
        print("Browser refresh 2nd time")
        driver.get(driver.current_url)

        # Open another url
        print("Moving to second url")
        driver.get(self.sec_url)

        # Browse back
        print("Going back a step")
        driver.back()

        # Browse forward
        print("Coming forward a step")
        driver.forward()

        # Get page source
        pagesource = driver.page_source
        print("Len of pagesource is: ", len(pagesource))

        # driver.close()  # closes currently focuse
        driver.quit()  # closes all window


def main():
    '''main function'''
    furl = "https://letskodeit.com/"
    surl = "https://courses.letskodeit.com/courses/step-by-step-java-for-testers?coupon=FREECODE"
    first_method = BrowserInteraction(furl, surl)
    first_method.test()


if __name__ == "__main__":
    main()
