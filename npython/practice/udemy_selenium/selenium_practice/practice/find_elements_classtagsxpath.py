#!/usr/bin/env python3

'''
find element by class and tags
'''

from selenium import webdriver
from selenium.webdriver.common.by import By


class FindElements():

    def test(self, baseURL):
        driver = webdriver.Chrome()
        driver.get(baseURL)

        # difference is 's', link find_elements instead find_element
        elementlistbyclass = driver.find_elements_by_class_name("inputs")
        if elementlistbyclass is not None:
            print("Total 'inputs' class is/are: " + str(len(elementlistbyclass)))

        elementlistbyxpath = driver.find_elements(
            By.XPATH, "//input[@class='btn-style']")
        if elementlistbyxpath is not None:
            print("Total 'btn-style' class of input tag is/are: ", str(len(elementlistbyxpath)))

        elementlistbytag = driver.find_elements(By.TAG_NAME, "div")
        if elementlistbytag is not None:
            print("Total 'div' is/are: " + str(len(elementlistbytag)))


def main():
    element_found = FindElements()
    baseURL = "https://letskodeit.teachable.com/pages/practice"
    element_found.test(baseURL)


if __name__ == "__main__":
    main()
