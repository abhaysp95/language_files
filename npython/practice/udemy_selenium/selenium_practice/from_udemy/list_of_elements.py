#!/usr/bin/env python3

from time import sleep
from selenium import webdriver
from selenium.webdriver.common.by import By


class testListOfElements():
    '''class to demonstrate usage on list of elements'''

    def __init__(self, url):
        self.url = url
        print("Initializing Operation")
        self.driver = webdriver.Firefox()
        print("Getting the page")
        self.driver.get(self.url)

    def select_some_check_boxes(self):
        '''select some checkboxes'''
        bmwcheck = self.driver.find_element_by_id("bmwcheck")
        bmwcheck.click()
        hondacheck = self.driver.find_element_by_id("hondacheck")
        hondacheck.click()

    def get_the_list(self, xpath):
        '''get the list based on the given xpath'''
        elements = self.driver.find_elements(
            By.XPATH, xpath
        )
        return elements

    def if_not_selected(self, xpath):
        '''if not selected do following'''
        elements = self.get_the_list(xpath)
        for element in elements:
            name = element.get_attribute('value')
            if not element.is_selected():
                print(f"Element {name} not selected, selecting now")
                element.click()
                sleep(2)  # give time for user to select(testing purpose)
            else:
                # this will happen if user selects something in middle
                print(f"Element {name} already selected")


def main():
    '''main function'''
    url = "https://letskodeit.teachable.com/pages/practice"
    ele_lists = testListOfElements(url)
    print("Test for radio buttons")
    xpath = "//input[contains(@name, 'cars') and contains(@type, 'radio')]"
    ele_lists.if_not_selected(xpath)
    print("Test for checkboxes")
    ele_lists.select_some_check_boxes()
    xpath = "//input[contains(@name, 'cars') and contains(@type, 'checkbox')]"
    ele_lists.if_not_selected(xpath)


if __name__ == "__main__":
    main()
