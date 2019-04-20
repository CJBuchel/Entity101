#!/bin/sh

# Enable password-less sudo for everyone
echo "%sudo ALL=(ALL) NOPASSWD:ALL" | sudo tee -a /etc/sudoers

# Install required packages
sudo apt-get update
sudo apt-get install -y avahi-daemon libnss-mdns v4l-utils imagemagick

# Add entity101 user and password
sudo adduser entity101 --disabled-password --gecos ""
sudo adduser entity101 sudo
sudo adduser entity101 video
sudo adduser entity101 audio
echo "entity101:entity101" | sudo chpasswd

# Set hostname, user and password
echo entity101 | sudo tee /etc/hostname
echo "127.0.0.1 entity101" | sudo tee /etc/hosts


# Set Team #
echo Team Number?
read teamnum < /dev/tty

mkdir -p /home/Vision
mkdir -p /home/VoiceRecognition
mkdir -p /home/MachineLearning

echo $teamnum | sudo tee /home/Vision/team
echo $teamnum | sudo tee /home/VoiceRecognition/team
echo $teamnum | sudo tee /home/MachineLearning/team

sudo chown entity101 /home/Vision/team
sudo chmod 777 /home/Vision/team

sudo chown entity101 /home/VoiceRecognition/team
sudo chmod 777 /home/VoiceRecognition/team

sudo chown entity101 /home/MachineLearning/team
sudo chmod 777 /home/MachineLearning/team


# Reboot to commit changes
sudo reboot