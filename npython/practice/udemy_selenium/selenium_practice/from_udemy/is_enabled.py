#!/usr/bin/env python3

'''
check whether the DOM element is enabled or not
'''

from selenium import webdriver
from selenium.webdriver.common.keys import Keys


class ElementState():
    '''performs operation on given element state'''

    def __init__(self, url):
        '''initializing operation'''
        self.url = url
        self.driver = webdriver.Firefox()
        self.element = None
        print("Initializing Operation")
        self.driver.get(url)

    def isEnabled(self, element_id):
        '''returs the element state'''
        self.element = self.driver.find_element_by_id(element_id)
        # DOM elements having attribute of "disabled" are disabled
        state = self.element.is_enabled()
        return state

    def do_operation(self, element_id):
        '''performing operation'''
        get_state = self.isEnabled(element_id)
        print("Id {} has state => {}".format(id, get_state))
        if get_state:
            print("Sending keys")
            self.element.send_keys("element successful" + Keys.RETURN)
        else:
            print("Not performing any operation")


def main():
    '''main function'''
    url = "https://www.bing.com/"
    test_state = ElementState(url)
    test_state.do_operation('sb_form_q')


if __name__ == "__main__":
    main()
