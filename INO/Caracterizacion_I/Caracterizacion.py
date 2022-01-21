import serial
import time
import os

import subprocess
import pyautogui
import time

"""
Please do the following steps before running this code
    1. Upload Caracterizacion.ino to the Arduino board which is connected in port "arduino_port"
    2. Restar code by clicking reboot buttom
"""

# Create dataframe with readings
import pandas as pd
import os

path = './recording.csv'
if not os.path.exists(path):
    df = pd.DataFrame(columns=['angle','ldr0','ldr1','ldr2','ldr3','ldr4','ldr5'])
    df.to_csv(path, index=False)

buffer = ['angle','ldr0','ldr1','ldr2','ldr3','ldr4','ldr5']
data = dict()

# Initialize arduino
print('Initializing arduino')
arduino_port = '/dev/ttyACM0' #'/dev/ttyUSB0' or '/dev/ttyACM0'
arduino_baudrate = 9600
arduino = serial.Serial(arduino_port,arduino_baudrate)
print('Arduino initialized!')

print('Waiting ...')
status = False
while status == False:
    try:
        msg = arduino.readline().decode()
        print(msg)
    except:
        pass
    if 'Start characterization' in msg:
        status = True


# Start recording
print('--------- Start recording ---------')
while 'End characterization' not in msg:

    try:
        # Try to read
        try:
            msg = arduino.readline().decode()
        except:
            msg = 'error'

        # Open buffer
        if 'Begin report' in msg:
            print('--------- Begin report ---------')
            while status == True:
                msg = arduino.readline().decode()
                print(msg)
                if 'angle' in msg:
                    data['angle'] = float(msg.split('=')[1])
                if 'ldr0' in msg:
                    data['ldr0'] = float(msg.split('=')[1])
                if 'ldr1' in msg:
                    data['ldr1'] = float(msg.split('=')[1])
                if 'ldr2' in msg:
                    data['ldr2'] = float(msg.split('=')[1])
                if 'ldr3' in msg:
                    data['ldr3'] = float(msg.split('=')[1])
                if 'ldr4' in msg:
                    data['ldr4'] = float(msg.split('=')[1])
                if 'ldr5' in msg:
                    data['ldr5'] = float(msg.split('=')[1])
                if 'End report' in msg:
                    status = False


            # Write buffer
            print('--------- Writting to csv ---------')
            df = pd.DataFrame({'angle': [data['angle']],'ldr0': [data['ldr0']],'ldr1': [data['ldr1']],'ldr2': [data['ldr2']],'ldr3': [data['ldr3']],'ldr4': [data['ldr4']],'ldr5': [data['ldr5']]})

            with open(path, 'a') as f:
                df.to_csv(f, header=False, index=False)
            print('CSV saved!')
            status = True
    except:
        pass

print('--------- End characterization ---------')

arduino.close()
