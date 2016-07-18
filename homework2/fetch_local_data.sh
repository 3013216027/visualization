#!/bin/bash
#################################################
#  File Name: fetch_local_data.sh
#  
#  Author: zhengdongjian@tju.edu.cn
#  
#  Created Time: 2015年11月29日 12:06:17
#  
#################################################
# Fetch data from local html pages

# Prepare data
cp -rf ./58921.com/ ./web/public/
if [ -e ./local_data_result ]; then
	echo 'ERROR: file ./local_data_result already exists! Exit...'
	exit 1
fi
mkdir ./local_data_result

# PLEASE start your local web server before.

for i in ./58921.com/*_unix.html; do
	jsonname=`echo $i | cut -d '/' -f3 | cut -d 't' -f2 | cut -d '_' -f1`
	python spider2.py localhost:3000/58921.com/dat$jsonname\_unix.html > ./local_data_result/$jsonname\.json
done

echo 'json files are successfully saved to ./local_data_result^_^'
exit 0
