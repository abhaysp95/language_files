#!/usr/bin/env python3

'''
selecting radio buttons and check boxes
'''

from time import sleep
from selenium import webdriver


class RadioButtonsAndCheckBoxes():
    '''click radio buttons and check boxes'''

    def __init__(self, url):
        self.url = url
        self.flag = False
        self.btn_state = dict()
        print("Initializing the Operation")
        print("To get the state whether isselected or not, enable flag")
        self.driver = webdriver.Firefox()
        print("Getting the page")
        self.driver.get(self.url)
        self.driver.implicitly_wait(20)

    def click_button_boxes(self, element_id, ret):
        '''
        using elements id to click buttons and boxes
        :param: element_id = pass an element_id as string
        '''
        element = self.driver.find_element_by_id(element_id)
        element.click()
        print("Clicked => ", element_id)
        sleep(1)  # let time do the magic
        if self.flag:
            self.btn_state[element_id] = element.is_selected()
        if ret:
            return element

    def print_state_list(self):
        '''print the state list'''
        for key, value in self.btn_state.items():
            print("{}: {}".format(key, value))

    # this will only return True as recorded when it was selected
    def isselected(self, element_id):
        '''
        like the other DOM elements have 'isenabled' property,
        checkboxes and radiobuttons have 'isselected' property
        '''
        # this way, I don't have to find_element_by_id again
        state = self.btn_state[element_id]
        if state:
            string = "Selected"
        else:
            string = "Not Selected"
        print("State of element_id => ", string)

    def is_currently_selected(self, element_id):
        '''currently button selected or not'''
        element = self.click_button_boxes(element_id, True)
        state = element.is_selected()
        if state:
            string = "Selected"
        else:
            string = "Not Selected"
        print("State of element_id => ", string)


def main():
    '''main function'''
    url = "https://letskodeit.teachable.com/pages/practice"
    bbox = RadioButtonsAndCheckBoxes(url)
    ids = [
        'bmwradio',
        'hondacheck',
        'benzradio',
        'benzcheck',
        'hondaradio',
        'bmwcheck'
    ]
    # bbox.flag = True  # to get the state list
    for id in ids:
        bbox.click_button_boxes(id)
    # print("State list: ")
    # print(bbox.btn_state)
    # bbox.print_state_list()
    print("Getting the selection state")
    # if you want specific element from the list of ids,
    # else use the print_state_list() method
    # or just print btn_state attr from RadioButtonsAndCheckBoxes class
    for id in ids:
        bbox.is_currently_selected(id)


if __name__ == "__main__":
    main()
