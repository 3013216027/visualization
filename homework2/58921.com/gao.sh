#!/bin/bash
#################################################
#  File Name: gao.sh
#  
#  Author: zhengdongjian@tju.edu.cn
#  
#  Created Time: Thu 19 Nov 2015 09:57:49 AM CST
#  
#################################################

date=`date +%Y%m%d`
filename=dat$date\.html
curl http://58921.com > /home/dong/visualization/homework2/58921.com/$filename 2> /dev/null
cp /home/dong/visualization/homework2/58921.com/$filename /home/dong/visualization/homework2/58921.com/dat$date\_unix.html
dos2unix /home/dong/visualization/homework2/58921.com/dat$date\_unix.html 2> /dev/null

## update git repo
cd /home/dong/visualization
git pull
git add .
git commit -m "add homepage data of $(date +%Y-%2m-%2d):smile:"
git push

echo "update at $(date)."
