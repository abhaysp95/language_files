#!/usr/bin/env python3

'''
another example of handling multiple windows
'''

from selenium import webdriver


class MultipleWindows():
    '''class to see functions of multiple windows'''

    def __init__(self, url):
        self.url = url
        self.driver = webdriver.Firefox()
        self.driver.get(url)
        print("Initializing Test")

    def get_handle(self):
        '''get the size of window_handles'''
        self.driver.find_element_by_xpath(
            "//table//td//a").click()
# "//table//a[text()='python_log_parsing/']"

        # returns handles of all windows in current session
        handles = self.driver.window_handles
        size = len(handles)
        return size, handles

    def print_all_windows(self):
        '''print all the windows title'''
        size, handles = self.get_handle()
        print("Size is: ", size)
        print("Handles is: ", handles)
        for x in range(size):
            self.driver.switch_to.window(handles[x])  # the . here ain't error
            print('Title is: ', self.driver.title)
        # close the browser
        self.driver.close()


class MultipleWindows2(MultipleWindows):
    '''Another class getting title for all the windows except current one'''

    # I haven't understood this

    def get_handle(self):
        '''get the window handles'''
        self.driver.find_element_by_xpath(
            "//table//td//a").click()

        handles = self.driver.window_handles
        size = len(handles)
        return size, handles

    # nothing new here, wrt get_handle() method
    # but tried something so created this new method
    def print_all_except_current_window(self):
        '''get the title of all windows except current one'''
        size, handles = self.get_handle()
        print("Size is: ", size)
        print("Handles is/are: ", handles)
        for x in range(size):
            # match to the current window
            if handles[x] != self.driver.current_window_handle:
                self.driver.switch_to.window(handles[x])
                print("Title is/are: ", self.driver.title)
        # close the browser
        self.driver.close()


class MultipleWindows3(MultipleWindows):
    '''class to switch back-n-forth between child and parent'''

    def switch_back_n_forth(self):
        '''
        perform operation in child then close and then perform operation in
        parent
        '''
        parent_handle = self.driver.current_window_handle
        print("Parent handle is: ", parent_handle)
        size, handles = self.get_handle()
        for x in range(size):
            if handles[x] != parent_handle:
                # this isn't printing because it's the only window
                # maybe I didn't understood this properly yet(2020-07-21)
                self.driver.switch_to.windows(handles[x])
                print("Title of child: ", self.driver.title)
            break

        self.driver.switch_to.window(parent_handle)
        print("Switched back to parent_handle")
        print("Title of parent: ", self.driver.title)
        # close the browser
        self.driver.close()


def main():
    '''main function'''
    url = "http://localhost"

    # test = MultipleWindows(url)
    # test.print_all_windows()
    # test.print_all_windows()

    # test2 = MultipleWindows2(url)
    # test2.print_all_except_current_window()

    test3 = MultipleWindows3(url)
    test3.switch_back_n_forth()


if __name__ == "__main__":
    main()
