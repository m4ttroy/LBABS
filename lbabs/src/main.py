#! /usr/bin/env python

import rospy
import serial
import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import PointCloud2
import numpy as np

arduino = serial.Serial ('/dev/ttyUSB0', 115200)

def rem():
	arduino.flushOutput()
	arduino.write(b'p')
	

def jalan():
	arduino.flushOutput()
	arduino.write(b'h')

#List Kosong

A = []
B = []

def bintang():
	lenY = len(B)
	for k in range (0, lenY) :
		rem()

			


def callback(msg):
	for point in pc2.read_points(msg, skip_nans=True) :
		x = point[0]
		y = point[1]
		z = point[2]

		if x < 20 and y >= 0 : #area 180 derajat di depan
			if x < 1 and x > -1 and y < 2 : #area rem
				B.append(point[1])
				
				
			if y == 0 and x > 0 :
				bintang()
				lenB = len(B)
				if lenB == 0 :
					jalan()
				else :
					B[:] = []
					print lenB

rospy.init_node('object_detection')
sub = rospy.Subscriber('/velodyne_points', PointCloud2, callback)

rospy.spin()
