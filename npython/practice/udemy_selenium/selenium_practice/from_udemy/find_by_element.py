#!/usr/bin/env python3

'''
example of find element by giving attribute as argument
'''

from selenium import webdriver
from selenium.webdriver.common.by import By


class FindByElement():
    '''
    Attributes passed as parameters are
    ID
    XPATH
    LINK_TEXT
    PARTIAL_LINK_TEXT
    CLASS_NAME
    CSS_SELECTOR
    NAME
    TAG_NAME
    '''

    def test(self, baseURL):
        '''test method'''
        driver = webdriver.Chrome()
        driver.get(baseURL)

        findbyclass = driver.find_element(By.CLASS_NAME, "displayed-class")
        if findbyclass is not None:
            print("Found element by CLASS_NAME")

        findbyxpath = driver.find_element(By.XPATH, "//input[@id='name']")
        if findbyxpath is not None:
            print("Found element by XPATH")

        findbylinktext = driver.find_element(By.LINK_TEXT, "Practice")
        if findbylinktext is not None:
            print("Found element by LINK_TEXT")


def main():
    chrome_test = FindByElement()
    baseURL = "https://letskodeit.teachable.com/pages/practice"
    chrome_test.test(baseURL)


if __name__ == "__main__":
    main()
