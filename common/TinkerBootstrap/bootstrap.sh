#!/bin/sh

# Enable password-less sudo for everyone
echo "%sudo ALL=(ALL) NOPASSWD:ALL" | sudo tee -a /etc/sudoers

# Install required packages
sudo apt-get update
sudo apt-get install -y avahi-daemon libnss-mdns v4l-utils imagemagick
sudo apt-get install openjdk-8-jdk

# Add entity101 user and password
sudo adduser entity101 --disabled-password --gecos ""
sudo adduser entity101 sudo
sudo adduser entity101 video
sudo adduser entity101 audio
echo "entity101:entity101" | sudo chpasswd

# Set hostname, user and password
echo entity101 | sudo tee /etc/hostname
echo "127.0.0.1 entity101" | sudo tee /etc/hosts

mkdir -p /home/Vision
mkdir -p /home/VoiceRecognition
mkdir -p /home/MachineLearning


# Reboot to commit changes
sudo reboot