#!/usr/bin/env sh

echo "Use this script to manipulate files in your current working directory:"
echo "----------------------------------------------------------------------"
echo "Here is a list of all your files."
echo "Select a file to access all availabe file actions:"

PS3="Select File: "

select file in * exit; do
	case ${file} in
		exit)
			echo "Exiting Now..."
			break ;;
		*)
			select ACTION in move view exit; do
				case "${ACTION}" in
					move)
						echo "You've chose to delete you file " "${file}"
						echo "Enter the new name: "
						read -r new_name
						mv "${file}" "${new_name}"
						echo "File renamed"
						break ;;
					view)
						echo "Your file is: "
						bat "${file}"
						break ;;
					exit)
						echo "Exiting now"
						break ;;
				esac
			done
			break;;
	esac
done
