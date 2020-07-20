#!/usr/bin/env python3

'''
find element by class and tags
'''

from time import time
from time import sleep
from selenium import webdriver


class FindByClassTags():

    def test(self, baseURL):
        driver = webdriver.Chrome()
        driver.get(baseURL)

        start_time = time()
        # only one class can be passed
        elementbyclass = driver.find_element_by_class_name('displayed-class')
        # if multiple class of same name found then first one will be used
        elementbyclass.send_keys("This is name")
        if elementbyclass is not None:
            print("Found element by class")
        print("For class ", time() - start_time, "seconds")

        start_time = time()
        elementbytag = driver.find_element_by_tag_name('a')  # anchor tag
        print("Found element tag ", elementbytag)
        if elementbytag is not None:
            print("Found element by anchor tag")
        print("For tags %s seconds" % (time() - start_time))

        print("\nPrinting h1: ", driver.find_element_by_tag_name('h1').text)
        sleep(30)


def main():
    element_found = FindByClassTags()
    baseURL = "https://letskodeit.teachable.com/pages/practice"
    element_found.test(baseURL)


if __name__ == "__main__":
    main()
