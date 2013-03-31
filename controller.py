import serial

import pygame
from pygame.locals import *


ser = serial.Serial("/dev/rfcomm0");
ser.baudrate = 115200;

def forward():
   ser.write('0')


def stop():
   ser.write('1')


def right():
   ser.write('5')


def left ():
   ser.write('4')

 
while True:
      i = raw_input()

      if (i == "w"):
        forward()
      
      if (i == "d"):
        right()
      
      if (i == "a"):
        left()
      if (i == "s"):
        stop()
      
