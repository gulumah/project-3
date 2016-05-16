#!/bin/bash
echo "########## Package Update ############"
sudo apt-get update
echo "########## Git Installing ############"
sudo apt-get install git
echo "########## Cloning components/metrics directory ############"
git clone https://chromium.googlesource.com/chromium/src/components/metrics
echo "########## C++ Installing ############"
sudo apt-get install g++
cd metrics
git ls-files > allfiles.txt
git log --after="2016-1-1" --before="2016-5-15" --format="%an" | sort -u > allusers.txt
git log --after="2016-1-1" --before="2016-5-15" --format=%an | sort -u | while read line; do echo $line;git log --author="$line" --pretty='/ %h' --name-only | grep -v ^/ | grep -v ^$ | sort -u;echo ""; done > fileset.txt
cd ..
mkdir Question3
mkdir Question4
cp metrics/allfiles.txt Question3/allfiles.txt
cp metrics/allusers.txt Question3/allusers.txt
cp metrics/fileset.txt Question3/fileset.txt
g++ fileset.cpp -o fileset
./fileset
echo "######### Output of Question 3 and 4 were written in Question3 and Question4 #######"
