#!/usr/bin/env python3

'''
If you want to reuse a piece of code that you wrote which expects a file object but it happens to be on the interweb
'''

import urllib

url_file = urllib.urlopen("http://docs.python.org/lib/module-urllib.html")
urllib_docs = url_file.read()

url_file.close()

print(len(urllib_docs))
print(urllib_docs[:80])
print(urllib_docs[-80:])
