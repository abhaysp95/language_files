#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-04-23
Description: music album, learning basics of function
Email: abhaysp9955@gmail.com
Last Edit: 2020-04-23
"""


# music_album function <<<
def make_album(artist_name, album_title, num_of_songs=None):
    '''function giving information for album'''
    album_info = {'name of artist': artist_name.title(),
                  'title of album': album_title.title()}

    # check for num of songs
    if num_of_songs:
        album_info['Number of Songs'] = num_of_songs
    return album_info
# >>>


# main function <<<
def main():
    '''Inside main function'''
    prompt = '> '

    while True:
        print('''Enter details for album:
        1. artist name
        2. album title
        3. num of songs(optional)''')
        print('Enter "q" to quit')
        artist = input(prompt)
        if artist == 'q':
            break
        album = input(prompt)
        if album == 'q':
            break

        print('To enter number of songs in album, press 1 else press 0',
              end='\n')
        num_songs = int(input(prompt))
        if num_songs == 1:
            num_songs = int(input(prompt))

        if num_songs != 0:
            all_info = make_album(artist, album, num_songs)
        else:
            all_info = make_album(artist, album)

        print('Info you entered is:\n', all_info, end='\n')

        # asking user again for iteration
        print('Do you want to enter for second artist/album\nTrue/False\n')
        choice = input(prompt)
        if choice == 'False':
            break
# >>>


if __name__ == "__main__":
    print(main.__doc__)
    main()
