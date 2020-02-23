#!/usr/bin/env sh

# Author: Abhay Shanker Pathak
# Date: 2020-02-23
# Description: testing music
# Email: abhaysp9955@gmail.com
# Github: https://github.com/CoolAbhayS
# Last Edited: 2020-02-23

if pidof mpd; then
	mpc toggle && notify-send --icon=audio-headphones -t 3000 "Music played/paused\nCurrent Song" "$(mpc | head -1)"
else
	cmus-remote -u && notify-send --icon=audio-headphones -t 3000 "Music played/paused\nCurrent Song" "$(cmus-remote -Q | head -n 2 | grep file | cut -c 22-)"
fi
