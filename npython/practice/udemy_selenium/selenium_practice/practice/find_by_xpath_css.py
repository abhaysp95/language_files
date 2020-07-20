#!/usr/bin/env python3

'''
example for finding element by xpath and css
'''

from selenium import webdriver


class FindByXpathCss():
    '''class to find elements'''

    def test(self, baseURL):
        '''test method'''

        driver = webdriver.Firefox()  # geckodriver on PATH
        driver.get(baseURL)

        elementbyxpath = driver.find_element_by_xpath("//input[@id='name']")
        if elementbyxpath is not None:
            print("Found element by xpath")

        elementbycss = driver.find_element_by_css_selector("#displayed-text")
        if elementbycss is not None:
            print("Found element by css")


def main():
    baseURL = "https://letskodeit.teachable.com/pages/practice"
    find_element = FindByXpathCss()
    find_element.test(baseURL)


if __name__ == "__main__":
    main()
