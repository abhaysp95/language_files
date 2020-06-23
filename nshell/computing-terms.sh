#!/usr/bin/env sh

echo "This script shows how to create menus in bash script"
echo "Enter a number: "
PS3="My selection is: "

select TERM in cloud-computing virtual-machine object-storage exit; do
	case "${TERM}" in
		cloud-computing)
			echo "Cloud Computing: A combined set of remote severs, hosted on internet, to store, manage, and process data." ;;
		virtual-machine)
			echo "Virtual Maching: The emulating process of single computer system, such that a single piece of hardware can deploy and manage a number of host environments, by provideing the functionality of physical hardware." ;;
		object-storage)
			echo "Object Storage: Stores data called objects in containers, called buckets, and each object is given a unique identifier with which it is accessed." ;;
		exit)
			echo "Exting Now"
			break ;;
		*)
			echo "Make a selection from provided options" ;;
	esac
done
