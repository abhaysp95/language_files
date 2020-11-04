#!/usr/bin/env bash

theme_file="/tmp/vim-colorschemes"

theme_array=($(cat "${theme_file}" | sed 's/\n/ /g'))
echo "${theme_array[@]}"

select theme in "${theme_array[@]}"; do
	echo "You selected ${theme}"
	break
done
