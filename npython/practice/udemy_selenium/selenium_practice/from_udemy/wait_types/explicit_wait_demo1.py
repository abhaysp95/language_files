#!/usr/bin/env python3

'''
demonstration of explicit wait, making verbose just to track errors
'''

# still left

from time import sleep
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import *
from explicit_wait_type import TestHandyWrapper


class TestExplicit():
    '''class to test explicit wait'''

    def __init__(self, url):
        self.url = url
        print("Initializing Operation")
        self.driver = webdriver.Firefox()
        print("Getting the page")
        self.driver.get(self.url)
        self.driver.implicitly_wait(0.5)

    def move_to_flights(self):
        '''move to the flights tab'''
        flight_tab = self.driver.find_element(
            By.XPATH, "//span[contains(text(),'Flights')]"
        )
        print("Moved to flight tab")
        flight_tab.click()
        print("Flight tab clicked")

    def fill_entries(self):
        '''fill the required entries and click search'''
        # from
        self.driver.find_element(
            By.XPATH, "//input[@id='flight-origin-hp-flight']"
        ).send_keys("NYC")
        print("Destination From filled")
        sleep(1.5)
        # to
        self.driver.find_element(
            By.XPATH, "//input[@id='flight-destination-hp-flight']"
        ).send_keys("SFO")
        print("Destination To filled")
        sleep(1.5)
        # departure date
        self.driver.find_element(
            By.XPATH, "//input[@id='flight-departing-hp-flight']"
        ).send_keys("07/30/2020")
        print("Departure date filled")
        sleep(1.5)
        return_date = self.driver.find_element(
            By.XPATH, "//input[@id='flight-returning-hp-flight']"
        )
        return_date.clear()
        print("Return Date Clear")
        sleep(1.5)
        return_date.send_keys("08/08/2020")
        print("Arrival date filled")
        sleep(1.5)
        # click search
        self.driver.find_element(
            By.XPATH, "//form[@id='gcw-flights-form-hp-flight']//button[@class='btn-primary btn-action gcw-submit']"
        ).click()

    def find_ele_with_wait(self):
        '''explicit wait'''
        thw = TestHandyWrapper(self.driver)
        element = thw.wait_for_elements(
            "//input[@id='stopFilter_stops-0']",
            'xpath'
        )
        return element

    def check_nonstop(self):
        '''check the non-stop checkbox'''
        # self.driver.find_element(
        # By.XPATH, "//input[@id='stopFilter_stops-0']"
        # ).click()
        # detail about it
        element = self.find_ele_with_wait()
        element.click()
        nonstop = self.driver.find_element(
            By.XPATH, "//span[@id='Nonstop-stop-flights-checkbox']"
        )
        print("Detail: " + nonstop.text)


def main():
    '''main function'''
    url = "https://expedia.com"
    texp = TestExplicit(url)
    texp.move_to_flights()
    texp.fill_entries()
    texp.check_nonstop()
    texp.driver.close()


if __name__ == "__main__":
    main()
