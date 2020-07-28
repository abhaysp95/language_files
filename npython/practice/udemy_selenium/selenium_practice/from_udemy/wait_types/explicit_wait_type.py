#!/usr/bin/env python3


'''
module for explicit wait type
'''

from traceback import print_stack
import importlib.util
spec = importlib.util.spec_from_file_location(
    "utilities.handy_wrapper",
    "../../utilities/handy_wrapper.py")  # supports rel and abs paths
handy_wrapper = importlib.util.module_from_spec(spec)
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import *


class TestHandyWrapper():
    '''class to test handy_wrapper'''

    def __init__(self, driver):
        print("begin testing")
        self.driver = driver
        self.hwm = handy_wrapper()

    def wait_for_elements(self, locator, locatortype=id,
                          timeout=10, p_frequency=0.5):
        '''
        method for element to wait
        :param1: give locator from DOM
        :param2: give locatortype, default is id
        :param3: provide timeout, default is 10 seconds
        :param4: give poll_frequency, default is 0.5 seconds
        '''
        try:
            element = None
            bytype = self.hwm.get_by_type(locatortype)
            print("Waiting for Maximum :: " + str(timeout) +
                  " :: seconds for element to be clickable")
            wait = WebDriverWait(
                self.driver,
                timeout,
                poll_frequency=p_frequency,
                ignored_exceptions=[
                    'NoSuchElementException',
                    'ElementNotVisibleException',
                    'ElementNotSelectableException'
                ]
            )
            element = wait.until(EC.element_to_be_clickable((bytype, locator)))
            print("Element appeared in the webpage")
        except:
            print("Element Not Found")
            print_stack()
        return element
