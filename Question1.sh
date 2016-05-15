#!/bin/bash
echo "########## Git Installing ############"
sudo apt-get install git
echo "########## Cloning components/metrics directory ############"
git clone https://chromium.googlesource.com/chromium/src/components/metrics
cd metrics
echo "########## Getting all commits between Jan 2016 - May 2016 period ###########"
git log --stat --after="2016-1-1" --before="2016-5-15" > stats.txt
cd ..
mkdir Question1
cp metrics/stats.txt Question1/stats.txt
echo "######### Output of Question#1 was written in Question1/stats.txt #########"


