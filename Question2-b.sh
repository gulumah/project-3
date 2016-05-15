#!/bin/bash
echo "########## Git Installing ############"
sudo apt-get install git
echo "########## Cloning components/metrics directory ############"
git clone https://chromium.googlesource.com/chromium/src/components/metrics
echo "########## C++ Installing ############"
sudo apt-get install g++
cd metrics
git shortlog -ns > allCommits.txt
cd ..
mkdir Question2-b
cp metrics/allCommits.txt Question2-b/allCommits.txt
g++ topDevelopers.cpp -o topDev
./topDev
echo "######### Output of Question#2-b was written in Question2-b/80percentage.txt #######"
