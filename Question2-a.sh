#!/bin/bash
echo "########## Git Installing ############"
sudo apt-get install git
echo "########## Cloning components/metrics directory ############"
git clone https://chromium.googlesource.com/chromium/src/components/metrics
echo "########## Gitstats Installing ############"
sudo apt-get install gitstats
echo "########## Python 2.7 Installing ############"
sudo apt-get install python2.7
echo "########## Gnuplot Installing ############"
sudo apt-get install gnuplot
gitstats metrics Question2-a
sensible-browser Question2-a/authors.html
echo "######### Output of Question#2-a was written in Question2-a/authors.html #########
