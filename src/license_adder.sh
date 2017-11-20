#!/bin/bash

function add_license_by_file_type(){
	for file in  `find $1 -name "$2"`
	do
		if ! grep -q Copyright "$file"; then
			cat /home/zhoujy/temp/header $file > $file.new && mv $file.new $file
			echo add LICENSE for $file
		fi
	done
}
function add_license_in_dir(){
	add_license_by_file_type $1 "*.cpp"
	add_license_by_file_type $1 "*.c"
	add_license_by_file_type $1 "*.hpp"
	add_license_by_file_type $1 "*.h"
}

add_license_in_dir ~/tmp/TopCNN/framework
add_license_in_dir ~/tmp/TopCNN/layers
add_license_in_dir ~/tmp/TopCNN/math
add_license_in_dir ~/tmp/TopCNN/tools
add_license_in_dir ~/tmp/TopCNN/tpm_maker