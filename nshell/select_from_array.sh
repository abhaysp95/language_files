#!/usr/bin/env sh

PS3="Select your distro: "

menu_from_array () {
	select item; do
		echo "$REPLY"
		# check the selected menu item number
		if [ 1 -le "$REPLY" ] && [ "$REPLY" -le "$#" ]; then
			echo "The selected operating system is $item"
			break
		else
			echo "Wrong Selection: Select number between 1-$#"
		fi
	done
}

# declare the array
linux=('Arch' 'Debian' 'Gentoo' 'RHEL')

# call the subroutine to create the menu
menu_from_array "${linux[@]}"
