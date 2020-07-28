#!/usr/bin/env python3

'''
making a handy wrapper script for selenium practice
'''

from selenium import webdriver
from selenium.webdriver.common.by import By


class HandyWrappers():
    '''handy wrappers class'''

    def __init__(self, driver):
        self.driver = driver

    def get_by_type(self, locatortype):
        '''get element with different styles'''
        locatortype = locatortype.lower()
        if locatortype == 'id':
            return By.ID
        if locatortype == 'class_name':
            return By.CLASS_NAME
        if locatortype == 'tag_name':
            return By.TAG_NAME
        if locatortype == 'link_text':
            return By.LINK_TEXT
        if locatortype == 'partial_link_text':
            return By.PARTIAL_LINK_TEXT
        if locatortype == 'css_selector':
            return By.CSS_SELECTOR
        if locatortype == 'xpath':
            return By.XPATH
        if locatortype == 'name':
            return By.NAME
        return False

    def get_element(self, locator, locatortype='id'):
        '''
        get the element
        :param1: locator = give the name, class_name, xpath etc.
        :param2: locatortype = give the type of locator you are providing
        '''
        element = None
        try:
            locatortype = locatortype.lower()
            bytype = self.get_by_type(locatortype)
            element = self.driver.find_element(bytype, locator)
            print("Element found")
        except:
            print("Element not found")
        return element

    def iselementpresent(self, locator, locatortype='id'):
        '''check if element present'''
        bytype = self.get_by_type(locatortype)
        element = self.driver.find_element(bytype, locator)
        if element is not None:
            print("Element Present")
            return True
        print("Element Not Present")
        return False

    def elementpresencecheck(self, locator, locatortype='id'):
        '''checks for multiple elements'''
        bytype = self.get_by_type(locatortype)
        element_list = self.driver.find_elements(bytype, locator)
        if len(element_list) != 0:
            print("Element/s Present")
            return True
        print("Element/s Not Present")
        return False


if __name__ == "__main__":
    print("This file is meant to run as module")
