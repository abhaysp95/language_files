#!/usr/bin/env python3

'''
get price of the python course
'''

from selenium import webdriver


class GetPrice():
    '''get the price'''

    def __init__(self, url):
        print("Getting Price")
        self.url = url

    # def get_url(self, url):
        # '''sets the url'''
        # return url

    def give_price(self):
        '''returns the price'''
        driver = webdriver.Chrome()
        driver.get(self.url)

        price_is = driver.find_element_by_xpath(
            "//div[@class='small course-price']")

        return price_is.text


class GetAnotherPrice(GetPrice):
    '''get the price from another website'''

    def give_price(self):
        '''returns the price'''
        # super(GetAnotherPrice, self).give_price()
        driver = webdriver.Chrome()
        driver.get(self.url)

        price_is = driver.find_element_by_xpath(
            "//table[@id='product']//td[text()='Python Programming Language']//following-sibling::td")
# "//table[@id='product']//tr[3]//td[3]")

        return price_is.text


class GetBalance():
    '''get the balance'''

    def __init__(self, url):
        self.url = url
        print('Getting the balance')
        self.driver = webdriver.Chrome()
        self.driver.get(url)

    def get_name(self, name):
        '''match the name'''
        get_name = self.driver.find_element_by_xpath(
            "//div[text()='Catherine Johnson']"
        )
        return name == get_name.text

    def get_balance(self, name):
        '''get the balance'''
        if self.get_name(name):
            get_balance = self.driver.find_element_by_xpath(
                # something is wrong with this xpath
                "//div[text()='Catherine Johnson']//parent::div//following-sibling::div[4]//div")
# "//div[text()='Catherine Johnson']//parent::div//following-sibling::div"
# //following-sibling::div[4]//div"
            get_balance = get_balance.text
        else:
            print("Name Mismatched or Balance Not entered")
            get_balance = None
        return get_balance


def main():
    '''main function'''
    url = "https://learn.letskodeit.com/"
    python_price1 = GetPrice(url)
    print("Price is: ", python_price1.give_price())

    url = "https://letskodeit.teachable.com/p/practice"
    python_price2 = GetAnotherPrice(url)
    print("Price is: ", python_price2.give_price())

    url = "https://dhtmlx.com/docs/products/dhtmlxGrid/"
    balance_price = GetBalance(url)
    balance_is = balance_price.get_balance('Catherine Johnson')
    print("Balance is: ", balance_is)


if __name__ == "__main__":
    main()
