#!/usr/bin/env python3

'''
Get text and value of elements attribute
'''

from selenium import webdriver
from selenium.webdriver.common.by import By


class GetTextAndValue():
    '''class to get text and value of elements attribute'''

    def __init__(self, url):
        self.url = url
        print("Initializing Operation")
        self.driver = webdriver.Firefox()
        print("Getting web page")
        self.driver.get(self.url)
        self.driver.implicitly_wait(10)

    def get_text(self):
        '''get text'''
        element = self.driver.find_element(By.TAG_NAME, 'h1')
        text = element.text
        # another way
        # text = element.get_attribute("innerText")
        # innerText is the attribute from js, which provides text of tag
        print("Text for h1 is: " + text)

    def get_value(self):
        '''get value of element'''
        # you can get value of any attribute AIK, in the given tag
        element = self.driver.find_element(
            By.XPATH, "//input[@id='displayed-text']"
        )
        placeholder = element.get_attribute('placeholder')
        print("Placeholder for textbox is: " + placeholder)

        print("Another value example ")

        element = self.driver.find_element(By.ID, 'hide-textbox')
        btn_value = element.get_attribute('value')
        print("Value of hide button is: " + btn_value)


def main():
    '''main function'''
    url = "https://letskodeit.teachable.com/pages/practice"
    text_and_value = GetTextAndValue(url)
    text_and_value.get_text()
    text_and_value.get_value()


if __name__ == "__main__":
    main()
