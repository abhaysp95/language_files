#!/usr/bin/env python3

'''
to find by linktext and partial linktext
'''

from selenium import webdriver


class FindByLinkText():

    def test(self, baseURL):
        driver = webdriver.Chrome()
        driver.get(baseURL)

        elementlinktext = driver.find_element_by_link_text("Login")
        if elementlinktext is not None:
            print("Got element by link text")

        # full anchor name is Practice
        elementpartialinktext = driver.find_element_by_partial_link_text('Prac')
        if elementpartialinktext is not None:
            print("Got element by partial link text")


def main():
    element_find = FindByLinkText()
    baseURL = "https://letskodeit.teachable.com/pages/practice"
    element_find.test(baseURL)


if __name__ == "__main__":
    main()
