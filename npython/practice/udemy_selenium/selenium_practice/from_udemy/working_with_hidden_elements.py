#!/usr/bin/env python3

'''
working with hidden elements in DOM
'''

from time import sleep
from selenium import webdriver


class WorkingWithHiddenElements():
    '''to test different hidden elements of DOM'''

    def __init__(self, url):
        self.url = url
        print("Initializing Operation")
        self.driver = webdriver.Firefox()
        print("Opening the page")
        self.driver.get(self.url)
        self.driver.implicitly_wait(10)

    def test_website(self, cond=None):
        '''test hidden element from letskodeit'''
        print("Getting state of text box")
        # get hidden_box state
        hidden_box = self.driver.find_element_by_id(
            "displayed-text")
        hidden_box_state = hidden_box.is_displayed()
        if cond is not None:
            return str(hidden_box_state)
        print("State of the text box is: " + str(
            hidden_box_state
        ))
        return None

    def click_hide_button(self):
        '''click the hide button and find element state'''
        # click button
        self.driver.find_element_by_id(
            "hide-textbox"
        ).click()
        # get box state
        box_state = self.test_website('test')
        print("Current state of box is: " + box_state)
        sleep(2)

    def click_show_button(self):
        '''click the show button and get the state of box'''
        # click button
        self.driver.find_element_by_id(
            "show-textbox"
        ).click()
        # get box state
        box_state = self.test_website('test')
        print("Current state of box is: " + box_state)
        sleep(2)

    def close_the_browser(self):
        '''close the browser'''
        print("Closing the browser")
        self.driver.quit()


class WorkingWithHiddenElements2():
    '''Another example site to get the hidden element'''
    # actually element in this DOM we are looking is not hidden,
    # but doesn't exist if not selected from certain dropdown

    def __init__(self, url):
        self.url = url
        print("Initializing Operation")
        self.driver = webdriver.Firefox()
        print("Getting the page:")
        self.driver.get(self.url)
        self.driver.implicitly_wait(10)

    def move_to_the_position(self):
        '''move to the desired postion'''
        self.driver.find_element_by_id(
            "tab-flight-tab-hp"  # wrong element as last tested
        ).click()

    def check_state(self, cond=None):
        '''check the state of the dropdown item we want'''
        age_dropdown = self.driver.find_element_by_xpath(
            "//select[@id='flight-age-select-1-hp-flight']"
        )[0]
        age_dropdown_state = age_dropdown.is_displayed()
        if cond is not None:
            return age_dropdown_state
        print("Current state of age-dropdown is: " + str(
            age_dropdown_state
        ))
        return None

    def make_age_dropdown_show(self):
        '''progress through the path to make age dropdown show'''
        # click the Travelers dropdown
        self.driver.find_element_by_xpath(
            "//li//button[@data-gcw-component='gcw-traveler-amount-select']"
        )[0].click()
        # select the number for child
        self.driver.find_element_by_xpath(
            "//div[@id='traveler-selector-hp-flight']/div/ul/li//div[1]/div[4]/button/span[1]"
        )[0].click()
        get_state = self.check_state('check')
        print("Current state of age-dropdown is: " + str(
            get_state
        ))

    def close_the_browser(self):
        '''close the browser'''
        print("Closing the browser")
        self.driver.quit()


def main():
    '''main function'''
    site_url = "https://letskodeit.teachable.com/pages/practice"
    letskodeit = WorkingWithHiddenElements(site_url)
    # change the url instance of class
    # letskodeit.url = site_url
    letskodeit.test_website()  # get the state first
    letskodeit.click_hide_button()
    letskodeit.click_show_button()
    letskodeit.close_the_browser()

    # another example
    site_url = "https://www.expedia.com"
    expedia = WorkingWithHiddenElements2(site_url)
    expedia.move_to_the_position()
    expedia.check_state()  # get the initial state
    expedia.make_age_dropdown_show()
    expedia.close_the_browser()


if __name__ == "__main__":
    main()
