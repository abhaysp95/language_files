#!/usr/bin/env python3

'''
demonstration of selenium feature for select
'''

from time import sleep
from selenium import webdriver
from selenium.webdriver.support.select import Select


class dropDownSelect():
    '''feature for drop down'''

    def __init__(self, url):
        self.url = url
        print("Initializing Operation")
        self.driver = webdriver.Firefox()
        print("Getting page")
        self.driver.get(self.url)

    def test(self):
        '''testing feature for Select'''
        element = self.driver.find_element_by_id("carselect")
        sel = Select(element)  # only works with "select" tag
        # these select tags can have "option" tag as child
        # don't get fooled by seeing a dropdown visually, check it's xpath

        print("Select Benz by value")
        sel.select_by_value('benz')
        sleep(2)

        print("Select Honda by index")
        sel.select_by_index('2')
        sleep(2)

        print("Select BMW by visible text")
        sel.select_by_visible_text('BMW')
        sleep(2)

        print("Select Honda by index(another method)")
        sel.select_by_index(2)
        sleep(2)


def main():
    '''main function'''
    url = 'https://letskodeit.teachable.com/pages/practice'
    ddown = dropDownSelect(url)
    ddown.test()


if __name__ == "__main__":
    main()
