#!/usr/bin/env python3

from selenium import webdriver


def test(url):
    '''test function'''
    driver = webdriver.Firefox()
    driver.get(url)
    elements = driver.find_elements_by_xpath(
        "//div[@class='row']")[6]
    print(elements.text)
    email, passkey = elements.text.split('\n')
    print('email: ', email.split(' ')[1])
    print('passkey: ', passkey.split(' ')[1])
    print(email.split(' ')[1])
    print(passkey.split(' ')[1])

def test1(url):
    '''another test function'''
    driver = webdriver.Firefox()
    driver.get(url)
    element = driver.find_element_by_xpath(
        "//div[@class='row']"
    )
    print(element.text)


if __name__ == "__main__":
    url = "https://phptravels.com/demo/"
    test(url)
