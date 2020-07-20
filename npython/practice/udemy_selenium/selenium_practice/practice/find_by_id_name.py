#!/usr/bin/env python3

'''
finding element by name and id attributes
'''

from selenium import webdriver


class FindByIdName():
    '''class to find by id and name'''

    def test(self, baseURL):
        '''test method'''

        driver = webdriver.Chrome()  # driver is in PATH
        driver.get(baseURL)

        elementbyid = driver.find_element_by_id("name")
        # be careful of dynamic ids and attributes
        if elementbyid is not None:
            print("Found element by id ", elementbyid)

        elementbyname = driver.find_element_by_name("show-hide")
        if elementbyname is not None:
            print("Found element by name ", elementbyname)


def main():
    '''main function'''
    find_element = FindByIdName()
    baseURL = "https://letskodeit.teachable.com/pages/practice"
    find_element.test(baseURL)


if __name__ == "__main__":
    main()
